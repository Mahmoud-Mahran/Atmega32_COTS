//#include "00 LIB/STD_TYPES.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//#include "01 MCAL/03 GIE/GIE_interface.h"
//#include "01 MCAL/02 EXTI/EXTI_interface.h"
//#include "02 HAL/02 Button/BUTTON_interface.h"
//#include "02 HAL/03 LCD/LCD_interface.h"
//void my_func(void);
//int main(void) {
//	HLCD_voidInit();
//	BUTTONS btn = { DIO_PORT_D, DIO_PIN2 };
//	HBUTTON_u8Init(&btn);
//	HBUTTON_u8ConnectIPU(&btn);
//	MEXTI_voidInit();
//	MEXTI_voidSetInt0Callback(my_func);
//	MGIE_voidEnableGI();
//	while (1) {
//		HLCD_voidGoToCursor(1, 5);
//		HLCD_voidSendString("no one");
//		HLCD_voidSendCommand(LCD_NEXT_LINE);
//		HLCD_voidSendString("can interrupt me");
//		delay_ms(1000);
//		HLCD_voidSendCommand(LCD_CLEAR_SC);
//	}
//	return 0;
//}
//void my_func(void) {
//	HLCD_voidSendCommand(LCD_CLEAR_SC);
//	HLCD_voidSendString("no one");
//	delay_ms(300);
//}
