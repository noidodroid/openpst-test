/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_statfs_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_statfs_request.h"

using namespace OpenPST::QC;

QcdmEfsStatfsRequest::QcdmEfsStatfsRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsStatfsRequest::~QcdmEfsStatfsRequest()
{

}

std::vector<uint8_t> QcdmEfsStatfsRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsStatfsRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsStatfsRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

