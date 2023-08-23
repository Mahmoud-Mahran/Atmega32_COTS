//#include <util/delay.h>
//#include "00 LIB/STD_TYPES.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//int main(void){
//	MDIO_intInit(PORT_A, PIN0, OUTPUT);
//	MDIO_intInit(PORT_B, PIN1, OUTPUT);
//	MDIO_intInit(PORT_C, PIN2, OUTPUT);
//	MDIO_intInit(PORT_D, PIN3, OUTPUT);
//	while(1){
//		MDIO_intWrite(PORT_A, PIN0, HIGH);
//		MDIO_intWrite(PORT_B, PIN1, LOW);
//		MDIO_intWrite(PORT_C, PIN2, LOW);
//		MDIO_intWrite(PORT_D, PIN3, LOW);
//		_delay_ms(1000);
//		MDIO_intWrite(PORT_A, PIN0, LOW);
//		MDIO_intWrite(PORT_B, PIN1, HIGH);
//		MDIO_intWrite(PORT_C, PIN2, LOW);
//		MDIO_intWrite(PORT_D, PIN3, LOW);
//		_delay_ms(1000);
//		MDIO_intWrite(PORT_A, PIN0, LOW);
//		MDIO_intWrite(PORT_B, PIN1, LOW);
//		MDIO_intWrite(PORT_C, PIN2, HIGH);
//		MDIO_intWrite(PORT_D, PIN3, LOW);
//		_delay_ms(1000);
//		MDIO_intWrite(PORT_A, PIN0, LOW);
//		MDIO_intWrite(PORT_B, PIN1, LOW);
//		MDIO_intWrite(PORT_C, PIN2, LOW);
//		MDIO_intWrite(PORT_D, PIN3, HIGH);
//		_delay_ms(1000);
//	}
//
//	return 0;
//}
