//#include "../00 LIB/STD_TYPES.h"
//#include "../00 LIB/BIT_MATH.h"
//#include "../01 MCAL/00 DIO/DIO_Interface.h"
//#include "../01 MCAL/04 TIMER/TIMER_interface.h"
//#include "../01 MCAL/02 GIE/GIE_interface.h"
//#include "../02 HAL/03 LCD/LCD_interface.h"
//#include "../01 MCAL/04 TIMER/TIMER_private.h"
//
//int main(void) {
//	u32 freq = 0;
//	u32 Ton = 0;
//	HLCD_voidInit();
//	MDIO_intInit(DIO_PORT_B, DIO_PIN3, DIO_OUTPUT);
//	MDIO_intInit(DIO_PORT_D, DIO_PIN6, DIO_INPUT);
//	MDIO_intWrite(DIO_PORT_D, DIO_PIN6, DIO_HIGH);
//	MTIMER_voidInit();
//	MTIMER_voidload(50, TIMER_TM0);
//	MTIMER_voidGenerateFastPwmSignal(TIMER_TM0);
//	MTIMER_voidGenerateFastPwmSignal(TIMER_TM2);
//	MTIMER_voidStart(TIMER_TM0);
//	HLCD_voidSendCommand(LCD_CLEAR_SC);
//	HLCD_voidSendString((u8*) "Freq =");
//	HLCD_voidSendCommand(LCD_NEXT_LINE);
//	HLCD_voidSendString((u8*) "Ton =");
//	MGIE_voidEnableGI();
//	while (1) {
//		MTIMER_voidMeasureSignal(&freq, &Ton);
//		HLCD_voidGoToCursor(1, 8);
//		HLCD_voidSendString((u8*) "         ");
//		HLCD_voidGoToCursor(1, 8);
//		HLCD_voidSendNum(freq);
//		HLCD_voidSendString((u8*)"Hz");
//		HLCD_voidGoToCursor(2, 7);
//		HLCD_voidSendString((u8*) "          ");
//		HLCD_voidGoToCursor(2, 7);
//		HLCD_voidSendNum(Ton);
//		HLCD_voidSendString((u8*)"us");
//		delay_ms(500);
//	}
//	return 0;
//}
