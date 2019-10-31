#ifndef __LED_H
#define __LED_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"

#define RED_LED   (0x01 << 1)
#define GREEN_LED (0x01 << 2)
#define BLUE_LED  (0x01 << 3)
#define OPEN   true
#define CLOSE  false
void LED_Init(void);
void LED_Control(INT8U uch_led, bool b_status);


#endif

