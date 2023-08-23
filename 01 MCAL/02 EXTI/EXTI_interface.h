#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

void MEXTI_voidInit(void);
void MEXTI_voidSetInt0Callback(void (*ptfc) (void));
void MEXTI_voidSetInt1Callback(void (*ptfc) (void));
void MEXTI_voidSetInt2Callback(void (*ptfc) (void));

void __vector_1(void) __attribute__ ((signal,used));
void __vector_2(void) __attribute__ ((signal,used));
void __vector_3(void) __attribute__ ((signal,used));

#endif
