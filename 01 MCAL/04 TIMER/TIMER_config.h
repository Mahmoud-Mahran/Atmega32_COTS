/*
 * TIMER_config.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H
#ifndef F_CPU
#define F_CPU         8000000UL
#endif
///////////////Enable Or Disable Timers///////////////
#define TIMER_0			    ENABLE
#define TIMER_1			    ENABLE
#define TIMER_2			    DISABLE

/***************************************/
/*************TIMER0 CONFIG*************/
/***************************************/
///////////////CHOOSE MODE OF OPERATION///////////////
/* Timer/Counter Mode of Operation | TOP | Update of OCR0 | TOV0 Flag Set-on
-----------------------------------|-----|----------------|-----------------
               NORMAL              |0xFF |    Immediate   |      MAX
               CTC                 |0xFF |       TOP      |     BOTTOM
               PWM_PHASE_CORRECT   |OCR0 |    Immediate   |      MAX
               FAST_PWM            |0xFF |     BOTTOM     |      MAX
 */
#define TIMER_0_MODE         FAST_PWM
///////////////CHOOSE NORMAL/CTC MODE CONFIG///////////////
/*options in Compare Output Mode, non-PWM Mode
OC0_OFF: Normal port operation, OC0 disconnected.
TGL_OC0: Toggle OC0 on compare match
CLR_OC0: Clear OC0 on compare match
SET_OC0: Set OC0 on compare match
*/
#define TIMER_0_NORMAL       TGL_OC0
///////////////CHOOSE FAST PWM MODE CONFIG////////////////
/*options in Compare Output Mode, Fast PWM Mode
OC0_OFF: Normal port operation, OC0 disconnected.
CLR_OC0: Clear OC0 on compare match, set OC0 at BOTTOM, (non-inverting mode)
SET_OC0: Set OC0 on compare match, clear OC0 at BOTTOM, (inverting mode)
*/
#define TIMER_0_FAST_PWM     CLR_OC0
///////////////CHOOSE Phase Correct PWM MODE CONFIG////////////////
/*options in Compare Output Mode,  Phase Correct PWM Mode
OC0_OFF: Normal port operation, OC0 disconnected.
CLR_OC0: Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
SET_OC0: Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
*/
#define TIMER_0_PHASE_PWM    CLR_OC0
///////////////CHOOSE TIMER0 CLOCK SOURCE///////////////
/*options   :
NO_PRE      : F_CPU (No prescaling)
PRE_8       : F_CPU / 8 (From prescaler)
PRE_64      : F_CPU / 64 (From prescaler)
PRE_256     : F_CPU / 256 (From prescaler)
PRE_1024    : F_CPU / 1024 (From prescaler)
EXT_FALLING : External clock source on T0 pin. Clock on falling edge.
EXT_RISING  : External clock source on T0 pin. Clock on rising edge.
*/
#define TIMER_0_CLK           PRE_8
///////////////ENABLE TIMER0 INTERRUPTS///////////////
#define TIMER_0_OC_INTERRUPT  DISABLE
#define TIMER_0_OVF_INTERRUPT DISABLE
/***************************************/
/*************TIMER1 CONFIG*************/
/***************************************/
///////////////CHOOSE MODE OF OPERATION///////////////
/* Timer/Counter Mode of Operation |  TOP  | Update of OCR1x | TOV1 Flag Set-on
-----------------------------------|-------|-----------------|-----------------
NORMAL                             |0xFFFF |Immediate        |MAX
PWM_PHASE_CORRECT_8_BIT            |0x00FF |TOP              |BOTTOM
PWM_PHASE_CORRECT_9_BIT            |0x01FF |TOP              |BOTTOM
PWM_PHASE_CORRECT_10_BIT           |0x03FF |TOP              |BOTTOM
CTC_OCR1A_TOP                      |OCR1A  |Immediate        |MAX
FAST_PWM_8_BIT                     |0x00FF |BOTTOM           |TOP
FAST_PWM_9_BIT                     |0x01FF |BOTTOM           |TOP
FAST_PWM_10_BIT                    |0x03FF |BOTTOM           |TOP
PWM_PHASE_FREQ_CORRECT_ICR1_TOP    |ICR1   |BOTTOM           |BOTTOM
PWM_PHASE_FREQ_CORRECT_OCR1A_TOP   |OCR1A  |BOTTOM           |BOTTOM
PWM_PHASE_CORRECT_ICR1_TOP         |ICR1   |TOP              |BOTTOM
PWM_PHASE_CORRECT_OCR1A_TOP        |OCR1A  |TOP              |BOTTOM
CTC_ICR1_TOP                       |ICR1   |Immediate        |MAX
FAST_PWM_ICR1_TOP                  |ICR1   |BOTTOM           |TOP
FAST_PWM_OCR1A_TOP                 |OCR1A  |BOTTOM           |TOP
*/
#define TIMER_1_MODE         NORMAL
///////////////CHOOSE NORMAL/CTC MODE CONFIG FOR CH A & CH B///////////////
/*options in Compare Output Mode, non-PWM Mode
OC1_OFF: Normal port operation, OC1A/OC1B disconnected.
TGL_OC1: Toggle OC1A/OC1B on compare match
CLR_OC1: Clear OC1A/OC1B on compare match (Set output to low level)
SET_OC1: Set OC1A/OC1B on compare match (Set output to high level)
*/
#define TIMER_1_NORMAL_A     TGL_OC1
#define TIMER_1_NORMAL_B     TGL_OC1
///////////////CHOOSE FAST PWM MODE CONFIG FOR CH A & CH B////////////////
/*options in Compare Output Mode, Fast PWM Mode
OC1_OFF: Normal port operation, OC1A/OC1B disconnected.
TGL_OC1: FAST_PWM_OCR1A_TOP Mode: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
         For all other Modes, normal port operation, OC1A/OC1B disconnected.
CLR_OC1: Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when down-counting.
SET_OC1: Set OC1A/OC1B on compare match when up-counting. Clear OC1A/OC1B on compare match when down-counting.
*/
#define TIMER_1_FAST_PWM_A    CLR_OC1
#define TIMER_1_FAST_PWM_B    CLR_OC1
///////////////CHOOSE Phase Correct PWM and Phase and Frequency Correct PWM MODE CONFIG FOR CH A & CH B////////////////
/*options in Compare Output Mode,  Phase Correct PWM Mode
OC1_OFF:  Normal port operation, OC1A/OC1B disconnected.
TGL_OC1: -PWM_PHASE_FREQ_CORRECT_OCR1A_TOP & FAST_PWM_ICR1_TOP Modes:
            Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
         -For all other Modes, normal port operation, OC1A/OC1B disconnected.
CLR_OC1: Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when down-counting.
SET_OC1: Set OC1A/OC1B on compare match when up-counting. Clear OC1A/OC1B on compare match when down-counting.
*/
#define TIMER_1_PHASE_PWM_A   TGL_OC1
#define TIMER_1_PHASE_PWM_B   TGL_OC1
///////////////Enable OR Disable Input Capture Noise Canceler///////////////
//options: { ENABLE, DISABLE }
#define ICNC                  DISABLE
///////////////Choose Falling OR Rising Edge For Input Capture///////////////
//options: { TIMER_1_IC_FALLING, TIMER_1_IC_RISING }
#define IC_EDGE               TIMER_1_IC_FALLING
///////////////CHOOSE TIMER1 CLOCK SOURCE///////////////
/*options   :
NO_PRE      : F_CPU (No prescaling)
PRE_8       : F_CPU / 8 (From prescaler)
PRE_64      : F_CPU / 64 (From prescaler)
PRE_256     : F_CPU / 256 (From prescaler)
PRE_1024    : F_CPU / 1024 (From prescaler)
EXT_FALLING : External clock source on T1 pin. Clock on falling edge
EXT_RISING  : External clock source on T1 pin. Clock on rising edge.
*/
#define TIMER_1_CLK          NO_PRE
///////////////ENABLE TIMER1 INTERRUPTS///////////////
#define TIMER_1_IC_INTERRUPT  DISABLE
#define TIMER_1_OCA_INTERRUPT DISABLE
#define TIMER_1_OCB_INTERRUPT DISABLE
#define TIMER_1_OVF_INTERRUPT DISABLE
/***************************************/
/*************TIMER2 CONFIG*************/
/***************************************/
///////////////CHOOSE MODE OF OPERATION///////////////
/* Timer/Counter Mode of Operation | TOP | Update of OCR0 | TOV0 Flag Set-on
-----------------------------------|-----|----------------|-----------------
           TM2_NORMAL              |0xFF |    Immediate   |      MAX
           TM2_PWM_PHASE_CORRECT   |0xFF |       TOP      |     BOTTOM
           TM2_CTC                 |OCR2 |    Immediate   |      MAX
           TM2_FAST_PWM            |0xFF |     BOTTOM     |      MAX
*/
#define TIMER_2_MODE         TM2_FAST_PWM
///////////////CHOOSE NORMAL/CTC MODE CONFIG///////////////
/*options in Compare Output Mode, non-PWM Mode
OC2_OFF: Normal port operation, OC2 disconnected.
TGL_OC2: Toggle OC2 on compare match
CLR_OC2: Clear OC2 on compare match
SET_OC2: Set OC2 on compare match
*/
#define TIMER_2_NORMAL       TGL_OC2
///////////////CHOOSE FAST PWM MODE CONFIG////////////////
/*options in Compare Output Mode, Fast PWM Mode
OC2_OFF: Normal port operation, OC2 disconnected.
CLR_OC2: Clear OC2 on compare match, set OC0 at BOTTOM, (non-inverting mode)
SET_OC2: Set OC2 on compare match, clear OC0 at BOTTOM, (inverting mode)
*/
#define TIMER_2_FAST_PWM     CLR_OC2
///////////////CHOOSE Phase Correct PWM MODE CONFIG////////////////
/*options in Compare Output Mode,  Phase Correct PWM Mode
OC2_OFF: Normal port operation, OC2 disconnected.
CLR_OC2: Clear OC2 on compare match when up-counting. Set OC2 on compare match when down-counting.
SET_OC2: Set OC2 on compare match when up-counting. Clear OC0 on compare match when down-counting.
*/
#define TIMER_2_PHASE_PWM    CLR_OC2
///////////////CHOOSE TIMER0 CLOCK SOURCE///////////////
/*options       :
NO_PRE          : F_CPU (No prescaling)
PRE_8           : F_CPU / 8 (From prescaler)
TM2_PRE_32      : F_CPU / 32 (From prescaler)
TM2_PRE_64      : F_CPU / 64 (From prescaler)
TM2_PRE_128     : F_CPU / 128 (From prescaler)
TM2_PRE_256     : F_CPU / 256 (From prescaler)
TM2_PRE_1024    : F_CPU / 1024 (From prescaler)
*/
#define TIMER_2_CLK          TM2_PRE_1024
///////////////ENABLE TIMER2 INTERRUPTS///////////////
#define TIMER_2_OC_INTERRUPT  DISABLE
#define TIMER_2_OVF_INTERRUPT DISABLE
#endif
