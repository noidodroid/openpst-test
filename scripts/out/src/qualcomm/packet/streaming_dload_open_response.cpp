/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_response.h"

StreamingDloadOpenResponse::StreamingDloadOpenResponse() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadOpened);
}

StreamingDloadOpenResponse::~StreamingDloadOpenResponse()
{

}


void StreamingDloadOpenResponse::unpack(std::vector<uint8_t>& data)
{
	
}