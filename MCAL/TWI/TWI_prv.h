/*
 * TWI_prv.h
 *
 *  Created on: Apr 8, 2023
 *      Author: User
 */

#ifndef MCAL_TWI_TWI_PRV_H_
#define MCAL_TWI_TWI_PRV_H_


#define TWCR           *((volatile u8 *)0x56)
#define TWDR           *((volatile u8 *)0x23)
#define TWAR           *((volatile u8 *)0x22)
#define TWSR           *((volatile u8 *)0x21)
#define TWBR           *((volatile u8 *)0x20)

      //TWBR
#define        TWBR0               0
#define        TWBR1               1
#define        TWBR2               2
#define        TWBR3               3
#define        TWBR4               4
#define        TWBR5               5
#define        TWBR6               6
#define        TWBR7               7

      //TWCR
#define        TWIE               0
#define        TWEN               2
#define        TWWC               3
#define        TWSTO              4
#define        TWSTA              5
#define        TWEA               6
#define        TWINT              7

      //TWSR
#define        TWPS0               0
#define        TWPS1               1
#define        TWS3                3
#define        TWS4                4
#define        TWS5                5
#define        TWS6                6
#define        TWS7                7

      //TWDR
#define        TWD0               0
#define        TWD1               1
#define        TWD2               2
#define        TWD3               3
#define        TWD4               4
#define        TWD5               5
#define        TWD6               6
#define        TWD7               7

      //TWAR
#define        TWGCE              0
#define        TWA0               1
#define        TWA1               2
#define        TWA2               3
#define        TWA3               4
#define        TWA4               5
#define        TWA5               6
#define        TWA6               7

      //Status Codes for Master Transmitter Mode
#define        START_T_ACK                             0x08
#define        REPEADED_T_START_ACK                    0x10
#define        MASTER_ACK_T_RECEIVED                   0x18
#define        MASTER_NACK_T_RECEIVED                  0x20
#define        MASTER_ACK_T_RECEIVED_DATA              0x28
#define        MASTER_NACK_T_RECEIVED_DATA             0x30
#define        ARBITRATION_T_LOST                      0x38

      //Status Codes for Master Receiver Mode
#define        START_R_ACK                             0x08
#define        REPEADED_R_START_ACK                    0x10
#define        ARBITRATION_R_LOST                      0x38
#define        MASTER_ACK_R_RECEIVED                   0x40
#define        MASTER_NACK_R_RECEIVED                  0x48
#define        MASTER_ACK_R_RECEIVED_DATA              0x50
#define        MASTER_NACK_R_RECEIVED_DATA             0x58

#define        Own_SLA_W_Ack                           0x60          /* Means Slave Address is Receive with write request */
#define        Own_SLA_R_Ack                           0xA8          /* Means Slave Address is Receive with Read request */
#define	       Arb_Loss_SLA_RW_Own_SLA_W_Ack           0x68
#define	       Gen_Call_R_Ack                          0x70
#define	       Arb_Loss_SLA_RW_Gen_Call_R_Ack          0x78
#define	       SLAVE_DATA_RECEIVED                     0x80       /* means that the byte is received */
#define	       SLAVE_DATA_TRANSMITED                   0xB8     /* means that the byte is Transmitted */

#endif /* MCAL_TWI_TWI_PRV_H_ */
