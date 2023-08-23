//#include "00 LIB/STD_TYPES.h"
//#include "00 LIB/BIT_MATH.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//#include "02 HAL/03 LCD/LCD_interface.h"
//#include "02 HAL/04 KEYPAD/KEYPAD_interface.h"
//int main(void) {
//	HLCD_voidInit();
//	HKEYBAD_voidInit();
//	u8 key = 0xff;
//	while (1) {
//		if (HKEYBAD_u8GetPressed() != 0xff) {
//			key = HKEYBAD_u8GetPressed();
//			HLCD_voidSendCommand(LCD_CLEAR_SC);
//			HLCD_voidSendNum(key);
//			delay_ms(500);
//		}
//		//
//
//		//delay_ms(250);
//
//	}
//	return 0;
//}
