#include "pca9685.h"
#include "myiic.h"
#include "delay.h"
#include "math.h"

static void pca_write(INT8U adrr,INT8U data)//向PCA写数据,adrrd地址,data数据
{ 
	IIC_Start();
	
	IIC_Send_Byte(PCA_ADDR);
	IIC_Wait_Ack();
	
	IIC_Send_Byte(adrr);
	IIC_Wait_Ack();
	
	IIC_Send_Byte(data);
	IIC_Wait_Ack();
	
	IIC_Stop();
}

static INT8U pca_read(INT8U adrr)//从PCA读数据
{
	INT8U data;
	IIC_Start();
	
	IIC_Send_Byte(PCA_ADDR);
	IIC_Wait_Ack();
	
	IIC_Send_Byte(adrr);
	IIC_Wait_Ack();
	
	IIC_Start();
	
	IIC_Send_Byte(PCA_ADDR | 0x01);
	IIC_Wait_Ack();
	
	data = IIC_Read_Byte(0);
	IIC_Stop();
	
	return data;
}


static void pca_setfreq(float freq)//设置PWM频率
{
		INT8U prescale,oldmode,newmode;
		double prescaleval;
		freq *= 0.92f; 
		prescaleval = 25000000.0f;
		prescaleval /= 4096;
		prescaleval /= freq;
		prescaleval -= 1;
		prescale =floor(prescaleval + 0.5f);

		oldmode = pca_read(PCA_MODE);
	
		newmode = (oldmode&0x7F) | 0x10; // sleep
	
		pca_write(PCA_MODE, newmode); // go to sleep
	
		pca_write(PCA_PRE, prescale); // set the prescaler
	
		pca_write(PCA_MODE, oldmode);
		delay_ms(2);
	
		pca_write(PCA_MODE, oldmode | 0xa1); 
}

static void pca_setpwm(INT8U num, INT32U on, INT32U off)
{
		pca_write(LED0_ON_L + 4 * num, on);
		pca_write(LED0_ON_H + 4 * num, on >> 8 );
		pca_write(LED0_OFF_L + 4 * num, off);
		pca_write(LED0_OFF_H + 4 * num, off >> 8);
}


void PCA9685_Init(void)
{
    const FP32 f_freq = 60.0f;
    MYIIC_Init();
	pca_write(PCA_MODE,0x00);
	pca_setfreq(f_freq);//设置PWM频率
}

void PCA9685_ControlServo(INT8U uch_num, INT8U uch_angle)
{
    INT32U ul_off;
    ul_off = (INT32U)(158.0f + uch_angle * 2.2f);
    pca_setpwm(uch_num, 0, ul_off);
}


