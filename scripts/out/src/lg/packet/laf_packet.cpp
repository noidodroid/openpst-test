/**
* LICENSE PLACEHOLDER
*
* @file laf_packet.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "lg/packet/laf_packet.h"

using namespace OpenPST::LG;

LafPacket::LafPacket() : Packet()
{
	addField("command", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg0", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg1", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg_opt0", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg_opt1", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("crc", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("magic", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 2);

}

LafPacket::~LafPacket()
{

}

uint32_t LafPacket::getCommand()
{
    return read<uint32_t>(getFieldOffset("command"));
}
                
void LafPacket::setCommand(uint32_t command)
{
    write<uint32_t>("command", command);
}
uint32_t LafPacket::getArg0()
{
    return read<uint32_t>(getFieldOffset("arg0"));
}
                
void LafPacket::setArg0(uint32_t arg0)
{
    write<uint32_t>("arg0", arg0);
}
uint32_t LafPacket::getArg1()
{
    return read<uint32_t>(getFieldOffset("arg1"));
}
                
void LafPacket::setArg1(uint32_t arg1)
{
    write<uint32_t>("arg1", arg1);
}
uint32_t LafPacket::getArgOpt0()
{
    return read<uint32_t>(getFieldOffset("arg_opt0"));
}
                
void LafPacket::setArgOpt0(uint32_t argOpt0)
{
    write<uint32_t>("arg_opt0", argOpt0);
}
uint32_t LafPacket::getArgOpt1()
{
    return read<uint32_t>(getFieldOffset("arg_opt1"));
}
                
void LafPacket::setArgOpt1(uint32_t argOpt1)
{
    write<uint32_t>("arg_opt1", argOpt1);
}
uint32_t LafPacket::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void LafPacket::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t LafPacket::getCrc()
{
    return read<uint32_t>(getFieldOffset("crc"));
}
                
void LafPacket::setCrc(uint32_t crc)
{
    write<uint32_t>("crc", crc);
}
uint32_t LafPacket::getMagic()
{
    return read<uint32_t>(getFieldOffset("magic"));
}
                
void LafPacket::setMagic(uint32_t magic)
{
    write<uint32_t>("magic", magic);
}
std::vector<uint8_t> LafPacket::getData()
{
	return readV(getFieldSize("data"), getFieldOffset("data"));
}
                
void LafPacket::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void LafPacket::unpack(std::vector<uint8_t>& data)
{
}

void LafPacket::prepareResponse()
{
	if (response != nullptr) {
		LafPacket* r = new LafPacket();
		this->response = r;
	}
}
