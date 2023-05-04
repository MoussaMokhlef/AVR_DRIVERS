/*
 * SPI_int.h
 *
 *  Created on: Apr 6, 2023
 *      Author: User
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

#define          MASTER       0
#define          SLAVE        1

#define          LSB          0
#define          MSB1          1

#define          IDLE_LOW     0
#define          IDLE_HIGH    1


#define          SAMPLE_FIRST  0
#define          SETUP_FIRST   1

#define          PRESC_4_MODE       0
#define          PRESC_16_MODE      1
#define          PRESC_64_MODE      2
#define          PRESC_128_MODE     3
#define          PRESC_2_MODE       4
#define          PRESC_8_MODE       5
#define          PRESC_32_MODE      6
//#define          PRESC_64_MODE      7


void MSPI_voidInit(void);
void MSPI_voidSendData(u8 Copy_u8Data);
u8 MSPI_u8ReceiveData(void);

#endif /* MCAL_SPI_SPI_INT_H_ */
