#include "UartCommands.h"
#include "ObjectDictionary.h"
#include "CANAppLayer.h"

/* Private */

static rxUartCommand_t receivedCmd;
static BOOL toggleCanMonitor = FALSE;

/* Public */

rxUartCommand_t* UART_CMD_getCommandBuffer(void)
{
    return &receivedCmd;
}

void 
UART_CMD_execCommand(void)
{
    switch (receivedCmd.command)
    {
        case 'W':
            if (receivedCmd.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPP_RequestToWriteObject(LOCAL_OBJECT, 
                    receivedCmd.address, 0, receivedCmd.node_id, receivedCmd.value);
            }
            else
            {   // FPGA register
                receivedCmd.address = receivedCmd.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPP_RequestToWriteObject(FPGA_OBJECT, 
                    receivedCmd.address, 0, receivedCmd.node_id, receivedCmd.value);
            }
            break;
        case 'R':
            if (receivedCmd.address < BASE_ADDRESS_FPGA_REGISTERS)
            {
                CANAPP_RequestToReadObject(LOCAL_OBJECT, receivedCmd.address, 0, receivedCmd.node_id);
                CANAPP_enableDisplayReadCommand(receivedCmd.address, receivedCmd.node_id);
            }
            else
            {   // FPGA register
                receivedCmd.address = receivedCmd.address - BASE_ADDRESS_FPGA_REGISTERS;
                CANAPP_RequestToReadObject(FPGA_OBJECT, receivedCmd.address, 0, receivedCmd.node_id);
                CANAPP_enableDisplayReadCommand(receivedCmd.address, receivedCmd.node_id);
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
