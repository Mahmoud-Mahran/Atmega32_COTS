/*
 * ADC_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef  ADC_INTERFACE_H_
#define  ADC_INTERFACE_H_
/***
 * initializes ADC peripheral based on the selected config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MADC_voidInit(void);
/***
 * Starts ADC conversion, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MADC_voidStartConversion(void);
/***
 * Assigns the ADC conversion result to a u16 pointer, usually used with interrupt mode, returns void
 * INPUT: void
 * OUTPUT: (u16*) ADC conversion
 * Returns: void
 * **/
void MADC_voidGetConversion(u16 *data);
/***
 * Assigns the ADC conversion result to a u16 pointer, busy-waits for conversion flag(blocking)
(usually used with non-interrupt mode), returns void
 * INPUT: void
 * OUTPUT: (u16*) ADC conversion
 * Returns: void
 * **/
void MADC_voidGetConversionBlocking(u16 *data);
/***
 * sets the callback function (to be called in the ADC ISR) to the passed pointer, returns void
 * INPUT: (*ptr_func) pointer to the function you want to execute when the ADC interrupt fires
 * OUTPUT: void
 * Returns: void
 * **/
void MADC_voidSetCallback(void (*ptfnc)(void));

#endif
