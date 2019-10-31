#include "hc05.h"
#include <string.h>

/**
 *************************************************************************
 * @brief: Hc05_Process
 * @param: puch_buf -- ��������ָ��
 * @return: void
 * @function: ����ģ�鴦��
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Hc05_Process(INT8U *puch_buf)
{
	if(*puch_buf == 0x00)
	{
		return;
	}
	if((*puch_buf != HEAD_PACK) //����ͷ�ж�
	|| (*(puch_buf + 2) != HEAD_TAIL))//����λ�ж�
	{
		memset(puch_buf, 0, strlen((char*)puch_buf));//�������
		return;
	}
	switch(*(puch_buf + 1))
	{
		case RUN_CMD://ǰ��
		{
			//gast_ServoArray[SERVO_6].uin_PresentAngle = 100;
			//Servo_Process(SERVO_6, gast_ServoArray);
		    Robot_Run(gast_ServoArray);//ǰ��
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case BACK_CMD://����
		{
			//gast_ServoArray[SERVO_6].uin_PresentAngle = 50;
			//Servo_Process(SERVO_6, gast_ServoArray);
		    Robot_Back(gast_ServoArray);//����
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case LEFT_CMD://��ת
		{
		    Robot_Left(gast_ServoArray);//��ת
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case RIGHT_CMD://��ת
		{
		    Robot_Right(gast_ServoArray);//��ת
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case STOP_CMD://ֹͣ
		{
		    Robot_Stop(gast_ServoArray);//ֹͣ
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		default://�������
		{
			memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
	}
}

/**
 *************************************************************************
 * @brief: Robot_GoHome
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_GoHome(SERVO *pst_Servo)
{
    /*//SERVO1
    pst_Servo[SERVO_1].uin_PresentAngle = 10;
    //SERVO2
    pst_Servo[SERVO_2].uin_PresentAngle = 10;
    //SERVO3
    pst_Servo[SERVO_3].uin_PresentAngle = 10;
    //SERVO4
    pst_Servo[SERVO_4].uin_PresentAngle = 10;
    //SERVO5
    pst_Servo[SERVO_5].uin_PresentAngle = 10;
    //SERVO6
    pst_Servo[SERVO_6].uin_PresentAngle = 10;
    //SERVO7
    pst_Servo[SERVO_7].uin_PresentAngle = 10;
    //SERVO8
    pst_Servo[SERVO_8].uin_PresentAngle = 10;
    //SERVO9
    pst_Servo[SERVO_9].uin_PresentAngle = 10;
    //SERVO10
    pst_Servo[SERVO_10].uin_PresentAngle = 10;
    //SERVO11
    pst_Servo[SERVO_11].uin_PresentAngle = 10;
    //SERVO12
    pst_Servo[SERVO_12].uin_PresentAngle = 10;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    */
    pst_Servo[SERVO_1].uin_PresentAngle = 60;
    pst_Servo[SERVO_5].uin_PresentAngle = 30;
    pst_Servo[SERVO_9].uin_PresentAngle = 10;
    Servo_Process(SERVO_1, pst_Servo);
    Servo_Process(SERVO_5, pst_Servo);
    Servo_Process(SERVO_9, pst_Servo);

    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 40;
    pst_Servo[SERVO_10].uin_PresentAngle = 15;

    Servo_Process(SERVO_2, pst_Servo);
    Servo_Process(SERVO_6, pst_Servo);
    Servo_Process(SERVO_10, pst_Servo);

    pst_Servo[SERVO_3].uin_PresentAngle = 75;
    pst_Servo[SERVO_7].uin_PresentAngle = 20;
    pst_Servo[SERVO_11].uin_PresentAngle = 15;

    Servo_Process(SERVO_3, pst_Servo);
    Servo_Process(SERVO_7, pst_Servo);
    Servo_Process(SERVO_11, pst_Servo);

    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 20;
    pst_Servo[SERVO_12].uin_PresentAngle = 10;


    Servo_Process(SERVO_4, pst_Servo);
    Servo_Process(SERVO_8, pst_Servo);
    Servo_Process(SERVO_12, pst_Servo);
}
/**
 *************************************************************************
 * @brief: Robot_Stand
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Stand(SERVO *pst_Servo)
{
    pst_Servo[SERVO_1].uin_PresentAngle = 60;
    pst_Servo[SERVO_5].uin_PresentAngle = 70;
    pst_Servo[SERVO_9].uin_PresentAngle = 40;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 75;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 60;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12

}
/**
 *************************************************************************
 * @brief: Robot_Run
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Run(SERVO *pst_Servo)
{

    //̧��1
    pst_Servo[SERVO_1].uin_PresentAngle = 60;
    pst_Servo[SERVO_5].uin_PresentAngle = 20;
    pst_Servo[SERVO_9].uin_PresentAngle = 50;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 75;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 40;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);

    //ת��1
    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 20;
    pst_Servo[SERVO_9].uin_PresentAngle = 50;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;

    pst_Servo[SERVO_3].uin_PresentAngle = 75;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 40;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);
    //����1
    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 70;
    pst_Servo[SERVO_9].uin_PresentAngle = 40;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 75;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 60;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);
    //̧��4
    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 50;
    pst_Servo[SERVO_9].uin_PresentAngle = 50;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 45;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 70;
    pst_Servo[SERVO_8].uin_PresentAngle = 20;
    pst_Servo[SERVO_12].uin_PresentAngle = 80;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);
    //ת��4
    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 50;
    pst_Servo[SERVO_9].uin_PresentAngle = 50;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 45;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 20;
    pst_Servo[SERVO_8].uin_PresentAngle = 20;
    pst_Servo[SERVO_12].uin_PresentAngle = 80;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);
    //����4
    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 50;
    pst_Servo[SERVO_9].uin_PresentAngle = 50;


    pst_Servo[SERVO_2].uin_PresentAngle = 145;
    pst_Servo[SERVO_6].uin_PresentAngle = 90;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;



    pst_Servo[SERVO_3].uin_PresentAngle = 45;
    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;


    pst_Servo[SERVO_4].uin_PresentAngle = 20;
    pst_Servo[SERVO_8].uin_PresentAngle = 60;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_1, pst_Servo);//���1
    Servo_Process(SERVO_2, pst_Servo);//���2
    Servo_Process(SERVO_3, pst_Servo);//���3
    Servo_Process(SERVO_4, pst_Servo);//���4
    Servo_Process(SERVO_5, pst_Servo);//���5
    Servo_Process(SERVO_6, pst_Servo);//���6
    Servo_Process(SERVO_7, pst_Servo);//���7
    Servo_Process(SERVO_8, pst_Servo);//���8
    Servo_Process(SERVO_9, pst_Servo);//���9
    Servo_Process(SERVO_10, pst_Servo);//���10
    Servo_Process(SERVO_11, pst_Servo);//���11
    Servo_Process(SERVO_12, pst_Servo);//���12
    delay_ms(50000);
}
/**
 *************************************************************************
 * @brief: Robot_Back
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Back(SERVO *pst_Servo)
{
    //̧��4
       pst_Servo[SERVO_1].uin_PresentAngle = 110;
       pst_Servo[SERVO_5].uin_PresentAngle = 50;
       pst_Servo[SERVO_9].uin_PresentAngle = 50;


       pst_Servo[SERVO_2].uin_PresentAngle = 145;
       pst_Servo[SERVO_6].uin_PresentAngle = 90;
       pst_Servo[SERVO_10].uin_PresentAngle = 45;



       pst_Servo[SERVO_3].uin_PresentAngle = 45;
       pst_Servo[SERVO_7].uin_PresentAngle = 60;
       pst_Servo[SERVO_11].uin_PresentAngle = 45;


       pst_Servo[SERVO_4].uin_PresentAngle = 70;
       pst_Servo[SERVO_8].uin_PresentAngle = 30;
       pst_Servo[SERVO_12].uin_PresentAngle = 100;

       Servo_Process(SERVO_1, pst_Servo);//���1
       Servo_Process(SERVO_2, pst_Servo);//���2
       Servo_Process(SERVO_3, pst_Servo);//���3
       Servo_Process(SERVO_4, pst_Servo);//���4
       Servo_Process(SERVO_5, pst_Servo);//���5
       Servo_Process(SERVO_6, pst_Servo);//���6
       Servo_Process(SERVO_7, pst_Servo);//���7
       Servo_Process(SERVO_8, pst_Servo);//���8
       Servo_Process(SERVO_9, pst_Servo);//���9
       Servo_Process(SERVO_10, pst_Servo);//���10
       Servo_Process(SERVO_11, pst_Servo);//���11
       Servo_Process(SERVO_12, pst_Servo);//���12
       delay_ms(50000);
       //ת��4
       pst_Servo[SERVO_1].uin_PresentAngle = 110;
       pst_Servo[SERVO_5].uin_PresentAngle = 50;
       pst_Servo[SERVO_9].uin_PresentAngle = 50;


       pst_Servo[SERVO_2].uin_PresentAngle = 145;
       pst_Servo[SERVO_6].uin_PresentAngle = 90;
       pst_Servo[SERVO_10].uin_PresentAngle = 45;



       pst_Servo[SERVO_3].uin_PresentAngle = 45;
       pst_Servo[SERVO_7].uin_PresentAngle = 60;
       pst_Servo[SERVO_11].uin_PresentAngle = 45;


       pst_Servo[SERVO_4].uin_PresentAngle = 20;
       pst_Servo[SERVO_8].uin_PresentAngle = 20;
       pst_Servo[SERVO_12].uin_PresentAngle = 80;

       Servo_Process(SERVO_1, pst_Servo);//���1
       Servo_Process(SERVO_2, pst_Servo);//���2
       Servo_Process(SERVO_3, pst_Servo);//���3
       Servo_Process(SERVO_4, pst_Servo);//���4
       Servo_Process(SERVO_5, pst_Servo);//���5
       Servo_Process(SERVO_6, pst_Servo);//���6
       Servo_Process(SERVO_7, pst_Servo);//���7
       Servo_Process(SERVO_8, pst_Servo);//���8
       Servo_Process(SERVO_9, pst_Servo);//���9
       Servo_Process(SERVO_10, pst_Servo);//���10
       Servo_Process(SERVO_11, pst_Servo);//���11
       Servo_Process(SERVO_12, pst_Servo);//���12
       delay_ms(50000);
       //����4
       pst_Servo[SERVO_1].uin_PresentAngle = 110;
       pst_Servo[SERVO_5].uin_PresentAngle = 50;
       pst_Servo[SERVO_9].uin_PresentAngle = 50;


       pst_Servo[SERVO_2].uin_PresentAngle = 145;
       pst_Servo[SERVO_6].uin_PresentAngle = 90;
       pst_Servo[SERVO_10].uin_PresentAngle = 45;



       pst_Servo[SERVO_3].uin_PresentAngle = 45;
       pst_Servo[SERVO_7].uin_PresentAngle = 60;
       pst_Servo[SERVO_11].uin_PresentAngle = 45;


       pst_Servo[SERVO_4].uin_PresentAngle = 20;
       pst_Servo[SERVO_8].uin_PresentAngle = 60;
       pst_Servo[SERVO_12].uin_PresentAngle = 40;

       Servo_Process(SERVO_1, pst_Servo);//���1
       Servo_Process(SERVO_2, pst_Servo);//���2
       Servo_Process(SERVO_3, pst_Servo);//���3
       Servo_Process(SERVO_4, pst_Servo);//���4
       Servo_Process(SERVO_5, pst_Servo);//���5
       Servo_Process(SERVO_6, pst_Servo);//���6
       Servo_Process(SERVO_7, pst_Servo);//���7
       Servo_Process(SERVO_8, pst_Servo);//���8
       Servo_Process(SERVO_9, pst_Servo);//���9
       Servo_Process(SERVO_10, pst_Servo);//���10
       Servo_Process(SERVO_11, pst_Servo);//���11
       Servo_Process(SERVO_12, pst_Servo);//���12
       delay_ms(50000);
}
/**
 *************************************************************************
 * @brief: Robot_Stop
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Stop(SERVO *pst_Servo)
{


       pst_Servo[SERVO_8].uin_PresentAngle = 20;


       Servo_Process(SERVO_8, pst_Servo);//���4

}
/**
 *************************************************************************
 * @brief: Robot_Left
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Left(SERVO *pst_Servo)
{
    delay_ms(9000);
/*    pst_Servo[SERVO_5].uin_PresentAngle = 20;
    pst_Servo[SERVO_9].uin_PresentAngle = 140;

    pst_Servo[SERVO_6].uin_PresentAngle = 80;
    pst_Servo[SERVO_10].uin_PresentAngle = 45;

    pst_Servo[SERVO_7].uin_PresentAngle = 60;
    pst_Servo[SERVO_11].uin_PresentAngle = 45;

    pst_Servo[SERVO_8].uin_PresentAngle = 60;
    pst_Servo[SERVO_12].uin_PresentAngle = 40;

    Servo_Process(SERVO_5, pst_Servo);
    Servo_Process(SERVO_9, pst_Servo);
    Servo_Process(SERVO_6, pst_Servo);
    Servo_Process(SERVO_10, pst_Servo);
    Servo_Process(SERVO_7, pst_Servo);
    Servo_Process(SERVO_11, pst_Servo);
    Servo_Process(SERVO_8, pst_Servo);
    Servo_Process(SERVO_12, pst_Servo);
    */

    pst_Servo[SERVO_1].uin_PresentAngle = 110;
    pst_Servo[SERVO_5].uin_PresentAngle = 20;
    pst_Servo[SERVO_9].uin_PresentAngle = 140;


        pst_Servo[SERVO_2].uin_PresentAngle = 95;
        pst_Servo[SERVO_6].uin_PresentAngle = 40;
        pst_Servo[SERVO_10].uin_PresentAngle = 15;

        pst_Servo[SERVO_3].uin_PresentAngle = 135;
        pst_Servo[SERVO_7].uin_PresentAngle = 30;
        pst_Servo[SERVO_11].uin_PresentAngle = 15;


        pst_Servo[SERVO_4].uin_PresentAngle = 120;
        pst_Servo[SERVO_8].uin_PresentAngle = 20;
        pst_Servo[SERVO_12].uin_PresentAngle = 10;

        Servo_Process(SERVO_1, pst_Servo);
        Servo_Process(SERVO_5, pst_Servo);
        Servo_Process(SERVO_9, pst_Servo);
        Servo_Process(SERVO_2, pst_Servo);
        Servo_Process(SERVO_6, pst_Servo);
        Servo_Process(SERVO_10, pst_Servo);

        Servo_Process(SERVO_3, pst_Servo);
        Servo_Process(SERVO_7, pst_Servo);
        Servo_Process(SERVO_11, pst_Servo);
        Servo_Process(SERVO_4, pst_Servo);
        Servo_Process(SERVO_8, pst_Servo);
        Servo_Process(SERVO_12, pst_Servo);
        delay_ms(9000);
        pst_Servo[SERVO_1].uin_PresentAngle = 110;
        pst_Servo[SERVO_5].uin_PresentAngle = 30;
        pst_Servo[SERVO_9].uin_PresentAngle = 10;


            pst_Servo[SERVO_2].uin_PresentAngle = 95;
            pst_Servo[SERVO_6].uin_PresentAngle = 40;
            pst_Servo[SERVO_10].uin_PresentAngle = 15;

            pst_Servo[SERVO_3].uin_PresentAngle = 135;
            pst_Servo[SERVO_7].uin_PresentAngle = 30;
            pst_Servo[SERVO_11].uin_PresentAngle = 15;


            pst_Servo[SERVO_4].uin_PresentAngle = 20;
            pst_Servo[SERVO_8].uin_PresentAngle = 60;
            pst_Servo[SERVO_12].uin_PresentAngle = 40;
            Servo_Process(SERVO_1, pst_Servo);
            Servo_Process(SERVO_5, pst_Servo);
            Servo_Process(SERVO_9, pst_Servo);
            Servo_Process(SERVO_2, pst_Servo);
            Servo_Process(SERVO_6, pst_Servo);
            Servo_Process(SERVO_10, pst_Servo);

            Servo_Process(SERVO_3, pst_Servo);
            Servo_Process(SERVO_7, pst_Servo);
            Servo_Process(SERVO_11, pst_Servo);
            Servo_Process(SERVO_4, pst_Servo);
            Servo_Process(SERVO_8, pst_Servo);
            Servo_Process(SERVO_12, pst_Servo);

}
/**
 *************************************************************************
 * @brief: Robot_Right
 * @param: pst_Servo -- ����ṹָ��
 * @return: void
 * @function:
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Robot_Right(SERVO *pst_Servo)
{
    pst_Servo[SERVO_1].uin_PresentAngle = 60;
    pst_Servo[SERVO_5].uin_PresentAngle = 30;
    pst_Servo[SERVO_9].uin_PresentAngle = 10;


    Servo_Process(SERVO_1, pst_Servo);
    Servo_Process(SERVO_5, pst_Servo);
    Servo_Process(SERVO_9, pst_Servo);
}






