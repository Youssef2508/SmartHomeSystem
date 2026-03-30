/******************************************************************************
 *
 * Module: LED Driver
 *
 * File Name: led_driver.h
 *
 * Description: Header file for controlling Red, Green, and Blue LEDs based on light intensity.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LED Pins Configurations: Adjust to match your microcontroller port/pin assignments */
#define RED_LED_PORT_ID      PORTB_ID
#define GREEN_LED_PORT_ID    PORTB_ID
#define BLUE_LED_PORT_ID     PORTB_ID

#define RED_LED_PIN_ID       PIN5_ID
#define GREEN_LED_PIN_ID     PIN6_ID
#define BLUE_LED_PIN_ID      PIN7_ID

/* LED Logic Configuration:
 * 0 = Negative Logic (Turn ON LED by setting pin low, Turn OFF by setting pin high)
 * 1 = Positive Logic (Turn ON LED by setting pin high, Turn OFF by setting pin low)
 */
#define LED_LOGIC_TYPE       1  /* 0: Negative Logic, 1: Positive Logic */

/* LED ID enumeration for function readability */
typedef enum
{
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the LED pins (red, green, blue) as output pins and turns off all LEDs.
 */
void LEDS_init(void);

/*
 * Description:
 * Turns on the specified LED based on the provided LED ID.
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Turns off the specified LED based on the provided LED ID.
 */
void LED_off(LED_ID id);

#endif /* LED_DRIVER_H_ */
