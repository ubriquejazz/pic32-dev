#ifndef UART_COMMANDS_H
#define UART_COMMANDS_H

#include "global.h"

#define NULMBER_OF_COMMAND_ARGUMENTS 4

typedef enum {
    UART_CMD_COMMAND=0, 
    UART_CMD_NODE_ID, 
    UART_CMD_ADDRESS, 
    UART_CMD_VALUE} 
commandArguments_e;
 
typedef struct {
    uint8_t command;
    uint32_t node_id;
    uint32_t address;
    uint32_t value;
}  rxUartCommand_t;

#define COMMAND_STR_LENGTH 2    // includes NUL for end of string
#define NODE_ID_STR_LENGTH 4    // includes NUL for end of string
#define ADDRESS_STR_LENGTH 9    // includes NUL for end of string
#define VALUE_STR_LENGTH 9      // includes NUL for end of string

rxUartCommand_t* UART_CMD_API_getCommandBuffer(void);
void UART_CMD_API_execCommand(void);

#endif 