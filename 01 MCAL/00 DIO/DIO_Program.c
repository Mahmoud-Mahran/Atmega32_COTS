#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../00 DIO/DIO_Config.h"
#include "../00 DIO/DIO_Interface.h"
#include "../00 DIO/DIO_Private.h"

int MDIO_intInit(u8 portNumber, u8 pinNumber, u8 direction) {
	switch (direction) {
	case OUTPUT:
		switch (portNumber) {
		case PORT_A:
			Set_Bit(DDRA, pinNumber);   //output
			return DIO_OK;
			break;
		case PORT_B:
			Set_Bit(DDRB, pinNumber);   //output
			return DIO_OK;
			break;
		case PORT_C:
			Set_Bit(DDRC, pinNumber);   //output
			return DIO_OK;
			break;
		case PORT_D:
			Set_Bit(DDRD, pinNumber);   //output
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case INPUT:
		switch (portNumber) {
		case PORT_A:
			Clr_Bit(DDRA, pinNumber);   //input
			return DIO_OK;
			break;
		case PORT_B:
			Clr_Bit(DDRB, pinNumber);   //input
			return DIO_OK;
			break;
		case PORT_C:
			Clr_Bit(DDRC, pinNumber);   //input
			return DIO_OK;
			break;
		case PORT_D:
			Clr_Bit(DDRD, pinNumber);   //input
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
	case OUTPUT:
		switch (portNumber) {
		case PORT_A:
			DDRA = 0xff;   //output
			return DIO_OK;
			break;
		case PORT_B:
			DDRB = 0xff;   //output
			return DIO_OK;
			break;
		case PORT_C:
			DDRC = 0xff;   //output
			return DIO_OK;
			break;
		case PORT_D:
			DDRD = 0xff;   //output
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case INPUT:
		switch (portNumber) {
		case PORT_A:
			DDRA = 0x00;   //input
			return DIO_OK;
			break;
		case PORT_B:
			DDRB = 0x00;   //input
			return DIO_OK;
			break;
		case PORT_C:
			DDRC = 0x00;    //input
			return DIO_OK;
			break;
		case PORT_D:
			DDRD = 0x00;   //input
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
	case HIGH:
		switch (portNumber) {
		case PORT_A:
			Set_Bit(PORTA, pinNumber);   //high
			return DIO_OK;
			break;
		case PORT_B:
			Set_Bit(PORTB, pinNumber);   //high
			return DIO_OK;
			break;
		case PORT_C:
			Set_Bit(PORTC, pinNumber);   //high
			return DIO_OK;
			break;
		case PORT_D:
			Set_Bit(PORTD, pinNumber);   //high
			return DIO_OK;
			break;
		default:
			return DIO_INIT_FAILED;
		}
		break;
	case LOW:
		switch (portNumber) {
		case PORT_A:
			Clr_Bit(PORTA, pinNumber);   //low
			return DIO_OK;
			break;
		case PORT_B:
			Clr_Bit(PORTB, pinNumber);   //low
			return DIO_OK;
			break;
		case PORT_C:
			Clr_Bit(PORTC, pinNumber);   //low
			return DIO_OK;
			break;
		case PORT_D:
			Clr_Bit(PORTD, pinNumber);   //low
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
	case PORT_A:
		Tgl_Bit(PORTA, pinNumber);
		return DIO_OK;
		break;
	case PORT_B:
		Tgl_Bit(PORTB, pinNumber);
		return DIO_OK;
		break;
	case PORT_C:
		Tgl_Bit(PORTC, pinNumber);
		return DIO_OK;
		break;
	case PORT_D:
		Tgl_Bit(PORTD, pinNumber);
		return DIO_OK;
		break;
	default:
		return DIO_INIT_FAILED;
	}
}

int MDIO_intRead(u8 portNumber, u8 pinNumber, u8 *value) {
	switch (portNumber) {
	case PORT_A:
		*value = Get_Bit(PORTA, pinNumber);   //read bit
		return DIO_OK;
		break; //redundant
	case PORT_B:
		*value = Get_Bit(PORTB, pinNumber);   //read bit
		return DIO_OK;
		break;
	case PORT_C:
		*value = Get_Bit(PORTC, pinNumber);   //read bit
		return DIO_OK;
		break;
	case PORT_D:
		*value = Get_Bit(PORTD, pinNumber);   //read bit
		return DIO_OK;
		break;
	default:
		return DIO_READ_FAILED;
		break;
	}
}
int MDIO_intWritePort(u8 portNumber, u8 value) {
	switch (portNumber) {
	case PORT_A:
		PORTA =   value; //high
		return DIO_OK;
		break;
	case PORT_B:
		PORTB =   value;  //high
		return DIO_OK;
		break;
	case PORT_C:
		PORTC =   value;   //high
		return DIO_OK;
		break;
	case PORT_D:
		PORTD =   value;   //high
		return DIO_OK;
		break;
	default:
		return DIO_INIT_FAILED;
	}
}
