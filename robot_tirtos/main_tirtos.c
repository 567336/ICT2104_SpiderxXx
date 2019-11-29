#include <stdint.h>
#include <stddef.h>
/* POSIX Header files */
#include <pthread.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>
/* RTOS header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
/* Driver configuration */
#include <ti/drivers/Board.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/Timer.h>
#include "ti_drivers_config.h"
#include "main.h"
#include "app.h"
/* Stack size in bytes */
#define TASKSTACKSIZE    1024

/*
 *  ======== main ========
 */

//Important Variables
char * message; //instruction received from bluetooth
int new = 0; // bool for whether got new instruction, 1 = true, 0 = false
int topUS = 0; //bool for top US obstacle detection, 1 = obstacle detected, 0 = no obstacle detected
int botUS = 0; //bool for bottom US obstacle detection, 1 = obstacle detected, 0 = no obstacle detected


/* UART Variables */
char        input; // char to store the Bluetooth instruction
UART_Handle uart;
UART_Params uartParams;

/* US Variables */
Timer_Handle handle,handle2;
Timer_Params params;
int32_t status;
int sum = 0;
int us = 1;
int traverse = 0;
int blocked = 0;
int alt = 0; // 1 = turn left, 2 = turn right, only used for 3 way scan

/* TASK Variables */
Task_Struct task1Struct, task2Struct, task3Struct;
Char task1Stack[TASKSTACKSIZE], task2Stack[TASKSTACKSIZE], task3Stack[TASKSTACKSIZE];;
Task_Params taskParams;

/* SEMAPHORE Variables */
Semaphore_Params semParams;
Semaphore_Struct semStruct,semStruct2;
Semaphore_Handle semHandle,semHandle2;


//BLUETOOTH THREAD AND FUNCTIONS---------------------------------------------------------------------------------------------------------------------
void bluetooth_irq (UART_Handle handle, void *buffer, size_t num)
{
    UART_control(uart, UART_CMD_RXDISABLE,NULL);


    message = buffer;
    new = 1;
}
void *BTThread(void *arg0)
{

    System_printf("I at BT now\n");
    System_flush();
    RobotHalfStand();
    uart = UART_open(CONFIG_UART_0, &uartParams);

    if (uart == NULL) {
        /* UART_open() failed */
        while (1);
    }

    /* Loop forever echoing */
    while (1) {
        UART_control(uart, UART_CMD_RXENABLE,NULL);
        UART_read(uart, &input, 1);
        if(new == 1)
        {
            Semaphore_pend(semHandle, BIOS_WAIT_FOREVER);

        }

    }
}

//ULTRASONIC THREAD AND FUNCTIONS---------------------------------------------------------------------------------------------------------------------
int scanBottom()
{
    int i = 5;
    float distance = 0;
    while(i>0)
        {
            GPIO_toggle(CONFIG_US_1_TRIG);
            us = 1;
            Timer_start(handle2);
            while(GPIO_read(CONFIG_US_1_ECHO) == 0);
            status = Timer_start(handle);
            while(GPIO_read(CONFIG_US_1_ECHO) == 1);
            Timer_stop(handle);
            System_printf("%d\n", sum);
            System_flush();
            i--;
        }
    distance = ((float)sum*10) / 290;
    sum = 0;
    if(distance > 8.0)
    {
        return 0; //No obstacle
    }
    else
    {
        return 1; //Got obstacle
    }
}

int scanTop()
{
    int i = 5;
    float distance = 0;
    while(i>0)
        {
            GPIO_toggle(CONFIG_US_2_TRIG);
            us = 2;
            Timer_start(handle2);
            while(GPIO_read(CONFIG_US_2_ECHO) == 0);

            status = Timer_start(handle);
            while(GPIO_read(CONFIG_US_2_ECHO) == 1);
            Timer_stop(handle);
            System_printf("%d\n", sum);
            System_flush();
            i--;
        }
    distance = ((float)sum*10) / 290;
    sum = 0;
    if(distance > 12.0)
    {
        return 0; //No obstacle
    }
    else
    {
        return 1; //Got obstacle
    }
}

void threeWayScan()
{
    RobotUSleft();
    if(scanTop() == 0) // LEFT TOP NO OBSTACLE
    {
        alt = 1; //TURN LEFT
    }
    else // LEFT TOP GOT OBSTACLE
    {
        RobotUSright();
        if(scanTop() == 0) // RIGHT TOP NO OBSTACLE
        {
            alt = 2;
        }
        else
        {
            //DIE
        }
    }
    RobotUSmiddle();
}

