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
* @file sahara_client_command_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/packet/sahara_client_command_response.h"

using OpenPST::Qualcomm::SaharaPacket;
using OpenPST::Qualcomm::SaharaClientCommandResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class SaharaClientCommandRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaClientCommandRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaClientCommandRequest();

                
                /**
                * @brief Get client_command
                * @return uint32_t
                */
                uint32_t getClientCommand();
                                

                /**
                * @brief Set client_command
                * @param uint32_t clientCommand
                * @return void
                */
                void setClientCommand(uint32_t clientCommand);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
