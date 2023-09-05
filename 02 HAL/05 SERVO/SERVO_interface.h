/*
 * SERVO_interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void HSERVO_voidInit(void);
void HSERVO_voidSelectChannel(u8 cpy_u8Timer1Channel);
void HSERVO_voidWriteAngle(u8 cpy_u8Angle, u8 cpy_u8Timer1Channel);

#endif
