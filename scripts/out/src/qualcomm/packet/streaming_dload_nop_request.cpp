/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_nop_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_nop_request.h"

StreamingDloadNopRequest::StreamingDloadNopRequest() : StreamingDloadPacket()
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadNop);
}

StreamingDloadNopRequest::~StreamingDloadNopRequest()
{

}

uint32_t StreamingDloadNopRequest::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopRequest::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}

void StreamingDloadNopRequest::unpack(std::vector<uint8_t>& data)
{
	
}