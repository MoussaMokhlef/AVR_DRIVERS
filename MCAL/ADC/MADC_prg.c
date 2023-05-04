/*
 * HADC_prg.c
 *
 *  Created on: Apr 1, 2023
 *      Author: User
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"
#include"../DIO/DIO_int.h"
#include "MADC_cfg.h"
#include "MADC_int.h"
#include "MADC_prv.h"
#include"../INTERRUPT/INTERRUPT_int.h"
//static void (*Call_Back_Global_PtrTofun)(void)=NULL_POINTER;
static u16 * Global_ptr_Var=NULL_POINTER;


void MADC_voidInit(u8 Local_u8Chanal)
{
	ADC_ADMUX  =   ADC_ADMUX   & 0b11100000;
	ADC_ADMUX |=Local_u8Chanal;


#if  Voltage_Reference_Selections == INTERNAL_VOLTAGE
	SET_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF0);
	SET_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF1);
#elif Voltage_Reference_Selections == AREV
	CLEAR_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF0);
	CLEAR_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF1);
#elif Voltage_Reference_Selections == AVCC
	SET_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF0);
	CLEAR_BIT(ADC_ADMUX,ADC_BIT_VOLT_REF1);
#endif


#if     ADC_Adjust_Result == Left_Adjust
	SET_BIT(ADC_ADMUX,ADC_BIT_ADLAR);
#elif     ADC_Adjust_Result == Right_Adjust
	CLEAR_BIT(ADC_ADMUX,ADC_BIT_ADLAR);
#endif



     #if    PRESCALLER == PRESCALLER2
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x01;

     #elif    PRESCALLER == PRESCALLER4
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x02;

     #elif    PRESCALLER == PRESCALLER8
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x03;

     #elif    PRESCALLER == PRESCALLER16
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x04;

     #elif    PRESCALLER == PRESCALLER32
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x05;

     #elif    PRESCALLER == PRESCALLER64
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x06;

     #elif    PRESCALLER == PRESCALLER128
	ADC_ADCSRA &=0b11111000;
	ADC_ADCSRA |= 0x07;
#endif


    SET_BIT(ADC_ADCSRA,ADC_BIT_EN);
    SET_BIT(ADC_ADCSRA,ADC_BIT_ST);
	//CLEAR_BIT(ADC_ADCSRA,ADATE);
	//SET_BIT(ADC_ADCSRA,ADIF);




}

u16  MADC_u16GetData(void)
{
	u16  Local_value=0;
	SET_BIT(ADC_ADCSRA,ADC_BIT_ST);

	while(GET_BIT(ADC_ADCSRA,ADC_BIT_interrupt_flag)  == 0);

#if   ADC_Adjust_Result==  Left_Adjust
	Local_value=(ADC_ADCL>>6) | (ADC_ADCH <<2);

#elif  ADC_Adjust_Result== Right_Adjust
	Local_value=ADC_ADCL;
	Local_value=(Local_value )|( (ADC_ADCH<<8));

#endif

	SET_BIT(ADC_ADCSRA,ADC_BIT_interrupt_flag);


return Local_value;

}

void MADC_voidADCEnableInterrupt (void)
{
	SET_BIT(ADC_ADCSRA,ADIE);
}
void MADC_voidADCDisEnableInterrupt (void)
{
	SET_BIT(ADC_ADCSRA,ADIE);
}


void MADC_StartChange(void)
{
	SET_BIT(ADC_ADCSRA,ADC_BIT_ST);
}




void  MADC_u16ReadDataAsyn(u16 *Local_var)
{

		//Call_Back_Global_PtrTofun=ptr;

		Global_ptr_Var=Local_var;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
/*
          #if   ADC_Adjust_Result==  Left_Adjust

		*Global_ptr_Var |= (ADC_ADCL>>6)|(ADC_ADCH<<2);

          #elif  ADC_Adjust_Result==Right_Adjust
		*Global_ptr_Var  = ADC_ADCL;
		*Global_ptr_Var |= ( ADC_ADCH<<8);
          #endif
	//	Call_Back_Global_PtrTofun();
*/
	*Global_ptr_Var=ADC_ADC;
}

