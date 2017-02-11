/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file 
* @package 
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "transport/serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

AsyncSerial::AsyncSerial(
	const std::string& device,
	unsigned int baud,
	int timeout,
	serial_port_base::parity parity,
	serial_port_base::character_size csize,
	serial_port_base::flow_control flow,
	serial_port_base::stop_bits stop
) : io(), port(io), timer(io), timeout(timeout)
{
	if (device.size()) {
		open(device, baud, parity, csize, flow, stop);
	}
}

AsyncSerial::~AsyncSerial()
{
	if (isOpen()) {
		try {
			close();
		} catch(...) {}
	}
}

bool AsyncSerial::isOpen()
{
	return port.is_open();
}

void AsyncSerial::open(
	const std::string& device,
	unsigned int baud,
	serial_port_base::parity parity,
    serial_port_base::character_size csize,
    serial_port_base::flow_control flow,
    serial_port_base::stop_bits stop
)
{
	if (!device.size()) {
		throw AsyncSerialError("No device specified");
	}
	if (isOpen()) {
		close();
	}
	
	boost::system::error_code error;

	port.open(device.c_str(), error);

	if (error) {
		throw AsyncSerialError(error.message());
	}

	port.set_option(serial_port_base::baud_rate(baud));
	port.set_option(parity);
	port.set_option(csize);
	port.set_option(flow);
	port.set_option(stop);
	
	this->device = device;
}

void AsyncSerial::close()
{
	if (port.is_open()) {
		port.cancel();
		port.close();
	}

	io.stop();
	io.reset();
}

size_t AsyncSerial::write(std::vector<uint8_t>& out)
{
	if (!isOpen()) {
		throw AsyncSerialError("Not open");
	}

	error_code error;

	size_t ret = boost::asio::write(port, boost::asio::buffer(out), boost::asio::transfer_all(), error);

	if (error) {
		throw AsyncSerialError(error.message());
	}

#ifdef SERIAL_DEBUG_TX
	std::cout << "Wrote " << ret << " bytes" << std::endl;
	hexdump(reinterpret_cast<uint8_t*>(&out[0]), ret);
#endif

	return ret;
}

size_t AsyncSerial::read(std::vector<uint8_t>& in, size_t amount)
{
	if (!isOpen()) {
		throw AsyncSerialError("Not open");
	}

	rxbuff.empty();
	rxbuff.reserve(amount);

	doAsyncRead(amount);

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&AsyncSerial::onTimeout, this, boost::asio::placeholders::error));

    received = 0;
    timedOut = false;

    io.run();

    io.reset();

#ifdef SERIAL_DEBUG_RX
	std::cout << "Read " << received << " bytes" << std::endl;
	hexdump(&rxbuff[0], received);
#endif

	if (received) {
		in.insert(in.end(), rxbuff.begin(), rxbuff.begin() + received);
	}

    return in.size();
}

size_t AsyncSerial::available()
{
	if (!isOpen()) {
		return 0;
	}

	boost::system::error_code error;
#if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
	COMSTAT status;
	if (::ClearCommError(port.native_handle(), NULL, &status)) {
		error = boost::system::error_code(
			::GetLastError(), 
			boost::asio::error::get_system_category()
		);
		throw AsyncSerialError(error.message());
	}
	return static_cast<size_t>(status.cbInQue);
#else
	size_t amount;
	if (!::ioctl(port.native_handle(), FIONREAD, &amount)) {
		error = boost::system::error_code(errno, boost::asio::error::get_system_category());
		throw AsyncSerialError(error.message());
	}
	return amount;
#endif
}

void AsyncSerial::onReadComplete(const boost::system::error_code& error, size_t received, size_t requested)
{
	if (error && error != boost::asio::error::eof) {
		timer.cancel();
		if (error.value() == ECANCELED) {
			return;
		}
		throw AsyncSerialError(error.message());
	}

	if (received || timedOut) {
		this->received = received;
		timer.cancel();
		return;
	}

	doAsyncRead(requested);
}

void AsyncSerial::doAsyncRead(size_t amount)
{
	port.async_read_some(
		boost::asio::buffer(&rxbuff[0], amount), 
		boost::bind(
			&AsyncSerial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred,
			amount
		)
	);
}

void AsyncSerial::onTimeout(const boost::system::error_code& error)
{	
	std::cout << "Read Timeout" << std::endl;

	timedOut = true;

	port.cancel();

	if (error && error.value() != ECANCELED) {
		throw AsyncSerialError(error.message());
	}
}

const std::string& AsyncSerial::getDevice()
{
	return this->device;
}


void AsyncSerial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int AsyncSerial::getTimeout()
{
	return timeout;
}
