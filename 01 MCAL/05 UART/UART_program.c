/*
 * UART_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"

void MUART_voidInit(void) {
#if DOUBLE_SPEED == ENABLE

#elif DOUBLE_SPEED == DISABLE
	u16 ubbr = (u16) (((double) F_CPU / (16 * (double) BAUDE_RATE)) - 1);
	UBRRL = (u8) ubbr;
	UBRRH = (u8) (ubbr >> 8);
#endif
	UCSRA = ((UCSRA & 0x00) | (DOUBLE_SPEED << U2X));
	UCSRB = ((UCSRB & 0x00) | (RX_INTERRUPT << RXCIE) | (TX_INTERRUPT << TXCIE)
			| (REG_EMPTY_INTERRUPT << UDRIE) | (UART_RX << RXEN)
			| (UART_TX << TXEN));
#if CHAR_SIZE == BIT_9
	Set_Bit(UCSRB, UCSZ2);
#endif
	UCSRC = ((1 << URSEL) | (PARITY << UPM0) | (STOP_BITS << USBS)
			| (CHAR_SIZE << UCSZ0) | (POLARITY << UCPOL));

}
void MUART_voidTX_Byte(u8 u8cpyData) {
	/* Wait for empty transmit buffer */
	while(!(UCSRA & (1 << UDRE)));
	UDR = u8cpyData;
}
void MUART_voidRX_Byte(u8 *u8Data) {
	/* Wait for data to be received */
	while(!(UCSRA & (1 << RXC)));
	/* Get and return received data from buffer */
	*u8Data = UDR;
}
