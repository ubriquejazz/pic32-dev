#ifndef I2C_H_
#define I2C_H_

#include "types.h"

#define I2C_OUTPUT_PORT_EXPANDER 0x68
#define I2C_WRITE_CONFIG_COMMAND 0x06
#define I2C_WRITE_OUTPUT_COMMAND 0x02

void I2C_Initialise(uint8_t numberOfDevices);
BOOL TCA9555_ReadFrom(uint8_t address, uint8_t*);
BOOL TCA9555_WriteTo(uint8_t address, uint8_t value);

#endif //I2C_H_
