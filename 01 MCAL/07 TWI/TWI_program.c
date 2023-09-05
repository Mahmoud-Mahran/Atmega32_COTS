/*
 * TWI_program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"
void MTWI_voidInitMaster(void) {
	TWSR = (TWSR & 0x00) | (PRESCALER);
	TWCR = (TWCR & 0x00) | (INTERRUPTS << TWIE);
	TWBR = (u8)( ( ( ((f64)F_CPU / (f64)FREQ) - 16)/ (f64)(2 * power(4, PRESCALER) ) ) );
}
void MTWI_voidInitSlave(u8 cpy_u8Address){
	TWCR = (TWCR & 0x00) | (GENERATE_ACK<<TWEA) |(INTERRUPTS << TWIE) | (1 << TWEN);
	TWAR = (TWAR & 0x00) |  (cpy_u8Address<<1) | GENERAL_CALL;
}
void MTWI_voidSendStart(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != 0x08);

}
void MTWI_voidSendRepeatedStart(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != 0x10);
}
void MTWI_voidSendSlaveAddress(u8 cpy_u8Address, u8 cpy_u8Mode) {
	TWDR = ( (cpy_u8Address<<1) | cpy_u8Mode);
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	switch (cpy_u8Mode) {
	case TWI_WRITE:
		while((TWSR & 0xF8) != 0x18);
		break;
	case TWI_READ:
		while((TWSR & 0xF8) != 0x40);
		break;
	}

}
void MTWI_voidMasterData(u8 *u8Byte, u8 cpy_u8Mode) {
	switch (cpy_u8Mode) {
	case TWI_WRITE:
		TWDR = *u8Byte;
		TWCR = (1 << TWINT) | (1 << TWEN);
		while (!(TWCR & (1 << TWINT)));
		while((TWSR & 0xF8) != 0x28);
		break;
	case TWI_READ:
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while (!(TWCR & (1<<TWINT)));
		while((TWSR & 0xF8) != 0x50);
		*u8Byte = TWDR;
		break;
	}
}
//
void MTWI_voidSlaveData(u8 *u8Byte, u8 cpy_u8Mode){

}
void MTWI_voidSendStop(void) {
	TWCR |= (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	while((TWCR & (1<<TWSTO)));
}
void MTWI_voidMasterSendString(u8* cpy_string){
	while(cpy_string != '\0'){
		MTWI_voidMasterData(cpy_string, TWI_WRITE);
		cpy_string++;
	}
}
void MTWI_voidMasterReadString(u8* cpy_string){
	while(cpy_string != '\0'){
		MTWI_voidMasterData(cpy_string, TWI_READ);
		//delay_ms(5);
		cpy_string++;
	}
}
