#ifndef SPI3A_H_
#define SPI3A_H_

#include "global.h"

BOOL SPIOne_IsTxComplete(void);
void SPIOne_Initialise(void);
void SPIOne_TxRxBuffer(uint8_t* pTxBuffer, uint8_t* pRxBuffer, uint16_t bufferLengths);

#endif //SPI3A_H_