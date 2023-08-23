#ifndef		KEYPAD_CONFIG_H
#define		KEYPAD_CONFIG_H
u8 keypad_chars[4][4] = { { 1,  2,  3,  4  },
						  { 5,  6,  7,  8  },
						  { 9,  10, 11, 12 },
						  { 13, 14, 15, 16 } };

#define 	row_1_port			DIO_PORT_D
#define 	row_2_port			DIO_PORT_D
#define 	row_3_port			DIO_PORT_D
#define 	row_4_port			DIO_PORT_D
#define 	column_1_port		DIO_PORT_D
#define 	column_2_port		DIO_PORT_D
#define 	column_3_port		DIO_PORT_D
#define 	column_4_port		DIO_PORT_D

#define 	row_1_pin			 DIO_PIN3
#define 	row_2_pin			 DIO_PIN2
#define 	row_3_pin			 DIO_PIN1
#define 	row_4_pin			 DIO_PIN0
#define 	column_1_pin		 DIO_PIN7
#define 	column_2_pin		 DIO_PIN6
#define 	column_3_pin		 DIO_PIN5
#define 	column_4_pin		 DIO_PIN4

#endif