void *USThread(void *arg0)
{
    while(1)
    {
        System_printf("I at US now\n");
            System_flush();
            if(new == 1)
            {
                new = 0;
            }
            if(message[0] == 'r' || message[0] == 'l')
            {
                Semaphore_pend(semHandle2, BIOS_WAIT_FOREVER);

            }
            else if(message[0] == 'f')
            {

                if(scanBottom() == 0) //Bottom US detect no obstacle
                {
                    if(scanTop() == 0) // Top US detect no obstacle
                    {
                       if(traverse == 1)
                       {
                           traverse = 0;
                       }
                       if(blocked == 1)
                       {
                           blocked = 0;
                       }
                    }
                    else // Top US detect obstacle
                    {
                        //DO SOMETHING GO INTO CROUCH MODE
                        //NOT IMPLEMENTED, TREAT AS BLOCKED
                        blocked = 1;
                        threeWayScan();


                    }

                }
                else // Bottom US detect obstacle
                {
                    if(scanTop() == 0) // Top US detect no obstacle
                    {
                      //DO SOMETHING GO INTO STANDING MODE
                        if(blocked == 1)
                        {
                            blocked = 0;
                        }
                        traverse = 1;
                        RobotStandup(1000);
                        RobotRaiseup(1000);

                    }
                    else // Top US detect obstacle
                    {
                      //DO SOMETHING NEED TO TURN
                      blocked = 1;
                      threeWayScan();

                    }
                }
                Semaphore_pend(semHandle2, BIOS_WAIT_FOREVER);
            }

            if(blocked == 0 && traverse == 0)
            {
                Semaphore_post(semHandle); //Go back to BT
            }

    }

}

void timerCallback(Timer_Handle myHandle)
{
    sum++;
}

void timerCallback2(Timer_Handle myHandle)
{
    if(us == 1)
    {
        GPIO_toggle(CONFIG_US_1_TRIG);
    }
    else if(us == 2)
    {
        GPIO_toggle(CONFIG_US_2_TRIG);
    }

}

//PCA9685/SERVO THREAD AND FUNCTIONS---------------------------------------------------------------------------------------------------------------------
void *PCAThread(void *arg0)
{
while(1)
{
    System_printf("I at PCA now\n");
    System_flush();
    if(message[0] == 'r')
    {
        RobotRight(1000);
    }
    else if(message[0] == 'l')
    {
        RobotLeft(1000);
    }
    else if(message[0] == 'f')
    {
        if(traverse == 1)
        {
            RobotClimb(2000);
        }
        else if(blocked == 1)
        {
            if(alt == 1)
            {
                RobotLeft(1000); // UNTIL IT REACHES 90 DEGREE LEFT
                RobotLeft(1000);
                RobotLeft(1000);
                alt = 0;

            }
            else if(alt == 2)
            {
                RobotRight(1000); // UNTIL IT REACHES 90 DEGREE RIGHT
                RobotRight(1000);
                RobotRight(1000);
                alt = 0;
            }
        }
        else
        {
            RobotPrepare(1000);
            RobotRun(1000);

        }

    }

    Semaphore_post(semHandle2); // Go back to US
}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

int main(void)
{
    /* Call driver init functions */
    Board_init();
    GPIO_init();
    UART_init();
    Timer_init();
    I2C_init();
    App_Init();

    /* Configure the US pin as normal GPIO*/
    GPIO_setConfig(CONFIG_US_1_TRIG, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_US_1_ECHO, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(CONFIG_US_2_TRIG, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_US_2_ECHO, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);


    // Initialise Timer for US
    Timer_Params_init(&params);
    params.period = 10;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;
    handle = Timer_open(CONFIG_TIMER_0, &params);

    params.period = 10;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_ONESHOT_CALLBACK;
    params.timerCallback = timerCallback2;
    handle2 = Timer_open(CONFIG_TIMER_1, &params);



    /* Initialise UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.readCallback = bluetooth_irq;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;

    // Initialise all 3 tasks---------------------------------------------------------------------------------------------------------
    Task_Params_init(&taskParams);
    taskParams.stackSize = TASKSTACKSIZE;

    //Initialise PCAThread, lowest priority
    taskParams.stack = &task1Stack;
    taskParams.priority = 1;
    Task_construct(&task1Struct, (Task_FuncPtr)PCAThread, &taskParams, NULL);

    //Initialise USThread, middle priority
    taskParams.stack = &task2Stack;
    taskParams.priority = 2;
    Task_construct(&task2Struct, (Task_FuncPtr)USThread, &taskParams, NULL);

    //Initialise BTThread, highest priority
    taskParams.stack = &task3Stack;
    taskParams.priority = 3;
    Task_construct(&task3Struct, (Task_FuncPtr)BTThread, &taskParams, NULL);

    //Initialise Semaphore 1 and 2
    Semaphore_Params_init(&semParams);
    Semaphore_construct(&semStruct, 0, &semParams);
    Semaphore_construct(&semStruct2, 0, &semParams);

    /* Obtain instance handle */
    semHandle = Semaphore_handle(&semStruct);
    semHandle2 = Semaphore_handle(&semStruct2);


    BIOS_start();

    return (0);
}


