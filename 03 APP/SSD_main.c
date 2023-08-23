//#include <util/delay.h>
//#include "00 LIB/STD_TYPES.h"
//#include "01 MCAL/00 DIO/DIO_Interface.h"
//#include "02 HAL/00 HSSD/HSSD_Interface.h"
//int main(void) {
//	HSSD_voidInit();
//	MDIO_intInitPort(PORT_B, OUTPUT);
//	MDIO_intInit(PORT_A, PIN7, OUTPUT);
//	MDIO_intInit(PORT_C, PIN7, OUTPUT);
//	MDIO_intWrite(PORT_A, PIN7, LOW);
//	MDIO_intWrite(PORT_C, PIN7, LOW);
//	u8 temp = 0;
//	u8 smol_delay = 5;
//	u16 big_smol_delay = 12500;
//	while (1) {
//		MDIO_intWritePort(PORT_B, temp);
//		for (int i = 0; i < ( 1000/(2*smol_delay) ) ; i++){
//			MDIO_intWrite(PORT_A, PIN7, LOW);
//			MDIO_intWrite(PORT_C, PIN7, LOW);
//			HSSD_voidDisplayNum(temp % 10);
//			MDIO_intWrite(PORT_A, PIN7, HIGH);
//			_delay_ms(smol_delay);
//			MDIO_intWrite(PORT_A, PIN7, LOW);
//			MDIO_intWrite(PORT_C, PIN7, LOW);
//			HSSD_voidDisplayNum(temp / 10);
//			MDIO_intWrite(PORT_C, PIN7, HIGH);
//			_delay_ms(smol_delay);
//		}
//		temp++;
//		if (temp > 99)temp = 0;
////		for (int i = 0; i < 8; i++) {
////			MDIO_intWrite(PORT_B, i, HIGH);
////			for (int k = 0; k < 5; k++) {
////				MDIO_intWrite(PORT_A, PIN7, LOW);
////				MDIO_intWrite(PORT_C, PIN7, LOW);
////				HSSD_voidDisplayNum(temp % 10);
////				MDIO_intWrite(PORT_A, PIN7, HIGH);
////				_delay_us(big_smol_delay);
////				MDIO_intWrite(PORT_A, PIN7, LOW);
////				MDIO_intWrite(PORT_C, PIN7, LOW);
////				HSSD_voidDisplayNum(temp / 10);
////				MDIO_intWrite(PORT_C, PIN7, HIGH);
////				_delay_us(big_smol_delay);
////			}
////			MDIO_intWritePort(PORT_B, 0x00);
////		}
////		temp++;
////		if (temp > 20)
////			temp = 0;
////		for (int i = 7; i >= 0; i--) {
////			MDIO_intWrite(PORT_B, i, HIGH);
////			for (int k = 0; k < 5; k++) {
////				MDIO_intWrite(PORT_A, PIN7, LOW);
////				MDIO_intWrite(PORT_C, PIN7, LOW);
////				HSSD_voidDisplayNum(temp % 10);
////				MDIO_intWrite(PORT_A, PIN7, HIGH);
////				_delay_us(big_smol_delay);
////				MDIO_intWrite(PORT_A, PIN7, LOW);
////				MDIO_intWrite(PORT_C, PIN7, LOW);
////				HSSD_voidDisplayNum(temp / 10);
////				MDIO_intWrite(PORT_C, PIN7, HIGH);
////				_delay_us(big_smol_delay);
////			}
////			MDIO_intWritePort(PORT_B, 0x00);
////		}
////		temp++;
////		if (temp > 20)
////			temp = 0;
//	}
//
//	return 0;
//}
