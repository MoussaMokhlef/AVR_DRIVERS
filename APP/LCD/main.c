#include"../../LIB/BIT_MATH.h"
#include"../../HAL/LCD/LCD_int.h"
#include"../../HAL/LED/LED_int.h"
#include"../../HAL/SSD/SSD_int.h"
#include"../../HAL/SSD/SSD_prv.h"
#include"../../HAL/SSD/SSD_cfg.h"
#include"../../HAL/STEPPER/STEPPER_MOTOR_int.h"
#include"../../MCAL/INTERRUPT/INTERRUPT_int.h"
#include"../../MCAL/INTERRUPT/INTERRUPT_cfg.h"
#include"../../MCAL/INTERRUPT/INTERRUPT_prv.h"
#include"../../MCAL/ADC/MADC_int.h"
#include"../../HAL/KPD/KPD_int.h"
#include"../../MCAL/MTIMER/TIMER_INTERFACE.h"
#include"../../MCAL/USART/USART_int.h"
#include"../../MCAL/SPI/SPI_int.h"
#include"../../MCAL/TWI/TWI_int.h"
#include"../../MCAL/EEPROM/EEPROM_int.h"

#include<avr/delay.h>

void ICU_HW(void);

u32 Sum_u32(u32 arr[],u8 size);

void  LED_Interrupt(void);
void  LED_Interrupt2(void);
void  LED_Interrupt3(void);

u16 Period=0 , Ton=0;

#define    code  5



#if     code==1
int main(void)
{
/**************************USART******************************/
/*	u16 number ;
	number=280;
	MUSART_voidSelect_Bout_Rate(9600);
	MUSART_voidInit();

	while(1){

		MUSART_voidTransmitDataSync(number);
		_delay_ms(500);

	}*/
/******************************************************************/

	MDIO_voidSetPinDirection(PORTB,PIN5,PIN_OUT);
	MDIO_voidSetPinDirection(PORTB,PIN6,PIN_IN);
	MDIO_voidSetPinDirection(PORTB,PIN7,PIN_OUT);
	MDIO_voidSetPinDirection(PORTB,PIN4,PIN_OUT);

	MDIO_voidSetPinDirection(PORTD,PIN0,PIN_IN);
	 MSPI_voidInit();
	 HKPD_voidINIT();
	 u8 x;
	 while(1)
	 {
		 x=HKPD_u8GetPressedKey();
		 if(x !=0xff){
		 MDIO_voidSetPinValue(PORTB,PIN4,PIN_LOW);
		 MSPI_voidSendData(x);
		 MDIO_voidSetPinValue(PORTB,PIN4,PIN_HIGH);
		 }
		 else
		 {

		 }
	 }

}
#elif     code == 2
int main(void)
{
/**************************USART******************************/

/******************************************************************/

	MDIO_voidSetPinDirection(PORTB,PIN5,PIN_IN);
	MDIO_voidSetPinDirection(PORTB,PIN6,PIN_OUT);
	MDIO_voidSetPinDirection(PORTB,PIN7,PIN_IN);
	MDIO_voidSetPinDirection(PORTB,PIN4,PIN_IN);
     HLCD_4_voidInit();
	 MSPI_voidInit();
	 u8 x;
	 while(1)
	 {
       x=MSPI_u8ReceiveData();
       if(x!=0xff)
       {
    	  HLCD_voidDisplayNumber(x);
    	  _delay_ms(200);

       }
       else
       {

       }

	 }
}

