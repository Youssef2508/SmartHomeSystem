/******************************************************************************
 *  ADC_Driver.c
 *
 *  Created on: Sep 28, 2024
 *  Author: Youssef Hassan
 *******************************************************************************/

#include "common_macros.h"
#include <avr/io.h>
#include "adc.h"

void ADC_init(void)
{
    /* ADMUX Register Bits Description:
     * REFS1:0 = 11 to choose internal 2.56V as reference voltage
     * ADLAR   = 0 (right-adjusted result)
     * MUX4:0  = 00000 (channel 0 as default for initialization)
     */
    ADMUX = (1 << REFS1) | (1 << REFS0);

    /* ADCSRA Register Bits Description:
     * ADEN    = 1 (Enable ADC)
     * ADIE    = 0 (Disable ADC interrupt)
     * ADATE   = 0 (Disable Auto Trigger)
     * ADPS2:0 = 111 (Prescaler = F_CPU/128, ensuring ADC clock is within 50-200kHz)
     */
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16 ADC_readChannel(uint8 ch_num)
{
    /* Clear the first 5 bits of ADMUX (MUX4:0) to select the correct channel */
    ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);

    /* Start conversion by setting ADSC bit */
    SET_BIT(ADCSRA, ADSC);

    /* Wait for the conversion to complete (ADIF becomes '1') */
    while (BIT_IS_CLEAR(ADCSRA, ADIF));

    /* Clear ADIF by writing '1' to it */
    SET_BIT(ADCSRA, ADIF);

    /* Return the converted digital value */
    return ADC;
}
