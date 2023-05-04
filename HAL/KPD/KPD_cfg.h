/*
 * KPD_cfg.h
 *
 *  Created on: Mar 25, 2023
 *      Author: User
 */

#ifndef HAL_KPD_KPD_CFG_H_
#define HAL_KPD_KPD_CFG_H_

#define  KPD_POR           PORTC


#define KPD_ROW0_PIN        PIN0
#define KPD_ROW1_PIN        PIN1
#define KPD_ROW2_PIN        PIN2
#define KPD_ROW3_PIN        PIN3


#define KPD_COL0_PIN        PIN4
#define KPD_COL1_PIN        PIN5
#define KPD_COL2_PIN        PIN6
#define KPD_COL3_PIN        PIN7

#define COL_NUM              4
#define ROW_NUM              4

#define KPD_BUTTON_VALUE  {{'0','1','2','+'},{'4','5','6','-'},{'7','8','9','*'},{'=','0','/','='}}
#define KPD_BUTTON_VALUE2  {{1,2,3,'+'},{4,5,6,'-'},{7,8,9,'/'},{'0',0,'*','='}};


#endif /* HAL_KPD_KPD_CFG_H_ */
