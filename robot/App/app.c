#include "app.h"
/**
 *************************************************************************
 * @brief: App_Init
 * @param: void
 * @return: void
 * @function: 应用程序初始化
 * @author: 
 * @version: V1.0
 * @note: 初始化对应的外设资源
 *************************************************************************
**/
void App_Init(void)
{
    MAP_WDT_A_holdTimer();//挂起看门狗
	SystemClockInit(HFXT);//初始化时钟到48MHz
	
	/* Enabling the FPU for floating point operation */
    MAP_FPU_enableModule();
    MAP_FPU_enableLazyStacking();//打开浮点运算单元
	
	CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_4);//48MHz / 4 = 12MHz
	LED_Init();//LED灯初始化
	//TimerA0_Init();//定时器A0初始化
	TimerA1_Init();//定时器A1初始化
	TimerA2_Init();//定时器A2初始化
	TimerA3_Init();//定时器A3初始化	
	KEY_Init();//按键初始化
	Uart0_Init();//串口0初始化 9600
	//Adc_Init();//ADC初始化
	HC_SR04_Init();
	GlobalValue_Init();//全局变量初始化
	PCA9685_Init();//舵机驱动器初始化
	Interrupt_enableMaster();//使能全局中断
}



