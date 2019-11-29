#include "hc05.h"
#include <string.h>

/**
 *************************************************************************
 * @brief: Hc05_Process
 * @param: puch_buf -- ��������ָ��
 * @return: void
 * @function: ����ģ�鴦��
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
	if((*puch_buf != HEAD_PACK) //����ͷ�ж�
	|| (*(puch_buf + 2) != HEAD_TAIL))//����λ�ж�
	{
		memset(puch_buf, 0, strlen((char*)puch_buf));//�������
		return;
	}
	switch(*(puch_buf + 1))
	{
		case RUN_CMD://ǰ��
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case BACK_CMD://����
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case LEFT_CMD://��ת
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case RIGHT_CMD://��ת
		{

			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		case STOP_CMD://ֹͣ
		{
			//memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
		default://�������
		{
			memset(puch_buf, 0, strlen((char*)puch_buf));//�������
			break;
		}
	}
}
