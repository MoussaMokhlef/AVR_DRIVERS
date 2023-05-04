/*
 * EEPROM_prv.h
 *
 *  Created on: Apr 9, 2023
 *      Author: User
 */

#ifndef MCAL_EEPROM_EEPROM_PRV_H_
#define MCAL_EEPROM_EEPROM_PRV_H_

#define        EEARH           *((volatile u8 *)0x3F)
#define        EEARL           *((volatile u8 *)0x3E)
#define        EEDR            *((volatile u8 *)0x3D)
#define        EECR            *((volatile u8 *)0x3C)

     //EEARL
#define       EEAR0            0
#define       EEAR1            1
#define       EEAR2            2
#define       EEAR3            3
#define       EEAR4            4
#define       EEAR5            5
#define       EEAR6            6
#define       EEAR7            7

     //EEARH
#define       EEAR8            0
#define       EEAR9            1

     //EEDR
#define       LSB              0
#define       MSB              7

     //EECR
#define       EERE             0
#define       EEWE             1
#define       EEMWE            2
#define       EERIE            3

#define EEPROM_FIRST_ADDRESSS  0x50
#endif /* MCAL_EEPROM_EEPROM_PRV_H_ */
