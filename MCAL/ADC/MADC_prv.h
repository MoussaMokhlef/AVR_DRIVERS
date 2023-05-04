/*
 * HADC_prv.h
 *
 *  Created on: Apr 1, 2023
 *      Author: User
 */

#ifndef HAL_ADC_HADC_PRV_H_
#define HAL_ADC_HADC_PRV_H_

#define           ADC_ADMUX                    *((volatile u8*)0x27)
#define           ADC_ADCSRA                   *((volatile u8*)0x26)
#define           ADC_ADCL                     *((volatile u8*)0x24)
#define           ADC_ADCH                     *((volatile u8*)0x25)
#define           ADC_SFIOR                    *((volatile u8*)0x50)
#define           ADC_ADC                      *((volatile u16*)0x24)

#define           ADC_BIT_EN                   7
#define           ADC_BIT_ST                   6
#define           ADC_BIT_interrupt_flag       4
#define           ADC_BIT_PRESCALER_0          0
#define           ADC_BIT_PRESCALER_1          1
#define           ADC_BIT_PRESCALER_2          2
#define           ADC_BIT_VOLT_REF0            6
#define           ADC_BIT_VOLT_REF1            7
#define           ADC_BIT_ADLAR                5
#define           ADC_BIT_ADC0                 0
#define           ADC_BIT_ADC1                 1
#define           ADC_BIT_ADC2                 2
#define           ADC_BIT_ADC3                 3
#define           ADC_BIT_ADC4                 4
#define           ADATE                        5
#define           ADIF                         4
#define           ADIE                         3


#endif /* HAL_ADC_HADC_PRV_H_ */
