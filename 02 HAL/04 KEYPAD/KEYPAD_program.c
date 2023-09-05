/*
 * KEYPAD_program.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include 	"../../00 LIB/BIT_MATH.h"
#include 	"../../00 LIB/Std_Types.h"
#include	"../../01 MCAL/00 DIO/DIO_Interface.h"
#include	"KEYPAD_interface.h"
#include	"KEYPAD_config.h"

void HKEYBAD_voidInit(void) {
	int rows[4][2] = { { row_1_port, row_1_pin }, { row_2_port, row_2_pin }, {
	row_3_port, row_3_pin }, { row_4_port, row_4_pin } };
	int cols[4][2] = { { column_1_port, column_1_pin }, { column_2_port,
	column_2_pin }, { column_3_port, column_3_pin }, { column_4_port,
	column_4_pin } };
	for (int i = 0; i < 4; i++) {
		MDIO_intInit(rows[i][0], rows[i][1], DIO_INPUT);
		MDIO_intWrite(rows[i][0], rows[i][1], DIO_HIGH);
		MDIO_intInit(cols[i][0], cols[i][1], DIO_OUTPUT);
		MDIO_intWrite(cols[i][0], cols[i][1], DIO_LOW);
	}
}

u8 HKEYBAD_u8GetPressed(void) {
	int rows[4][2] = { { row_1_port, row_1_pin }, { row_2_port, row_2_pin }, {
	row_3_port, row_3_pin }, { row_4_port, row_4_pin } };
	int cols[4][2] = { { column_1_port, column_1_pin }, { column_2_port,
	column_2_pin }, { column_3_port, column_3_pin }, { column_4_port,
	column_4_pin } };
	u8 pressed = 0xff;
	u8 temp = 55;
	for (int i = 0; i < 4; i++) {
		MDIO_intRead(rows[i][0], rows[i][1], &temp);
		if (temp == DIO_LOW) {
			for (int j = 0; j < 4; j++) {
				MDIO_intWrite(cols[j][0], cols[j][1], DIO_HIGH);
				MDIO_intRead(rows[i][0], rows[i][1], &temp);
				if (temp == DIO_HIGH)
					pressed = keypad_chars[i][j];
				MDIO_intWrite(cols[j][0], cols[j][1], DIO_LOW);
			}
		}
	}
	return pressed;

}

