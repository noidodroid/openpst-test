/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_statfs_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::QC::DmEfsPacket;

namespace OpenPST {
    namespace QC {
        
        class QcdmEfsStatfsResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsStatfsResponse();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsStatfsResponse();

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
                * @brief Get filesystem_id
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getFilesystemId();
                
                /**
                * @brief Set filesystem_id
                * @param uint8_t* filesystemId
                * @param size_t size
                * @return void
                */
                void setFilesystemId(uint8_t* data, size_t size);
                /**
                * @brief Get filesystem_type
                * @return uint32_t
                */
                uint32_t getFilesystemType();
                
                /**
                * @brief Set filesystem_type
                * @param uint32_t filesystemType
                * @return void
                */
                void setFilesystemType(uint32_t filesystemType);
                /**
                * @brief Get block_size
                * @return uint32_t
                */
                uint32_t getBlockSize();
                
                /**
                * @brief Set block_size
                * @param uint32_t blockSize
                * @return void
                */
                void setBlockSize(uint32_t blockSize);
                /**
                * @brief Get total_blocks
                * @return uint32_t
                */
                uint32_t getTotalBlocks();
                
                /**
                * @brief Set total_blocks
                * @param uint32_t totalBlocks
                * @return void
                */
                void setTotalBlocks(uint32_t totalBlocks);
                /**
                * @brief Get available_blocks
                * @return uint32_t
                */
                uint32_t getAvailableBlocks();
                
                /**
                * @brief Set available_blocks
                * @param uint32_t availableBlocks
                * @return void
                */
                void setAvailableBlocks(uint32_t availableBlocks);
                /**
                * @brief Get free_blocks
                * @return uint32_t
                */
                uint32_t getFreeBlocks();
                
                /**
                * @brief Set free_blocks
                * @param uint32_t freeBlocks
                * @return void
                */
                void setFreeBlocks(uint32_t freeBlocks);
                /**
                * @brief Get max_file_size
                * @return uint32_t
                */
                uint32_t getMaxFileSize();
                
                /**
                * @brief Set max_file_size
                * @param uint32_t maxFileSize
                * @return void
                */
                void setMaxFileSize(uint32_t maxFileSize);
                /**
                * @brief Get file_count
                * @return uint32_t
                */
                uint32_t getFileCount();
                
                /**
                * @brief Set file_count
                * @param uint32_t fileCount
                * @return void
                */
                void setFileCount(uint32_t fileCount);
                /**
                * @brief Get max_file_count
                * @return uint32_t
                */
                uint32_t getMaxFileCount();
                
                /**
                * @brief Set max_file_count
                * @param uint32_t maxFileCount
                * @return void
                */
                void setMaxFileCount(uint32_t maxFileCount);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
