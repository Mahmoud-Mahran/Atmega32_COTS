#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include  "EXTI_private.h"
#include  "EXTI_interface.h"
#include  "EXTI_config.h"

static void (*ptrfunc_int0)(void) = NULL ;
static void (*ptrfunc_int1)(void) = NULL ;
static void (*ptrfunc_int2)(void) = NULL ;

void MEXTI_voidInit(void) {
#if  EXTI_INT0 == ENABLE
	Clr_Bit(MCUCR, ISC00);
	Clr_Bit(MCUCR, ISC01);
	MCUCR |= (SENSE_MODE_INT0 << ISC00);
	Set_Bit(GICR, INT0);
#endif
#if  EXTI_INT1 == ENABLE
	Clr_Bit(MCUCR, ISC10);
	Clr_Bit(MCUCR, ISC11);
	MCUCR |= (SENSE_MODE_INT1 << ISC10);
	Set_Bit(GICR, INT1);
#endif
#if  EXTI_INT2 == ENABLE
	Clr_Bit(GICR, INT2);
	Clr_Bit(MCUCSR, ISC2);
	MCUCSR |= (SENSE_MODE_INT2 << ISC2);
	Set_Bit(GICR, INT2);
#endif
}
void MEXTI_voidSetInt0Callback(void (*ptfc) (void)){
	ptrfunc_int0 = ptfc;
}
void MEXTI_voidSetInt1Callback(void (*ptfc) (void)){
	ptrfunc_int1 = ptfc;
}
void MEXTI_voidSetInt2Callback(void (*ptfc) (void)){
	ptrfunc_int2 = ptfc;
}
void __vector_1 (void){
	if(ptrfunc_int0 != NULL) ptrfunc_int0();
}
void __vector_2 (void){
	if(ptrfunc_int1 != NULL) ptrfunc_int1();
}
void __vector_3 (void){
	if(ptrfunc_int2 != NULL) ptrfunc_int2();

}
