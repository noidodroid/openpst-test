/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_power_off_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_power_off_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadPowerOffResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadPowerOffRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPowerOffRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPowerOffRequest();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
