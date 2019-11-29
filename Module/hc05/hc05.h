#ifndef __HC05_H
#define __HC05_H
#include "uart0.h"
#include "main.h"
#include "servo.h"
typedef enum 
{
	NO_CMD  = 0x00,
	RUN_CMD = 0x10,
	BACK_CMD,
	LEFT_CMD,
	RIGHT_CMD,
	STOP_CMD
}gen_HC05CMD;
void Hc05_Process(INT8U *puch_buf);

#endif



