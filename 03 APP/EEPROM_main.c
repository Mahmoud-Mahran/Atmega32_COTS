//#include "../00 LIB/STD_TYPES.h"
//#include "../00 LIB/BIT_MATH.h"
//#include "../01 MCAL/00 DIO/DIO_Interface.h"
//#include "../02 HAL/07 EEPROM/EEPROM_interface.h"
//#include "../02 HAL/03 LCD/LCD_interface.h"
//int main(void) {
//	MDIO_intInit(DIO_PORT_B, DIO_PIN0, DIO_OUTPUT);
//	MDIO_intWrite(DIO_PORT_B, DIO_PIN0, DIO_LOW);
//	HEEPROM_voidInit();
//	HLCD_voidInit();
//	u8 data[16] = "i2c is meh :/  ";
//	u8 data2[16] = { 0 };
//	HEEPROM_voidWrite16BytePage(data, 5);
//	delay_ms(15);
//	HEEPROM_voidRead16BytePage(data2, 5);
//	HLCD_voidSendString(data2);
//	MDIO_intWrite(DIO_PORT_B, DIO_PIN0, DIO_HIGH);
//	while (1) {
//
//	}
//	return 0;
//}
