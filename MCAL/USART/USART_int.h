/*
 * USART_int.h
 *
 *  Created on: Apr 5, 2023
 *      Author: User
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_


void MUSART_voidInit(void);
void MUSART_voidSelect_Bout_Rate(u16 Copy_BOUT_RADE);
void MUSART_voidTransmitDataSync(u16 Copy_u8Data);
u16 MUSART_u8ReceiveDataSync(void);
/*
void MUSART_SET_Call_BackTransmitData(void (*ptr)(void));
void MUSART_SET_Call_BackReceiveData(void (*ptr)(void));

*/

u8 MUSART_u8ReceiveDataASync(void);
void MUSART_u8TransmitDataASync(u8 Copy_u8Data);

#endif /* MCAL_USART_USART_INT_H_ */
