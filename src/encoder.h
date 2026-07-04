/******************************************************************************
* Copyright (c) 2026 lin
* SPDX-License-Identifier: MIT
******************************************************************************/
 
#ifndef _ENCODER_H_
#define _ENCODER_H_

/*************************************************
宏定义
*************************************************/
typedef struct {
	u8  g_u8Data;
	u8  g_u8DataBuf;
	u8 	g_u8FliterNum;
	u8 	g_u8Event;
}ENCODER_TypeDef;

#define def_EncoderLeftPin		P00
#define def_EncoderRightPin		P01

#define def_FliterNum			8

#define def_EncoderLeftData		0xE1
#define def_EncoderRightData	0xD2

#define def_EncoderLeftEvent	0x01
#define def_EncoderRightEvent	0x02

/*************************************************
外部声明
*************************************************/
extern void F_EncoderInit(void);
extern void F_EncoderCheck(ENCODER_TypeDef *l_sEncoder);

#endif