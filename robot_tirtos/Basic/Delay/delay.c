#include "delay.h"

#define clock_source  12 //ʱ��Ƶ����д�������λMHz��    

void delay_us(u32 us)
{ //uS΢�뼶��ʱ����
	/*SysTick_setPeriod(us * clock_source);	//���ؼ���ֵ
	SysTick_enableModule();   //ʹ��ϵͳʱ��
	while(SysTick_getValue()&(us*clock_source));
	SysTick_disableModule();//�رռ���*/
    int count = us;
    while (count > 0)
    {
        count--;
    }

}

void delay_ms(u16 ms)
{ //mS���뼶��ʱ���� 		  	  
	while( ms-- != 0)
	{
		delay_us(1000);	
	}
}

void delay_s(u16 s)
{ //S�뼶��ʱ���� 		  	  
	while( s-- != 0)
	{
		delay_ms(1000);	
	}
} 






