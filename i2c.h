#ifndef I2C_H_
#define I2C_H_

#include "types.h"

#define ADDRESS_PORT_EXPANDER_1     0x68
#define ADDRESS_PORT_EXPANDER_2     0x6D
#define ADDRESS_PORT_EXPANDER_3     0x20
#define ADDRESS_PORT_EXPANDER_4     0x21
#define ADDRESS_PORT_EXPANDER_5     0x22
#define ADDRESS_PORT_EXPANDER_6     0x23
#define ADDRESS_PORT_EXPANDER_7     0x24

#define I2C_WRITE_CONFIGURATION_COMMAND 0x06
#define I2C_WRITE_OUTPUT_COMMAND 0x02

void I2C_Initialise(uint8_t numberOfDevices);
BOOL I2C_ReadPortExpander(uint8_t address);
void I2C_ProcessI2CPortExpander(void);
BOOL I2C_Access_TCA9555(uint32_t address, uint32_t data, BOOL readCommand);
BOOL I2C_initialiseTCA9555(void);
uint8_t I2C_ReadPortExpanderComBoardSlotId(void);

#endif //I2C_H_
