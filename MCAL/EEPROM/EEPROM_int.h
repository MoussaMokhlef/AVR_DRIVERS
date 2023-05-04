/*
 * EEPROM_int.h
 *
 *  Created on: Apr 9, 2023
 *      Author: User
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_



 void EEPROM_voidInit(void);
 void EEPROM_voidWriteData(u16 Copy_u16Addrse,u8 Copy_u8Data);
// void  EEPROM_u8Read(u16 Copy_u16Addrse, u8* Copy_u8Data);
 u8 EEPROM_voidReadData(u16 Copy_u16Addrse);

#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
