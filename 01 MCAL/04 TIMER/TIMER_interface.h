/*
 * TIMER_interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
/***
 * initializes TIMERS based on the selected config, returns void
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidInit(void);
/***
 * Starts a specific TIMER based on input, returns void
 * INPUT: (u8) Timer to start
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidStart(u8 u8cpyTimerNumber);
/***
 * Stops a specific TIMER based on input, returns void
 * INPUT: (u8) Timer to stop
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidStop(u8 u8cpyTimerNumber);
/***
 * Reads a specific TIMER's current value(counter register) based on input, returns void
 * INPUT: (u8) Timer to read, (u16*) pointer to store the value
 * OUTPUT: (u16) timer current value
 * Returns: void
 * **/
void MTIMER_voidRead(u8 u8cpyTimerNumber, u16* u16TimerValue);
/***
 * Preloads a specific TIMER value(counter register) based on input, returns void
 * INPUT:(u16) preload value , (u8) Timer to preload
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidPreload(u16 u16cpyValue, u8 u8cpyTimerNumber);
/***
 * Loads a specific TIMER value(compare register) based on input, returns void
 * INPUT:(u16) load value , (u8) Timer to load
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidload(u16 u16cpyValue, u8 u8cpyTimerNumber);
/***
 * Generates a non-pwm signal from a specific TIMER based on input, returns void
 * INPUT: (u8) Timer to generate signal from
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidGenerateNonPwmSignal(u8 u8cpyTimerNumber);
/***
 * Generates a fast pwm signal from a specific TIMER based on input, returns void
 * INPUT: (u8) Timer to generate signal from
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidGenerateFastPwmSignal(u8 u8cpyTimerNumber);
/***
 * Generates a phase correct pwm signal from a specific TIMER based on input, returns void
 * INPUT: (u8) Timer to generate signal from
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidGeneratePhasePwmSignal(u8 u8cpyTimerNumber);
/***
 * Specifies the working edge of timer1's input capture unit, returns void
 * INPUT: (u8) Wanted edge
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidSetICUEdge(u8 u8cpyIC_EDGE);
/***
 * Reads the value of timer1's input capture unit, returns void
 * INPUT: (u16*) Pointer to store the read value
 * OUTPUT: (u16) captured value
 * Returns: void
 * **/
void MTIMER_voidGetICU(u16 *u8cpy_Value);
/***
 * Sets the callback function for the input timer interrupt, returns void
 * INPUT: (u8) timer interrupt name, (*ptr) call back function
 * OUTPUT: void
 * Returns: void
 * **/
void MTIMER_voidSetCallBack(u8 u8cpyTimerInterruptNum, void (*ptr)(void));
/***
 * Reads the value of the input frequency & pulse width from the ICU, returns void
 * INPUT: (u16*) Pointer to store frequency, (u16*) Pointer to store pulse width
 * OUTPUT: (u16) signal frequency, (u16) signal TimeOn
 * Returns: void
 * **/
void MTIMER_voidMeasureSignal(u32 *u16cpy_frequency, u32 *u16cpy_timeOn);
//driver interfacing macros
#define    TIMER_TM0			0
#define    TIMER_TM1			1
#define    TIMER_TM2			2

#define    TIMER_TM1_ICR	    3
#define    TIMER_TM1_CH_A       4
#define    TIMER_TM1_CH_B	    5

#define    TIMER_1_IC_FALLING   0
#define    TIMER_1_IC_RISING    1
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
