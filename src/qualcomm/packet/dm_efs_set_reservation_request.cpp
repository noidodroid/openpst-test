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
* @file dm_efs_set_reservation_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_set_reservation_request.h"

using namespace OpenPST::Qualcomm;

DmEfsSetReservationRequest::DmEfsSetReservationRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("gid", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("amount", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsSetReservation);
}

DmEfsSetReservationRequest::~DmEfsSetReservationRequest()
{

}

uint32_t DmEfsSetReservationRequest::getGid()
{
    return read<uint32_t>(getFieldOffset("gid"));
}
                
void DmEfsSetReservationRequest::setGid(uint32_t gid)
{
    write<uint32_t>("gid", gid);
}
uint32_t DmEfsSetReservationRequest::getAmount()
{
    return read<uint32_t>(getFieldOffset("amount"));
}
                
void DmEfsSetReservationRequest::setAmount(uint32_t amount)
{
    write<uint32_t>("amount", amount);
}
std::vector<uint8_t> DmEfsSetReservationRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsSetReservationRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsSetReservationRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
void DmEfsSetReservationRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsSetReservationResponse* resp = new DmEfsSetReservationResponse();
		response = resp;
	}
}