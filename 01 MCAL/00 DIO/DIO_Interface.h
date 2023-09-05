/*
 * DIO_Interface.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
/***
 * initializes the pin based on input arguments, returns an int for error handling
 * INPUT: (u8) port number, (u8) pin number, (u8) mode
 * OUTPUT: void
 * Returns: (int) error state
 * **/
int MDIO_intInit(u8 portNumber, u8 pinNumber, u8 direction);
/***
 * sets the pin value based on input arguments, returns an int for error handling
 * INPUT: (u8) port number, (u8) pin number, (u8) value
 * OUTPUT: void
 * Returns: (int) error state
 * **/
int MDIO_intWrite(u8 portNumber, u8 pinNumber, u8 value);
/***
 * toggles the pin value, returns an int for error handling
 * INPUT: (u8) port number, (u8) pin number
 * OUTPUT: void
 * Returns: (int) error state
 * **/
int MDIO_intToggle(u8 portNumber, u8 pinNumber);
/***
 * reads the pin value and stores it in the address given by the pointer, returns an int for error handling
 * INPUT: (u8) port number, (u8) pin number, (u8*) pointer to store value
 * OUTPUT: pin value
 * Returns: (int) error state
 * **/
int MDIO_intRead(u8 portNumber, u8 pinNumber, u8 *value);
/***
 * sets the port value based on input arguments, returns an int for error handling
 * INPUT: (u8) port number, (u8) value
 * OUTPUT: void
 * Returns: (int) error state
 * **/
int MDIO_intWritePort(u8 portNumber, u8 value);
/***
 * initializes the port based on input arguments, returns an int for error handling
 * INPUT: (u8) port number, (u8) direction
 * OUTPUT: void
 * Returns: (int) error state
 * **/
int MDIO_intInitPort(u8 portNumber, u8 direction);
//helper macros for ports
#define DIO_PORT_A   'A'
#define DIO_PORT_B   'B'
#define DIO_PORT_C   'C'
#define DIO_PORT_D   'D'

//helper macros for pins
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

//helper macros for direction
#define DIO_OUTPUT   'o'
#define DIO_INPUT    'i'

#define DIO_HIGH	 1
#define DIO_LOW		 0
//helper macros for error handling
#define DIO_OK				111
#define DIO_INIT_FAILED		22
#define DIO_WRITE_FAILED	33
#define DIO_TOGGLE_FAILED	44
#define DIO_READ_FAILED		55

#endif
