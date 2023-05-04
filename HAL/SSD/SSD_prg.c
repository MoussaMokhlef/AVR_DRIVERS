#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"
#include<util/delay.h>
#include"../../MCAL/DIO/DIO_int.h"
#include "../LCD/LCD_int.h"

#include"SSD_cfg.h"
#include"SSD_prv.h"
#include"SSD_int.h"
  u8 VALUE_CATHODE[]=SSD_VALUES_CATHODE ;
  u8 VALUE_ANODE[]=SSD_VALUES_ANODE ;
void HSSD_voidInit(u8 Copy_u8Single_Double)
{
	switch(Copy_u8Single_Double)
	{
	  case(SINGLE):
		MDIO_voidSetPortDirection(SSD_PORT_F,SSD_PORT_VALUE);
		break;
	  case(DOUBLE):
		MDIO_voidSetPortDirection(SSD_PORT_F,SSD_PORT_VALUE);
		MDIO_voidSetPortDirection(SSD_PORT_S,SSD_PORT_VALUE);
		break;
	}
}

void HSSD_voidDisplay(u8 Copy_u8Number,u8 Copy_u8Type_SSD)
{

    switch(Copy_u8Type_SSD)
    {
    case ANODE:
    	MDIO_voidSetPortValue(SSD_PORT_F,VALUE_ANODE[Copy_u8Number]);
    		break;
    case CATHODE:
    	MDIO_voidSetPortValue(SSD_PORT_F,VALUE_CATHODE[Copy_u8Number]);
    		break;

    }

}
void HSSD_viodCount(u8 Copy_u8Start,u8 Copy_u8End)
{
	u8 counter;
	u8 temp1=Copy_u8Start/10;
	u8 temp2=Copy_u8Start%10;
	for(counter=Copy_u8Start;counter<=Copy_u8End;counter++)
	{
	MDIO_voidSetPortValue(SSD_PORT_F,VALUE_CATHODE[temp1]);
	MDIO_voidSetPortValue(SSD_PORT_S,VALUE_CATHODE[temp2++]);
	if(temp2==10){
		    temp1++;
	       	temp2=0;
				}
	_delay_ms(100);
	}
	}
void HSSD_voidInit_DEC(void)
{
	MDIO_voidSetPortDirection(SSD_PORT_DEC,SSD_DEC_PORT_VALUE);
}

void HSSD_voidDisplay_DEC(u8 Copy_u8Number)
{
     u8 Copy_Temp1=(Copy_u8Number%10);
     u8 Copy_Temp2=((Copy_u8Number/10));
  	( Copy_Temp2) =(Copy_Temp1)|((Copy_Temp2)<<4);
	MDIO_voidSetPortValue(SSD_PORT_DEC,Copy_Temp2);

}

void HSSD_viodCount_Dec(u8 Copy_u8Start,u8 Copy_u8End)
{
	u8 counter;
	u8 temp;
    u8 Copy_Temp2=(Copy_u8Start%10);
    u8 Copy_Temp1=((Copy_u8Start/10));
	for(counter=Copy_u8Start;counter<=Copy_u8End;counter++)
	{

	  	( temp) =(Copy_Temp1)|((Copy_Temp2)<<4);

	  	MDIO_voidSetPortValue(SSD_PORT_DEC,temp);
		HLCD_4_voidSendCommand(0x01);
	  	HLCD_voidDisplayNumber(counter);
	  	Copy_Temp2++;
		if(Copy_Temp2==10){
			Copy_Temp1++;
			Copy_Temp2=0;
					}
		_delay_ms(200);

		}
	}




