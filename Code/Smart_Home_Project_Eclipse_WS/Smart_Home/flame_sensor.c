/******************************************************************************
 *
 * Module: Flame Sensor Driver
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the Flame Sensor Driver that detects fire incidents.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#include "flame_sensor.h"
#include "gpio.h" /* GPIO driver for pin configuration and reading */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the flame sensor pin direction as an input pin.
 */
void FlameSensor_init(void)
{
    /* Set the flame sensor pin as an input pin */
    GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Description:
 * Reads the value from the flame sensor. If fire is detected, the function will return '1',
 * otherwise '0'.
 *
 * Returns:
 * 1 - Fire detected.
 * 0 - No fire detected.
 */
uint8 FlameSensor_getValue(void)
{
    /* Read the value from the flame sensor pin */
    return GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}