#elif     code == 3
int main(void){

    while(1){
    MINTERRUPT_voidEnableGlobalEntrrupt();
	TIMER1_voidInit(TIMER1_CHANNEL_A,SET,NORMAL_MODE,PRESCALER_DIV_BY_8);
	TIMER_voidSetCallBack(TIMER1_OVERFLOW_INT,LED_Interrupt);
	_delay_ms(500);
    }

/*
	HLCD_4_voidInit();
//	SET_BIT(MSREG_REG,7);
	MDIO_voidSetPinDirection(PORTB,PIN3,PIN_OUT);
	MDIO_voidSetPinDirection(PORTD,PIN6,PIN_IN);

	TIMER0_voidInit(NON_INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_8);
	TIMER0_voidSetCompareMatchValue(150);

	TIMER_voidSetCallBack(TIMER1_ICU_INT,ICU_HW);
	ICU_voidInit();

	while(1)
	{
		if( (Period == 0) || (Ton == 0)){

		}
		else{
		HLCD_voidGoTo(0,0);
		HLCD_voidDisplayNumber(Period);
		HLCD_voidGoTo(0,1);
		HLCD_voidDisplayNumber(Ton);
        CLEAR_BIT(MSREG_REG,7);
		_delay_ms(1000);}


	}
	*/
/*
	MDIO_voidSetPinDirection(PORTD,PIN5,PIN_OUT);
	TIMER1_voidSetMode_14(TIMER1_CHANNEL_A,NON_INVERTING,PRESCALER_DIV_BY_8);
	TIMER1_voidSetTopValueMode_14(20000);
	while(1)
	{
		TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A,1700);
	}
*/

/*	EX_voidInteruptEnable(EXT_INTERRUPT0,ANY_CHANGE_SENSE_INTERRUPT);
	EX_voidInteruptEnable(EXT_INTERRUPT1,ANY_CHANGE_SENSE_INTERRUPT);
	EX_voidInteruptEnable(EXT_INTERRUPT2,RISING_EDGE_SENSE_INTERRUPT);
	//EX_voidInteruptEnable(EXT_INTERRUPT0,ANY_CHANGE_SENSE_INTERRUPT);
	Set_Call_back_Exit_Int0(LED_Interrupt);
	Set_Call_back_Exit_Int1(LED_Interrupt2);
	Set_Call_back_Exit_Int2(LED_Interrupt3);
	while(1){}
*/
   // HSTEPPER_MOTOR_voidInit();
   // HSTEPPER_MOTOR_voidOneRevFullStepCW();
	//HSSD_voidInit_DEC();
	//HSSD_voidDisplay_DEC(99);
	//while(1){
	/*************************************************************************/
/*	HLCD_4_voidInit();
	MADC_voidInit(0);
	//HLCD_voidDisplayNumber(18);
    u32 local_value=0;
    //u32 local_value1=0;
	while(1){
		//MADC_voidStartConversion(0);
		local_value=(MADC_u16GetData()*4.88 );

		local_value /=10;
		HLCD_voidDisplayNumber(local_value);
		_delay_ms(100);
		HLCD_4_voidSendCommand(0x01);
	}
*/
	/************************************************************************/
/*	MDIO_voidSetPinDirection(PORTB,PIN3,PIN_OUT);
	TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
	MDIO_voidSetPinDirection(PORTD,PIN7,PIN_OUT);
	TIMER2_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
	u8  value=0;
	while(1)
	{
		TIMER0_voidSetCompareMatchValue(value);
		TIMER2_voidSetCompareMatchValue(value);
		_delay_ms(100);
		value++;
		if(value==255)
		{
			value=0;
		}
	}

*/
	/**************************************************************/
/*
	HLCD_4_voidInit();
	u16 local_var=0;
	u16 local_var1;
	while(1)
	{
		MADC_voidInit(0);
	//	MADC_StartChange();
		MINTERRUPT_voidEnableGlobalEntrrupt();
		MADC_voidADCEnableInterrupt();
		MADC_u16ReadDataAsyn(&local_var);
		local_var1=(local_var*4.88)/10;
		if(local_var1 != 0)
		HLCD_voidDisplayNumber(local_var1);
		_delay_ms(100);
		HLCD_4_voidSendCommand(0x01);

	}
*/
	/****************************************************************/
	/*
	MADC_voidEnableGlobalEntrrupt();
	M_TIMER0_voidInit();
	while(1){
    MTIMER0_SET_OVERFLOW(LED_Interrupt3);
	}
	*/
	//HLCD_voidSendData('A');
	//HLCD_4_voidSendData('M');
	//MADC_voidInit();
//	MADC_voidStartConversion();
	//u16 local;
	//local=MADC_u16GetData();
	//HLCD_4_voidSendData('k');
	//HLCD_voidDisplayNumber(55);
	//_delay_ms(500);
	//HLCD_4_voidSendCommand(0x01);
	//}
	//HLED_voidOn(PORTD,PIN0);
	//HSSD_voidInit(DOUBLE);
//	HSSD_voidInit(PORTD);
	//HSSD_viodCount(1,9);
	//HSSD_viodCount(5,99);

	//HLCD_voidInit();
	//HLCD_4_voidSendData('o');
	//HLCD_voidSendDataString("moussa",5,1);
	/**********************print my name in arabic sign wave***************************/
  /*  u8 arr1[]={0x00,0xff,0x09,0x09,0x09,0x0f,0x00,0x00};
    u8 arr2[]={0x00,0x0f,0x09,0x09,0x0f,0x01,0x0f,0x00};
    u8 arr3[]={0x00,0x15,0x15,0x15,0x1f,0x00,0x00,0x00};
    u8 arr4[]={0x00,0x17,0x14,0x14,0x17,0x11,0xff,0x00};
    u8*arr5[]={arr4,arr3,arr2,arr1};
    u8 counter=0;
    u8 i=0;
    u8 x=0;
    u8 y=0;

	while(1)
	{
		HLCD_voidSendSpecialChar(arr5[counter++],i++,x++,y);
		if(counter==4)
		{
			_delay_ms(500);
			counter=0;
			HLCD_4_voidSendCommand(0x01);
			_delay_ms(500);
			y=1-y;
		}
		if(i==7)
		{
	    	i=0;
		}
		if(x>=12)x=0;



	}*/

/*******************************************************************************************/

/*******************************************************************************************/
/*
    HLED_voidInit(PORTD,PIN0);
    HLED_voidInit(PORTD,PIN1);
    HLED_voidOn(PORTD,PIN0);
    _delay_ms(100);

    HLED_voidToggle(PORTD,PIN0);
*/
//	HLCD_voidDisplayNumber(1258);
	/**********************print any number on LCD ******************************/
/*	u32 number=5847475;              //Yoy can enter any number
	u8 counter=0;
	u8 x=3;                          // x on LCD
	u8 y=0;                          //y on LCD
    u8 remender;
	u8 arr0[]={0x0E,0x11,0x13,0x15,0x19,0x11,0x0E};   //number0
	u8 arr1[]={0x04,0x0c,0x04,0x04,0x04,0x04,0x0E};   //number1
	u8 arr2[]={0x0E,0x11,0x01,0x02,0x04,0x08,0x1f};   //number2
	u8 arr3[]={0x1f,0x02,0x04,0x02,0x01,0x11,0x0E};   //number3
	u8 arr4[]={0x02,0x06,0x0A,0x12,0x1f,0x02,0x02};   //number4
	u8 arr5[]={0x1f,0x10,0x1e,0x01,0x01,0x11,0x0E};   //number5
	u8 arr6[]={0x06,0x08,0x10,0x1e,0x11,0x11,0x0E};   //number6
	u8 arr7[]={0x1f,0x01,0x02,0x04,0x08,0x08,0x08};   //number7
	u8 arr8[]={0x0e,0x11,0x11,0x0e,0x11,0x11,0x0E};   //number8
	u8 arr9[]={0x0E,0x11,0x11,0x0f,0x01,0x12,0x0c};   //number 9
	u8*arr[]={arr0,arr1,arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9};  //array have all nuhmbers
    while(number)
    {
    	remender=number%10;         // remnender number to Display in LCD
    	HLCD_voidSendSpecialChar(arr[remender],counter,x,y);  //function to Display special char
    	number/=10;
    	counter++;
    	x++;
    	if(x==13)                  //check if x =13 to change y to next row
    	{
    		y=1-y;
    		x=3;
    	}
    }*/
    /*********************************************************************/


//}
}
#elif   code ==5
int main(void)
{
		u16 number ;
		MUSART_voidSelect_Bout_Rate(9600);
		MUSART_voidInit();
		HLCD_4_voidInit();
		//MINTERRUPT_voidEnableGlobalEntrrupt();

		while(1){

			number=MUSART_u8ReceiveDataSync();
			HLCD_voidDisplayNumber(number);
			_delay_ms(500);
			HLCD_4_voidSendCommand(0x01);

		}
}
#elif   code ==5
int main(void)
{
		u16 number ;
		number=300;
		MUSART_voidSelect_Bout_Rate(9600);
		MUSART_voidInit();
		//MINTERRUPT_voidEnableGlobalEntrrupt();

		while(1){

			MUSART_voidTransmitDataSync(number);

			_delay_ms(500);

		}
}


