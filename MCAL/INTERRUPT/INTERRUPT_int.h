/*
 * MINTERUPT_int.h
 *
 *  Created on: Mar 30, 2023
 *      Author: User
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INT_H_
#define MCAL_INTERRUPT_INTERRUPT_INT_H_
#include"../../LIB/STD_Types.h"

void EX_voidInteruptEnable(u8 Copy_u8InterruptExitNum,u8 Copy_u8InterruptState);

void EX_voidInteruptDisEnable(u8 Copy_u8InterruptExitNum);
void MINTERRUPT_voidEnableGlobalEntrrupt(void);

void Set_Call_back_Exit_Int0(void(*ptr)(void));
void Set_Call_back_Exit_Int1(void(*ptr)(void));
void Set_Call_back_Exit_Int2(void(*ptr)(void));

#endif /* MCAL_INTERRUPT_INTERRUPT_INT_H_ */
