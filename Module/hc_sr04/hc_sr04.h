#ifndef __HC_SR04_H
#define __HC_SR04_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
#include "stdbool.h"

#define MIN_DISTANCE 10.0f//cm ◊Ó–°æ‡¿Î


void HC_SR04_Init(void);
FP32 Get_SR04Distance(void);//
bool Check_SR04Distance(FP32 f_dis);//
#endif

