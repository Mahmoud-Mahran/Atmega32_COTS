#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (*ptr_func[8])(void) = { NULL };
void MTIMER_voidInit(void) {
#if TIMER_0 == ENABLE
	TCCR0 = ((TCCR0 & 0x00) | TIMER_0_MODE);
	TCNT0 = 0x00;
	OCR0 = 0x00;
#endif
#if TIMER_1 == ENABLE
	TCCR1A = ((TCCR1A & 0x00) | (TIMER_1_MODE & 0x03));
	TCCR1B = ((TCCR1B & 0x00) | ((TIMER_1_MODE >> 2) << WGM12)
			| (IC_EDGE << ICES1) | (ICNC << ICNC1));
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	OCR1AH = 0x00;
	OCR1AL = 0x00;
	OCR1BH = 0x00;
	OCR1BL = 0x00;
	ICR1H = 0x00;
	ICR1L = 0x00;
#endif
#if TIMER_2 == ENABLE
	TCCR2 = ((TCCR2 & 0x00) | TIMER_2_MODE);
	TCNT2 = 0x00;
	OCR2 = 0x00;
	ASSR = 0x00;
#endif
	TIMSK = 0x00;
	TIMSK = (TIMER_0_OC_INTERRUPT << OCIE0) | (TIMER_0_OVF_INTERRUPT << TOIE0)
			| (TIMER_1_IC_INTERRUPT << TICIE1)
			| (TIMER_1_OCA_INTERRUPT << OCIE1A)
			| (TIMER_1_OCB_INTERRUPT << OCIE1B)
			| (TIMER_1_OVF_INTERRUPT << TOIE1) | (TIMER_2_OC_INTERRUPT << OCIE2)
			| (TIMER_2_OVF_INTERRUPT << TOIE2);
	TIFR = 0x00;
}
void MTIMER_voidStart(u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCCR0 |= (TIMER_0_CLK << CS00);
		break;
	case TIMER_TM1:
		TCCR1B |= (TIMER_1_CLK << CS10);
		break;
	case TIMER_TM2:
		TCCR2 |= (TIMER_2_CLK << CS20);
		break;
	}

}
void MTIMER_voidStop(u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCCR0 &= 0xF8;
		break;
	case TIMER_TM1:
		TCCR1B &= 0xF8;
		break;
	case TIMER_TM2:
		TCCR2 &= 0xF8;
		break;
	}

}
void MTIMER_voidRead(u8 u8cpyTimerNumber, u16* u16TimerValue) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		*u16TimerValue = TCNT0;
		break;
	case TIMER_TM1:
		*u16TimerValue = (TCNT1L | (TCNT1H << 8));
		break;
	case TIMER_TM2:
		*u16TimerValue = TCNT2;
		break;
	}
}
void MTIMER_voidPreload(u16 u16cpyValue, u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCNT0 = (u8) u16cpyValue;
		break;
	case TIMER_TM1:
		TCNT1L = (u8) u16cpyValue;
		TCNT1H = (u8) (u16cpyValue >> 8);
		break;
	case TIMER_TM2:
		TCNT2 = (u8) u16cpyValue;
		break;
	}
}
void MTIMER_voidload(u16 u16cpyValue, u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		OCR0 = (u8) u16cpyValue;
		break;
	case TIMER_TM1_ICR:
		ICR1H = (u8) (u16cpyValue >> 8);
		ICR1L = (u8) u16cpyValue;
		break;
	case TIMER_TM1_CH_A:
		OCR1AH = (u8) (u16cpyValue >> 8);
		OCR1AL = (u8) u16cpyValue;
		break;
	case TIMER_TM1_CH_B:
		OCR1BH = (u8) (u16cpyValue >> 8);
		OCR1BL = (u8) u16cpyValue;
		break;
	case TIMER_TM2:
		OCR2 = (u8) u16cpyValue;
		break;
	}
}
void MTIMER_voidGenerateNonPwmSignal(u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCCR0 = ((TCCR0 & 0xCF) | (TIMER_0_NORMAL << COM00));
		break;
	case TIMER_TM1_CH_A:
		TCCR1A = ((TCCR1A & 0x3F) | (TIMER_1_NORMAL_A << COM1A0));
		break;
	case TIMER_TM1_CH_B:
		TCCR1A = ((TCCR1A & 0xCF) | (TIMER_1_NORMAL_B << COM1B0));
		break;
	case TIMER_TM2:
		TCCR2 = ((TCCR2 & 0xCF) | (TIMER_2_NORMAL << COM20));
		break;
	}
}
void MTIMER_voidGenerateFastPwmSignal(u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCCR0 = ((TCCR0 & 0xCF) | (TIMER_0_FAST_PWM << COM00));
		break;
	case TIMER_TM1_CH_A:
		TCCR1A = ((TCCR1A & 0x3F) | (TIMER_1_FAST_PWM_A << COM1A0));
		break;
	case TIMER_TM1_CH_B:
		TCCR1A = ((TCCR1A & 0xCF) | (TIMER_1_FAST_PWM_B << COM1B0));
		break;
	case TIMER_TM2:
		TCCR2 = ((TCCR2 & 0xCF) | (TIMER_2_FAST_PWM << COM20));
		break;
	}
}
void MTIMER_voidGeneratePhasePwmSignal(u8 u8cpyTimerNumber) {
	switch (u8cpyTimerNumber) {
	case TIMER_TM0:
		TCCR0 = ((TCCR0 & 0xCF) | (TIMER_0_PHASE_PWM << COM00));
		break;
	case TIMER_TM1_CH_A:
		TCCR1A = ((TCCR1A & 0x3F) | (TIMER_1_PHASE_PWM_A << COM1A0));
		break;
	case TIMER_TM1_CH_B:
		TCCR1A = ((TCCR1A & 0xCF) | (TIMER_1_PHASE_PWM_B << COM1B0));
		break;
	case TIMER_TM2:
		TCCR2 = ((TCCR2 & 0xCF) | (TIMER_2_PHASE_PWM << COM20));
		break;
	}
}
void MTIMER_voidSetCallBack(u8 u8cpyTimerInterruptNum, void (*ptr)(void)) {
	if (u8cpyTimerInterruptNum >= 0 && u8cpyTimerInterruptNum < 8) {
		ptr_func[u8cpyTimerInterruptNum] = ptr;
	} else {
		//input error
	}
}
void MTIMER_voidSetICUEdge(u8 u8cpyIC_EDGE) {
	TCCR1B &= u8cpyIC_EDGE;
}
void MTIMER_voidGetICU(u16 *u8cpy_Value) {
	*u8cpy_Value = (ICR1L | (ICR1H << 8));
}
void __vector_4(void) {
	if (ptr_func[TIMER2_COMP] != NULL)
		ptr_func[TIMER2_COMP]();
}
void __vector_5(void) {
	if (ptr_func[TIMER2_OVF] != NULL)
		ptr_func[TIMER2_OVF]();
}
void __vector_6(void) {
	if (ptr_func[TIMER1_CAPT] != NULL)
		ptr_func[TIMER1_CAPT]();
}
void __vector_7(void) {
	ptr_func[TIMER1_COMPA]();
}
void __vector_8(void) {
	ptr_func[TIMER1_COMPB]();
}
void __vector_9(void) {
	ptr_func[TIMER1_OVF]();
}
void __vector_10(void) {
	ptr_func[TIMER0_COMP]();
}
void __vector_11(void) {
	ptr_func[TIMER0_OVF]();
}
