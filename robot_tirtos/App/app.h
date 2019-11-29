#ifndef __APP_H
#define __APP_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "delay.h"

#include "global_val.h"

#include "myiic.h"
//#include "iic.h"

#include "servo.h"
#include "pca9685.h"

#define LEG_ONE   0x11
#define LEG_TWO   0x22
#define LEG_THREE 0x33
#define LEG_FOUR  0x44

#define NUM_ONE   0xAA
#define NUM_TWO   0xBB
#define NUM_THREE 0xCC

void App_Init(void);
void RobtotProcess(INT8U uch_WhichLeg, INT8U uch_Num, INT16U uin_Angle);//



void RobotStandup(uint16_t uin_Speed);
void RobotHalfStand(void);
void RobotStand(void);
void RobotRaise(void);
void RobotRaiseup(uint16_t uin_Speed);
void RobotClimb(uint16_t uin_Speed);
void RobotPrepare(uint16_t uin_Speed);
void RobotPrepareLeft(uint16_t uin_Speed);
void RobotRun(uint16_t uin_Speed);
void RobotBack(uint16_t uin_Speed);
void RobotLeft(uint16_t uin_Speed);
void RobotRight(uint16_t uin_Speed);
void RobotTest(uint16_t uin_Speed);
void RobotUSright(void);
void RobotUSleft(void);
void RobotUSmiddle(void);
#endif



