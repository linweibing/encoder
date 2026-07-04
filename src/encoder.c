/******************************************************************************
* Copyright (c) 2026 lin
* SPDX-License-Identifier: MIT
******************************************************************************/

#include "encoder.h"

/*************************************************
变量定义
*************************************************/

																												
/******************************************************************
函数名称：						F_EncoderInit
功能描述：						编码器初始化
调用本函数的时钟周期：           无		
输入参数：						无
输出参数：						无
其他说明：						无
*******************************************************************/
void F_EncoderInit(void)
{
	//GPIO初始化配置
}
/******************************************************************
函数名称：						F_EncoderCheck
功能描述：						编码器检测
调用本函数的时钟周期：			 125us
输入参数：						参数1:编码器结构体
输出参数：						无
其他说明：						无
*******************************************************************/
void F_EncoderCheck(ENCODER_TypeDef *l_sEncoder)
{	
	if(l_sEncoder != NULL){
		u8 l_u8Buf = 0;
		if(def_EncoderLeftPin)l_u8Buf |= 0x01;
		if(def_EncoderRightPin)l_u8Buf |= 0x02;

		if(l_sEncoder->g_u8DataBuf != l_u8Buf){
			l_sEncoder->g_u8DataBuf = l_u8Buf;
			l_sEncoder->g_u8FliterNum = def_FliterNum;
		}else{
			if(l_sEncoder->g_u8FliterNum > 0){
				l_sEncoder->g_u8FliterNum--;
				if(0 == l_sEncoder->g_u8FliterNum){
					l_sEncoder->g_u8Data <<= 2;
					l_sEncoder->g_u8Data |= l_sEncoder->g_u8DataBuf;

					if(def_EncoderLeftData == l_sEncoder->g_u8Data){
						l_sEncoder->g_u8Event = def_EncoderLeftEvent;	
					}else if(def_EncoderRightData == l_sEncoder->g_u8Data){
						l_sEncoder->g_u8Event = def_EncoderRightEvent;	
					}
				}
			}
		}
	}
}
