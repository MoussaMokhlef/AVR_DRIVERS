/*
 * USART_prv.h
 *
 *  Created on: Apr 5, 2023
 *      Author: User
 */

#ifndef MCAL_USART_USART_PRV_H_
#define MCAL_USART_USART_PRV_H_

#define           UDR                        *((volatile u16*)0x2C)
#define           UCSRA                      *((volatile u8*)0x2B)
#define           UCSRB                      *((volatile u8*)0x2A)
#define           UCSRC                      *((volatile u8*)0x3F)
#define           UBRRL                      *((volatile u8*)0x29)
#define           UBRRH                      *((volatile u8*)0x3F)

          //UCSRA
#define           MPCM                       0
#define           U2X                        1
#define           PE                         2
#define           DOR                        3
#define           FE                         4
#define           UDRE                       5
#define           TXC                        6
#define           RXC                        7

          //UCSRB
#define           TXB8                       0
#define           RXB8                       1
#define           UCSZ2                      2
#define           TXEN                       3
#define           RXEN                       4
#define           UDRIE                      5
#define           TXCIE                      6
#define           RXCIE                      7

          //UCSRC
#define           UCPOL                      0
#define           UCSZ0                      1
#define           UCSZ1                      2
#define           USBS                       3
#define           UPM0                       4
#define           UPM1                       5
#define           UMSEL                      6
#define           URSEL                      7



#endif /* MCAL_USART_USART_PRV_H_ */