#elif   code ==6
int main(void)
{
	u8 Counter_X=0;
	u32 TEMPRETURE=0 ;
	u8 Counter_error=0;
	u32 PASSWORD_array[4];
	u32 SUM;
	u8 array[]="PASSWORD = ";
	MADC_voidInit(0);
	HLCD_4_voidInit();
	HKPD_voidINIT();


//	MDIO_voidSetPinDirection(PORTD,PIN7,PIN_OUT);



	HLCD_voidSendDataString(array,0,0);

	u8 Local_variable;
	while(1)
	{
		//HLCD_voidGoTo(0,8);
		Local_variable =HKPD_u8GetPressedKey();
		if(Local_variable !=0xff)
		{

           HLCD_voidDisplayNumber(Local_variable);
           PASSWORD_array[Counter_X]=Local_variable;
           Counter_X++;

        }
		if (Counter_X ==4)
		{
			SUM = Sum_u32(PASSWORD_array,4);
			HLCD_4_voidSendCommand(0x01);
			HLCD_voidSendDataString(array,0,0);


			Counter_X=0;
			if(SUM==1234)
			{
				        MDIO_voidSetPinDirection(PORTB,PIN3,PIN_OUT);
			         	MDIO_voidSetPinDirection(PORTD,PIN7,PIN_OUT);
				        TIMER2_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
						TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
						TIMER0_voidSetCompareMatchValue(255);

						TIMER2_voidSetCompareMatchValue(50);
						_delay_ms(1000);
						TIMER2_voidSetCompareMatchValue(255);

		    }
			else
			{
				MDIO_voidSetPinDirection(PORTB,PIN3,PIN_OUT);
			//	TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
			//	TIMER0_voidSetCompareMatchValue(0);
			//	_delay_ms(1000);
				switch(Counter_error)
				{
				case 0:
					TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
					TIMER0_voidSetCompareMatchValue(200);
					break;
				case 1:
					TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
					TIMER0_voidSetCompareMatchValue(100);
					break;
				case 2:
					TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
					TIMER0_voidSetCompareMatchValue(0);
					break;
				default:
					TIMER0_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
					TIMER0_voidSetCompareMatchValue(255);
					break;
				}
				 Counter_error ++;
			}
			}

		TEMPRETURE = (MADC_u16GetData() *4.88);
		TEMPRETURE /=10;
		MDIO_voidSetPinDirection(PORTD,PIN7,PIN_OUT);

		if(TEMPRETURE<20)
		{
			TIMER2_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
			TIMER2_voidSetCompareMatchValue(255);
		}
		else if(TEMPRETURE>=100)
		{
			TIMER2_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
			TIMER2_voidSetCompareMatchValue(255);
		}
		else
		{
			TIMER2_voidInit(INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_64);
			TEMPRETURE = 255-(TEMPRETURE*2.55);
			TIMER2_voidSetCompareMatchValue(TEMPRETURE);
		}



		}






}

