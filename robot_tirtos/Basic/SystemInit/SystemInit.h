#ifndef _SYSTEMINIT_H
#define _SYSTEMINIT_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
/***************************
      ±÷”‘¥—°‘Ò
***************************/
#define  LFXT    1
#define  HFXT    2
#define  DCO     3
#define  REFO    4

void SystemClockInit(u8 ClockSource);

#endif

