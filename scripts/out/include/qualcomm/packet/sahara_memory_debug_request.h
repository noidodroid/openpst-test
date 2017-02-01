/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_debug_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/packet/sahara_memory_read_request.h"

using OpenPST::QC::SaharaPacket;
using OpenPST::QC::SaharaMemoryReadRequest;

namespace OpenPST {
    namespace QC {
        
        class SaharaMemoryDebugRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaMemoryDebugRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~SaharaMemoryDebugRequest();

                /**
                * @brief Get address
                * @return uint32_t
                */
                uint32_t getAddress();
                
                /**
                * @brief Set address
                * @param uint32_t address
                * @return void
                */
                void setAddress(uint32_t address);
                /**
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                
                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);
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
