#ifndef __MYIIC_H
#define __MYIIC_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "main.h"
//IO Direction setting
 
#define SDA_IN()  {MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN6);}//IN
#define SDA_OUT() {MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6);}//OUT

//IO Toggle
#define IIC_SCL(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN7)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN7)))     //SCL
#define IIC_SDA(x) (x ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN6)) : (MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN6)))
#define READ_SDA() (MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN6))  //Read SDA
//IIC all functions
void MYIIC_Init(void);                //Initialize IIC IO ports
void IIC_Start(void);				//Send IIC start signal
void IIC_Stop(void);	  			//Send IIC stop signal
void IIC_Send_Byte(INT8U txd);			//IIC send 1 byte
INT8U IIC_Read_Byte(unsigned char ack);//IIC read 1 byte
INT8U IIC_Wait_Ack(void); 				//Wait for ACK signal
void IIC_Ack(void);					//Generate ACK signal
void IIC_NAck(void);				//Generate nACK signal

#endif
