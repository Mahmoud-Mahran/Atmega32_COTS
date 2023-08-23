#ifndef  ADC_INTERFACE_H_
#define  ADC_INTERFACE_H_

void MADC_voidInit(void);
void MADC_u16StartConversion(void);
void MADC_voidGetConversion(u16 *data);
void MADC_voidGetConversionBlocking(u16 *data);
void MADC_voidSetCallback(void (*ptfnc)(void));

void __vector_16(void) __attribute__ ((signal,used));
#endif
