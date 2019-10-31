#include "hc_sr04.h"
#include "led.h"
#include "delay.h"

INT16U uin_SR04Times;//定时器计时时间 us
/**
 *************************************************************************
 * @brief: 
 * @param: void
 * @return: void
 * @function:
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void HC_SR04_Init(void)
{
	/* Timer_A UpMode Configuration Parameter */
	const Timer_A_UpModeConfig upConfig =
	{
			TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
			TIMER_A_CLOCKSOURCE_DIVIDER_12,         // SMCLK/12 = 1MHz
			1000,                                   // 1000 tick period
			TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
			TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
			TIMER_A_DO_CLEAR                        // Clear value
	};
	//IO config  P3.6 Trig  P3.7 Ech0
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6);//	
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);//
	
	MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN7);

	
    /* Configuring Timer_A0 for Up Mode */
    MAP_Timer_A_configureUpMode(TIMER_A0_BASE, &upConfig);

    /* Enabling interrupts and starting the timer */
    MAP_Interrupt_enableInterrupt(INT_TA0_0);
    MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	
	MAP_Timer_A_stopTimer(TIMER_A0_BASE);//关闭定时器
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//清空定时器计数

}
/**
 *************************************************************************
 * @brief: TA0_0_IRQHandler
 * @param: void
 * @return: void
 * @function:定时器A0中断
 * @author: 
 * @version: V1.0
 * @note: 1ms产生一次中断
 *************************************************************************
**/
void TA0_0_IRQHandler(void)
{
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE,
                                             TIMER_A_CAPTURECOMPARE_REGISTER_0);//清除中断标志位
	uin_SR04Times++;//计时值++
}
/**
 *************************************************************************
 * @brief: Start_SR04Timer
 * @param: void
 * @return: void
 * @function: 打开定时器
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
static void Start_SR04Timer(void)
{
	uin_SR04Times = 0;//计数值清零
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//清空定时器A0	
    MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);//开启定时器A0计数
}
/**
 *************************************************************************
 * @brief: Stop_SR04Timer
 * @param: void
 * @return: void
 * @function: 关闭定时器
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
static void Stop_SR04Timer(void)
{
	MAP_Timer_A_stopTimer(TIMER_A0_BASE);//关闭定时器A0
}
/**
 *************************************************************************
 * @brief: 
 * @param: void
 * @return: void
 * @function:
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
static INT32U Get_SR04Time(void)
{
	INT32U t;
	t = uin_SR04Times * 1000;//ms
	t += MAP_Timer_A_getCounterValue(TIMER_A0_BASE);//us
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//清除定时器
	delay_us(2);//短暂延时
	return t;
}

/**
 *************************************************************************
 * @brief: Get_SR04Distance
 * @param: void
 * @return: 测量值  单位为cm
 * @function: 获得超声波测量的距离
 * @author:  
 * @version: V1.0
 * @note:
 *************************************************************************
**/
FP32 Get_SR04Distance(void)
{
	//发送10us脉冲
	INT8U i = 5;
	INT8U t;
	INT32U ul_time = 0;
	FP32 f_distance = 0;
	FP32 f_sum = 0;
	while(i--)
	{
		MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);//高
		for(t = 0; t <= 120; t++);//10us   1/12MHz * 120 = 10us
		MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);//低
		while(MAP_GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 0);//等到高电平到来
		Start_SR04Timer();//打开定时器
		while(MAP_GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 1);//等到低电平到来
		Stop_SR04Timer();//关闭定时器
		ul_time = Get_SR04Time();//获得时间
		f_distance = (FP32)ul_time / 58.0f;//cm
		f_sum += f_distance;//求和
	}
	f_distance = f_sum / 5.0f;//求平均
	return f_distance;	
}
/**
 *************************************************************************
 * @brief: Check_SR04Distance
 * @param: f_dis--距离值
 * @return: bool
 * @function: 检查距离
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
bool Check_SR04Distance(FP32 f_dis)
{
    return(f_dis < MIN_DISTANCE)?true:false;
}

