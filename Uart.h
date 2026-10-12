#ifndef UART_H
#define UART_H

#include "global.h"
#include "UartCommands.h"

#define UART_DMA_TX_BUFFER_SIZE 64
#define UART_DMA_RX_BUFFER_SIZE 32

void UART1_Initialise(void);
void UART2_Initialise(void);
void UART3_Initialise(void);

void UART_TxString(uchar_t*, uint8_t);

BOOL UART_ProcessRxString(rxUartCommand_t**);

#endif //UART_H
