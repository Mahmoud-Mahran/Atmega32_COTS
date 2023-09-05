/*
 * EXTI_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
/***
 * initializes External interrupts according to the choosen config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MEXTI_voidInit(void);
/***
 * sets the call back function for interrupt 0, returns void
 * INPUT: (*ptfc) the function to be called when the interrupt fires
 * OUTPUT: void
 * Returns: void
 * **/
void MEXTI_voidSetInt0Callback(void (*ptfc) (void));
/***
 * sets the call back function for interrupt 1, returns void
 * INPUT: (*ptfc) the function to be called when the interrupt fires
 * OUTPUT: void
 * Returns: void
 * **/
void MEXTI_voidSetInt1Callback(void (*ptfc) (void));
/***
 * sets the call back function for interrupt 2, returns void
 * INPUT: (*ptfc) the function to be called when the interrupt fires
 * OUTPUT: void
 * Returns: void
 * **/
void MEXTI_voidSetInt2Callback(void (*ptfc) (void));



#endif
