#include "global_val.h"
#include "servo.h"

INT8U guch_ServoAngle;//舵机角度
INT16U guin_AdcValue;//ADC值

/**
 *************************************************************************
 * @brief: GlobalValue_Init
 * @param: void
 * @return: void
 * @function: 全局变量初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void GlobalValue_Init(void)
{
	INT16U i;
	guch_ServoAngle = 0;//舵机初始角度为0
	guin_AdcValue = 0;//初始化ADC值为0
	for(i = 0; i < SERVO_MAX_NUM; i++)
	{
		gast_ServoArray[i].uin_LastAngle = 0;
		gast_ServoArray[i].uin_PresentAngle = 0;
		gast_ServoArray[i].uin_TurnSpeed = 0;
	}//初始化舵机参数
}