#elif  code ==8

int main(void)
{
	u8 x,y,z;
	MINTERRUPT_voidEnableGlobalEntrrupt();
	HLCD_4_voidInit();

	//_delay_ms(500);


while(1){
	MTWI_voidMASTERInit(0x12);

	x=MTWI_voidSend_Start_condition();
	_delay_ms(500);
	y=MTWI_voidSendAddresse_Write(0x10);
	z=MTWI_MASTER_WriteData(15);
	MTWI_voidSendStopCondition();
	HLCD_voidDisplayNumber(x);
	_delay_ms(200);
	HLCD_voidDisplayNumber(y);
	_delay_ms(200);
	HLCD_voidDisplayNumber(z);
	_delay_ms(200);
	HLCD_4_voidSendCommand(0x01);

}
}
#elif  code ==8

int main(void)
{
	MINTERRUPT_voidEnableGlobalEntrrupt();

	u8 x=0;
	HLCD_4_voidInit();
	MTWI_voidSLAVE_Init(0x10);
	while(1){
	    x= MTWI_MASTER_ReadData();
	   // _delay_ms(500);

	    if(x!=0)
		HLCD_voidDisplayNumber(x);
		_delay_ms(500);
		HLCD_4_voidSendCommand(0x01);
	}
	}

#elif code  ==8

