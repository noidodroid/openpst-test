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
* @file dm_efs_deltree_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_deltree_request.h"

using namespace OpenPST::Qualcomm;

DmEfsDeltreeRequest::DmEfsDeltreeRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsDeltree);

	setResponseExpected(true);
}

DmEfsDeltreeRequest::~DmEfsDeltreeRequest()
{

}

uint16_t DmEfsDeltreeRequest::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                

void DmEfsDeltreeRequest::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}

std::vector<uint8_t> DmEfsDeltreeRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                

void DmEfsDeltreeRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsDeltreeRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsDeltreeResponse* resp = new DmEfsDeltreeResponse();
		response = resp;
	}
}

void DmEfsDeltreeRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setSequence(read<uint16_t>(data, getFieldOffset("sequence")));
	//variable
}
