#include "UartCommands.h"
#include "CANObjectDictionary.h"

static rxUartCommand_t rxUartCommand;

static BOOL toggleCanMonitor = FALSE;

rxUartCommand_t* 
UART_CMD_API_getCommandBuffer(void)
{
    return &rxUartCommand;
}

void UART_CMD_API_execCommand(void)
{
    switch (rxUartCommand.command)
    {
        case 'W':
            if (rxUartCommand.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPPAPI_RequestToWriteObject(LOCAL_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id, rxUartCommand.value);
            }
            else
            {   // FPGA register
                rxUartCommand.address = rxUartCommand.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPPAPI_RequestToWriteObject(FPGA_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id, rxUartCommand.value);
            }
            break;
        case 'R':
            if (rxUartCommand.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPPAPI_RequestToReadObject(LOCAL_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id);
                CANAPPAPI_enableDisplayReadCommand(rxUartCommand.address, rxUartCommand.node_id);
            }
            else
            {   // FPGA register
                rxUartCommand.address = rxUartCommand.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPPAPI_RequestToReadObject(FPGA_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id);
                CANAPPAPI_enableDisplayReadCommand(rxUartCommand.address, rxUartCommand.node_id);
            }
            break;
        default:
            if (toggleCanMonitor)
            { 
                toggleCanMonitor = FALSE;
            }
            else
            {
                toggleCanMonitor = TRUE; 
            }
            CANAPPAPI_enableCANMonitor(toggleCanMonitor);
            break;
    }
}
