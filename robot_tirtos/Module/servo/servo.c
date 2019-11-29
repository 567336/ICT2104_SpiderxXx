#include "servo.h"
#include "pca9685.h"
/*
SERVO_1   TA1.0  P8.0
SERVO_2   TA1.1  P7.7 
SERVO_3   TA2.0  P8.1    
SERVO_4   TA2.1  P5.6     
SERVO_5   TA2.2  P5.7   
SERVO_6   TA2.3  P6.6
SERVO_7   TA2.4  P6.7   
SERVO_8   TA3.0  P10.4  
SERVO_9   TA3.1  P10.5   
SERVO_10  TA3.2  P8.2   
SERVO_11  TA3.3  P9.2    
SERVO_12  TA3.4  P9.3 
*/
SERVO gast_ServoArray[SERVO_MAX_NUM];
/**
 *************************************************************************
 * @brief: Servo_ControlAngle
 * @param: uin_Num -- 瑙掑害
 * @return: void
 * @function:
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
/*
static void Servo_ControlAngle(INT16U uin_Num, SERVO *pst_Servo)
{
	INT16U i;
	if(pst_Servo[uin_Num].uin_LastAngle >= pst_Servo[uin_Num].uin_PresentAngle)
	{
		for(i = pst_Servo[uin_Num].uin_PresentAngle; i <= pst_Servo[uin_Num].uin_LastAngle; i++)
		{
			//Servo_TurnAngle(uin_Num, i);//
		    PCA9685_ControlServo(uin_Num, i);//PCA9685
		}
	}
	else
	{
		for(i = pst_Servo[uin_Num].uin_LastAngle; i <= pst_Servo[uin_Num].uin_PresentAngle; i++)
		{
			//Servo_TurnAngle(uin_Num, i);//
		    PCA9685_ControlServo(uin_Num, i);//PCA9685
		}				
	}
	pst_Servo[uin_Num].uin_LastAngle = pst_Servo[uin_Num].uin_PresentAngle;
}*/
/**
 *************************************************************************
 * @brief: Servo_Process
 * @param: uin_Num -- 瑙掑害  pst_Servo --
 * @return: void
 * @function:
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
/*
void Servo_Process(INT16U uin_Num, SERVO *pst_Servo)
{

	switch(uin_Num)
	{
		case SERVO_1:
		{
			Servo_ControlAngle(SERVO_1, pst_Servo);
			break;
		}
		case SERVO_2:
		{
			Servo_ControlAngle(SERVO_2, pst_Servo);
			break;
		}
		case SERVO_3:
		{
			Servo_ControlAngle(SERVO_3, pst_Servo);
			break;
		}
		case SERVO_4:

			break;
		}		
	}
}*/

