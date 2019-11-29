#include "timer.h"
#include "servo.h"
//TA0.1
Timer_A_PWMConfig TIM0_1_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_1,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA0.2
Timer_A_PWMConfig TIM0_2_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_1,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA0.3
Timer_A_PWMConfig TIM0_3_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_3,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA0.4
Timer_A_PWMConfig TIM0_4_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_4,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA1.1
Timer_A_PWMConfig TIM1_1_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_1,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA1.0
Timer_A_PWMConfig TIM1_0_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_0,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA2.0
Timer_A_PWMConfig TIM2_0_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_0,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA2.1
Timer_A_PWMConfig TIM2_1_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_1,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA2.2
Timer_A_PWMConfig TIM2_2_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_2,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA2.3
Timer_A_PWMConfig TIM2_3_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_3,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA2.4
Timer_A_PWMConfig TIM2_4_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_4,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA3.0
Timer_A_PWMConfig TIM3_0_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_0,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA3.1
Timer_A_PWMConfig TIM3_1_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_1,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA3.2
Timer_A_PWMConfig TIM3_2_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_2,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA3.3
Timer_A_PWMConfig TIM3_3_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_3,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
//TA3.4
Timer_A_PWMConfig TIM3_4_PwmConfig =
{
		TIMER_A_CLOCKSOURCE_SMCLK,
		TIMER_A_CLOCKSOURCE_DIVIDER_4,//12MHZ / 4 = 3MHz
		60000,//3000 000 / 50 = 60000
		TIMER_A_CAPTURECOMPARE_REGISTER_4,
		TIMER_A_OUTPUTMODE_RESET_SET,
		1500//
};
/**
 *************************************************************************
 * @brief: TimerA0_Init
 * @param: void
 * @return: void
 * @function: 定时器A0初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void TimerA0_Init(void)
{
    /* Configuring GPIO2.4 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, 
													GPIO_PIN4,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO2.5 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, 
													GPIO_PIN5,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO2.6 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, 
													GPIO_PIN6,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO2.7 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, 
													GPIO_PIN7,
												    GPIO_PRIMARY_MODULE_FUNCTION);   
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TIM0_1_PwmConfig);//TA0.1
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TIM0_2_PwmConfig);//TA0.2
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TIM0_3_PwmConfig);//TA0.3
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TIM0_4_PwmConfig);//TA0.4	
}
/**
 *************************************************************************
 * @brief: TimerA1_Init
 * @param: void
 * @return: void
 * @function: 定时器A1初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void TimerA1_Init(void)
{
    /* Configuring GPIO8.0 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P8, 
													GPIO_PIN0,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO7.7 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, 
													GPIO_PIN7,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    
	MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TIM1_0_PwmConfig);//TA1.0
	MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TIM1_1_PwmConfig);//TA1.1		
}
/**
 *************************************************************************
 * @brief: TimerA2_Init
 * @param: void
 * @return: void
 * @function: 定时器A2初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void TimerA2_Init(void)
{
    /* Configuring GPIO8.1 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P8, 
													GPIO_PIN1,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO5.6 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, 
													GPIO_PIN7,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO5.7 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, 
													GPIO_PIN6,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO6.6 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, 
													GPIO_PIN6,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO6.7 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, 
													GPIO_PIN7,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
             
	MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_0_PwmConfig);//TA2.0
	MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_1_PwmConfig);//TA2.1	
	MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_2_PwmConfig);//TA2.2	
	MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_3_PwmConfig);//TA2.3	
	MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_4_PwmConfig);//TA2.4	
}
/**
 *************************************************************************
 * @brief: TimerA3_Init
 * @param: void
 * @return: void
 * @function: 定时器A3初始化
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void TimerA3_Init(void)
{
    /* Configuring GPIO10.4 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P10, 
													GPIO_PIN4,
												    GPIO_PRIMARY_MODULE_FUNCTION);
    /* Configuring GPIO10.5 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P10, 
													GPIO_PIN5,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO8.2 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P8, 
													GPIO_PIN2,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO9.2 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P9, 
													GPIO_PIN2,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
    /* Configuring GPIO9.3 as peripheral output for PWM  */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P9, 
													GPIO_PIN3,
												    GPIO_PRIMARY_MODULE_FUNCTION);		
 	
    MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_0_PwmConfig);//TA3.0
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_1_PwmConfig);//TA3.1	
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_2_PwmConfig);//TA3.2	
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_3_PwmConfig);//TA3.3	
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_4_PwmConfig);//TA3.4	
}



/**
 *************************************************************************
 * @brief: Servo_TurnAngle
 * @param: uin_Num -- 舵机编号 uch_Angle -- 旋转角度
 * @return: void
 * @function: 舵机旋转角度
 * @author: 
 * @version: V1.0
 * @note: 舵机需要50hz 64000/1280 = 50hz 60000
		 0度 0.5/20=0.025  60000*0.025=32  1500
		 180度 2.5/20=0.125  60000*0.125=160 7500
 *************************************************************************
**/
void Servo_TurnAngle(INT16U uin_Num, INT8U uch_Angle)
{
	FP32 f_cycle;
	f_cycle = (7500.0f - 1500.0f) / 180.0f * uch_Angle + 1500.0f;//定时器计数与角度

	switch(uin_Num)
	{
		case SERVO_1://TA1.0
		{
			TIM1_0_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TIM1_0_PwmConfig);
			break;
		}
		case SERVO_2://TA1.1
		{
			TIM1_1_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TIM1_1_PwmConfig);			
			break;
		}
		case SERVO_3://TA2.0
		{
			TIM2_0_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_0_PwmConfig);				
			break;
		}
		case SERVO_4://TA2.1
		{
			TIM2_1_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_1_PwmConfig);				
			break;
		}
		case SERVO_5://TA2.2
		{
			TIM2_2_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_2_PwmConfig);				
			break;
		}
		case SERVO_6://TA2.3
		{
			TIM2_3_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_3_PwmConfig);				
			break;
		}
		case SERVO_7://TA2.4
		{
			TIM2_4_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TIM2_4_PwmConfig);				
			break;
		}
		case SERVO_8://TA3.0
		{
			TIM3_0_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_0_PwmConfig);	
			break;
		}	
		case SERVO_9://TA3.1
		{
			TIM3_1_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_1_PwmConfig);	
			break;
		}
		case SERVO_10://TA3.2
		{
			TIM3_2_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_2_PwmConfig);				
			break;
		}
		case SERVO_11://TA3.3
		{
			TIM3_3_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_3_PwmConfig);				
			break;
		}
		case SERVO_12://TA3.4
		{
			TIM3_4_PwmConfig.dutyCycle = (INT16U)f_cycle;//新的占空比
			MAP_Timer_A_generatePWM(TIMER_A3_BASE, &TIM3_4_PwmConfig);				
			break;
		}			
		default:
			break;
	}
}


