#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "../../01 MCAL/04 TIMER/TIMER_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"

void HDC_MOTOR_voidInit(MOTOR cpy_Motor) {

	MDIO_intInit(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_OUTPUT);
	MDIO_intInit(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_OUTPUT);

	MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_LOW);
	cpy_Motor.state = CW_DIR;
}
void HDC_MOTOR_voidSetDirection(u8 cpy_u8Dir, MOTOR cpy_Motor) {
	switch (cpy_u8Dir) {
	case CW_DIR:
		//make sure ccw is off
		MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_HIGH);
		cpy_Motor.state = CW_DIR;
		break;
	case CCW_DIR:
		//make sure cw is off
		MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_HIGH);
		cpy_Motor.state = CCW_DIR;
		break;
	default:
		break;
	}
}
void HDC_MOTOR_voidStart(MOTOR cpy_Motor) {
	switch(cpy_Motor.state){
	case CW_DIR:
		//make sure ccw is off
		MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_HIGH);
		break;
	case CCW_DIR:
		//make sure cw is off
		MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_LOW);
		MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_LOW);

		MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_HIGH);
		MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_HIGH);
		break;
	}
}
void HDC_MOTOR_voidStop(MOTOR cpy_Motor) {
	MDIO_intWrite(cpy_Motor.cw_port[0], cpy_Motor.cw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.cw_port[1], cpy_Motor.cw_pin[1], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[0], cpy_Motor.ccw_pin[0], DIO_LOW);
	MDIO_intWrite(cpy_Motor.ccw_port[1], cpy_Motor.ccw_pin[1], DIO_LOW);
}
void HDC_MOTOR_voidControlSpeed(MOTOR cpy_Motor, u8 cpy_speed) {
	if(cpy_speed >= 0 && cpy_speed <=255 ){
		MTIMER_voidInit();
		MTIMER_voidload(cpy_speed, TIMER_TM0);
		MTIMER_voidGenerateFastPwmSignal(TIMER_TM0);
		MTIMER_voidStart(TIMER_TM0);
	} else {
		//wrong input
	}
}

