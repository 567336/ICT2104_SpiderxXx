#ifndef __UART2_H
#define __UART2_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"


void Uart2_Init(void);//����1��ʼ����������
void Uart2_SendByte(INT8U uch_byte);//����1�����ֽں�������
void Uart2_SendString(INT8U *puch_buf, INT16U uin_len);//����1�����ַ�������


#endif
