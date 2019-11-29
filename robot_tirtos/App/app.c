#include "app.h"
/**
 *************************************************************************
 * @brief: App_Init
 * @param: void
 * @return: void
 * @function: Initialize App
 * @author: 
 * @version: V1.0
 * @note: Initialize required modules
 *************************************************************************
**/
void App_Init(void)
{
    MAP_WDT_A_holdTimer();//�����Ź�
	

	/* Enabling the FPU for floating point operation */
    MAP_FPU_enableModule();
    MAP_FPU_enableLazyStacking();
	
	CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_4);//48MHz / 4 = 12MHz
	PCA9685_Init();//Initialize PCA9685 servo controller and I2C connection

}
void RobotProcess(INT8U uch_WhichLeg, INT8U uch_Num, INT16U uin_Angle)
{
    switch(uch_WhichLeg)
    {
        case LEG_ONE:
        {
            switch(uch_Num)
            {
                case NUM_ONE:
                {
                    PCA9685_ControlServo(0, uin_Angle);
                    break;
                }
                case NUM_TWO:
                {
                    PCA9685_ControlServo(1, uin_Angle);
                    break;
                }
                case NUM_THREE:
                {
                    PCA9685_ControlServo(2, uin_Angle);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case LEG_TWO:
        {
            switch(uch_Num)
            {
                case NUM_ONE:
                {
                    PCA9685_ControlServo(3, uin_Angle);
                    break;
                }
                case NUM_TWO:
                {
                    PCA9685_ControlServo(4, uin_Angle);
                    break;
                }
                case NUM_THREE:
                {
                    PCA9685_ControlServo(5, uin_Angle);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case LEG_THREE:
        {
            switch(uch_Num)
            {
                case NUM_ONE:
                {
                    PCA9685_ControlServo(6, uin_Angle);
                    break;
                }
                case NUM_TWO:
                {
                    PCA9685_ControlServo(7, uin_Angle);
                    break;
                }
                case NUM_THREE:
                {
                    PCA9685_ControlServo(8, uin_Angle);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case LEG_FOUR:
        {
            switch(uch_Num)
            {
                case NUM_ONE:
                {
                    PCA9685_ControlServo(9, uin_Angle);
                    break;
                }
                case NUM_TWO:
                {
                    PCA9685_ControlServo(10, uin_Angle);
                    break;
                }
                case NUM_THREE:
                {
                    PCA9685_ControlServo(11, uin_Angle);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}
void RobotStandup(uint16_t uin_Speed)
{
    //step 1
    RobotProcess(LEG_ONE, NUM_TWO, 49);
    RobotProcess(LEG_TWO, NUM_TWO, 49);
    RobotProcess(LEG_THREE, NUM_TWO, 50);
    RobotProcess(LEG_FOUR, NUM_TWO, 49);
    RobotProcess(LEG_ONE, NUM_ONE, 70);
    RobotProcess(LEG_TWO, NUM_ONE, 62);
    RobotProcess(LEG_THREE, NUM_ONE, 71);
    RobotProcess(LEG_FOUR, NUM_ONE, 61);
    //step 2
    RobotProcess(LEG_ONE, NUM_TWO, 54);
    RobotProcess(LEG_TWO, NUM_TWO, 54);
    RobotProcess(LEG_THREE, NUM_TWO, 56);
    RobotProcess(LEG_FOUR, NUM_TWO, 54);
    RobotProcess(LEG_ONE, NUM_ONE, 75);
    RobotProcess(LEG_TWO, NUM_ONE, 69);
    RobotProcess(LEG_THREE, NUM_ONE, 77);
    RobotProcess(LEG_FOUR, NUM_ONE, 67);
    //step 3
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 58);
    RobotProcess(LEG_TWO, NUM_TWO, 58);
    RobotProcess(LEG_THREE, NUM_TWO, 61);
    RobotProcess(LEG_FOUR, NUM_TWO, 58);
    RobotProcess(LEG_ONE, NUM_ONE, 80);
    RobotProcess(LEG_TWO, NUM_ONE, 76);
    RobotProcess(LEG_THREE, NUM_ONE, 84);
    RobotProcess(LEG_FOUR, NUM_ONE, 74);

    //step 4
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 63);
    RobotProcess(LEG_TWO, NUM_TWO, 63);
    RobotProcess(LEG_THREE, NUM_TWO, 67);
    RobotProcess(LEG_FOUR, NUM_TWO, 63);
    RobotProcess(LEG_ONE, NUM_ONE, 85);
    RobotProcess(LEG_TWO, NUM_ONE, 83);
    RobotProcess(LEG_THREE, NUM_ONE, 90);
    RobotProcess(LEG_FOUR, NUM_ONE, 80);

    //step 5
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 67);
    RobotProcess(LEG_TWO, NUM_TWO, 67);
    RobotProcess(LEG_THREE, NUM_TWO, 73);
    RobotProcess(LEG_FOUR, NUM_TWO, 67);
    RobotProcess(LEG_ONE, NUM_ONE, 90);
    RobotProcess(LEG_TWO, NUM_ONE, 90);
    RobotProcess(LEG_THREE, NUM_ONE, 97);
    RobotProcess(LEG_FOUR, NUM_ONE, 87);

    //step 6
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 72);
    RobotProcess(LEG_TWO, NUM_TWO, 72);
    RobotProcess(LEG_THREE, NUM_TWO, 78);
    RobotProcess(LEG_FOUR, NUM_TWO, 72);
    RobotProcess(LEG_ONE, NUM_ONE, 95);
    RobotProcess(LEG_TWO, NUM_ONE, 97);
    RobotProcess(LEG_THREE, NUM_ONE, 103);
    RobotProcess(LEG_FOUR, NUM_ONE, 93);
    //step 7
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 75);
    RobotProcess(LEG_TWO, NUM_TWO, 75);
    RobotProcess(LEG_THREE, NUM_TWO, 84);
    RobotProcess(LEG_FOUR, NUM_TWO, 75);
    RobotProcess(LEG_ONE, NUM_ONE, 100);
    RobotProcess(LEG_TWO, NUM_ONE, 103);
    RobotProcess(LEG_THREE, NUM_ONE, 109);
    RobotProcess(LEG_FOUR, NUM_ONE, 98);

    //step 8
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 80);
    RobotProcess(LEG_TWO, NUM_TWO, 80);
    RobotProcess(LEG_THREE, NUM_TWO, 90);
    RobotProcess(LEG_FOUR, NUM_TWO, 80);
    RobotProcess(LEG_ONE, NUM_ONE, 105);
    RobotProcess(LEG_TWO, NUM_ONE, 110);
    RobotProcess(LEG_THREE, NUM_ONE, 115);
    RobotProcess(LEG_FOUR, NUM_ONE, 105);
    //adjust angle
    //LEG 1
    RobotProcess(LEG_ONE, NUM_TWO, 65);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 80);
    delay_ms(uin_Speed);
    //LEG 2
    RobotProcess(LEG_TWO, NUM_TWO, 65);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 80);
    delay_ms(uin_Speed);
    //LEG 3
    RobotProcess(LEG_THREE, NUM_TWO, 75);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 90);
    delay_ms(uin_Speed);
    //LEG 4
    RobotProcess(LEG_FOUR, NUM_TWO, 65);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 80);
    delay_ms(uin_Speed);


}
void RobotRaiseup(uint16_t uin_Speed)
{
    //step 1
    RobotProcess(LEG_ONE, NUM_TWO, 79);
    RobotProcess(LEG_TWO, NUM_TWO, 79);
    RobotProcess(LEG_THREE, NUM_TWO, 80);
    RobotProcess(LEG_FOUR, NUM_TWO, 79);
    RobotProcess(LEG_ONE, NUM_ONE, 110);
    RobotProcess(LEG_TWO, NUM_ONE, 102);
    RobotProcess(LEG_THREE, NUM_ONE, 111);
    RobotProcess(LEG_FOUR, NUM_ONE, 101);
    //step 2
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 84);
    RobotProcess(LEG_TWO, NUM_TWO, 84);
    RobotProcess(LEG_THREE, NUM_TWO, 86);
    RobotProcess(LEG_FOUR, NUM_TWO, 84);
    RobotProcess(LEG_ONE, NUM_ONE, 115);
    RobotProcess(LEG_TWO, NUM_ONE, 109);
    RobotProcess(LEG_THREE, NUM_ONE, 117);
    RobotProcess(LEG_FOUR, NUM_ONE, 107);
    //step 3
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 88);
    RobotProcess(LEG_TWO, NUM_TWO, 88);
    RobotProcess(LEG_THREE, NUM_TWO, 91);
    RobotProcess(LEG_FOUR, NUM_TWO, 88);
    RobotProcess(LEG_ONE, NUM_ONE, 120);
    RobotProcess(LEG_TWO, NUM_ONE, 116);
    RobotProcess(LEG_THREE, NUM_ONE, 124);
    RobotProcess(LEG_FOUR, NUM_ONE, 114);

    //step 4
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 93);
    RobotProcess(LEG_TWO, NUM_TWO, 93);
    RobotProcess(LEG_THREE, NUM_TWO, 97);
    RobotProcess(LEG_FOUR, NUM_TWO, 93);
    RobotProcess(LEG_ONE, NUM_ONE, 125);
    RobotProcess(LEG_TWO, NUM_ONE, 123);
    RobotProcess(LEG_THREE, NUM_ONE, 130);
    RobotProcess(LEG_FOUR, NUM_ONE, 120);

    //step 5
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 97);
    RobotProcess(LEG_TWO, NUM_TWO, 97);
    RobotProcess(LEG_THREE, NUM_TWO, 103);
    RobotProcess(LEG_FOUR, NUM_TWO, 97);
    RobotProcess(LEG_ONE, NUM_ONE, 130);
    RobotProcess(LEG_TWO, NUM_ONE, 130);
    RobotProcess(LEG_THREE, NUM_ONE, 137);
    RobotProcess(LEG_FOUR, NUM_ONE, 127);

    //step 6
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 102);
    RobotProcess(LEG_TWO, NUM_TWO, 102);
    RobotProcess(LEG_THREE, NUM_TWO, 108);
    RobotProcess(LEG_FOUR, NUM_TWO, 102);
    RobotProcess(LEG_ONE, NUM_ONE, 135);
    RobotProcess(LEG_TWO, NUM_ONE, 137);
    RobotProcess(LEG_THREE, NUM_ONE, 143);
    RobotProcess(LEG_FOUR, NUM_ONE, 133);
    //step 7
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 105);
    RobotProcess(LEG_TWO, NUM_TWO, 105);
    RobotProcess(LEG_THREE, NUM_TWO, 114);
    RobotProcess(LEG_FOUR, NUM_TWO, 105);
    RobotProcess(LEG_ONE, NUM_ONE, 140);
    RobotProcess(LEG_TWO, NUM_ONE, 143);
    RobotProcess(LEG_THREE, NUM_ONE, 149);
    RobotProcess(LEG_FOUR, NUM_ONE, 138);

    //step 8
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 110);
    RobotProcess(LEG_TWO, NUM_TWO, 110);
    RobotProcess(LEG_THREE, NUM_TWO, 120);
    RobotProcess(LEG_FOUR, NUM_TWO, 110);
    RobotProcess(LEG_ONE, NUM_ONE, 145);
    RobotProcess(LEG_TWO, NUM_ONE, 150);
    RobotProcess(LEG_THREE, NUM_ONE, 155);
    RobotProcess(LEG_FOUR, NUM_ONE, 145);

    delay_ms(uin_Speed);


}
void RobotHalfStand(void)
{
    RobotProcess(LEG_ONE, NUM_ONE, 65);
    RobotProcess(LEG_ONE, NUM_TWO, 45);
    RobotProcess(LEG_ONE, NUM_THREE, 90);

    RobotProcess(LEG_TWO, NUM_ONE, 60);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    RobotProcess(LEG_TWO, NUM_THREE, 90);

    RobotProcess(LEG_THREE, NUM_ONE, 65);
    RobotProcess(LEG_THREE, NUM_TWO, 45);
    RobotProcess(LEG_THREE, NUM_THREE, 90);

    RobotProcess(LEG_FOUR, NUM_ONE, 60);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    RobotProcess(LEG_FOUR, NUM_THREE, 90);
}
void RobotStand(void)
{
    RobotProcess(LEG_ONE, NUM_ONE, 105);
    RobotProcess(LEG_ONE, NUM_TWO, 80);
    RobotProcess(LEG_ONE, NUM_THREE, 90);

    RobotProcess(LEG_TWO, NUM_ONE, 110);
    RobotProcess(LEG_TWO, NUM_TWO, 80);
    RobotProcess(LEG_TWO, NUM_THREE, 90);

    RobotProcess(LEG_THREE, NUM_ONE, 115);
    RobotProcess(LEG_THREE, NUM_TWO, 90);
    RobotProcess(LEG_THREE, NUM_THREE, 90);

    RobotProcess(LEG_FOUR, NUM_ONE, 105);
    RobotProcess(LEG_FOUR, NUM_TWO, 80);
    RobotProcess(LEG_FOUR, NUM_THREE, 90);


}
void RobotRaise(void)
{
    RobotProcess(LEG_ONE, NUM_ONE, 140);
        RobotProcess(LEG_ONE, NUM_TWO, 120);
        RobotProcess(LEG_ONE, NUM_THREE, 90);

        RobotProcess(LEG_TWO, NUM_ONE, 140);
        RobotProcess(LEG_TWO, NUM_TWO, 110);
        RobotProcess(LEG_TWO, NUM_THREE, 90);

        RobotProcess(LEG_THREE, NUM_ONE, 145);
        RobotProcess(LEG_THREE, NUM_TWO, 110);
        RobotProcess(LEG_THREE, NUM_THREE, 90);

        RobotProcess(LEG_FOUR, NUM_ONE, 145);
        RobotProcess(LEG_FOUR, NUM_TWO, 120);
        RobotProcess(LEG_FOUR, NUM_THREE, 90);



}
void RobotPrepare(uint16_t uin_Speed)
{
        RobotProcess(LEG_ONE, NUM_ONE, 65);
        RobotProcess(LEG_ONE, NUM_TWO, 45);
        RobotProcess(LEG_ONE, NUM_THREE, 60);

        RobotProcess(LEG_TWO, NUM_ONE, 55);
        RobotProcess(LEG_TWO, NUM_TWO, 45);
        RobotProcess(LEG_TWO, NUM_THREE, 120);

        RobotProcess(LEG_THREE, NUM_ONE, 70);
        RobotProcess(LEG_THREE, NUM_TWO, 45);
        RobotProcess(LEG_THREE, NUM_THREE, 120);

        RobotProcess(LEG_FOUR, NUM_ONE, 55);
        RobotProcess(LEG_FOUR, NUM_TWO, 45);
        RobotProcess(LEG_FOUR, NUM_THREE, 60);
}
void RobotPrepareLeft(uint16_t uin_Speed)
{
        //leg 4
        RobotProcess(LEG_ONE, NUM_TWO, 45);
        RobotProcess(LEG_THREE, NUM_TWO, 45);
        RobotProcess(LEG_TWO, NUM_TWO, 30);
        delay_ms(uin_Speed);
        RobotProcess(LEG_ONE, NUM_THREE, 130);
        RobotProcess(LEG_THREE, NUM_THREE, 50);
        delay_ms(uin_Speed);
        RobotProcess(LEG_FOUR, NUM_TWO, 0);
        delay_ms(uin_Speed);
        RobotProcess(LEG_FOUR, NUM_ONE, 60);
        delay_ms(uin_Speed);
        RobotProcess(LEG_FOUR, NUM_THREE, 80);
        delay_ms(uin_Speed);

        RobotProcess(LEG_FOUR, NUM_TWO, 45);
        //leg 1
        RobotProcess(LEG_THREE, NUM_TWO, 10);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_ONE, 65);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_THREE, 100);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_TWO, 45);
        RobotProcess(LEG_FOUR, NUM_TWO, 45);
        RobotProcess(LEG_TWO, NUM_TWO, 45);
        delay_ms(uin_Speed);

        delay_ms(uin_Speed);
}
void RobotUSleft()
{
    PCA9685_ControlServo(12, 180);
}
void RobotUSright()
{
    PCA9685_ControlServo(12, 0);
}
void RobotUSmiddle()
{
    PCA9685_ControlServo(12, 90);
}
void RobotRun(uint16_t uin_Speed)
{
       //Set to state 1, raise LEG 2 and move forward
        RobotProcess(LEG_TWO, NUM_TWO, 0);
        delay_ms(uin_Speed);
        RobotProcess(LEG_TWO, NUM_THREE, 60);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_THREE, 90);
        RobotProcess(LEG_ONE, NUM_THREE, 90);
        RobotProcess(LEG_TWO, NUM_TWO, 45);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_THREE, 80);
        RobotProcess(LEG_ONE, NUM_THREE, 100);

        //Raise LEG 4 and move forward
        RobotProcess(LEG_FOUR, NUM_TWO, 10);
        delay_ms(uin_Speed);
        RobotProcess(LEG_FOUR, NUM_THREE, 120);
        delay_ms(uin_Speed);
        RobotProcess(LEG_FOUR, NUM_TWO, 45);
        delay_ms(uin_Speed);
        //Raise LEG 3 and move forward
        RobotProcess(LEG_THREE, NUM_TWO, 0);
        delay_ms(uin_Speed);
        RobotProcess(LEG_THREE, NUM_THREE, 120);
        delay_ms(uin_Speed);

        //Push body forward using LEG 2 and 4 by turning left/right
        RobotProcess(LEG_TWO, NUM_THREE, 115);
        RobotProcess(LEG_FOUR, NUM_THREE, 75);
        RobotProcess(LEG_THREE, NUM_TWO, 45);
        //RobotProcess(LEG_ONE, NUM_TWO, 45);
        delay_ms(uin_Speed);
        RobotProcess(LEG_TWO, NUM_THREE, 125);
        RobotProcess(LEG_FOUR, NUM_THREE, 65);
        delay_ms(uin_Speed);

        //Raise LEG 1 and move forward
        RobotProcess(LEG_ONE, NUM_TWO, 0);
        delay_ms(uin_Speed);
        RobotProcess(LEG_ONE, NUM_THREE, 60);
        delay_ms(uin_Speed);
        RobotProcess(LEG_ONE, NUM_TWO, 45);
        delay_ms(uin_Speed);
}
void RobotClimb(uint16_t uin_Speed)
{
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 140);
    RobotProcess(LEG_THREE, NUM_THREE, 40);
    RobotProcess(LEG_ONE, NUM_THREE, 110);
    RobotProcess(LEG_FOUR, NUM_THREE, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 50);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_ONE, 125);
    RobotProcess(LEG_ONE, NUM_TWO, 120);

    //Raise LEG 2
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 80);
    RobotProcess(LEG_THREE, NUM_ONE, 120);
    RobotProcess(LEG_FOUR, NUM_ONE, 90);
    RobotProcess(LEG_FOUR, NUM_TWO, 90);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_ONE, 60);
    delay_ms(uin_Speed);

    RobotProcess(LEG_TWO, NUM_THREE, 40);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 100);
    RobotProcess(LEG_THREE, NUM_THREE, 10);
    RobotProcess(LEG_FOUR, NUM_TWO, 110);
    RobotProcess(LEG_FOUR, NUM_ONE, 140);
    RobotProcess(LEG_TWO, NUM_TWO, 40);
    delay_ms(uin_Speed);

    RobotProcess(LEG_ONE, NUM_THREE, 110);
    RobotProcess(LEG_THREE, NUM_ONE, 130);
    delay_ms(uin_Speed);
    //Raise LEG 4
    RobotProcess(LEG_FOUR, NUM_TWO, 0);
    delay_ms(uin_Speed);

    RobotProcess(LEG_FOUR, NUM_THREE, 130);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_ONE, 125);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 120);
    RobotProcess(LEG_TWO, NUM_TWO, 60);
    delay_ms(uin_Speed);

    //Raise LEG 3
    RobotProcess(LEG_THREE, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_ONE, 70);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 140);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 60);
    RobotProcess(LEG_TWO, NUM_THREE, 90);
    RobotProcess(LEG_THREE, NUM_TWO, 60);
    RobotProcess(LEG_ONE, NUM_ONE, 140);

    //
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 50);
    RobotProcess(LEG_TWO, NUM_THREE, 100);
    delay_ms(uin_Speed);
    //Raise LEG 1
    RobotProcess(LEG_ONE, NUM_TWO, 40);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 30);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_ONE, 110);
    RobotProcess(LEG_ONE, NUM_TWO, 120);
    RobotProcess(LEG_THREE, NUM_TWO, 80);
    delay_ms(uin_Speed);
    //Raise LEG 2
    RobotProcess(LEG_TWO, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_ONE, 40);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 120);
    RobotProcess(LEG_THREE, NUM_THREE, 60);
    RobotProcess(LEG_TWO, NUM_TWO, 40);
    RobotProcess(LEG_FOUR, NUM_ONE, 140);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 100);

    delay_ms(uin_Speed);
    //Raise LEG 4
    RobotProcess(LEG_FOUR, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 110);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_ONE, 115);
    RobotProcess(LEG_FOUR, NUM_TWO, 130);
    delay_ms(uin_Speed);

    RobotProcess(LEG_TWO, NUM_TWO, 60);
    delay_ms(uin_Speed);
    //Raise LEG 3
    RobotProcess(LEG_THREE, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 130);
    RobotProcess(LEG_THREE, NUM_ONE, 40);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 120);
    RobotProcess(LEG_FOUR, NUM_THREE, 50);
    RobotProcess(LEG_THREE, NUM_TWO, 70);
    RobotProcess(LEG_ONE, NUM_ONE, 140);


    delay_ms(uin_Speed);
    //Raise LEG 1
    RobotProcess(LEG_ONE, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_ONE, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 80);
    delay_ms(uin_Speed);

    //Raise LEG 2
    RobotProcess(LEG_TWO, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 50);
    RobotProcess(LEG_TWO, NUM_ONE, 50);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 60);
    RobotProcess(LEG_ONE, NUM_THREE, 10);
    RobotProcess(LEG_TWO, NUM_TWO, 20);
    RobotProcess(LEG_FOUR, NUM_TWO, 140);

    delay_ms(uin_Speed);
    //Raise LEG 4

    RobotProcess(LEG_FOUR, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 150);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_ONE, 40);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 40);
    delay_ms(uin_Speed);

}
void RobotRight(uint16_t uin_Speed)
{
    RobotProcess(LEG_TWO, NUM_THREE, 60);
    RobotProcess(LEG_ONE, NUM_THREE, 60);
    RobotProcess(LEG_THREE, NUM_THREE, 60);
    RobotProcess(LEG_FOUR, NUM_THREE, 60);
    RobotProcess(LEG_THREE, NUM_TWO, 30);
    delay_ms(uin_Speed);
    //Raise LEG 1, turn towards right
    RobotProcess(LEG_TWO, NUM_TWO, 50);

    RobotProcess(LEG_FOUR, NUM_TWO, 50);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 65);
    RobotProcess(LEG_ONE, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 110);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 60);
    RobotProcess(LEG_ONE, NUM_TWO, 50);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    RobotProcess(LEG_THREE, NUM_TWO, 50);
    delay_ms(uin_Speed);
    //Raise LEG 4
    RobotProcess(LEG_FOUR, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 110);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 50);
    RobotProcess(LEG_TWO, NUM_TWO, 50);
    RobotProcess(LEG_ONE, NUM_TWO, 30);
    RobotProcess(LEG_THREE, NUM_TWO, 45);
    //Raise LEG 3, 90, turn LEG 4
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 110);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 30);
    RobotProcess(LEG_ONE, NUM_TWO, 50);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 50);
    RobotProcess(LEG_FOUR, NUM_THREE, 50);
    RobotProcess(LEG_THREE, NUM_TWO, 50);
    delay_ms(uin_Speed);
    //Raise LEG 2, 90
    RobotProcess(LEG_TWO, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 110);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    RobotProcess(LEG_ONE, NUM_THREE, 45);
    RobotProcess(LEG_THREE, NUM_THREE, 45);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    delay_ms(uin_Speed);

}

