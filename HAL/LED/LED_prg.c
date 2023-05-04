#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_int.h"
#include"../../MCAL/DIO/DIO_prv.h"

#include"LED_cfg.h"
#include"LED_prv.h"
#include"LED_int.h"
#include<avr/delay.h>









void HLED_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,PIN_OUT);
}

void HLED_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,PIN_HIGH);
}

void HLED_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,PIN_LOW);
}

void HLED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	  switch(Copy_u8Port)
	  {
	  case (PORTA):
			  TOGGLE_BIT(MDIO_PORTA,Copy_u8Pin);
			break;
	  case(PORTB):
			  TOGGLE_BIT(MDIO_PORTB,Copy_u8Pin);
			break;
	  case(PORTC):
			TOGGLE_BIT(MDIO_PORTC,Copy_u8Pin);
			break;
	  case(PORTD):
			TOGGLE_BIT(MDIO_PORTD,Copy_u8Pin);
			break;
	  }
}

