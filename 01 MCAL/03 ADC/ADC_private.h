/*
 * ADC_private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef  ADC_PRIVATE_H_
#define  ADC_PRIVATE_H_

#ifndef  SFIOR
#define  SFIOR			*( (volatile u8*)0x50 )
#endif
/*ADTS2 | ADTS1 | ADTS0 | Trigger Source
--------|-------|-------|-----------------
    0   |   0   |   0   | Free Running mode
    0   |   0   |   1   | Analog Comparator
    0   |   1   |   0   | External Interrupt Request 0
    0   |   1   |   1   | Timer/Counter0 Compare Match
    1   |   0   |   0   | Timer/Counter0 Overflow
    1   |   0   |   1   | Timer/Counter1 Compare Match B
    1   |   1   |   0   | Timer/Counter1 Overflow
    1   |   1   |   1   | Timer/Counter1 Capture Event
 */
#define  ADTS2			7						//ADC Auto Trigger Source Selection Bit 2
#define  ADTS1			6						//ADC Auto Trigger Source Selection Bit 1
#define  ADTS0			5						//ADC Auto Trigger Source Selection Bit 0
#define  ADCSR			*( (volatile u8*)0x28 )
#define  ADMUX			*( (volatile u8*)0x27 )
/*REFS1 REFS0 Voltage Reference Selection
-------|-----|---------------------------
    0  |  0  |AREF, Internal Vref turned off
    0  |  1  |AVCC with external capacitor at AREF pin
    1  |  0  |Reserved
    1  |  1  |Internal 2.56V Voltage Reference with external capacitor at AREF pin
    */
#define  REFS1			7						//Reference Selection Bit 1
#define  REFS0			6						//Reference Selection Bit 0
#define  ADLAR			5						//ADC Left Adjust Result
#define  MUX4			4						//Analog Channel and Gain Selection Bit 4
#define  MUX3			3                       //Analog Channel and Gain Selection Bit 3
#define  MUX2			2                       //Analog Channel and Gain Selection Bit 2
#define  MUX1			1                       //Analog Channel and Gain Selection Bit 1
#define  MUX0			0                       //Analog Channel and Gain Selection Bit 0
#define  ADCSRA			*( (volatile u8*)0x26 )
#define  ADEN			7						// ADC Enable
#define  ADSC			6						// ADC Start Conversion
#define  ADATE			5						// ADC Auto Trigger Enable
#define  ADIF			4						// ADC Interrupt Flag
#define  ADIE			3                       // ADC Interrupt Enable
/*ADPS2 ADPS1 ADPS0 Division Factor
-------|-----|-----|---------------
    0  |  0  |  0  |    2
    0  |  0  |  1  |    2
    0  |  1  |  0  |    4
    0  |  1  |  1  |    8
    1  |  0  |  0  |    16
    1  |  0  |  1  |    32
    1  |  1  |  0  |    64
    1  |  1  |  1  |    128
    */
#define  ADPS2			2                       // ADC Prescaler Select Bit 2
#define  ADPS1			1                       // ADC Prescaler Select Bit 1
#define  ADPS0			0                       // ADC Prescaler Select Bit 0
#define  ADCH			*( (volatile u8*)0x25 )
#define  ADCL			*( (volatile u8*)0x24 )


#define  AREF                     0             //AREF, Internal Vref turned off
#define  AVCC           		  1             //AVCC with external capacitor at AREF pin
#define  INTERNAL_2_56V           3             //Internal 2.56V Voltage Reference with external capacitor at AREF pin

#define  ENABLE                   1
#define  DISABLE                  0

/***
 * Declaration of the ADC ISR
 * INPUT: void
 * OUTPUT: void
 * Returns: void
 * **/
void __vector_16(void) __attribute__ ((signal,used));
#endif
