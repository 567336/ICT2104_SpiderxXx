#include "led.h"
#include "delay.h"
void LED_Init(void)
{
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);//RED
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);//GREEN
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);//BLUE
	
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}
void LED_Control(INT8U uch_led, bool b_status)
{
	if(uch_led == RED_LED)
	{
	    b_status ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0)):(MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0));
		//MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
		//MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
		//delay_ms(uin_ms);
	}
	if(uch_led == GREEN_LED)
	{
	    b_status ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1)):(MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1));
		//MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//delay_ms(uin_ms);		
	}
	if(uch_led == BLUE_LED)
	{
	    b_status ? (MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2)):(MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2));
		//MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);
		//MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
		//delay_ms(uin_ms);		
	}	
}


