/*
 * UART_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H
/***
 * initializes UART peripheral based on the selected config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MUART_voidInit(void);
/***
 * sends an input byte, returns void
 * INPUT: (u8) byte to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void MUART_voidTX_Byte(u8 u8cpyData);
/***
 * receives a byte, returns void
 * INPUT: (u8*) pointer to the byte to be received
 * OUTPUT: (u8) received byte
 * Returns: void
 * **/
void MUART_voidRX_Byte(u8 *u8Data);


#endif
