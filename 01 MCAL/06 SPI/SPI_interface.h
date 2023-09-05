/*
 * SPI_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
/***
 * initializes SPI peripheral in master mode based on the selected config, returns void
 * INPUT: (u8) slave selection port, (u8) slave selection pin
 * OUTPUT: void
 * Returns: void
 * **/
void MSPI_voidMasterInit(u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin);
/***
 * initializes SPI peripheral in slave mode based on the selected config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MSPI_voidSlaveInit(void);
/***
 * Sends a byte and reads the buffer in master mode, returns void
 * INPUT: (u8*) pointer to the data to be sent and to store the buffer, (u8) slave selection port, (u8) slave selection pin
 * OUTPUT: (u8) date received
 * Returns: void
 * **/
void MSPI_voidMasterTransmitReceive(u8 *cpy_u8Data,u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin);
/***
 * Sends a byte and reads the buffer in slave mode, returns void
 * INPUT: (u8*) pointer to the data to be sent and to store the buffer
 * OUTPUT: (u8) date received
 * Returns: void
 * **/
void MSPI_voidSlaveTransmitReceive(u8 *cpy_u8Data);

#endif
