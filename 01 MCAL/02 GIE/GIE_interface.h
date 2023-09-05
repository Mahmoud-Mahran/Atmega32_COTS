/*
 * GIE_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef _GIE_INTERFACE_H_
#define _GIE_INTERFACE_H_
/***
 * Enables global interrupts, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MGIE_voidEnableGI(void);
/***
 * Disables global interrupts, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MGIE_voidDisableGI(void);
#endif
