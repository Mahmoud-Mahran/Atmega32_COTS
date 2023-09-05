/*
 * TWI_interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H
/***
 * initializes TWI peripheral in master mode based on the selected config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidInitMaster(void);
/***
 * Sends a start condition (master mode), returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidSendStart(void);
/***
 * Sends a repeated start condition (master mode), returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidSendRepeatedStart(void);
/***
 * Sends a slave address to communicate with (master mode), returns void
 * INPUT: (u8) address of the slave, (u8) mode of operation(write/read)
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidSendSlaveAddress(u8 cpy_u8Address, u8 cpy_u8Mode);
/***
 * Sends/receives a byte to/from the slave (master mode), returns void
 * INPUT: (u8*) pointer to the data (to be sent/to be received), (u8) mode of operation(write/read)
 * OUTPUT: (u8) received data(in read mode)
 * Returns: void
 * **/
void MTWI_voidMasterData(u8 *u8Byte, u8 cpy_u8Mode);
/***
 * Sends a stop condition (master mode), returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidSendStop(void);
////////////////////////not yet implemented(currently empty)/////////////////////
/***
 * Sends/receives a byte to/from the master (slave mode), returns void
 * INPUT: (u8*) pointer to the data (to be sent/to be received), (u8) mode of operation(write/read)
 * OUTPUT: (u8) received data(in read mode)
 * Returns: void
 * **/
void MTWI_voidSlaveData(u8 *u8Byte, u8 cpy_u8Mode);
///////////////////////not yet tested////////////////////////
/***
 * Sends a series of chars(String) to the slave (master mode), returns void
 * INPUT: (u8*) pointer to the the 1st char to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidMasterSendString(u8* cpy_string);
///////////////////////not yet tested////////////////////////
/***
 * reads a series of chars(String) from the slave (master mode), returns void
 * INPUT: (u8*) pointer to the the 1st char to be read
 * OUTPUT: void
 * Returns: void
 * **/
void MTWI_voidMasterReadString(u8* cpy_string);

//interfacing macros
#define TWI_WRITE      0
#define TWI_READ       1
#endif
