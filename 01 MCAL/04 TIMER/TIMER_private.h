#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMSK              *( (volatile u8*)0x59)
#define TOIE0              0
#define OCIE0              1
#define TOIE1              2
#define OCIE1B             3
#define OCIE1A             4
#define TICIE1             5
#define TOIE2              6
#define OCIE2              7
#define TIFR               *( (volatile u8*)0x58)
#define TOV0               0
#define OCF0               1
#define TOV1               2
#define OCF1B              3
#define OCF1A              4
#define ICF1               5
#define TOV2               6
#define OCF2               7
/***************************************************/
/**            TIMER0 REGISTERS                   **/
/***************************************************/
#define TCCR0              *( (volatile u8*)0x53)
#define CS00               0
#define CS01               1
#define CS02               2
#define WGM01              3
#define COM00              4
#define COM01              5
#define WGM00              6
#define FOC0               7
#define TCNT0              *( (volatile u8*)0x52)
#define OCR0               *( (volatile u8*)0x5C)
/***************************************************/
/**            TIMER1 REGISTERS                   **/
/***************************************************/
#define TCCR1A             *( (volatile u8*)0x4F)
#define WGM10              0
#define WGM11              1
#define FOC1B              2
#define FOC1A              3
#define COM1B0             4
#define COM1B1             5
#define COM1A0             6
#define COM1A1             7
#define TCCR1B             *( (volatile u8*)0x4E)
#define CS10               0
#define CS11               1
#define CS12               2
#define WGM12              3
#define WGM13              4
#define ICES1              6
#define ICNC1              7
#define TCNT1H             *( (volatile u8*)0x4D)
#define TCNT1L             *( (volatile u8*)0x4C)
#define OCR1AH             *( (volatile u8*)0x4B)
#define OCR1AL             *( (volatile u8*)0x4A)
#define OCR1BH             *( (volatile u8*)0x49)
#define OCR1BL             *( (volatile u8*)0x48)
#define ICR1H              *( (volatile u8*)0x47)
#define ICR1L              *( (volatile u8*)0x46)
/***************************************************/
/**            TIMER2 REGISTERS                   **/
/***************************************************/
#define TCCR2              *( (volatile u8*)0x45)
#define CS20               0
#define CS21               1
#define CS22               2
#define WGM21              3
#define COM20              4
#define COM21              5
#define WGM20              6
#define FOC2               7
#define TCNT2              *( (volatile u8*)0x44)
#define OCR2               *( (volatile u8*)0x43)
#define ASSR               *( (volatile u8*)0x42)
#define TCR2UB             0
#define OCR2UB             1
#define TCN2UB             2
#define AS2                3
#ifndef SFIOR
#define SFIOR              *( (volatile u8*)0x50)
#endif
#define PSR2               1
///////////////////////CONFIG MACROS/////////////////////////
#define ENABLE                                           1
#define DISABLE                                          0
#define NO_PRE                                           1
#define PRE_8                                            2
#define PRE_64                                           3
#define PRE_256                                          4
#define PRE_1024                                         5
#define EXT_FALLING                                      6
#define EXT_RISING                                       7
#define NORMAL                                           0x00
//TIMER0 macros
#define CTC                                              0x08
#define PWM_PHASE_CORRECT                                0x40
#define FAST_PWM                                         0x48
#define OC0_OFF                                          0
#define TGL_OC0                                          1
#define CLR_OC0                                          2
#define SET_OC0                                          3
//TIMER1 macros
#define PWM_PHASE_CORRECT_8_BIT                          0x01
#define PWM_PHASE_CORRECT_9_BIT                          0x02
#define PWM_PHASE_CORRECT_10_BIT                         0x03
#define CTC_OCR1A_TOP                                    0x04
#define FAST_PWM_8_BIT                                   0x05
#define FAST_PWM_9_BIT                                   0x06
#define FAST_PWM_10_BIT                                  0x07
#define PWM_PHASE_FREQ_CORRECT_ICR1_TOP                  0x08
#define PWM_PHASE_FREQ_CORRECT_OCR1A_TOP                 0x09
#define PWM_PHASE_CORRECT_ICR1_TOP                       0x0A
#define PWM_PHASE_CORRECT_OCR1A_TOP                      0x0B
#define CTC_ICR1_TOP                                     0x0C
#define FAST_PWM_ICR1_TOP                                0x0E
#define FAST_PWM_OCR1A_TOP                               0x0F

#define OC1_OFF                                          0
#define TGL_OC1                                          1
#define CLR_OC1                                          2
#define SET_OC1                                          3


//TIMER2 macros
#define TM2_PWM_PHASE_CORRECT                            0x40
#define TM2_CTC                                          0x08
#define TM2_FAST_PWM                                     0x48
#define OC2_OFF                                          0
#define TGL_OC2                                          1
#define CLR_OC2                                          2
#define SET_OC2                                          3

#define TM2_PRE_32                                       3
#define TM2_PRE_64                                       4
#define TM2_PRE_128                                      5
#define TM2_PRE_256                                      6
#define TM2_PRE_1024                                     7

#endif
