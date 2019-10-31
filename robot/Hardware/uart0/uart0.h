#ifndef __UART0_H
#define __UART0_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
#define HEAD_PACK 0xEE//����ͷ
#define HEAD_TAIL 0xFF//����β

#define RECEIVE_NUM_MAX   200//����������
extern INT8U gauch_Uart0RecBuff[RECEIVE_NUM_MAX];//���ջ���



void Uart0_Init(void);//����0��ʼ����������
void Uart0_SendByte(INT8U uch_byte);//����0�����ֽں�������
void Uart0_SendString(INT8U *puch_buf, INT16U uin_len);//����0�����ַ�������
void U0_Sprintf(char *format, ...);


#endif
