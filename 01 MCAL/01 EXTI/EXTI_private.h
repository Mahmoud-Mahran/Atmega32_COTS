/*
 * EXTI_private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define GICR        *((volatile u8 *)0x5B)
#define IVCE		0						//Interrupt Vector Select
#define IVSEL		1						//Interrupt Vector Change Enable
#define INT2		5						//External Interrupt Request 2 Enable
#define INT0		6						//External Interrupt Request 0 Enable
#define INT1		7						//External Interrupt Request 1 Enable
#define GIFR        *((volatile u8 *)0x5A)
#define INTF2		5						//External Interrupt Flag 2
#define INTF0		6						//External Interrupt Flag 0
#define INTF1		7						//External Interrupt Flag 1
#define MCUCR       *((volatile u8 *)0x55)
#define ISC00		0                       // Interrupt Sense Control 0 bit 0
#define ISC01		1                       // Interrupt Sense Control 0 bit 1
#define ISC10		2						// Interrupt Sense Control 1 bit 0
#define ISC11		3						// Interrupt Sense Control 1 bit 1
#define MCUCSR      *((volatile u8 *)0x54)
#define ISC2		6                       //  Interrupt Sense Control 2

#define ENABLE				1
#define DISABLE				0

#define FALLING_EDGE		2
#define RISING_EDGE		    3
#define LOW_LEVEL		    0
#define LOGICAL_CHANGE		1

#define FALLING_EDGE_INT2	0
#define RISING_EDGE_INT2	1

void __vector_1(void) __attribute__ ((signal,used));
void __vector_2(void) __attribute__ ((signal,used));
void __vector_3(void) __attribute__ ((signal,used));
#endif
