#include "app.h"
/**
 *************************************************************************
 * @brief: App_Init
 * @param: void
 * @return: void
 * @function: Ӧ�ó����ʼ��
 * @author: 
 * @version: V1.0
 * @note: ��ʼ����Ӧ��������Դ
 *************************************************************************
**/
void App_Init(void)
{
    MAP_WDT_A_holdTimer();//�����Ź�
	SystemClockInit(HFXT);//��ʼ��ʱ�ӵ�48MHz
	
	/* Enabling the FPU for floating point operation */
    MAP_FPU_enableModule();
    MAP_FPU_enableLazyStacking();//�򿪸������㵥Ԫ
	
	CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_4);//48MHz / 4 = 12MHz
	LED_Init();//LED�Ƴ�ʼ��
	//TimerA0_Init();//��ʱ��A0��ʼ��
	TimerA1_Init();//��ʱ��A1��ʼ��
	TimerA2_Init();//��ʱ��A2��ʼ��
	TimerA3_Init();//��ʱ��A3��ʼ��	
	KEY_Init();//������ʼ��
	Uart0_Init();//����0��ʼ�� 9600
	//Adc_Init();//ADC��ʼ��
	HC_SR04_Init();
	GlobalValue_Init();//ȫ�ֱ�����ʼ��
	PCA9685_Init();//�����������ʼ��
	Interrupt_enableMaster();//ʹ��ȫ���ж�
}



