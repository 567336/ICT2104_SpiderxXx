/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include "app.h"
INT16U t = 0;
bool b_sta = OPEN;
INT8U auch_buff[200] = {0x00};
FP32 f_dis;
int main(void)
{
    App_Init();//Ӧ�ó����ʼ�� �ײ����Դ��ʼ��
    while(1)
    {

        if(t++ / 500)
        {
            t = 0;
            b_sta =! b_sta;
            LED_Control(RED_LED, b_sta);
        }
        delay_ms(10);//������ʱ


        //adjust servo angle
        Key_Scanf();
        sprintf((char*)auch_buff, "anle = %d\r\n",guch_ServoAngle);// ---FOR servo
        Uart0_SendString((char*)auch_buff, strlen((char*)auch_buff));




        /*//pca control servo
        //PCA9685_ControlServo(uin_Num, i);//PCA9685
        PCA9685_ControlServo(1, 180);//PCA9685
        delay_s(12);//������ʱ
        PCA9685_ControlServo(1, 0);//PCA9685
        delay_s(12);
        */
    }
}
