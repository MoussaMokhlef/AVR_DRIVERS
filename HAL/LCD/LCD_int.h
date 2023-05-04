#ifndef LCD_INT_H
#define LCD_INT_H


#include"../../LIB/STD_Types.h"

void HLCD_voidSendData(u8 Copy_u8Data);

void HLCD_voidSendCommand(u8 Copy_u8Command);

void HLCD_voidInit(void);

void HLCD_4_voidInit(void);

void HLCD_4_voidSendData(u8 Copy_u8Data);

void HLCD_4_voidSendCommand(u8 Copy_u8Command);

void HLCD_voidGoTo(u8 Copy_u8X,u8 Copy_u8Y);

void HLCD_voidSendDataString(u8 * str,u8 Copy_u8X,u8 Copy_u8Y);

void HLCD_voidSendSpecialChar(const char *arr,u8 Copy_u8PatternNumber,u8 Copy_u8X,u8 Copy_u8Y);

void HLCD_voidDisplayNumber(u32 Copy_u32Number);



#endif
