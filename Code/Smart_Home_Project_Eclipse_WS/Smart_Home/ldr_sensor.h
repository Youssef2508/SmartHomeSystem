/******************************************************************************
 *
 * Module: LDR Sensor
 *
 * File Name: ldr_sensor.h
 *
 * Description: Header file for the LDR (Light Dependent Resistor) sensor driver.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LDR_SENSOR_CHANNEL_ID            0    /* ADC channel 0 for LDR */
#define LDR_SENSOR_MAX_VOLT_VALUE        2.56 /* Maximum voltage when exposed to darkness */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY   100  /* Maximum light intensity percentage (0% - 100%) */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for reading the light intensity using the LDR sensor.
 * It reads the ADC value, converts it to a percentage (0 to 100%), and returns the light intensity.
 */
uint16 LDR_getLightIntensity(void);


#endif /* LDR_SENSOR_H_ */
