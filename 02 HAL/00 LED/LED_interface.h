/*
 * LED_interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
//helper macros for error handling
#define LED_OK					222
#define LED_OPERATION_FAILED	220
//struct to store led attributes
typedef struct LEDS{
	u8 port;
	u8 pin;
	u8 state;
}LEDS;
/*function that takes a "LEDS" struct and returns an int for error handling 
initializes led according to given arguments */
u8 HLED_init(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns on led */
u8 HLED_on(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns off led */
u8 HLED_off(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
toggles led */
u8 HLED_toggle(LEDS *led);






#endif /* LED_H_ */
