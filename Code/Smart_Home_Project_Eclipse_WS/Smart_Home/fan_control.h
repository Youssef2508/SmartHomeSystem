/******************************************************************************
 *
 * Module: Fan Control
 *
 * File Name: fan_control.h
 *
 * Description: Header file for the Fan Control based on temperature using PWM driver
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#ifndef FAN_CONTROL_H_
#define FAN_CONTROL_H_

/*******************************************************************************
 *                              Includes                                       *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Function that controls the fan speed based on the temperature measured by the LM35 sensor.
 * This function adjusts the PWM duty cycle to change the speed of the fan according to the temperature.
 */
void FanControl(void);

#endif /* FAN_CONTROL_H_ */
