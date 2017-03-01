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
* @file dm_efs_get_group_info_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsGetGroupInfoResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsGetGroupInfoResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsGetGroupInfoResponse();

                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                
                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);
                /**
                * @brief Get quota_size
                * @return uint32_t
                */
                uint32_t getQuotaSize();
                
                /**
                * @brief Set quota_size
                * @param uint32_t quotaSize
                * @return void
                */
                void setQuotaSize(uint32_t quotaSize);
                /**
                * @brief Get reservation_size
                * @return uint32_t
                */
                uint32_t getReservationSize();
                
                /**
                * @brief Set reservation_size
                * @param uint32_t reservationSize
                * @return void
                */
                void setReservationSize(uint32_t reservationSize);
                /**
                * @brief Get space_used
                * @return uint32_t
                */
                uint32_t getSpaceUsed();
                
                /**
                * @brief Set space_used
                * @param uint32_t spaceUsed
                * @return void
                */
                void setSpaceUsed(uint32_t spaceUsed);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
