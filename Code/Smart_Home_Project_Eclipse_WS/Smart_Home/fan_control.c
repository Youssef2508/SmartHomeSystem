/******************************************************************************
 *
 * Module: Fan Control
 *
 * File Name: fan_control.c
 *
 * Description: Controls fan speed based on temperature using PWM driver
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "pwm.h"
#include "gpio.h"
#include "fan_control.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Controls the fan speed based on the temperature measured by the LM35 sensor.
 */
void FanControl(void)
{
    uint8 temperature = LM35_getTemperature();

    /* Control fan speed based on temperature thresholds */
    if (temperature >= 40)
    {
        /* Set fan speed to 100% */
        PWM_Timer0_Start(100);
    }
    else if (temperature >= 35 && temperature < 40)
    {
        /* Set fan speed to 75% */
        PWM_Timer0_Start(75);
    }
    else if (temperature >= 30 && temperature < 35)
    {
        /* Set fan speed to 50% */
        PWM_Timer0_Start(50);
    }
    else if (temperature >= 25 && temperature < 30)
    {
        /* Set fan speed to 25% */
        PWM_Timer0_Start(25);
    }
    else
    {
        /* Turn off the fan (0% speed) */
        PWM_Timer0_Start(0);
    }
}
