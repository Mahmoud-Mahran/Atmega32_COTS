/*
 * TWI_private.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H


#define TWBR            *((volatile u8*)0x20)//TWI Bit Rate Register
#define TWCR            *((volatile u8*)0x56)//TWI Control Register
#define TWINT           7                    //TWI Interrupt Flag
#define TWEA            6                    //TWI Enable Acknowledge Bit
#define TWSTA           5                    //TWI START Condition Bit
#define TWSTO           4                    //TWI STOP Condition Bit
#define TWWC            3                    //TWI Write Collision Flag
#define TWEN            2                    //TWI Enable Bit
#define TWIE            0                    //TWI Interrupt Enable
#define TWSR            *((volatile u8*)0x21)
#define TWPS1           1                    //TWI Prescaler Bit 1
#define TWPS0           0                    //TWI Prescaler Bit 0
#define TWDR            *((volatile u8*)0x23)
#define TWAR            *((volatile u8*)0x22)
#define TWGCE           0                    //TWI General Call Recognition Enable Bit

#define PRE_1           0
#define PRE_4           1
#define PRE_16          2
#define PRE_64          3

#define ENABLE          1
#define DISABLE         0
#endif
