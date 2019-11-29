#include "global_val.h"
#include "servo.h"

INT8U guch_ServoAngle;//����Ƕ�
INT16U guin_AdcValue;//ADCֵ

/**
 *************************************************************************
 * @brief: GlobalValue_Init
 * @param: void
 * @return: void
 * @function: ȫ�ֱ�����ʼ��
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void GlobalValue_Init(void)
{
	INT16U i;
	guch_ServoAngle = 0;//�����ʼ�Ƕ�Ϊ0
	guin_AdcValue = 0;//��ʼ��ADCֵΪ0
	for(i = 0; i < SERVO_MAX_NUM; i++)
	{
		gast_ServoArray[i].uin_LastAngle = 0;
		gast_ServoArray[i].uin_PresentAngle = 0;
		gast_ServoArray[i].uin_TurnSpeed = 0;
	}//��ʼ���������
}








