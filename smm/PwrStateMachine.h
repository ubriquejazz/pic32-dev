#ifndef POWER_STATE_MACHINE_H_
#define POWER_STATE_MACHINE_H_

#include "global.h"

#define REMOVE_RESET_FROM_BLADES    0x0000
#define HOLD_BLADES_IN_RESET        0xFFFF  

#define FAN_CONTROLLER_READ_SIZE_MSG    2
#define DELAY_FOR_POWER_SUPPLY_BRING_UP 6


/** States of the Power-up Statemachine*/ 
typedef enum{
    P_SM_IDLE_STATE = 0,
    P_SM_INIT_STATE,
    P_SM_CONFIGURE_STATE,
    P_SM_DELAY_STATE,
    P_SM_READY_STATE,
    P_SM_ERROR_STATE
} powerStates_e; 

void P_SM_ServiceStateMachine(void);

#endif //POWER_STATE_MACHINE_H_







