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
* @file dm_efs_rename_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rename_response.h"

using namespace OpenPST::Qualcomm;

DmEfsRenameResponse::DmEfsRenameResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsRename);
}

DmEfsRenameResponse::~DmEfsRenameResponse()
{

}

uint32_t DmEfsRenameResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsRenameResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsRenameResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
