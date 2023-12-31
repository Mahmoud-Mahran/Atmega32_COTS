/*
 * SSD_Program.c
 *
 *  Created on: Aug 06, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "SSD_Config.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"

void    HSSD_voidInit(void){

	MDIO_intInit(HSSD_PORTA, HSSD_PINA, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTB, HSSD_PINB, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTC, HSSD_PINC, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTD, HSSD_PIND, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTE, HSSD_PINE, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTF, HSSD_PINF, DIO_OUTPUT);
	MDIO_intInit(HSSD_PORTG, HSSD_PING, DIO_OUTPUT);

}
void    HSSD_voidDisplayNum(u8 cpy_u8Num){
	u8 num = 0;
	if(cpy_u8Num >=0 && cpy_u8Num < 10){
		switch(cpy_u8Num){
		case 0: num = zero; break;
		case 1: num = one; break;
		case 2: num = two; break;
		case 3: num = three; break;
		case 4: num = four; break;
		case 5: num = five; break;
		case 6: num = six; break;
		case 7: num = seven; break;
		case 8: num = eight; break;
		case 9: num = nine; break;
		}
	} else{
		//error
		return;
	}
#if MODE == COMMON_CATHODE
	MDIO_intWrite(HSSD_PORTA, HSSD_PINA, !Get_Bit(num, 0) );
	MDIO_intWrite(HSSD_PORTB, HSSD_PINB, !Get_Bit(num, 1) );
	MDIO_intWrite(HSSD_PORTC, HSSD_PINC, !Get_Bit(num, 2) );
	MDIO_intWrite(HSSD_PORTD, HSSD_PIND, !Get_Bit(num, 3) );
	MDIO_intWrite(HSSD_PORTE, HSSD_PINE, !Get_Bit(num, 4) );
	MDIO_intWrite(HSSD_PORTF, HSSD_PINF, !Get_Bit(num, 5) );
	MDIO_intWrite(HSSD_PORTG, HSSD_PING, !Get_Bit(num, 6) );
#elif MODE == COMMON_ANODE
	MDIO_intWrite(HSSD_PORTA, HSSD_PINA, Get_Bit(num, 0) );
	MDIO_intWrite(HSSD_PORTB, HSSD_PINB, Get_Bit(num, 1) );
	MDIO_intWrite(HSSD_PORTC, HSSD_PINC, Get_Bit(num, 2) );
	MDIO_intWrite(HSSD_PORTD, HSSD_PIND, Get_Bit(num, 3) );
	MDIO_intWrite(HSSD_PORTE, HSSD_PINE, Get_Bit(num, 4) );
	MDIO_intWrite(HSSD_PORTF, HSSD_PINF, Get_Bit(num, 5) );
	MDIO_intWrite(HSSD_PORTG, HSSD_PING, Get_Bit(num, 6) );
#endif
}
