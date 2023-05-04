/*
 * USART_prg.c
 *
 *  Created on: Apr 5, 2023
 *      Author: User
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"
#include"../DIO/DIO_int.h"
#include "USART_cfg.h"
#include "USART_int.h"
#include "USART_prv.h"


static  u8 Global_RX_DATA = '\0';
static  u8 Global_TX_DATA = '\0';

  void MUSART_voidInit(void)
  {
	  SET_BIT(UCSRC,URSEL);       //select regester UCSRC

	  CLEAR_BIT(UCSRC,UMSEL);     //Asynchronous Operation


      #if Parity_Mode == Disabled         //disable parity mode
	      CLEAR_BIT(UCSRC, UPM0);
	      CLEAR_BIT(UCSRC, UPM1);

      #elif Parity_Mode == Even_Parity    //Even_Parity parity mode
	      CLEAR_BIT(UCSRC,UPM0);
	      SET_BIT(UCSRC,UPM1);

      #elif Parity_Mode == Odd_Parity    //Odd_Parity parity mode
	      SET_BIT(UCSRC,UPM0);
	      SET_BIT(UCSRC,UPM1);

      #endif

      #if STOP_BIT_MODE == BIT_1_MODE      //STOP_BIT_MODE one bit
	      CLEAR_BIT(UCSRC,USBS);

      #elif STOP_BIT_MODE == BIT_2_MODE     //STOP_BIT_MODE two bit
	      SET_BIT(UCSRC,USBS);
      #endif

      #if   NUMBER_BITS_DATA == BIT_5_DATA          //mode BIT_5_DATA
	      CLEAR_BIT(UCSRC,UCSZ0);
	      CLEAR_BIT(UCSRC,UCSZ1);
	      CLEAR_BIT(UCSRB,UCSZ2);
      #elif   NUMBER_BITS_DATA == BIT_6_DATA        //mode BIT_6_DATA
	      SET_BIT(UCSRC,UCSZ0);
	      CLEAR_BIT(UCSRC,UCSZ1);
	      CLEAR_BIT(UCSRB,UCSZ2);
      #elif   NUMBER_BITS_DATA == BIT_7_DATA        //mode BIT_7_DATA
	      CLEAR_BIT(UCSRC,UCSZ0);
	      SET_BIT(UCSRC,UCSZ1);
	      CLEAR_BIT(UCSRB,UCSZ2);
      #elif   NUMBER_BITS_DATA == BIT_8_DATA       //mode BIT_8_DATA
	      SET_BIT(UCSRC,UCSZ0);
	      SET_BIT(UCSRC,UCSZ1);
	      CLEAR_BIT(UCSRB,UCSZ2);
      #elif   NUMBER_BITS_DATA == BIT_9_DATA        // mode BIT_9_DATA
	      SET_BIT(UCSRC,UCSZ0);
	      SET_BIT(UCSRC,UCSZ1);
	      SET_BIT(UCSRB,UCSZ2);
       #endif


	      SET_BIT(UCSRB,RXEN);                       //Receiver Enable
	      SET_BIT(UCSRB,TXEN);                       //Transmitter Enable

	      SET_BIT(UCSRB, RXCIE);                     //Enable RX INT



/*	      UBRRH = (unsigned char)(baud>>8);
	      UBRRL = (unsigned char)baud;
	      // Enable receiver and transmitter
	      UCSRB = (1<<RXEN)|(1<<TXEN);
*/

  }

  void MUSART_voidSelect_Bout_Rate(u16 Copy_BOUT_RADE)
  {
      CLEAR_BIT(UBRRH,URSEL) ;                          //to write in UBRRH
	  UBRRH &= 0b11110000;
      UBRRH = (u8)(Copy_BOUT_RADE >> 8);                //SELECT BOUD RATE
      UBRRL = (u8)Copy_BOUT_RADE;
  }

  void MUSART_voidTransmitDataSync(u16 Copy_u8Data)
  {
          #if NUMBER_BITS_DATA   == BIT_9_DATA
			                                            /* Wait for empty transmit buffer */
	          while ( !( UCSRA & (1<<UDRE)) );

			                                             /* Copy 9th bit to TXB8 */
			// UCSRB &= ~(1<<TXB8);
			 CLEAR_BIT(UCSRB,TXB8);
			 if ( Copy_u8Data & 0x0100 )
			// UCSRB |= (1<<TXB8);
			 SET_BIT(UCSRB,TXB8);
			                                             /* Put data into buffer, sends the data */
			 UDR = Copy_u8Data;
          #else
	                                                     /* Wait for empty transmit buffer */
	              while ( !( UCSRA & (1<<UDRE)) );
	                                                     /* Put data into buffer, sends the data */
	              UDR =  Copy_u8Data;
          #endif
  }

  u16 MUSART_u8ReceiveDataSync(void)
  {
	                                                     /* Wait for data to be received */
        #if NUMBER_BITS_DATA   == BIT_9_DATA
          u16 status, resh, resl;
                                                         /* Wait for data to be received */
        while ( !(UCSRA & (1<<RXC)) );

                                                         /* Get status and 9th bit, then data */
                                                         /* from buffer */
          status = UCSRA;
          resh = UCSRB;
          resl = UDR;
                                                                                                                                                                     /* Filter the 9th bit, then return */
          resh = (resh >> 1) & 0x01;
          return ((resh << 8) | resl);

 #else
                                                /* Wait for data to be received */
        while ( !(UCSRA & (1<<RXC)) );
                                                /* Get and return received data from buffer */
        return UDR;

 #endif

  }

 u8 MUSART_u8ReceiveDataASync(void)
  {
	  return Global_RX_DATA;
  }

  void MUSART_u8TransmitDataASync(u8 Copy_u8Data)
  {
	 Global_TX_DATA = Copy_u8Data ;
	  SET_BIT(UCSRB, UDRIE);
  }

  void __vector_13 (void) __attribute__((signal));
  void __vector_13 (void)
  {
	 // u8 status = UCSRA;
	    Global_RX_DATA  = UDR;

	 /* if ( status & ((1<<FE)|(1<<DOR)|(1<<PE) ))
	  	{
		  Global_RX_DATA = '\0';
	  	}*/


  }


  void __vector_14 (void) __attribute__((signal));
  void __vector_14 (void)
  {
	 UDR = Global_TX_DATA;
	 CLEAR_BIT(UCSRB, UDRIE);


  }

