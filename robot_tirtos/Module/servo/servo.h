#ifndef __SERVO_H
#define __SERVO_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"

//Servo angle settings
#define SERVO_MAX_NUM 12 // Max servos used
#define SERVO_MAX_ANGLE 180//
#define SERVO_MIN_ANGLE 0//


#define SERVO_1    0x00//(0x01 << 0)
#define SERVO_2    0x01//(0x01 << 1)
#define SERVO_3    0x02//(0x01 << 2)
#define SERVO_4    0x03//(0x01 << 3)
#define SERVO_5    0x04//(0x01 << 4)
#define SERVO_6    0x05//(0x01 << 5)
#define SERVO_7    0x06//(0x01 << 6)
#define SERVO_8    0x07//(0x01 << 7)
#define SERVO_9    0x08//(0x01 << 8)
#define SERVO_10   0x09//(0x01 << 9)
#define SERVO_11   0x0A//(0x01 << 10)
#define SERVO_12   0x0B//(0x01 << 11)
#define SERVO_13   0x0C//(0x01 << 11)


// Includes
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>


//Define struct Servo structure
typedef struct _SERVO
{
	INT16U  uin_LastAngle; //Store last known angle of Servo
	INT16U  uin_PresentAngle; // Store current Servo angle
	INT16U  uin_TurnSpeed; // Store the rate of turning
}SERVO;

extern SERVO gast_ServoArray[SERVO_MAX_NUM]; // Array to store all Servo struct
//void Servo_Process(INT16U uch_Num, SERVO *pst_Servo);





#endif


