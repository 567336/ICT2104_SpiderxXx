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
    App_Init();//应用程序初始化 底层的资源初始化
    while(1)
    {

        if(t++ / 500)
        {
            t = 0;
            b_sta =! b_sta;
            LED_Control(RED_LED, b_sta);
        }
        delay_ms(10);//短暂延时
        //PCA9685_ControlServo(uin_Num, i);//PCA9685
        PCA9685_ControlServo(1, 180);//PCA9685
        delay_s(12);//短暂延时
        PCA9685_ControlServo(1, 0);//PCA9685
        delay_s(12);
    }
}
