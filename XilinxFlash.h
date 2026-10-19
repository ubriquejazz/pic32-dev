#ifndef XIL_FLASH_H_
#define XIL_FLASH_H_

#include "global.h"

#define OFFSET_BEGIN_DATA       4
#define RX_BUFFER_DATA_OFFSET   4

BOOL XILFLASH_ReadDataBytes(uint32_t flashAddress, uint32_t numberOfBytes);

BOOL XILFLASH_WriteDataBytes(uint32_t,uint8_t* txBuffer, uint32_t numberOfBytes);

uint8_t* XILFLASH_GetRxBuffer(void);

BOOL XILFLASH_UnProtectAllSectors(void);

BOOL XILFLASH_ProtectAllSectors(void);

BOOL XILFLASH_EraseFlash(void);

BOOL XILFLASH_ReadWriteComplete(void);

BOOL XILFLASH_Select_Flash(uint32_t flashId);

#endif //XIL_FLASH_H_ 
