#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"../TWI/TWI_int.h"
#include<util/delay.h>


#include "EEPROM_cfg.h"
#include "EEPROM_int.h"
#include "EEPROM_prv.h"

 
 void EEPROM_voidInit(void)
 {

 }
/* void EEPROM_voidWrite(u8 Copy_u8Data)
 {
	 EEDR = Copy_u8Data;
	                                       // Write logical one to EEMWE
	 SET_BIT(EECR,EEMWE);
	                                        // Start eeprom write by setting EEWE
	 SET_BIT(EECR,EEWE);
 }

 u8 EEPROM_u8Read(void)
 {
                                           	 // Start eeprom read by writing EERE
	 SET_BIT(EECR,EERE);
	                                         // Return data from data register
	 return EEDR;
 }
*/
  void EEPROM_voidWriteData(u16 Copy_u16Addrse,u8 Copy_u8Data)
  {
	//  u8 Local_u8Value;
	  MTWI_voidSend_Start_condition();
	 // Copy_u16Addrse &= 0xFF;
	 // Local_u8Value= (0b10100000) |(Copy_u16Addrse>>7);
	  //MTWI_voidSendAddresse_Write((10100 |(Copy_u16Addrse>>7))>>1);
	  MTWI_voidSendAddresse_Write(((EEPROM_FIRST_ADDRESSS)|(EEPROM_A2_VALUE << 2))|(Copy_u16Addrse >> 8));
	  MTWI_MASTER_WriteData((u8)Copy_u16Addrse);
	  MTWI_MASTER_WriteData(Copy_u8Data);
	  MTWI_voidSendStopCondition();
	 // _delay_ms(500);

  }
  u8  EEPROM_voidReadData(u16 Copy_u16Addrse)
  {
	  u8  Local_Value;
	  u8 Local_u8Value;
	                                /*Start Condition */
	  MTWI_voidSend_Start_condition();
	                                /*Send Slave Address with write condition */
	  Local_u8Value= ((EEPROM_FIRST_ADDRESSS)|(EEPROM_A2_VALUE << 2))|(Copy_u16Addrse >> 8) ;
	  MTWI_voidSendAddresse_Write(Local_u8Value);
	                                 /*SEND BYTE ADDRESS*/
	  MTWI_MASTER_WriteData((u8)Copy_u16Addrse);

		                            /*SEND REPEATED START CONDITION */
	  MTWI_voidSend_RepeatedStart_condition();
	  MTWI_voidSendAddresse_Read(Local_u8Value);
	  Local_Value= MTWI_MASTER_ReadData();
	  MTWI_voidSendStopCondition();
	  return Local_Value;

  }
