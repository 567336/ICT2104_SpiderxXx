#include "uart2.h"
#include <stdarg.h>
#include <string.h>


/**
 *************************************************************************
 * @brief: Uart2_Init
 * @param: void
 * @return: void
 * @function: 串口1初始化 波特率9600
 * @author: 
 * @version: V1.0
 * @note:http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 *************************************************************************
**/
void Uart2_Init(void)
{
	eUSCI_UART_Config uartConfig =
	{
			EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
			78,                                     // BRDIV = 78
			2,                                       // UCxBRF = 2
			0,                                       // UCxBRS = 0
			EUSCI_A_UART_NO_PARITY,                  // No Parity
			EUSCI_A_UART_LSB_FIRST,                  // LSB First
			EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
			EUSCI_A_UART_MODE,                       // UART mode
			EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
	};
	
    /* Selecting P3.2 and P3.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3,
												   GPIO_PIN2 | GPIO_PIN3, 
												   GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring UART Module */
    MAP_UART_initModule(EUSCI_A2_BASE, &uartConfig);

    /* Enable UART module */
    MAP_UART_enableModule(EUSCI_A2_BASE);

    /* Enabling interrupts */
    MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA2);
	//MAP_Interrupt_enableSleepOnIsrExit();
    //MAP_Interrupt_enableMaster(); 
}
/**
 *************************************************************************
 * @brief: EUSCIA2_IRQHandler
 * @param: void
 * @return: void
 * @function: 串口中断服务函数
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void EUSCIA2_IRQHandler(void)
{
	//static INT16U i = 0;
    uint32_t status;
	status = MAP_UART_getEnabledInterruptStatus(EUSCI_A2_BASE);

    MAP_UART_clearInterruptFlag(EUSCI_A2_BASE, status);

    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        //gauch_Uart0RecBuff[i++] = MAP_UART_receiveData(EUSCI_A0_BASE);
    }
}
/**
 *************************************************************************
 * @brief: Uart2_SendByte
 * @param: uch_byte -- 字节
 * @return: void
 * @function:
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Uart2_SendByte(INT8U uch_byte)
{
	MAP_UART_transmitData(EUSCI_A2_BASE, uch_byte);
}
/**
 *************************************************************************
 * @brief: Uart2_SendDtring
 * @param: puch_buf -- 缓存指针 uin_len --数据长度
 * @return: void
 * @function: 串口1发送字符串
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Uart2_SendString(INT8U *puch_buf, INT16U uin_len)
{
	INT16U i;
	for(i = 0; i < uin_len; i++)
	{
		Uart2_SendByte(*(puch_buf + i));
	}	
}

