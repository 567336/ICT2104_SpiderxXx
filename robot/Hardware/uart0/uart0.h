#ifndef __UART0_H
#define __UART0_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
#define HEAD_PACK 0xEE//数据头
#define HEAD_TAIL 0xFF//数据尾

#define RECEIVE_NUM_MAX   200//接收最大个数
extern INT8U gauch_Uart0RecBuff[RECEIVE_NUM_MAX];//接收缓存



void Uart0_Init(void);//串口0初始化函数声明
void Uart0_SendByte(INT8U uch_byte);//串口0发送字节函数声明
void Uart0_SendString(INT8U *puch_buf, INT16U uin_len);//串口0发送字符串声明
void U0_Sprintf(char *format, ...);


#endif
