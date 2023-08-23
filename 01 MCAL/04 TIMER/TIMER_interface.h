#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void MTIMER_voidInit(void);
void MTIMER_voidStart(u8 u8cpyTimerNumber);
void MTIMER_voidStop(u8 u8cpyTimerNumber);
void MTIMER_voidRead(u8 u8cpyTimerNumber, u16* u16TimerValue);
void MTIMER_voidPreload(u16 u16cpyValue, u8 u8cpyTimerNumber);
void MTIMER_voidload(u16 u16cpyValue, u8 u8cpyTimerNumber);
void MTIMER_voidGenerateNonPwmSignal(u8 u8cpyTimerNumber);
void MTIMER_voidGenerateFastPwmSignal(u8 u8cpyTimerNumber);
void MTIMER_voidGeneratePhasePwmSignal(u8 u8cpyTimerNumber);
void MTIMER_voidSetICUEdge(u8 u8cpyIC_EDGE);
void MTIMER_voidGetICU(u16 *u8cpy_Value);
void MTIMER_voidSetCallBack(u8 u8cpyTimerInterruptNum, void (*ptr)(void));
//TIMER INTERRUPT FUNCTIONS
void __vector_4  (void) __attribute__ ((signal, used));
void __vector_5  (void) __attribute__ ((signal, used));
void __vector_6  (void) __attribute__ ((signal, used));
void __vector_7  (void) __attribute__ ((signal, used));
void __vector_8  (void) __attribute__ ((signal, used));
void __vector_9  (void) __attribute__ ((signal, used));
void __vector_10 (void) __attribute__ ((signal, used));
void __vector_11 (void) __attribute__ ((signal, used));
//driver interfacing macros
#define    TIMER_TM0			0
#define    TIMER_TM1			1
#define    TIMER_TM2			2

#define    TIMER_TM1_ICR	    3
#define    TIMER_TM1_CH_A       4
#define    TIMER_TM1_CH_B	    5

#define    TIMER_1_IC_FALLING   0b00000000
#define    TIMER_1_IC_RISING    0b01000000
//TIMERS INTERRUPTS
#define    TIMER2_COMP          0
#define    TIMER2_OVF           1
#define    TIMER1_CAPT          2
#define    TIMER1_COMPA         3
#define    TIMER1_COMPB         4
#define    TIMER1_OVF           5
#define    TIMER0_COMP          6
#define    TIMER0_OVF           7
#endif
