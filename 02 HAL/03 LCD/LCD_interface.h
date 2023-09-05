/*
 * LCD_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/**
 * initializes the LCD
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidInit(void);
/**
 * Sends 8 bit command to the LCD
 * INPUT: (u8) command to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidSendCommand(u8 cpy_u8Command);
/**
 * Sends 8 bit character to the LCD
 * INPUT: (u8) character to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidSendChar(u8 cpy_u8Char);
/**
 * Sends a string of 8 bit characters to the LCD (loops till NULL char)
 * INPUT: (u8*) character pointer to the 1st char in the string to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidSendString(u8 *cpy_u8Char);
/**
 * Sends the cursor to the given index (row, column)
 * INPUTs:
 *     (u8) cpy_u8Row: row index(1 , 2)
 *     (u8) cpy_u8Column: column index (1 : 16)
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidGoToCursor(u8 cpy_u8Row, u8 cpy_u8Column);
/**
 * Sends number to the LCD (up to 32 bit)
 * INPUT: (s32) number to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidSendNum(s64 cpy_s64Num);
void HLCD_voidStoreCustomChar(u8 cpy_u8CharArr[7], u8 cpy_u8location);
void HLCD_voidSendFloat(f64 cpy_f64Num, u8 cpy_DigitNum);


//interfacing macros
#define LCD_FUNC_SET			                  0b00111000
#define LCD_INIT_4_BIT	                          0b00000010
#define LCD_FUNC_SET_4BIT		                  0b00101000
#define LCD_DISPLAY_ON_CURSOR_ON                  0b00001110
#define LCD_DISPLAY_ON			                  0b00001100
#define LCD_DISPLAY_OFF			                  0b00001000
#define LCD_CLEAR_SC			                  0b00000001
#define LCD_ENTRY_M_SET			                  0b00000110
#define LCD_NEXT_LINE			                  0b11000000

//#define LCD_SET_CG_RAM          0b01
#endif
