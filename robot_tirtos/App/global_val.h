#ifndef __GLOBAL_VAL_H
#define __GLOBAL_VAL_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"

extern INT8U guch_ServoAngle;//Servo angle
extern INT16U guin_AdcValue;//ADC value
void GlobalValue_Init(void);


#endif



