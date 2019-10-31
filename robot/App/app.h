#ifndef __APP_H
#define __APP_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "delay.h"
#include "timer.h"
#include "key.h"
#include "uart0.h"
#include "global_val.h"
#include "adc.h"
#include "myiic.h"
//#include "iic.h"

#include "servo.h"
#include "hc05.h"
#include "hc_sr04.h"
#include "pca9685.h"



void App_Init(void);//应用程序初始化


#endif



