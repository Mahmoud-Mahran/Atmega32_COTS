/*
 * BUTTON_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "BUTTON_config.h"
#include "BUTTON_interface.h"


u8 HBUTTON_u8Init(BUTTONS *butt){
	if(MDIO_intInit(butt->port, butt->pin, DIO_INPUT) == DIO_OK){
		return BUTTON_OK;
	}
	return BUTTON_OP_FAILED;
}

u8 HBUTTON_u8GetValue(BUTTONS *butt, u8 *val){
	if(MDIO_intRead(butt->port, butt->pin, val) == DIO_OK){
		return BUTTON_OK;
	}
	return BUTTON_OP_FAILED;
}

u8 HBUTTON_u8ConnectIPU(BUTTONS *butt){
	if(MDIO_intWrite(butt->port, butt->pin, DIO_HIGH) == DIO_OK){
		return BUTTON_OK;
	}
	return BUTTON_OP_FAILED;
}
