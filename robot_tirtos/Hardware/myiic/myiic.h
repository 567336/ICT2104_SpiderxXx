#ifndef __MYIIC_H
#define __MYIIC_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
//IO方向设置
 
#define SDA_IN()  {MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN6);}//输入
#define SDA_OUT() {MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6);}//输出

//IO操作函数	 
#define IIC_SCL(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN7)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN7)))     //SCL
#define IIC_SDA(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN6)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN6)))
#define READ_SDA() (MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN6))  //输入SDA 
//IIC所有操作函数
void MYIIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(INT8U txd);			//IIC发送一个字节
INT8U IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
INT8U IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

#endif
