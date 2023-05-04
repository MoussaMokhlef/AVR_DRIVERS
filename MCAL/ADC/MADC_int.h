/*
 * HADC_int.h
 *
 *  Created on: Apr 1, 2023
 *      Author: User
 */
#include"../../LIB/STD_Types.h"
#ifndef HAL_ADC_HADC_INT_H_
#define HAL_ADC_HADC_INT_H_

void MADC_voidInit(u8 Local_u8Chanal);
u16  MADC_u16GetData(void);
void MADC_voidADCEnableInterrupt (void);
void MADC_voidADCDisEnableInterrupt (void);
void MADC_StartChange(void);
void  MADC_u16ReadDataAsyn(u16 *Local_var);



#endif /* HAL_ADC_HADC_INT_H_ */
