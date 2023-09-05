/*
 * EXTI_config.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef  _EXTI_CONFIG_H_
#define  _EXTI_CONFIG_H_
//enable or disable interrupts
//options: { DISABLE, ENABLE }
#define  EXTI_INT0			ENABLE
#define  EXTI_INT1      	DISABLE
#define  EXTI_INT2      	DISABLE
//choose interrupt mode for external interrupts 0 & 1
//options: { FALLING_EDGE, RISING_EDGE, LOW_LEVEL, LOGICAL_CHANGE }
#define  SENSE_MODE_INT0 	FALLING_EDGE
#define  SENSE_MODE_INT1 	FALLING_EDGE
//choose interrupt mode for external interrupt 2
//options: { FALLING_EDGE_INT2, RISING_EDGE_INT2 }
#define  SENSE_MODE_INT2 	FALLING_EDGE_INT2

#endif
