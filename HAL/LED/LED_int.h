#ifndef LED_INT_H
#define LED_INT_H

#include"../../LIB/STD_Types.h"
#include"../../MCAL/DIO/DIO_int.h"


void HLED_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin);

void HLED_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin);

void HLED_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin);

void HLED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin);






#endif
