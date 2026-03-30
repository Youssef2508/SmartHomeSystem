/******************************************************************************
 *
 * Module: Flame Sensor Driver
 *
 * File Name: flame_sensor.h
 *
 * Description: Header file for the Flame Sensor Driver that detects fire incidents.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Flame Sensor Pin Configuration:
 * The flame sensor is connected to a specific port and pin, which can be configured here.
 */
#define FLAME_SENSOR_PORT_ID          PORTD_ID
#define FLAME_SENSOR_PIN_ID           PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the flame sensor pin direction as an input pin.
 */
void FlameSensor_init(void);

/*
 * Description:
 * Reads the value from the flame sensor. If fire is detected, the function will return '1',
 * otherwise '0'.
 *
 * Returns:
 * 1 - Fire detected.
 * 0 - No fire detected.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
