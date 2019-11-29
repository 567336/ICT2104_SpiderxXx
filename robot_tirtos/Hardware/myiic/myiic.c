#include "myiic.h"
#include "delay.h"
//static void delay_us(INT16U uin_us)
//{
//    INT16U i;
//    while(uin_us--)
//        for(i = 0; i < 12; i++);
//}

//Initialize IIC
void MYIIC_Init(void)
{					     
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6);//SDA
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN7);//SCL
    
	MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN7);
    
}
//Generate IIC start signal
void IIC_Start(void)
{
	SDA_OUT();     //SDA set to OUT
	IIC_SDA(1);	  	  
	IIC_SCL(1);
	delay_us(4);
 	IIC_SDA(0);//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL(0);//Hold IIC, ready for send or receive data
}	  
//Generate IIC stop signal
void IIC_Stop(void)
{
	SDA_OUT();//SDA set to OUT
	IIC_SCL(0);
	IIC_SDA(0);//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL(1); 
	IIC_SDA(1);//End transfer signal
	delay_us(4);							   	
}
//Wait for ACK signal
//1 returned = Receive failed, 0 returned = Receive success
INT8U IIC_Wait_Ack(void)
{
	INT8U ucErrTime=0;
	SDA_IN();      //SDA set as IN
	IIC_SDA(1);delay_us(1);	   
	IIC_SCL(1);delay_us(1);	 
	while(READ_SDA())
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL(0);
	return 0;  
} 
//Generate ACK response
void IIC_Ack(void)
{
	IIC_SCL(0);
	SDA_OUT();
	IIC_SDA(0);
	delay_us(2);
	IIC_SCL(1);
	delay_us(2);
	IIC_SCL(0);
}
//Dont generate ACK response
void IIC_NAck(void)
{
	IIC_SCL(0);
	SDA_OUT();
	IIC_SDA(1);
	delay_us(2);
	IIC_SCL(1);
	delay_us(2);
	IIC_SCL(0);
}					 				     
//IIC send 1 byte
//Check for response
//1, got response
//0, no response
void IIC_Send_Byte(INT8U txd)
{                        
    INT8U t;   
	SDA_OUT(); 	    
    IIC_SCL(0);
    for(t=0;t<8;t++)
    {              
        IIC_SDA((txd&0x80)>>7);
        txd<<=1; 	  
		delay_us(2);
		IIC_SCL(1);
		delay_us(2); 
		IIC_SCL(0);	
		delay_us(2);
    }	 
} 	    
//Read 1 byte, ack=1 send ACK, ack=0, send nACK
INT8U IIC_Read_Byte(INT8U ack)
{
	INT8U i,receive=0;
	SDA_IN();//SDA set to IN
    for(i=0;i<8;i++ )
	{
        IIC_SCL(0); 
        delay_us(2);
		IIC_SCL(1);
        receive<<=1;
        if(READ_SDA())receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        IIC_NAck();//Send nACK
    else
        IIC_Ack(); //Send ACK
    return receive;
}
