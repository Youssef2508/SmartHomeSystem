/******************************************************************************
 *  Smart_Home.c
 *  Description: Source file for the main application
 *  Created on: Oct 3, 2024
 *  Author: Youssef Hassan
 *******************************************************************************/


#include "lcd.h"               // Include the LCD driver header for displaying information on an LCD.
#include "led_driver.h"        // Include the LED driver header for controlling the LEDs.
#include "dc_motor.h"          // Include the DC motor driver header for fan control.
#include "buzzer.h"            // Include the buzzer driver header for controlling the buzzer.
#include "flame_sensor.h"      // Include the flame sensor driver header to detect flame presence.
#include "ldr_sensor.h"        // Include the LDR driver header for reading light intensity.
#include "lm35_sensor.h"       // Include the LM35 sensor driver header for temperature readings.
#include <util/delay.h>        // Include the delay library to create software delays.
#include <avr/io.h>            // Include input/output library for AVR microcontroller operations.
#include "adc.h"               // Include ADC driver header for reading analog sensors.
#include "pwm.h"               // Include the PWM driver header for Initialize the timer


// Flame sensor debounce time (adjust as necessary)
#define FLAME_DEBOUNCE_DELAY 30  // 50ms debounce delay

volatile unsigned char fire = 0; // Global variable to track flame detection state for debounce.


int main(void) {
    // Initialize hardware components
	Timer0_init();              // Initialize timer0 for PWM mode
	ADC_init();                 // Initialize ADC to read analog sensors like LDR, LM35, and flame sensor.
	LCD_init();                 // Initialize the LCD display.
    LEDS_init();                // Initialize the LEDs.
    DcMotor_Init();             // Initialize the DC motor for fan control.
    Buzzer_init();              // Initialize the buzzer.
    FlameSensor_init();         // Initialize the flame sensor.


    // Main loop
    while (1) {
        uint8 temperature = LM35_getTemperature();         // Read the temperature value from the LM35 sensor.
    	uint16 light_intensity = LDR_getLightIntensity();  // Read the light intensity from the LDR sensor.
        uint8 flame_detected = FlameSensor_getValue();     // Get the flame detection value (1 or 0).



        // Control LED based on light intensity
        if (light_intensity < 15) {
            LED_on(RED_LED);                               // Turn on the RED, GREEN, and BLUE LEDs if light intensity is < 15%.
            LED_on(GREEN_LED);
            LED_on(BLUE_LED);
        } else if (light_intensity <= 50) {
            LED_on(RED_LED);                               // Turn on RED and GREEN, and turn off BLUE if light intensity <= 50%.
            LED_on(GREEN_LED);
            LED_off(BLUE_LED);
        } else if (light_intensity <= 70) {
            LED_on(RED_LED);                               // Turn on RED and turn off GREEN and BLUE if light intensity <= 70%.
            LED_off(GREEN_LED);
            LED_off(BLUE_LED);
        } else {
            LED_off(RED_LED);                              // Turn off all LEDs if light intensity is > 70%.
            LED_off(GREEN_LED);
            LED_off(BLUE_LED);
        }

        // Control fan speed based on temperature
        if (temperature >= 40) {
            DcMotor_Rotate(CW, 100);  // Rotate the motor clockwise at full speed if temperature >= 40°C.
        } else if (temperature >= 35) {
            DcMotor_Rotate(CW, 75);   // Rotate motor at 75% speed if temperature >= 35°C.
        } else if (temperature >= 30) {
            DcMotor_Rotate(CW, 50);   // Rotate motor at 50% speed if temperature >= 30°C.
        } else if (temperature >= 25) {
            DcMotor_Rotate(CW, 25);   // Rotate motor at 25% speed if temperature >= 25°C.
        } else {
            DcMotor_Rotate(STOP, 0);  // Stop the motor if temperature is below 25°C.
        }


        // If flame is detected, sound the buzzer
        if (flame_detected == 1 && fire == 0) {
            Buzzer_on();       // Turn on the buzzer
            fire = 1;
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 1, "Critical Alert!");
        } else if (flame_detected == 0) {
        	if(fire == 1){
        		LCD_clearScreen();
        	}
            _delay_ms(FLAME_DEBOUNCE_DELAY);    // Debouncing to ensure consistent reading
            if (FlameSensor_getValue() == 0) {  // Re-check if flame is still not detected
                Buzzer_off();  // Turn off the buzzer
                fire = 0;
            }
            // Display the fan status on the first row of the LCD
            if (temperature >= 25) {
                LCD_displayStringRowColumn(0, 3, "FAN is ON");  // Display "FAN is ON" if temperature is above 25°C.
                LCD_displayCharacter(' ');                      // Clear any remaining characters on the LCD row.
            } else {
                LCD_displayStringRowColumn(0, 3, "FAN is OFF"); // Display "FAN is OFF" if temperature is below 25°C.
            }

            // Display temperature and light intensity on the second row of the LCD
            LCD_displayStringRowColumn(1, 0, "Temp=");          // Display the label for temperature.
            if(temperature >= 10){
            	LCD_intgerToString(temperature);                // Display the temperature if >= 10°C.
            } else {
            	LCD_intgerToString(temperature);                // Display the temperature if < 10°C.
            	LCD_displayCharacter(' ');                      // Clear any leftover characters.
            }

            LCD_displayStringRowColumn(1, 8, "LDR=");           // Display the label for light intensity (LDR).
            if(light_intensity == 100){
            	LCD_intgerToString(light_intensity);            // Display the LDR value if it's 100%.
            	LCD_displayCharacter('%');                      // Display the percentage symbol.
            } else if(light_intensity >= 10){
            	LCD_intgerToString(light_intensity);            // Display LDR value if it's >= 10%.
            	LCD_displayCharacter(' ');                      // Clear any leftover characters.
            	LCD_displayCharacter('%');
            } else {
            	LCD_intgerToString(light_intensity);            // Display the LDR value if it's < 10%.
            	LCD_displayCharacter(' ');                      // Clear any leftover characters.
            	LCD_displayCharacter(' ');                      // Clear any leftover characters.
            	LCD_displayCharacter('%');                      // Display percentage symbol.
            }
        }
    }
    return 0;
}
