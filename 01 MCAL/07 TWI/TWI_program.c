#include "../../00 LIB/STD_TYPES.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"
void MTWI_voidInit(void) {
	TWSR = (TWSR & 0x00) | (PRESCALER);
	TWCR = (TWCR & 0x00) | (GENERATE_ACK << TWEA) | (INTERRUPTS << TWIE);
	TWBR = (u8)( ( ( ((f64)F_CPU / (f64)FREQ) - 16)/ (f64)(2 * power(4, PRESCALER) ) ) );
}
void MTWI_voidSendStart(void) {
	TWCR |= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)))
		;
}
void MTWI_voidSendRepeatedStart(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)))
		;
}
void MTWI_voidSendSlaveAddress(u8 cpy_u8Address, u8 cpy_u8Mode) {
	TWDR = cpy_u8Address + cpy_u8Mode;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)))
		;
}
void MTWI_voidData(u8 *u8Byte, u8 cpy_u8Mode) {
	switch (cpy_u8Mode) {
	case TWI_WRITE:
		TWDR = *u8Byte;
		TWCR = (1 << TWINT) | (1 << TWEN) | (1<<TWEA);
		while (!(TWCR & (1 << TWINT)));
		break;
	case TWI_READ:
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while (!(TWCR & (1<<TWINT)));
		*u8Byte = TWDR;
		break;
	}
}
void MTWI_voidSendStop(void) {
	TWCR |= (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	while((TWCR & (1<<TWSTO)));
}
