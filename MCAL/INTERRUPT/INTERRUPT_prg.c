/*
 * MINTERUPT_prg.c
 *
 *  Created on: Mar 30, 2023
 *      Author: User
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"
#include"../DIO/DIO_int.h"
#include "INTERRUPT_cfg.h"
#include "INTERRUPT_int.h"
#include "INTERRUPT_prv.h"

void (*Call_Back_Exit_Int0)(void);
void (*Call_Back_Exit_Int1)(void);
void (*Call_Back_Exit_Int2)(void);

void EX_voidInteruptEnable(u8 Copy_u8InterruptExitNum,u8 Copy_u8InterruptState)
{
	SET_BIT(MSREG_REG,7);
	switch(Copy_u8InterruptExitNum)
	{
	case(EXT_INTERRUPT0):
			       MDIO_voidSetPinDirection(PORTD,PIN2,PIN_IN);
	               MDIO_voidSetPullupRessistor(PORTD,PIN2);
			       SET_BIT(MGICR_REG,6);
	               switch(Copy_u8InterruptState)
	               {
   		                case(LOW_LEVEL_SENSE_INTERRUPT):
                             CLEAR_BIT(MMCUCR_REG,0);
                             CLEAR_BIT(MMCUCR_REG,1);
                        break;
   		                case(ANY_CHANGE_SENSE_INTERRUPT):
                             SET_BIT(MMCUCR_REG,0);
                             CLEAR_BIT(MMCUCR_REG,1);
                        break;
   		                case(FALLING_EDGE_SENSE_INTERRUPT):
                             CLEAR_BIT(MMCUCR_REG,0);
                             SET_BIT(MMCUCR_REG,1);
                        break;
   		                case(RISING_EDGE_SENSE_INTERRUPT):
                             SET_BIT(MMCUCR_REG,0);
                             SET_BIT(MMCUCR_REG,1);
                        break;
	               }

	         	break;
	case(EXT_INTERRUPT1):
				   MDIO_voidSetPinDirection(PORTD,PIN3,PIN_IN);
			       MDIO_voidSetPullupRessistor(PORTD,PIN3);
			       SET_BIT(MGICR_REG,7);
	               switch(Copy_u8InterruptState)
	               {
   		                case(LOW_LEVEL_SENSE_INTERRUPT):
                             CLEAR_BIT(MMCUCR_REG,2);
                             CLEAR_BIT(MMCUCR_REG,3);
                        break;
   		                case(ANY_CHANGE_SENSE_INTERRUPT):
                             SET_BIT(MMCUCR_REG,2);
                             CLEAR_BIT(MMCUCR_REG,3);
                        break;
   		                case(FALLING_EDGE_SENSE_INTERRUPT):
                             CLEAR_BIT(MMCUCR_REG,2);
                             SET_BIT(MMCUCR_REG,3);
                        break;
   		                case(RISING_EDGE_SENSE_INTERRUPT):
                             SET_BIT(MMCUCR_REG,2);
                             SET_BIT(MMCUCR_REG,3);
                        break;
	               }

	         	break;
	case(EXT_INTERRUPT2):
				   MDIO_voidSetPinDirection(PORTB,PIN2,PIN_IN);
			       MDIO_voidSetPullupRessistor(PORTB,PIN2);
			       SET_BIT(MGICR_REG,5);
	               switch(Copy_u8InterruptState)
	               {
   		                case(FALLING_EDGE_SENSE_INTERRUPT):
                             CLEAR_BIT(MMCUCSR_REG,6);

                        break;
   		                case(RISING_EDGE_SENSE_INTERRUPT):

                             SET_BIT(MMCUCSR_REG,6);
	               }

	         	break;
	}

}
void MINTERRUPT_voidEnableGlobalEntrrupt(void)
{
	SET_BIT(MSREG_REG,7);
}

void EX_voidInteruptDisEnable(u8 Copy_u8InterruptExitNum)
{
	switch(Copy_u8InterruptExitNum)
	{
	case(EXT_INTERRUPT0):
		CLEAR_BIT(MGICR_REG,6);
		break;
	case(EXT_INTERRUPT1):
		CLEAR_BIT(MGICR_REG,7);
		break;
	case(EXT_INTERRUPT2):
		CLEAR_BIT(MGICR_REG,5);
		break;
	}
}

void Set_Call_back_Exit_Int0(void(*ptr)(void))
{
	Call_Back_Exit_Int0=ptr;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	Call_Back_Exit_Int0();
}


void Set_Call_back_Exit_Int1(void(*ptr)(void))
{
	Call_Back_Exit_Int1=ptr;
}

void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	Call_Back_Exit_Int1();
}

/*******************************************************************/
void Set_Call_back_Exit_Int2(void(*ptr)(void))
{
	Call_Back_Exit_Int2=ptr;
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	Call_Back_Exit_Int2();
}


