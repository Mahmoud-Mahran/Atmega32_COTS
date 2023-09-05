/*
 * DC_MOTOR_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "../../01 MCAL/04 TIMER/TIMER_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"

void HDC_MOTOR_voidInit(MOTOR *cpy_Motor) {
	MDIO_intInit(cpy_Motor->cw_port[0], cpy_Motor->cw_pin[0], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor->cw_port[1], cpy_Motor->cw_pin[1], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor->ccw_port[0],cpy_Motor->ccw_pin[0], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor->ccw_port[1],cpy_Motor->ccw_pin[1], DIO_OUTPUT);

	MDIO_intWrite(cpy_Motor->cw_port[0], cpy_Motor->cw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor->cw_port[1], cpy_Motor->cw_pin[1], DIO_LOW);
	MDIO_intWrite(cpy_Motor->ccw_port[0],cpy_Motor->ccw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor->ccw_port[1],cpy_Motor->ccw_pin[1], DIO_LOW);
	cpy_Motor->state = CW_DIR;
}
void HDC_MOTOR_voidInitSpeedControl(MOTOR *cpy_Motor){
	MTIMER_voidInit();
	MTIMER_voidload(0, cpy_Motor->cw_timer);
	MTIMER_voidload(0, cpy_Motor->ccw_timer);
	MTIMER_voidGenerateFastPwmSignal(cpy_Motor->cw_timer);
	MTIMER_voidGenerateFastPwmSignal(cpy_Motor->ccw_timer);
}
void HDC_MOTOR_voidSetDirection(u8 cpy_u8Dir, MOTOR *cpy_Motor) {
	switch (cpy_u8Dir) {
	case CW_DIR:
		MDIO_intWrite(cpy_Motor->ccw_port[0], cpy_Motor->ccw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor->ccw_port[1], cpy_Motor->ccw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor->cw_port[0], cpy_Motor->cw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor->cw_port[1], cpy_Motor->cw_pin[1], DIO_HIGH);
		cpy_Motor->state = CW_DIR;
		break;
	case CCW_DIR:
		MDIO_intWrite(cpy_Motor->cw_port[0], cpy_Motor->cw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor->cw_port[1], cpy_Motor->cw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor->ccw_port[0], cpy_Motor->ccw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor->ccw_port[1], cpy_Motor->ccw_pin[1], DIO_HIGH);
		cpy_Motor->state = CCW_DIR;
		break;
	default:
		break;
	}
}
void HDC_MOTOR_voidStart(MOTOR cpy_Motor) {
	switch(cpy_Motor.state){
	case CW_DIR:
		MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_HIGH);
		break;
	case CCW_DIR:
		MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_HIGH);
		break;
	}
}
void HDC_MOTOR_voidStop(MOTOR cpy_Motor) {
	MTIMER_voidStop(cpy_Motor.cw_timer);
	MTIMER_voidStop(cpy_Motor.ccw_timer);
	MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_LOW);
}
void HDC_MOTOR_voidControlSpeed(MOTOR cpy_Motor, u8 cpy_speed) {
	if(cpy_speed >= 0 && cpy_speed <=255 ){
		switch(cpy_Motor.state){
		case CW_DIR:
			MTIMER_voidStop(cpy_Motor.ccw_timer);
			MTIMER_voidload(cpy_speed, cpy_Motor.cw_timer);
			MTIMER_voidStart(cpy_Motor.cw_timer);
			break;
		case CCW_DIR:
		    MTIMER_voidStop(cpy_Motor.cw_timer);
			MTIMER_voidload(cpy_speed, cpy_Motor.ccw_timer);
			MTIMER_voidStart(cpy_Motor.ccw_timer);
			break;
		default:
			break;
		}
	} else {
		//wrong input
	}
}

