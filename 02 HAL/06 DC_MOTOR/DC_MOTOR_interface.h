/*
 * DC_MOTOR_interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef  _DC_MOTOR_INTERFACE_H
#define  _DC_MOTOR_INTERFACE_H

typedef struct{
	u8 cw_port[2];
	u8 ccw_port[2];
	u8 cw_pin[2];
	u8 ccw_pin[2];
	u8 state;
	u8 cw_timer;
	u8 ccw_timer;
}MOTOR;

#define CW_DIR                  1
#define CCW_DIR                 2

void HDC_MOTOR_voidInit(MOTOR *cpy_Motor);
void HDC_MOTOR_voidInitSpeedControl(MOTOR *cpy_Motor);
void HDC_MOTOR_voidSetDirection(u8 cpy_u8Dir, MOTOR *cpy_Motor);
void HDC_MOTOR_voidStart(MOTOR cpy_Motor);
void HDC_MOTOR_voidStop(MOTOR cpy_Motor);
void HDC_MOTOR_voidControlSpeed(MOTOR cpy_Motor, u8 cpy_speed);
#endif
