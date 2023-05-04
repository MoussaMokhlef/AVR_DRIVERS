#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_int.h"

#include"LCD_cfg.h"
#include"LCD_prv.h"
#include"LCD_int.h"
#include <avr/delay.h>
 static u8 lcd_init_u8_status=0;
void HLCD_voidSendCommand(u8 Copy_u8Command)
{
   MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RS_PIN,PIN_LOW);
   MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RW_PIN,PIN_LOW);

   MDIO_voidSetPortValue(HLCD_DATA_PORT,Copy_u8Command);

   MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_HIGH);
   _delay_ms(2);
   MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_LOW);
}
void HLCD_voidSendData(u8 Copy_u8Data)
{

	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RS_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RW_PIN,PIN_LOW);


    MDIO_voidSetPortValue(HLCD_DATA_PORT,Copy_u8Data);

    MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_LOW);



}
void HLCD_voidInit(void)
{
	MDIO_voidSetPortDirection(HLCD_DATA_PORT,0xff);

	MDIO_voidSetPortDirection(HLCD_CTRL_PORT,0xff);


   _delay_ms(40);
   HLCD_voidSendCommand(HLCD_FUNSET_CMD);

   HLCD_voidSendCommand(HLCD_DOC_CMD);

   HLCD_voidSendCommand(HLCD_CLR_CMD);

}
void HLCD_voidGoTo(u8 Copy_u8X,u8 Copy_u8Y)
{
    u8 addresse;
	addresse=(((Copy_u8Y)*(0x40))+(Copy_u8X));
    SET_BIT(addresse,7);
    HLCD_4_voidSendCommand(addresse);
}


void HLCD_voidSendDataString(u8* str,u8 Copy_u8X,u8 Copy_u8Y)
{
	HLCD_voidGoTo(Copy_u8X,Copy_u8Y);
    u8 counter=0;
    while(str[counter]!='\0')
    {
	HLCD_4_voidSendData(str[counter]);
	counter++;
    }
}

void HLCD_4_voidSendCommand(u8 Copy_u8Command)
{
	//u8 x;
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RS_PIN,PIN_LOW);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RW_PIN,PIN_LOW);

	//x=Copy_u8Command

//	MDIO_voidSetPortValue(HLCD_DATA_PORT,(Copy_u8Command));

	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA4,GET_BIT(Copy_u8Command,PIN4));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA5,GET_BIT(Copy_u8Command,PIN5));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA6,GET_BIT(Copy_u8Command,PIN6));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA7,GET_BIT(Copy_u8Command,PIN7));

	//Enable to write command
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_LOW);

    if(lcd_init_u8_status==1){
    	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA4,GET_BIT(Copy_u8Command,PIN0));
    	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA5,GET_BIT(Copy_u8Command,PIN1));
    	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA6,GET_BIT(Copy_u8Command,PIN2));
    	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA7,GET_BIT(Copy_u8Command,PIN3));
	//MDIO_voidSetPortValue(HLCD_DATA_PORT,(Copy_u8Command<<4));
	//Enable to write command
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_LOW);
     _delay_ms(2);
    }
}
void HLCD_4_voidSendData(u8 Copy_u8Data)
{
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RS_PIN,PIN_HIGH);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_RW_PIN,PIN_LOW);
    //sending upper four bits
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA4,GET_BIT(Copy_u8Data,PIN4));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA5,GET_BIT(Copy_u8Data,PIN5));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA6,GET_BIT(Copy_u8Data,PIN6));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA7,GET_BIT(Copy_u8Data,PIN7));
	//MDIO_voidSetPortValue(HLCD_DATA_PORT,(Copy_u8Data&0xf0));

	//Enable to write data Upeer four bits

	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_LOW);

    //Sendind lower four bits
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA4,GET_BIT(Copy_u8Data,PIN0));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA5,GET_BIT(Copy_u8Data,PIN1));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA6,GET_BIT(Copy_u8Data,PIN2));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN_DATA7,GET_BIT(Copy_u8Data,PIN3));
	//MDIO_voidSetPortValue(HLCD_DATA_PORT,(Copy_u8Data<<4));

	//Enable to write data lower four bits

    MDIO_voidSetPinValue(HLCD_CTRL_PORT,PIN2,PIN_HIGH);
    _delay_ms(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT,PIN2,PIN_LOW);


     _delay_ms(2);

}
void HLCD_4_voidInit(void)
{

	MDIO_voidSetPinDirection(HLCD_DATA_PORT,HLCD_PIN_DATA4,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT,HLCD_PIN_DATA5,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT,HLCD_PIN_DATA6,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT,HLCD_PIN_DATA7,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RS_PIN,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RW_PIN,PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_EN_PIN,PIN_OUT);

	_delay_ms(30);
	HLCD_voidSendCommand(0x20);
	HLCD_voidSendCommand(0x20);
	HLCD_voidSendCommand(0x80);

	_delay_ms(1);

	HLCD_voidSendCommand(0x00);
	HLCD_voidSendCommand(0xf0);

	_delay_ms(1);
	HLCD_voidSendCommand(0x00);
	HLCD_voidSendCommand(0x10);

    _delay_ms(2);


    lcd_init_u8_status=1;

}
void HLCD_voidSendSpecialChar(const char *arr,u8 Copy_u8PatternNumber,u8 Copy_u8X,u8 Copy_u8Y)
{
   u8 addresse;
   if(Copy_u8PatternNumber<8)
   {
	   addresse=(Copy_u8PatternNumber)*8;
	      SET_BIT(addresse,6);
	      HLCD_4_voidSendCommand(addresse);
	      u8 counter=0;
	      while(counter<8)
	      {
	   	  HLCD_4_voidSendData(arr[counter]);
	   	  counter++;

	      }
   }

   HLCD_4_voidSendCommand(0x02);
   HLCD_voidGoTo(Copy_u8X,Copy_u8Y);
   HLCD_4_voidSendData(Copy_u8PatternNumber);
}

void HLCD_voidDisplayNumber(u32 Copy_u32Number)
{
               //Yoy can enter any number

u8 temp[MAX_SIZE_TEMP];
s32 Local_var;
u8 counter_temp=MAX_SIZE_TEMP;

    if(Copy_u32Number==0)
    {
    	HLCD_4_voidSendData('0');
    }
    else
    {
        while(Copy_u32Number !=0){
        	Local_var=Copy_u32Number;
        	Copy_u32Number /=10;
        	Local_var=Local_var-(Copy_u32Number*10);
        	temp[--counter_temp]=Local_var;



       }
       while(counter_temp<MAX_SIZE_TEMP)
       {
       	HLCD_4_voidSendData(temp[counter_temp++]+'0');
       }

    }




}
