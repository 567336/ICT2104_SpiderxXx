#include "hc_sr04.h"
#include "led.h"
#include "delay.h"

INT16U uin_SR04Times;//��ʱ����ʱʱ�� us
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
	
	MAP_Timer_A_stopTimer(TIMER_A0_BASE);//�رն�ʱ��
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//��ն�ʱ������

}
/**
 *************************************************************************
 * @brief: TA0_0_IRQHandler
 * @param: void
 * @return: void
 * @function:��ʱ��A0�ж�
 * @author: 
 * @version: V1.0
 * @note: 1ms����һ���ж�
 *************************************************************************
**/
void TA0_0_IRQHandler(void)
{
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE,
                                             TIMER_A_CAPTURECOMPARE_REGISTER_0);//����жϱ�־λ
	uin_SR04Times++;//��ʱֵ++
}
/**
 *************************************************************************
 * @brief: Start_SR04Timer
 * @param: void
 * @return: void
 * @function: �򿪶�ʱ��
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
static void Start_SR04Timer(void)
{
	uin_SR04Times = 0;//����ֵ����
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//��ն�ʱ��A0	
    MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);//������ʱ��A0����
}
/**
 *************************************************************************
 * @brief: Stop_SR04Timer
 * @param: void
 * @return: void
 * @function: �رն�ʱ��
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
static void Stop_SR04Timer(void)
{
	MAP_Timer_A_stopTimer(TIMER_A0_BASE);//�رն�ʱ��A0
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
	MAP_Timer_A_clearTimer(TIMER_A0_BASE);//�����ʱ��
	delay_us(2);//������ʱ
	return t;
}

/**
 *************************************************************************
 * @brief: Get_SR04Distance
 * @param: void
 * @return: ����ֵ  ��λΪcm
 * @function: ��ó����������ľ���
 * @author:  
 * @version: V1.0
 * @note:
 *************************************************************************
**/
FP32 Get_SR04Distance(void)
{
	//����10us����
	INT8U i = 5;
	INT8U t;
	INT32U ul_time = 0;
	FP32 f_distance = 0;
	FP32 f_sum = 0;
	while(i--)
	{
		MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);//��
		for(t = 0; t <= 120; t++);//10us   1/12MHz * 120 = 10us
		MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);//��
		while(MAP_GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 0);//�ȵ��ߵ�ƽ����
		Start_SR04Timer();//�򿪶�ʱ��
		while(MAP_GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 1);//�ȵ��͵�ƽ����
		Stop_SR04Timer();//�رն�ʱ��
		ul_time = Get_SR04Time();//���ʱ��
		f_distance = (FP32)ul_time / 58.0f;//cm
		f_sum += f_distance;//���
	}
	f_distance = f_sum / 5.0f;//��ƽ��
	return f_distance;	
}
/**
 *************************************************************************
 * @brief: Check_SR04Distance
 * @param: f_dis--����ֵ
 * @return: bool
 * @function: ������
 * @author:
 * @version: V1.0
 * @note:
 *************************************************************************
**/
bool Check_SR04Distance(FP32 f_dis)
{
    return(f_dis < MIN_DISTANCE)?true:false;
}

