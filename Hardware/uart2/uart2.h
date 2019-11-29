#ifndef __UART2_H
#define __UART2_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"


void Uart2_Init(void);//串口1初始化函数声明
void Uart2_SendByte(INT8U uch_byte);//串口1发送字节函数声明
void Uart2_SendString(INT8U *puch_buf, INT16U uin_len);//串口1发送字符串声明


#endif
