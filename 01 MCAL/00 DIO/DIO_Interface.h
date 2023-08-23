#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/*function that takes the port number, pin, output or input mode and returns an int for error handling
 initializes the pin based on input arguments */
int MDIO_intInit(u8 portNumber, u8 pinNumber, u8 direction);
/*function that takes the port number, pin and a value to set and returns an int for error handling
 sets the pin value based on input arguments */
int MDIO_intWrite(u8 portNumber, u8 pinNumber, u8 value);
/*function that takes the port number and pin and returns an int for error handling
 toggles the pin value */
int MDIO_intToggle(u8 portNumber, u8 pinNumber);
/*function that takes the port number, pin and a  pointer to store value and returns an int for error handling.
 reads the pin value and stores it in the address given by the pointer */
int MDIO_intRead(u8 portNumber, u8 pinNumber, u8 *value);
int MDIO_intWritePort(u8 portNumber, u8 value);
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
