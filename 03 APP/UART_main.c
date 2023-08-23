//#include "00 LIB/STD_TYPES.h"
//#include "00 LIB/BIT_MATH.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//#include "01 MCAL/05 UART/UART_interface.h"
//#include "02 HAL/03 LCD/LCD_interface.h"
//
//int main(void){
//	//MDIO_intInit(DIO_PORT_D, DIO_PIN0, DIO_INPUT);
//	//MDIO_intInit(DIO_PORT_D, DIO_PIN1, DIO_OUTPUT);
//	MUART_voidInit();
//	HLCD_voidInit();
//	u8 data;
//	HLCD_voidSendString("Receiving...");
//	delay_ms(500);
//	HLCD_voidSendCommand(LCD_CLEAR_SC);
//	MUART_voidTX_Byte('A');
//	MUART_voidTX_Byte('M');
//	while(1){
//		data = 0xff;
//		MUART_voidRX_Byte(&data);
//		if(data != 0xff)HLCD_voidSendChar(data);
//		delay_ms(500);
//	}
//	return 0;
//}
