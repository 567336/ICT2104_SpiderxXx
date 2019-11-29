#ifndef __GLOBAL_VAL_H
#define __GLOBAL_VAL_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"

extern INT8U guch_ServoAngle;//舵机角度
extern INT16U guin_AdcValue;//ADC值
void GlobalValue_Init(void);//全局变量初始化函数声明


#endif



