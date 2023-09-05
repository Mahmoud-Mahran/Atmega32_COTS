/*
 * TWI_config.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H
//choose twi clock prescaler
/*options:
 * PRE_1   //(Fosc/1)
 * PRE_4   //(Fosc/4)
 * PRE_16  //(Fosc/16)
 * PRE_64  //(Fosc/64)
 * */
#define PRESCALER         PRE_4
//Enable or disable Acknowledge generation
//options: { ENABLE, DISABLE }
#define GENERATE_ACK      ENABLE
//Enable or disable interrupts
//options: { ENABLE, DISABLE }
#define INTERRUPTS        DISABLE
//Enable or disable Response to general call
//options: { ENABLE, DISABLE }
#define GENERAL_CALL      DISABLE
//set MCU and TWI working frequencies (in hz)
#define F_CPU             8000000UL
#define FREQ              100000UL

#endif
