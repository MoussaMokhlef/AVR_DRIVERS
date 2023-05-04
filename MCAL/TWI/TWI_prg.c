
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "TWI_cfg.h"
#include "TWI_int.h"
#include "TWI_prv.h"


  void MTWI_voidMASTERInit(u8 Copy_u8_Addresse)
  {
       //Bit Rate Register
	   //assuming SCL freq=400000
	   //and CPU CLK =8000000
	  TWBR = 2;
	  //select prescaler value=0
	  CLEAR_BIT(TWSR,TWPS0);
	  CLEAR_BIT(TWSR,TWPS1);
      //initiate addrese of master
	  TWAR = Copy_u8_Addresse<<1;
      // TWI Enable Acknowledge
	  SET_BIT(TWCR,TWEA);
	  //enable TWI interrupt
	  SET_BIT(TWCR,TWEN);

  }
   void MTWI_voidSLAVE_Init(u8 Copy_u8_Addresse)
   {
	      //initiate addrese of slave
		  TWAR = Copy_u8_Addresse<<1;
		  // TWI Enable Acknowledge
		  SET_BIT(TWCR,TWEA);
		  //enable TWI interrupt
		  SET_BIT(TWCR,TWEN);

   }

   TWI_TYPES_ERROR MTWI_voidSend_Start_condition(void)
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   //start TWI Condition
	   SET_BIT(TWCR,TWSTA);
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
     if((TWSR & 0xf8)!=START_T_ACK)
     {
    	 Local_Status_Error = START_CONDITION_ERROR;
     }
     else
  	     {
  	    	 //DO NOTHING
  	     }
     return Local_Status_Error;
   }
   TWI_TYPES_ERROR MTWI_voidSend_RepeatedStart_condition(void)
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   //Repeated start TWI Condition
	   SET_BIT(TWCR,TWSTA);
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
	     if((TWSR & 0xf8)!=REPEADED_T_START_ACK)
	     {
	    	 Local_Status_Error = RE_START_CONDITION_ERROR;
	     }
	     else
	     {
	    	 //DO NOTHING
	     }
	     return Local_Status_Error;
   }
   TWI_TYPES_ERROR MTWI_voidSendAddresse_Write(u8 Copy_u8Addresse)
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   //send addrese of slave to write
	   TWDR = (Copy_u8Addresse<<1);
	   //clear TWD0 Bit to write
	   CLEAR_BIT(TWDR,TWD0);
	   //Clear start condition
	   CLEAR_BIT(TWCR,TWSTA);
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
	     if((TWSR & 0xf8)!=Own_SLA_W_Ack)
	     {
	    	 Local_Status_Error = SLAVE_ADDRESSE_WRITE_ERROR;
	     }
	     else
	     {
	    	 //DO NOTHING
	     }
	     return Local_Status_Error;

   }
   TWI_TYPES_ERROR MTWI_voidSendAddresse_Read(u8 Copy_u8Addresse)
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   //send addrese of slave to Read
	   TWDR = Copy_u8Addresse<<1;
	   //set Bit TWD0 to Read
	   SET_BIT(TWDR,TWD0);
	   CLEAR_BIT(TWCR,TWSTA);
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
	     if((TWSR & 0xf8)!=Own_SLA_R_Ack)
	     {
	    	 Local_Status_Error = SLAVE_ADDRESSE_READ_ERROR;
	     }
	     else
	     {
	    	 //DO NOTHING
	     }
	     return Local_Status_Error;


   }
   TWI_TYPES_ERROR MTWI_MASTER_WriteData(u8 Copy_u8Data)
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   TWDR = Copy_u8Data;
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
	     if((TWSR & 0xf8)!=MASTER_ACK_T_RECEIVED_DATA)
	     {
	    	 Local_Status_Error = MASTER_WRITE_ERROR;
	     }
	     else
	     {
	    	 //DO NOTHING
	     }
	     return Local_Status_Error;

   }
   u8 MTWI_MASTER_ReadData()
   {
	   TWI_TYPES_ERROR  Local_Status_Error=NO_ERROR;
	   u8 ptr_u8Data;
	   //Clear interrupt flag
	   SET_BIT(TWCR,TWINT);
	   //waiting interrupt flag set
	   while(!(TWCR&(1<<TWINT)));
	   ptr_u8Data=TWDR;


	     if((TWSR & 0xf8)!=MASTER_ACK_R_RECEIVED_DATA)
	     {
	    	 Local_Status_Error = SLAVE_ADDRESSE_READ_ERROR;
	     }
	     else
	     {

	     }
	     return  ptr_u8Data;


   }
   void MTWI_voidSendStopCondition(void)
   {
	   SET_BIT(TWCR,TWSTO);
	   SET_BIT(TWCR,TWINT);

   }
