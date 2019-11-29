#ifndef __PCA_H
#define __PCA_H	
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"


#define PCA_ADDR 0x80

#define PCA_MODE 0x0
#define PCA_PRE 0xFE

#define LED0_ON_L 0x6
#define LED0_ON_H 0x7
#define LED0_OFF_L 0x8
#define LED0_OFF_H 0x9



void PCA9685_Init(void);
void PCA9685_ControlServo(INT8U uch_num, INT8U uch_angle);

#endif
