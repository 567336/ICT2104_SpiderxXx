#ifndef __TIMER_H
#define __TIMER_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
void TimerA0_Init(void);
void TimerA1_Init(void);
void TimerA2_Init(void);
void TimerA3_Init(void);
void Servo_TurnAngle(INT16U uin_Num, INT8U uch_Angle);



#endif


