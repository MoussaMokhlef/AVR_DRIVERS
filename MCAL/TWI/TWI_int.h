/*
 * TWI_int.h
 *
 *  Created on: Apr 8, 2023
 *      Author: User
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

typedef enum
{
    NO_ERROR,
	START_CONDITION_ERROR,
	RE_START_CONDITION_ERROR,
	MASTER_WRITE_ERROR,
	MASTER_READ_ERROR,
	SLAVE_ADDRESSE_WRITE_ERROR,
	SLAVE_ADDRESSE_READ_ERROR,
}TWI_TYPES_ERROR;


 void MTWI_voidMASTERInit(u8 Copy_u8_Addresse);
 void MTWI_voidSLAVE_Init(u8 Copy_u8_Addresse);
 TWI_TYPES_ERROR MTWI_voidSend_Start_condition(void);
 TWI_TYPES_ERROR MTWI_voidSend_RepeatedStart_condition(void);
 TWI_TYPES_ERROR MTWI_voidSendAddresse_Write(u8 Copy_u8Addresse);
 TWI_TYPES_ERROR MTWI_voidSendAddresse_Read(u8 Copy_u8Addresse);
 TWI_TYPES_ERROR MTWI_MASTER_WriteData(u8 Copy_u8Data);
 u8 MTWI_MASTER_ReadData();
 void MTWI_voidSendStopCondition(void);

#endif /* MCAL_TWI_TWI_INT_H_ */
