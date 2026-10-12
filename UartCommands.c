#include "UartCommands.h"
#include "ObjectDictionary.h"

static rxUartCommand_t rxUartCommand;
static BOOL toggleCanMonitor = FALSE;

rxUartCommand_t* 
UART_CMD_getCommandBuffer(void)
{
    return &rxUartCommand;
}

void 
UART_CMD_execCommand(void)
{
    switch (rxUartCommand.command)
    {
        case 'W':
            if (rxUartCommand.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPP_RequestToWriteObject(LOCAL_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id, rxUartCommand.value);
            }
            else
            {   // FPGA register
                rxUartCommand.address = rxUartCommand.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPP_RequestToWriteObject(FPGA_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id, rxUartCommand.value);
            }
            break;
        case 'R':
            if (rxUartCommand.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPP_RequestToReadObject(LOCAL_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id);
                CANAPP_enableDisplayReadCommand(rxUartCommand.address, rxUartCommand.node_id);
            }
            else
            {   // FPGA register
                rxUartCommand.address = rxUartCommand.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPP_RequestToReadObject(FPGA_OBJECT, 
                    rxUartCommand.address, 0, rxUartCommand.node_id);
                CANAPP_enableDisplayReadCommand(rxUartCommand.address, rxUartCommand.node_id);
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
            CANAPP_enableCANMonitor(toggleCanMonitor);
            break;
    }
}