void RobotLeft(uint16_t uin_Speed)
{
    RobotProcess(LEG_THREE, NUM_THREE, 120);
    RobotProcess(LEG_FOUR, NUM_THREE, 120);
    RobotProcess(LEG_ONE, NUM_THREE, 120);
    RobotProcess(LEG_TWO, NUM_THREE, 120);
    delay_ms(uin_Speed);
    //Raise LEG 4, turn towards left
    RobotProcess(LEG_TWO, NUM_TWO, 40);
    RobotProcess(LEG_ONE, NUM_THREE, 140);
    RobotProcess(LEG_THREE, NUM_THREE, 100);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 70);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 60);
    RobotProcess(LEG_TWO, NUM_TWO, 60);
    RobotProcess(LEG_THREE, NUM_TWO, 45);
    RobotProcess(LEG_ONE, NUM_TWO, 45);
    delay_ms(uin_Speed);
    //Raise LEG 1
    RobotProcess(LEG_ONE, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 60);

    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 60);
    RobotProcess(LEG_THREE, NUM_TWO, 60);
    RobotProcess(LEG_FOUR, NUM_TWO, 40);
    RobotProcess(LEG_TWO, NUM_TWO, 40);
    //Raise LEG 2, 90, turn LEG 4
    RobotProcess(LEG_ONE, NUM_THREE, 55);
    RobotProcess(LEG_TWO, NUM_TWO, 10);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    //RobotProcess(LEG_ONE, NUM_THREE, 70);
    RobotProcess(LEG_ONE, NUM_TWO, 45);
    RobotProcess(LEG_THREE, NUM_TWO, 45);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 120);
    RobotProcess(LEG_ONE, NUM_THREE, 120);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 60);
    RobotProcess(LEG_FOUR, NUM_TWO, 60);
    RobotProcess(LEG_ONE, NUM_TWO, 25);
    RobotProcess(LEG_THREE, NUM_TWO, 45);

    delay_ms(uin_Speed);
    //Raise LEG 3, 90
    RobotProcess(LEG_TWO, NUM_THREE, 65);
    RobotProcess(LEG_THREE, NUM_TWO, 0);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 45);
    RobotProcess(LEG_TWO, NUM_THREE, 70);
    RobotProcess(LEG_FOUR, NUM_TWO, 45);
    RobotProcess(LEG_TWO, NUM_TWO, 45);
    delay_ms(uin_Speed);

}

void RobotBack(uint16_t uin_Speed)
{
    RobotProcess(LEG_FOUR, NUM_THREE, 105);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_TWO, 120);
    delay_ms(uin_Speed);
    RobotProcess(LEG_THREE, NUM_THREE, 75);
    RobotProcess(LEG_THREE, NUM_TWO, 90);

    RobotProcess(LEG_TWO, NUM_THREE, 105);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_TWO, 120);
    delay_ms(uin_Speed);
    RobotProcess(LEG_ONE, NUM_THREE, 75);
    RobotProcess(LEG_ONE, NUM_TWO, 90);

    RobotProcess(LEG_THREE, NUM_THREE, 105);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_TWO, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_FOUR, NUM_THREE, 75);
    RobotProcess(LEG_FOUR, NUM_TWO, 90);

    RobotProcess(LEG_ONE, NUM_THREE, 75);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_TWO, 60);
    delay_ms(uin_Speed);
    RobotProcess(LEG_TWO, NUM_THREE, 105);
    RobotProcess(LEG_TWO, NUM_TWO, 90);
}

