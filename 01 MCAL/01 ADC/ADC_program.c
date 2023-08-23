#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"
void (*cb_func)(void);
void MADC_voidInit(void) {
	ADMUX  = 0x00;
	ADCSRA = 0x00;
	//selecting reference
	ADMUX |= (VOLTAGE_REF << REFS0);
#if LEFT_ADJUST == ENABLE
	Set_Bit(ADMUX, ADLAR);
#endif
	//selecting channel & gain
	ADMUX |= (ADC_MUX << MUX0);
	//enabling auto trigger
#if ADC_AUTO_TRIGGER == ENABLE
	SFIOR &= 0x0F;
	SFIOR |= (ADC_AUTO_TRIGGER_SRC<<ADTS0);
	Set_Bit(ADCSRA, ADATE);
#endif
	//enabling interrupt
#if ADC_INTERRUPT == ENABLE
	Set_Bit(ADCSRA, ADIE);
#endif
	//selecting prescaler
	ADCSRA |= (ADC_PRESCALER << ADPS0);
	//enabling ADC
	Set_Bit(ADCSRA, ADEN);
}

void MADC_u16StartConversion(void) {
	Set_Bit(ADCSRA, ADSC);
}

void MADC_voidGetConversion(u16 *data){
#if LEFT_ADJUST == DISABLE
	*data =  ADCL | ( ADCH<<8 );
#elif LEFT_ADJUST == ENABLE
	*data =  ADCH | ( ADCL>>8 );
#endif
}
void MADC_voidGetConversionBlocking(u16 *data){
	while(!(ADCSRA & (1<<ADIF)));
#if LEFT_ADJUST == DISABLE
	*data =  ADCL | ( ADCH<<8 );
#elif LEFT_ADJUST == ENABLE
	*data =  ADCH | ( ADCL>>8 );
#endif
}
void MADC_voidSetCallback(void (*ptfnc)(void)){
	cb_func = ptfnc;
}

void __vector_16(void){
	cb_func();
}
