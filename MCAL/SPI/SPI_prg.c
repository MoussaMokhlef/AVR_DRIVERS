/*
 * SPI_prg.c
 *
 *  Created on: Apr 6, 2023
 *      Author: User
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"
#include"../DIO/DIO_int.h"
#include "SPI_cfg.h"
#include "SPI_int.h"
#include "SPI_prv.h"

 void MSPI_voidInit(void)
 {
/*	     SET_BIT(SPCR,5);

    #if SPI_MODE     == MASTER     //master mode
	     SET_BIT(SPCR,4);

	     CLEAR_BIT(SPCR,2);
	     CLEAR_BIT(SPCR,3);

		 SET_BIT(SPCR,1);
		 SET_BIT(SPCR,0);

    #elif SPI_MODE   == SLAVE       //slave mode
	     CLEAR_BIT(SPCR,4);
    #endif

	  SET_BIT(SPCR,6);
*/
     #if SPI_MODE     == MASTER             //master mode
	     SET_BIT(SPCR,MSTR);                //select master mode
           #if     Data_Order  ==   LSB
	          SET_BIT(SPCR,DORD);
           #elif   Data_Order ==    MSB1
	          CLEAR_BIT(SPCR,DORD);
           #endif


               #if Clock_Polarity  == IDLE_LOW
	               CLEAR_BIT(SPCR,CPOL);
               #elif Clock_Polarity  == IDLE_HIGH
	               SET_BIT(SPCR,CPOL);
               #endif


               #if CLOCK_PHASE    == SAMPLE_FIRST
	               CLEAR_BIT(SPCR,CPHA);
               #elif CLOCK_PHASE  == SETUP_FIRST
	               SET_BIT(SPCR,CPHA);
               #endif

               #if SCK_FREQUENCY   == PRESC_4_MODE
	               CLEAR_BIT(SPCR,SPR0);
	               CLEAR_BIT(SPCR,SPR1);
               #elif SCK_FREQUENCY   == PRESC_16_MODE
	               SET_BIT(SPCR,SPR0);
	               CLEAR_BIT(SPCR,SPR1);
               #elif SCK_FREQUENCY   == PRESC_64_MODE
	               CLEAR_BIT(SPCR,SPR0);
	               SET_BIT(SPCR,SPR1);
               #elif SCK_FREQUENCY   == PRESC_128_MODE
	               SET_BIT(SPCR,SPR0);
	               SET_BIT(SPCR,SPR1);
               #elif SCK_FREQUENCY   == PRESC_2_MODE
	               CLEAR_BIT(SPCR,SPR0);
	               CLEAR_BIT(SPCR,SPR1);
	               SET_BIT(SPSR,SPI2X);
               #elif SCK_FREQUENCY   == PRESC_8_MODE
	               SET_BIT(SPCR,SPR0);
	               CLEAR_BIT(SPCR,SPR1);
	               SET_BIT(SPSR,SPI2X);
               #elif SCK_FREQUENCY   == PRESC_32_MODE
	               CLEAR_BIT(SPCR,SPR0);
	               SET_BIT(SPCR,SPR1);
	               SET_BIT(SPSR,SPI2X);
               #elif SCK_FREQUENCY   == PRESC_64_MODE
	               SET_BIT(SPCR,SPR0);
	               SET_BIT(SPCR,SPR1);
	               SET_BIT(SPSR,SPI2X);
            #endif


     #elif SPI_MODE   == SLAVE              //slave mode
	     CLEAR_BIT(SPCR,MSTR);              //select SLAVE mode
     #endif

	     SET_BIT(SPCR,SPE);
 }
   void MSPI_voidSendData(u8 Copy_u8Data)
    {
	   SPDR = Copy_u8Data;
	   while(GET_BIT(SPSR,SPIF)==0);
	  /* SPDR = Copy_u8Data;
	   while(GET_BIT(SPSR,7)==0);
	   //SET_BIT(SPSR,7);*/
	}
  u8 MSPI_u8ReceiveData(void)
  {
	  while(GET_BIT(SPSR,SPIF)==0);
	  return SPDR;
  }
  void MSPI_voidSET_INTERRUPT(void)
  {
	  SET_BIT(SPCR,SPIE);
  }
