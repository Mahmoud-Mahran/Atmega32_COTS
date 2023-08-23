//#include "../00 LIB/STD_TYPES.h"
//#include "../00 LIB/BIT_MATH.h"
//#include "../01 MCAL/00 DIO/DIO_Interface.h"
//#include "../01 MCAL/06 SPI/SPI_interface.h"
//#include "../02 HAL/03 LCD/LCD_interface.h"
//#define num    1
//int main(void) {
//	HLCD_voidInit();
//#if num == 1
//	MSPI_voidMasterInit();
//	u8 index = 1;
//	while (1) {
//		if (index == 1) {
//			while (index < 17) {
//				HLCD_voidGoToCursor(1, index);
//				HLCD_voidSendChar(0xFF);
//				delay_ms(50);
//				HLCD_voidGoToCursor(1, index);
//				HLCD_voidSendChar(' ');
//				index++;
//			}
//		}
//		if(index == 17){
//			MSPI_voidMasterTRansmitReceive(&index, DIO_PORT_B, DIO_PIN4);
//			MSPI_voidSlaveInit();
//			HLCD_voidGoToCursor(1, 7);
//			HLCD_voidSendString("PING!");
//		}
//		MSPI_voidSlaveReceive(&index);
//		if (index == 16) {
//			MSPI_voidMasterInit();
//			HLCD_voidSendCommand(LCD_CLEAR_SC);
//			while (index > 1) {
//				HLCD_voidGoToCursor(1, index);
//				HLCD_voidSendChar(0xFF);
//				delay_ms(50);
//				HLCD_voidGoToCursor(1, index);
//				HLCD_voidSendChar(' ');
//				index--;
//			}
//		}
//	}
//#elif num == 0
//	HLCD_voidInit();
//	MSPI_voidSlaveInit();
//	u8 index = 0;
//	while (1) {
//		MSPI_voidSlaveReceive(&index);
//		if (index == 17) {
//			MSPI_voidMasterInit();
//			HLCD_voidSendCommand(LCD_CLEAR_SC);
//			while (index < 32) {
//				HLCD_voidGoToCursor(1, (index - 16));
//				HLCD_voidSendChar(0xFF);
//				delay_ms(50);
//				HLCD_voidGoToCursor(1, (index - 16));
//				HLCD_voidSendChar(' ');
//				index++;
//			}
//		}
//		while (index > 16) {
//			HLCD_voidGoToCursor(1, (index - 16));
//			HLCD_voidSendChar(0xFF);
//			delay_ms(50);
//			HLCD_voidGoToCursor(1, (index - 16));
//			HLCD_voidSendChar(' ');
//			index--;
//		}
//		if(index == 16){
//			MSPI_voidMasterTRansmitReceive(&index, DIO_PORT_B, DIO_PIN4);
//			MSPI_voidSlaveInit();
//			HLCD_voidGoToCursor(1, 7);
//			HLCD_voidSendString("PONG!");
//		}
//	}
//
//#endif
//	return 0;
//}
//
