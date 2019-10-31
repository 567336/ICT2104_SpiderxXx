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
        f_dis = Get_SR04Distance();
        if(Check_SR04Distance(f_dis))
        {
            //避开障碍
            //Robot_Stop(gast_ServoArray);
            LED_Control(GREEN_LED, OPEN);
        }

        LED_Control(GREEN_LED, CLOSE);

        sprintf((char*)auch_buff, "dis = %0.2f\r\n", f_dis);
        Uart0_SendString((char*)auch_buff, strlen((char*)auch_buff));

    }
}
