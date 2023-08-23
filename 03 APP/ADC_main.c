//#include "00 LIB/STD_TYPES.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//#include "01 MCAL/01 ADC/ADC_interface.h"
//#include "01 MCAL/03 GIE/GIE_interface.h"
//#include "02 HAL/03 LCD/LCD_interface.h"
//
////void my_cb(void);
//int main(void) {
//	u16 data = 0;
//	//MDIO_intInit(DIO_PORT_A, DIO_PIN0, DIO_INPUT);
//	MADC_voidInit();
//	//MADC_voidSetCallback(my_cb);
//	//MGIE_voidEnableGI();
//	//MADC_u16StartConversion();
//	HLCD_voidInit();
//	HLCD_voidSendString("starting...");
//	delay_ms(1000);
//	HLCD_voidSendCommand(LCD_CLEAR_SC);
//	HLCD_voidSendString("TEMP=");
//	double temp = 0;
//	double avg;
//	while(1){
//		avg = 0;
//		for(int i = 0; i < 1000; i++){
//			MADC_u16StartConversion();
//			MADC_voidGetConversionBlocking(&data);
//			avg += ((double)data*5/1024) * 100;
//		}
//		temp = avg / 1000;
//		//temp = data;
//		HLCD_voidGoToCursor(1,6);
//		HLCD_voidSendString("      ");
//		HLCD_voidGoToCursor(1,6);
//		HLCD_voidSendNum((int)temp);
//		HLCD_voidSendChar('.');
//		HLCD_voidSendNum(((int)(temp * 100)) % 100);
//		HLCD_voidSendChar('C');
//		delay_ms(500);
//	}
//	return 0;
//}
////void my_cb(void){
////	MADC_voidGetConversion(&data);
////}
