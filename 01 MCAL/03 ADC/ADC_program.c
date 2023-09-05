/*
 * ADC_program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../03 ADC/ADC_config.h"
#include "../03 ADC/ADC_interface.h"
#include "../03 ADC/ADC_private.h"
//pointer to function to be called in ISR
void (*cb_func)(void);
void MADC_voidInit(void) {
	//reseting config
	ADMUX = 0x00;
	ADCSRA = 0x00;
	SFIOR &= 0x0F;
	//ADMUX setting
	ADMUX = (VOLTAGE_REF << REFS0) | (LEFT_ADJUST << ADLAR) | (ADC_MUX << MUX0);
	//SFIOR setting
	SFIOR |= (ADC_AUTO_TRIGGER_SRC << ADTS0);
	//ADCSRA setting
	ADCSRA = (ADC_PRESCALER << ADPS0) | (ADC_AUTO_TRIGGER << ADATE)
			 | (ADC_INTERRUPT << ADIE);
	//enabling ADC
	Set_Bit(ADCSRA, ADEN);
}

void MADC_voidStartConversion(void) {
	Set_Bit(ADCSRA, ADSC);
}

void MADC_voidGetConversion(u16 *data) {
#if LEFT_ADJUST == DISABLE
	*data = ADCL | ( ADCH << 8);
#elif LEFT_ADJUST == ENABLE
	*data = ADCH | ( ADCL>>8 );
#endif
}
void MADC_voidGetConversionBlocking(u16 *data) {
	while (!(ADCSRA & (1 << ADIF)))
		;
#if LEFT_ADJUST == DISABLE
	*data = ADCL | ( ADCH << 8);
#elif LEFT_ADJUST == ENABLE
	*data = ADCH | ( ADCL>>8 );
#endif
}
void MADC_voidSetCallback(void (*ptfnc)(void)) {
	cb_func = ptfnc;
}

void __vector_16(void) {
	cb_func();
}
