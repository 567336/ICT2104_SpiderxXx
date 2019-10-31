#include "key.h"
#include "timer.h"
#include "delay.h"
#include "global_val.h"
#include "servo.h"
/**
 *************************************************************************
 * @brief: KEY_Init
 * @param: void
 * @return: void
 * @function: 按键初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void KEY_Init(void)
{
	MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
	MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);
}

/**
 *************************************************************************
 * @brief: Key_Scanf
 * @param: void
 * @return: void
 * @function: 按键扫描
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Key_Scanf(void)
{
	if(!MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4))//S2按下
	{
		while(!MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4));//等待按键释放	
		if(guch_ServoAngle <= 0)
			guch_ServoAngle = 0;
		else
			guch_ServoAngle -= 5;
		Servo_TurnAngle(SERVO_6, guch_ServoAngle);
		Servo_TurnAngle(SERVO_7, 180 - guch_ServoAngle);

	}
	if(!MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1))//S1按下
	{
		while(!MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1));//等待按键释放
		if(guch_ServoAngle >= 180)
			guch_ServoAngle = 180;
		else
			guch_ServoAngle += 5;
		Servo_TurnAngle(SERVO_6, guch_ServoAngle);
		Servo_TurnAngle(SERVO_7, 180 - guch_ServoAngle);
	}
}

