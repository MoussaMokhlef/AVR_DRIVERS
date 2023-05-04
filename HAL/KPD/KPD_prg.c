/*
 * KPD_prg.c
 *
 *  Created on: Mar 25, 2023
 *      Author: User
 */



#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_int.h"
#include"KPD_cfg.h"
#include"KPD_prv.h"
#include"KPD_int.h"

void HKPD_voidINIT()
{
	MDIO_voidSetPinDirection(KPD_POR,KPD_ROW0_PIN ,PIN_IN);
	MDIO_voidSetPinDirection(KPD_POR,KPD_ROW1_PIN,PIN_IN);
	MDIO_voidSetPinDirection(KPD_POR,KPD_ROW2_PIN,PIN_IN);
	MDIO_voidSetPinDirection(KPD_POR,KPD_ROW3_PIN,PIN_IN);


    MDIO_voidSetPullupRessistor(KPD_POR,KPD_ROW0_PIN);
    MDIO_voidSetPullupRessistor(KPD_POR,KPD_ROW1_PIN);
    MDIO_voidSetPullupRessistor(KPD_POR,KPD_ROW2_PIN);
    MDIO_voidSetPullupRessistor(KPD_POR,KPD_ROW3_PIN);


	MDIO_voidSetPinDirection(KPD_POR,KPD_COL0_PIN,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_POR,KPD_COL1_PIN,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_POR,KPD_COL2_PIN,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_POR,KPD_COL3_PIN,PIN_OUT);

	MDIO_voidSetPinValue(KPD_POR,KPD_COL0_PIN,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_POR,KPD_COL1_PIN,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_POR,KPD_COL2_PIN,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_POR,KPD_COL3_PIN,PIN_HIGH);
}

u8 HKPD_u8GetPressedKey(void)
{
	u8 Local_u8ColumnArray[COL_NUM]={KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};
	u8 Local_u8RowsnArray[ROW_NUM]={KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

	u8 Local_u8ColumnCounter;
	u8 Local_u8RowsCounter;
	//pin state
	u8 Local_u8PinState;
	u8 Local_u8PressedKey= NOT_PRESSED;
	u8 Local_u8ButtonArray[ROW_NUM][COL_NUM]=KPD_BUTTON_VALUE2;


	//LOOPING FOR COL
	for(Local_u8ColumnCounter=0;Local_u8ColumnCounter< COL_NUM;Local_u8ColumnCounter++)
	{
		//SET COLUMN OF COUNTER LOW TO CHECK
		MDIO_voidSetPinValue(KPD_POR,Local_u8ColumnArray[Local_u8ColumnCounter],PIN_LOW);

		for(Local_u8RowsCounter=0;Local_u8RowsCounter< ROW_NUM;Local_u8RowsCounter++)
		{
			Local_u8PinState= MDIO_u8GetPinValue(KPD_POR,Local_u8RowsnArray[Local_u8RowsCounter]);


			if(Local_u8PinState==PIN_LOW)
			{
				Local_u8PressedKey=Local_u8ButtonArray[Local_u8RowsCounter][Local_u8ColumnCounter];

				while(Local_u8PinState==PIN_LOW)
				Local_u8PinState=MDIO_u8GetPinValue(KPD_POR,Local_u8RowsnArray[Local_u8RowsCounter]);
				return Local_u8PressedKey;
			}
		}
		MDIO_voidSetPinValue(KPD_POR ,Local_u8ColumnArray[Local_u8ColumnCounter], PIN_HIGH);
	}
	return Local_u8PressedKey;

}


//void HKPD_voidCalc()


