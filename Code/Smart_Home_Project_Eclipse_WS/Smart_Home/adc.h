/******************************************************************************
 *  ADC_Driver.h
 *
 *  Created on: Sep 28, 2024
 *  Author: Youssef Hassan
 *******************************************************************************/

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56   /* Updated to 2.56V internal reference */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for initializing the ADC driver.
 */
void ADC_init(void);

/*
 * Description:
 * Function responsible for reading analog data from a specific ADC channel
 * and converting it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_DRIVER_H_ */
