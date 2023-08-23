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
void  HLCD_voidSendString(char *cpy_u8Char);
/**
 * Sends the cursor to the given index (row, column)
 * INPUTs:
 *     (u8) cpy_u8Row: row index(1 , 2)
 *     (u8) cpy_u8Row: column index (1 : 16)
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidGoToCursor(u8 cpy_u8Row, u8 cpy_u8Column);
/**
 * Sends number to the LCD (up to 32 bit)
 * INPUT: (u32) number to be sent
 * OUTPUT: void
 * Returns: void
 * **/
void  HLCD_voidSendNum(s32 cpy_u32Num);

#define LCD_FUNC_SET			0b00111000
#define LCD_FUNC_SET_4BIT		0b00101000
#define LCD_DISPLAY_ON			0b00001100
#define LCD_CLEAR_SC			0b00000001
#define LCD_ENTRY_M_SET			0b00000110
#define LCD_NEXT_LINE			0b11000000
#define	LCD_4_BIT				33
#define	LCD_8_BIT				34

#endif
