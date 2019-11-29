#include "global_val.h"
#include "servo.h"

INT8U guch_ServoAngle;//Servo Angle
INT16U guin_AdcValue;//ADC value

/**
 *************************************************************************
 * @brief: GlobalValue_Init
 * @param: void
 * @return: void
 * @function: Initialize all Servo angle values
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void GlobalValue_Init(void)
{
	INT16U i;
	guch_ServoAngle = 0;//Servo angle initialized as 0
	guin_AdcValue = 0;//Initialize ADC value as 0
	for(i = 0; i < SERVO_MAX_NUM; i++)
	{
		gast_ServoArray[i].uin_LastAngle = 0;
		gast_ServoArray[i].uin_PresentAngle = 0;
		gast_ServoArray[i].uin_TurnSpeed = 0;
	}//Initialise Servo angle values
}