int main(void)
{
	u8 Local_u8Data;
	u8 i=0;
	MTWI_voidMASTERInit(0x16);
	HLCD_4_voidInit();

	u8 str[]="moussa";

	//HLCD_voidDisplayNumber(Local_u8Data);
	while(1)
	{
        if(*(str+i)!='\0'){
		EEPROM_voidWriteData(10,*(str+i));
		HLCD_voidSendDataString("W=",0,0);
		HLCD_voidGoTo(i+2,0);
	    HLCD_4_voidSendData(*(str+i));
	    _delay_ms(500);
		Local_u8Data=EEPROM_voidReadData(10);
		HLCD_voidSendDataString("R=",0,1);
		HLCD_voidGoTo(i+2,1);
		HLCD_4_voidSendData(Local_u8Data);
		 _delay_ms(500);
		//HLCD_4_voidSendCommand(0x01);
		i++;

	}
	}

	}


#elif code  ==7

int main(void)
{

	HSSD_voidInit_DEC();
	HLCD_4_voidInit();
	HSSD_viodCount_Dec(5,55);
	while(1)
	{

	}
}


#endif

u32 Sum_u32(u32 arr[],u8 size)
{
	 u8 local_index;

	 u32 sum_num=0;
	 for(local_index=0;local_index<size;local_index++)
	 {
		 sum_num=(sum_num*10)+(arr[local_index]);

	 }
	 return sum_num;
}

void ICU_HW(void)
{
	static u16 R1 ,R2,R3;
	static u8 counter=0;
	counter++;
	switch(counter)
	{
	case 1:
		R1=ICU_u16ReadICU();
		break;
	case 2:
		R2= ICU_u16ReadICU();
		Period=R2-R1;
		ICU_SetTriggerEdge(ICU_FALLING_EDGE);
		break;
	case 3:
		R3=ICU_u16ReadICU();
		Ton=R3-R2;
		break;
	default:
		counter=5;
		break;
	}
}


void  LED_Interrupt(void)
{
	HLED_voidInit(PORTA,PIN0);
	HLED_voidToggle(PORTA,PIN0);
}

void  LED_Interrupt2(void)
{
	HLED_voidInit(PORTA,PIN1);
	HLED_voidToggle(PORTA,PIN1);
}
void  LED_Interrupt3(void)
{
	HLED_voidInit(PORTA,PIN2);
	HLED_voidToggle(PORTA,PIN2);
}

