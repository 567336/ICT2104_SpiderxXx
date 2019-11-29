#include "hc05.h"
#include <string.h>

/**
 *************************************************************************
 * @brief: Hc05_Process
 * @param: puch_buf -- 接收数据指针
 * @return: void
 * @function: 蓝牙模块处理
 * @author: 
 * @version: V1.0
 * @note:
 *************************************************************************
**/
void Hc05_Process(INT8U *puch_buf)
{
	if(*puch_buf == 0x00)
	{
		return;
	}
	if((*puch_buf != HEAD_PACK) //数据头判断
	|| (*(puch_buf + 2) != HEAD_TAIL))//数据位判断
	{
		memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
		return;
	}
	switch(*(puch_buf + 1))
	{
		case RUN_CMD://前进
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
		case BACK_CMD://后退
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
		case LEFT_CMD://左转
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
		case RIGHT_CMD://右转
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
		case STOP_CMD://停止
		{
			//memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
		default://其他情况
		{
			memset(puch_buf, 0, strlen((char*)puch_buf));//清除数据
			break;
		}
	}
}
