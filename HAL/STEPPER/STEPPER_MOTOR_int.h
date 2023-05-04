/*
 * STEPPER_MOTOR_INT.h
 *
 *  Created on: Mar 29, 2023
 *      Author: User
 */

#ifndef HAL_STEPPER_STEPPER_MOTOR_INT_H_
#define HAL_STEPPER_STEPPER_MOTOR_INT_H_


void HSTEPPER_MOTOR_voidInit(void);

void  HSTEPPER_MOTOR_voidOneRevFullStepCW(void);

void  HSTEPPER_MOTOR_voidOneRevFullStepUNCW(void);

void  HSTEPPER_MOTOR_voidSpecificFullStepCW(u16 Degree);

void  HSTEPPER_MOTOR_voidSpecificFullStepUNCW(u16 Degree);

#endif /* HAL_STEPPER_STEPPER_MOTOR_INT_H_ */
