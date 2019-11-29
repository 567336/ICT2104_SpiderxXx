#ifndef __MYIIC_H
#define __MYIIC_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
//IO��������
 
#define SDA_IN()  {MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN6);}//����
#define SDA_OUT() {MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6);}//���

//IO��������	 
#define IIC_SCL(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN7)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN7)))     //SCL
#define IIC_SDA(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN6)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN6)))
#define READ_SDA() (MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN6))  //����SDA 
//IIC���в�������
void MYIIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(INT8U txd);			//IIC����һ���ֽ�
INT8U IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
INT8U IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

#endif
