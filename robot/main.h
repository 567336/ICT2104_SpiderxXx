/*****************************
      官方头文件
*****************************/
#ifndef __MAIN_H
#define __MAIN_H
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdbool.h>
/******************************
    数据类型定义
******************************/
typedef signed long s32;
typedef signed short s16;
typedef signed char s8;
typedef signed long const sc32; /* Read Only */
typedef signed short const sc16; /* Read Only */
typedef signed char const sc8; /* Read Only */
typedef volatile signed long vs32;
typedef volatile signed short vs16;
typedef volatile signed char vs8;
typedef volatile signed long const vsc32; /* Read Only */
typedef volatile signed short const vsc16; /* Read Only */
typedef volatile signed char const vsc8; /* Read Only */
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long const uc32; /* Read Only */
typedef unsigned short const uc16; /* Read Only */
typedef unsigned char const uc8; /* Read Only */
typedef volatile unsigned long vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char vu8;
typedef volatile unsigned long const vuc32; /* Read Only */
typedef volatile unsigned short const vuc16; /* Read Only */
typedef volatile unsigned char const vuc8; /* Read Only */
/*类型声明*/
typedef signed char       INT8S;
typedef unsigned char     INT8U;
typedef signed short      INT16S;
typedef unsigned short    INT16U;
typedef signed int        INT32S ;
typedef unsigned int      INT32U;
typedef signed long       INT64S;
typedef unsigned long     INT64U;
typedef float             FP32;
typedef double            FP64;
typedef signed char       BOOL;
/****************************
      Basic内部外设头文件
*****************************/
#include "delay.h"
#include "systeminit.h"



/****************************
      Hardware外设头文件
*****************************/



#endif


