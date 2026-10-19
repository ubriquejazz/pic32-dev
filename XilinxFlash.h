#ifndef XIL_FLASH_H_
#define XIL_FLASH_H_

#include "global.h"

#define OFFSET_BEGIN_DATA       4
#define RX_BUFFER_DATA_OFFSET   4

typedef union {
	struct {
        unsigned WRITE_IN_PROGRESS_BIT:1;
        unsigned WRITE_ENABLE_LATCH:1;
        unsigned BLOCK_PROTECT_BITS:3;
        unsigned :2;
        unsigned STATUS_REGISTER_WRITE_PROTECT:1;
    };
    uint8_t byte;
} flashStatusRegister_t;

BOOL XILFLASH_API_ReadDataBytes(uint32_t flashAddress, uint32_t numberOfBytes);

BOOL XILFLASH_API_WriteDataBytes(uint32_t,uint8_t* txBuffer, uint32_t numberOfBytes);

uint8_t* XILFLASH_API_GetRxBuffer(void);

BOOL  XILFLASH_API_UnProtectAllSectors(void);

BOOL  XILFLASH_API_ProtectAllSectors(void);

BOOL XILFLASH_API_EraseFlash(void);

BOOL XILFLASH_API_ReadWriteComplete(void);

BOOL XILFLASH_API_Select_Flash(uint32_t flashId);

#endif //XIL_FLASH_H_ 
