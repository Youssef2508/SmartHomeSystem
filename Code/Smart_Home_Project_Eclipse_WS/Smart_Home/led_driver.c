/******************************************************************************
 *
 * Module: LED Driver
 *
 * File Name: led_driver.c
 *
 * Description: Source file for controlling Red, Green, and Blue LEDs.
 *
 * Author: Youssef Hassan
 *
 *******************************************************************************/

#include "led_driver.h"
#include "gpio.h" /* Use the GPIO driver for setting pins as output */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the LED pins as output pins and turns off all the LEDs.
 */
void LEDS_init(void)
{
    /* Initialize all LED pins as output */
    GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

    /* Turn off all LEDs initially */
    LED_off(RED_LED);
    LED_off(GREEN_LED);
    LED_off(BLUE_LED);
}

/*
 * Description:
 * Turns on the specified LED based on the provided LED ID.
 */
void LED_on(LED_ID id)
{
    switch (id)
    {
        case RED_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);  /* Positive Logic */
            } else {
                GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);   /* Negative Logic */
            }
            break;

        case GREEN_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);  /* Positive Logic */
            } else {
                GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);   /* Negative Logic */
            }
            break;

        case BLUE_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);  /* Positive Logic */
            } else {
                GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);   /* Negative Logic */
            }
            break;
    }
}

/*
 * Description:
 * Turns off the specified LED based on the provided LED ID.
 */
void LED_off(LED_ID id)
{
    switch (id)
    {
        case RED_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);  /* Positive Logic */
            } else {
                GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH); /* Negative Logic */
            }
            break;

        case GREEN_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);  /* Positive Logic */
            } else {
                GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH); /* Negative Logic */
            }
            break;

        case BLUE_LED:
            if (LED_LOGIC_TYPE == 1) {
                GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);  /* Positive Logic */
            } else {
                GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH); /* Negative Logic */
            }
            break;
    }
}
