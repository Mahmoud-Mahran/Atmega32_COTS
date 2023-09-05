/*
 * DIO_Program.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../00 DIO/DIO_Config.h"
#include "../00 DIO/DIO_Interface.h"
#include "../00 DIO/DIO_Private.h"

int MDIO_intInit(u8 portNumber, u8 pinNumber, u8 direction) {
	switch (direction) {
	case DIO_OUTPUT:
		switch (portNumber) {
		case DIO_PORT_A:
			Set_Bit(DDRA, pinNumber);   //output
			return DIO_OK;
			break;
		case DIO_PORT_B:
			Set_Bit(DDRB, pinNumber);   //output
			return DIO_OK;
			break;
		case DIO_PORT_C:
			Set_Bit(DDRC, pinNumber);   //output
			return DIO_OK;
			break;
		case DIO_PORT_D:
			Set_Bit(DDRD, pinNumber);   //output
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case DIO_INPUT:
		switch (portNumber) {
		case DIO_PORT_A:
			Clr_Bit(DDRA, pinNumber);   //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_B:
			Clr_Bit(DDRB, pinNumber);   //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_C:
			Clr_Bit(DDRC, pinNumber);   //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_D:
			Clr_Bit(DDRD, pinNumber);   //DIO_INPUT
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	default:
		return DIO_INIT_FAILED;
	}
}
int MDIO_intInitPort(u8 portNumber, u8 direction){
	switch (direction) {
	case DIO_OUTPUT:
		switch (portNumber) {
		case DIO_PORT_A:
			DDRA = 0xff;   //output
			return DIO_OK;
			break;
		case DIO_PORT_B:
			DDRB = 0xff;   //output
			return DIO_OK;
			break;
		case DIO_PORT_C:
			DDRC = 0xff;   //output
			return DIO_OK;
			break;
		case DIO_PORT_D:
			DDRD = 0xff;   //output
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case DIO_INPUT:
		switch (portNumber) {
		case DIO_PORT_A:
			DDRA = 0x00;   //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_B:
			DDRB = 0x00;   //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_C:
			DDRC = 0x00;    //DIO_INPUT
			return DIO_OK;
			break;
		case DIO_PORT_D:
			DDRD = 0x00;   //DIO_INPUT
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	default:
		return DIO_INIT_FAILED;
	}
}
int MDIO_intWrite(u8 portNumber, u8 pinNumber, u8 value) {
	switch (value) {
	case DIO_HIGH:
		switch (portNumber) {
		case DIO_PORT_A:
			Set_Bit(PORTA, pinNumber);   //DIO_HIGH
			return DIO_OK;
			break;
		case DIO_PORT_B:
			Set_Bit(PORTB, pinNumber);   //DIO_HIGH
			return DIO_OK;
			break;
		case DIO_PORT_C:
			Set_Bit(PORTC, pinNumber);   //DIO_HIGH
			return DIO_OK;
			break;
		case DIO_PORT_D:
			Set_Bit(PORTD, pinNumber);   //DIO_HIGH
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case DIO_LOW:
		switch (portNumber) {
		case DIO_PORT_A:
			Clr_Bit(PORTA, pinNumber);   //DIO_LOW
			return DIO_OK;
			break;
		case DIO_PORT_B:
			Clr_Bit(PORTB, pinNumber);   //DIO_LOW
			return DIO_OK;
			break;
		case DIO_PORT_C:
			Clr_Bit(PORTC, pinNumber);   //DIO_LOW
			return DIO_OK;
			break;
		case DIO_PORT_D:
			Clr_Bit(PORTD, pinNumber);   //DIO_LOW
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	default:
		return DIO_INIT_FAILED;
	}
}

int MDIO_intToggle(u8 portNumber, u8 pinNumber) {
	switch (portNumber) {
	case DIO_PORT_A:
		Tgl_Bit(PORTA, pinNumber);
		return DIO_OK;
		break;
	case DIO_PORT_B:
		Tgl_Bit(PORTB, pinNumber);
		return DIO_OK;
		break;
	case DIO_PORT_C:
		Tgl_Bit(PORTC, pinNumber);
		return DIO_OK;
		break;
	case DIO_PORT_D:
		Tgl_Bit(PORTD, pinNumber);
		return DIO_OK;
		break;
	default:
		return DIO_INIT_FAILED;
	}
}

int MDIO_intRead(u8 portNumber, u8 pinNumber, u8 *value) {
	switch (portNumber) {
	case DIO_PORT_A:
		*value = Get_Bit(PINA, pinNumber);   //read bit
		return DIO_OK;
		break; //redundant
	case DIO_PORT_B:
		*value = Get_Bit(PINB, pinNumber);   //read bit
		return DIO_OK;
		break;
	case DIO_PORT_C:
		*value = Get_Bit(PINC, pinNumber);   //read bit
		return DIO_OK;
		break;
	case DIO_PORT_D:
		*value = Get_Bit(PIND, pinNumber);   //read bit
		return DIO_OK;
		break;
	default:
		return DIO_READ_FAILED;
		break;
	}
}
int MDIO_intWritePort(u8 portNumber, u8 value) {
	switch (portNumber) {
	case DIO_PORT_A:
		PORTA =   value; //DIO_HIGH
		return DIO_OK;
		break;
	case DIO_PORT_B:
		PORTB =   value;  //DIO_HIGH
		return DIO_OK;
		break;
	case DIO_PORT_C:
		PORTC =   value;   //DIO_HIGH
		return DIO_OK;
		break;
	case DIO_PORT_D:
		PORTD =   value;   //DIO_HIGH
		return DIO_OK;
		break;
	default:
		return DIO_INIT_FAILED;
	}
}
