/******************************************************************************
 *
 * Module: LDR Sensor
 *
 * File Name: ldr_sensor.c
 *
 * Description: Source file for the LDR (Light Dependent Resistor) sensor driver.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#include "ldr_sensor.h"
#include "adc.h" /* Use the ADC driver to read the analog values */
#include <util/delay.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for reading the light intensity using the LDR sensor.
 * It reads the ADC value, converts it to a percentage (0 to 100%), and returns the light intensity.
 */
uint16 LDR_getLightIntensity(void)
{
    uint16 adc_value = 0;
    uint16 light_intensity = 0;

    /* Read the ADC value from the specified channel (LDR_SENSOR_CHANNEL_ID) */
    adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /* Make delay for a short time until ADC value is stable */
    _delay_ms(5);

    /* Calculate the light intensity as a percentage:
     * light_intensity = (adc_value / max_adc_value) * LDR_SENSOR_MAX_LIGHT_INTENSITY
     * where max_adc_value = (LDR_SENSOR_MAX_VOLT_VALUE / ADC_REF_VOLT_VALUE) * ADC_MAXIMUM_VALUE
     */
    light_intensity = (uint16)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE) /
                              (LDR_SENSOR_MAX_VOLT_VALUE * ADC_MAXIMUM_VALUE));

    /* Return the calculated light intensity */
    return light_intensity;
}
