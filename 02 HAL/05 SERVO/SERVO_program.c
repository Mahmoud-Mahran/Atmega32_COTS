/*
 * SERVO_program.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "../../01 MCAL/04 TIMER/TIMER_interface.h"
#include "SERVO_private.h"
#include "SERVO_interface.h"
#include "SERVO_config.h"
void HSERVO_voidInit(void) {
	MTIMER_voidInit();
	MTIMER_voidload(20000, TIMER_TM1_ICR);
	MTIMER_voidStart(TIMER_TM1);
}
void HSERVO_voidSelectChannel(u8 cpy_u8Timer1Channel){
	if (cpy_u8Timer1Channel == TIMER_TM1_CH_A) {
		MDIO_intInit(DIO_PORT_D, DIO_PIN5, DIO_OUTPUT);
		MDIO_intWrite(DIO_PORT_D, DIO_PIN5, DIO_LOW);
	} else if (cpy_u8Timer1Channel == TIMER_TM1_CH_B) {
		MDIO_intInit(DIO_PORT_D, DIO_PIN4, DIO_OUTPUT);
		MDIO_intWrite(DIO_PORT_D, DIO_PIN4, DIO_LOW);
	} else {
		//error
	}
	MTIMER_voidload(0, cpy_u8Timer1Channel);
	MTIMER_voidGenerateFastPwmSignal(cpy_u8Timer1Channel);
}
void HSERVO_voidWriteAngle(u8 cpy_u8Angle, u8 cpy_u8Timer1Channel) {
	if ((cpy_u8Timer1Channel == TIMER_TM1_CH_A
			|| cpy_u8Timer1Channel == TIMER_TM1_CH_B) && cpy_u8Angle <= 180
			&& cpy_u8Angle >= 0) {
		u16 val = (u16) (((f32) cpy_u8Angle / 180.0) * 2164.0) + 413;
		MTIMER_voidload(val, cpy_u8Timer1Channel);
	} else {
		//error
	}
}
