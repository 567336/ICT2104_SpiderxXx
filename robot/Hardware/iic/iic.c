#include "iic.h"
#include <string.h>
#define SLAVE_ADDRESS 0xFF//´Ó»úµØÖ·
#define NUM_OF_REC_BYTES    10

/* Variables */
const INT8U TXData[] = {0x04};
static INT8U RXData[NUM_OF_REC_BYTES];
static uint8_t RXData[NUM_OF_REC_BYTES];
static volatile INT32U xferIndex;
static volatile BOOL stopSent;
/* I2C Master Configuration Parameter */
const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,                                // SMCLK = 3MHz
        EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 100khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
};
void IIC_Init(void)
{
    /* Select Port 1 for I2C - Set Pin 6, 7 to input Primary Module Function,
     *   (UCB0SIMO/UCB0SDA, UCB0SOMI/UCB0SCL).
     */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
												   GPIO_PIN6 + GPIO_PIN7, 
												   GPIO_PRIMARY_MODULE_FUNCTION);

    stopSent = false;
    memset(RXData, 0x00, NUM_OF_REC_BYTES);
    
    /* Initializing I2C Master to SMCLK at 100khz with no autostop */
    MAP_I2C_initMaster(EUSCI_B0_BASE, &i2cConfig);

    /* Specify slave address */
    //MAP_I2C_setSlaveAddress(EUSCI_B0_BASE, SLAVE_ADDRESS);

    /* Enable I2C Module to start operations */
    MAP_I2C_enableModule(EUSCI_B0_BASE);
   //MAP_Interrupt_enableInterrupt(INT_EUSCIB0);	
}
/*******************************************************************************
 * eUSCIB0 ISR. The repeated start and transmit/receive operations happen
 * within this ISR.
 *******************************************************************************/
void EUSCIB0_IRQHandler(void)
{
    uint_fast16_t status;

    status = MAP_I2C_getEnabledInterruptStatus(EUSCI_B0_BASE);
    MAP_I2C_clearInterruptFlag(EUSCI_B0_BASE, status);


}



