#include "adc.h"
#include "global_val.h"

void Adc_Init(void)
{
    /* Initializing ADC (MCLK/1/4) */
    ADC14_enableModule();
    ADC14_initModule(ADC_CLOCKSOURCE_MCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_1, 0);

    /* Configuring GPIOs (5.5 A0) */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P5, GPIO_PIN5, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Configuring ADC Memory */
    ADC14_configureSingleSampleMode(ADC_MEM0, true);
    ADC14_configureConversionMemory(ADC_MEM0, 
									ADC_VREFPOS_AVCC_VREFNEG_VSS, 
									ADC_INPUT_A0, 
									false);

    /* Configuring Sample Timer */
    MAP_ADC14_enableSampleTimer(ADC_MANUAL_ITERATION);

    /* Enabling/Toggling Conversion */
    ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();
    //![Single Sample Mode Configure]

    /* Enabling interrupts */
    MAP_ADC14_enableInterrupt(ADC_INT0);
    MAP_Interrupt_enableInterrupt(INT_ADC14);
    //MAP_Interrupt_enableMaster();
	
}
/* This interrupt is fired whenever a conversion is completed and placed in
 * ADC_MEM0 */
void ADC14_IRQHandler(void)
{
    INT64U	status;
    status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);
    if (status & ADC_INT0)
    {
		guin_AdcValue = ADC14_getResult(ADC_MEM0);
		MAP_ADC14_toggleConversionTrigger();
    }

}


