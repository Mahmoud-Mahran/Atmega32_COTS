/*
 * LCD_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void HLCD_voidInit(void) {
	u8 local_temp[8][2] = { { LCD_D0_PORT, LCD_D0_PIN }, { LCD_D1_PORT,
	LCD_D1_PIN }, { LCD_D2_PORT, LCD_D2_PIN }, { LCD_D3_PORT, LCD_D3_PIN }, {
	LCD_D4_PORT, LCD_D4_PIN }, {
	LCD_D5_PORT, LCD_D5_PIN }, { LCD_D6_PORT, LCD_D6_PIN }, {
	LCD_D7_PORT, LCD_D7_PIN } };
	MDIO_intInit(LCD_RS_PORT, LCD_RS_PIN, DIO_OUTPUT);
	MDIO_intInit(LCD_RW_PORT, LCD_RW_PIN, DIO_OUTPUT);
	MDIO_intInit(LCD_EN_PORT, LCD_EN_PIN, DIO_OUTPUT);
#if LCD_MODE == LCD_8_BIT
	for(int i = 0; i < 8; i++) {
		MDIO_intInit(local_temp[i][0], local_temp[i][1], DIO_OUTPUT);
	}
	delay_ms(100);
	HLCD_voidSendCommand(LCD_FUNC_SET);
#elif LCD_MODE == LCD_4_BIT
	for (int i = 0; i < 4; i++) {
		MDIO_intInit(local_temp[i + 4][0], local_temp[i + 4][1], DIO_OUTPUT);
	}
	delay_ms(100);
	HLCD_voidSendCommand(LCD_INIT_4_BIT);
	HLCD_voidSendCommand(LCD_FUNC_SET_4BIT);
#endif
	delay_ms(5);
	HLCD_voidSendCommand(LCD_DISPLAY_ON);
	delay_ms(5);
	HLCD_voidSendCommand(LCD_CLEAR_SC);
	delay_ms(5);
	HLCD_voidSendCommand(LCD_ENTRY_M_SET);
}
void HLCD_voidSendCommand(u8 cpy_u8Command) {
	u8 local_temp[8][2] = { { LCD_D0_PORT, LCD_D0_PIN }, { LCD_D1_PORT,
	LCD_D1_PIN }, { LCD_D2_PORT, LCD_D2_PIN }, { LCD_D3_PORT, LCD_D3_PIN }, {
	LCD_D4_PORT, LCD_D4_PIN }, {
	LCD_D5_PORT, LCD_D5_PIN }, { LCD_D6_PORT, LCD_D6_PIN }, {
	LCD_D7_PORT, LCD_D7_PIN } };
	MDIO_intWrite(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW);
	MDIO_intWrite(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW);
	delay_ms(1);
#if LCD_MODE == LCD_8_BIT
	for(int i = 0; i < 8; i++) {
		MDIO_intWrite(local_temp[i][0], local_temp[i][1], Get_Bit(cpy_u8Command, i));
	}
#elif LCD_MODE == LCD_4_BIT
	//send lower nibble
	for (int i = 0; i < 4; i++) {
		MDIO_intWrite(local_temp[i + 4][0], local_temp[i + 4][1],
				Get_Bit(cpy_u8Command, (i + 4)));
	}
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	delay_ms(1);
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	delay_ms(1);
	//send higher nibble
	for (int i = 0; i < 4; i++) {
		MDIO_intWrite(local_temp[i + 4][0], local_temp[i + 4][1],
				Get_Bit(cpy_u8Command, i));
	}
#endif
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	delay_ms(2);
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	delay_ms(2);
}
void HLCD_voidSendChar(u8 cpy_u8Char) {
	u8 local_temp[8][2] = { { LCD_D0_PORT, LCD_D0_PIN }, { LCD_D1_PORT,
	LCD_D1_PIN }, { LCD_D2_PORT, LCD_D2_PIN }, { LCD_D3_PORT, LCD_D3_PIN }, {
	LCD_D4_PORT, LCD_D4_PIN }, {
	LCD_D5_PORT, LCD_D5_PIN }, { LCD_D6_PORT, LCD_D6_PIN }, {
	LCD_D7_PORT, LCD_D7_PIN } };
	MDIO_intWrite(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH);
	MDIO_intWrite(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW);
	//delay_ms(5);
#if LCD_MODE == LCD_8_BIT
	for(int i = 0; i < 8; i++) {
		MDIO_intWrite(local_temp[i][0], local_temp[i][1], Get_Bit(cpy_u8Char, i));
	}
#elif LCD_MODE == LCD_4_BIT
	//send lower nibble
	for (int i = 0; i < 4; i++) {
		MDIO_intWrite(local_temp[i + 4][0], local_temp[i + 4][1],
				Get_Bit(cpy_u8Char, (i + 4)));
	}
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	delay_ms(1);
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	delay_ms(1);
	//send higher nibble
	for (int i = 0; i < 4; i++) {
		MDIO_intWrite(local_temp[i + 4][0], local_temp[i + 4][1],
				Get_Bit(cpy_u8Char, i));
	}
#endif
	delay_ms(1);
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	delay_ms(1);
	MDIO_intWrite(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	delay_ms(1);
}
void HLCD_voidSendString(u8 *cpy_u8Char) {
	u16 i = 0;
	while (cpy_u8Char[i] != '\0') {
		if (i == 16)
			HLCD_voidSendCommand(LCD_NEXT_LINE);
		HLCD_voidSendChar(cpy_u8Char[i]);
		delay_ms(1);
		i++;
	}
}
void HLCD_voidGoToCursor(u8 cpy_u8Row, u8 cpy_u8Column) {
	if ((cpy_u8Row < 3 && cpy_u8Row > 0)
			&& (cpy_u8Column > 0 && cpy_u8Column < 17)) {
		cpy_u8Column--;
		switch (cpy_u8Row) {
		case 1:
			HLCD_voidSendCommand(0x80 + cpy_u8Column);
			break;
		case 2:
			HLCD_voidSendCommand(0xC0 + cpy_u8Column);
			break;
		}
	} else {
		//error
	}

}
void HLCD_voidSendNum(s64 cpy_s64Num) {
	u8 temp[16] = { 0 };
	if (cpy_s64Num < 0) {
		HLCD_voidSendChar('-');
		cpy_s64Num *= -1;
	}
	if (cpy_s64Num == 0)
		HLCD_voidSendChar('0');
	u8 i = 15;
	while (cpy_s64Num != 0) {
		temp[i] = (cpy_s64Num % 10) + '0';
		cpy_s64Num /= 10;
		i--;
	}
	i++;
	while (i < 16) {
		HLCD_voidSendChar(temp[i]);
		i++;
	}
}
void HLCD_voidSendFloat(f64 cpy_f64Num, u8 cpy_DigitNum) {
	s64 cpy_s64Num = (s64) cpy_f64Num;
	HLCD_voidSendNum(cpy_s64Num);
	HLCD_voidSendChar('.');
	u32 temp = 1;
	for (int i = 0; i < cpy_DigitNum; i++)
		temp *= 10;
	HLCD_voidSendNum((s64)(cpy_f64Num * temp) % temp);
}
void HLCD_voidStoreCustomChar(u8 cpy_u8CharArr[8], u8 cpy_u8location) {
	if (cpy_u8location >= 0 && cpy_u8location <= 7) {
		cpy_u8location = (cpy_u8location << 3) | 0b01000000;
		HLCD_voidSendCommand(cpy_u8location);
		for (int i = 0; i < 8; i++) {
			HLCD_voidSendChar(cpy_u8CharArr[i]);
		}
		HLCD_voidGoToCursor(1, 1);
	} else {
		//input error
	}
}
