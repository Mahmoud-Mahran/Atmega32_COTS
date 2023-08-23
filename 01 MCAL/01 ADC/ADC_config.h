#ifndef  ADC_CONFIG_H_
#define  ADC_CONFIG_H_
/*       Choose reference voltage      */
//options: { AREF, AVCC, INTERNAL_2_56V }
#define  VOLTAGE_REF	             AVCC
/*       Enable left adjustment     */
//options: { ENABLE, DISABLE }
#define  LEFT_ADJUST                 DISABLE
/*        Analog Channel and Gain Selection     */
/*options:
(Single Ended Input)
 Value   | Channel
 --------|-------------
 * 0     |   ADC0
 * 1     |   ADC1
 * 2     |   ADC2
 * 3     |   ADC3
 * 4     |   ADC4
 * 5     |   ADC5
 * 6     |   ADC6
 * 7     |   ADC7
 * 30    |   1.22V(Vbg)
 * 31    |   0V (GND)
(Differential)
  Gain   | Positive | Negative | Gain
---------|----------|----------|-----
 * 8     |  ADC0    | ADC0     | 10x
 * 9     |  ADC1    | ADC0     | 10x
 * 10    |  ADC0    | ADC0     | 200x
 * 11    |  ADC1    | ADC0     | 200x
 * 12    |  ADC2    | ADC2     | 10x
 * 13    |  ADC3    | ADC2     | 10x
 * 14    |  ADC2    | ADC2     | 200x
 * 15    |  ADC3    | ADC2     | 200x
 * 16    |  ADC0    | ADC1     | 1x
 * 17    |  ADC1    | ADC1     | 1x
 * 18    |  ADC2    | ADC1     | 1x
 * 19    |  ADC3    | ADC1     | 1x
 * 20    |  ADC4    | ADC1     | 1x
 * 21    |  ADC5    | ADC1     | 1x
 * 22    |  ADC6    | ADC1     | 1x
 * 23    |  ADC7    | ADC1     | 1x
 * 24    |  ADC0    | ADC2     | 1x
 * 25    |  ADC1    | ADC2     | 1x
 * 26    |  ADC2    | ADC2     | 1x
 * 27    |  ADC3    | ADC2     | 1x
 * 28    |  ADC4    | ADC2     | 1x
 * 29    |  ADC5    | ADC2     | 1x
 * */
#define  ADC_MUX                       0
/*       Auto trigger enable     */
//options: { ENABLE, DISABLE }
#define  ADC_AUTO_TRIGGER              DISABLE
/*       ADC Interrupt Enable     */
//options: { ENABLE, DISABLE }
#define  ADC_INTERRUPT                 DISABLE
/*         ADC Prescaler Selection     */
/*options:
 * value  : Division
 * 0      : 2
 * 1      : 2
 * 2      : 4
 * 3      : 8
 * 4      : 16
 * 5      : 32
 * 6      : 64
 * 7      : 128
 * */
#define  ADC_PRESCALER		            6
/*ADC Auto Trigger Source Selections
value : Trigger Source
------|------------------------------
0     | Free Running mode
1     | Analog Comparator
2     | External Interrupt Request 0
3     | Timer/Counter0 Compare Match
4     | Timer/Counter0 Overflow
5     | Timer/Counter1 Compare Match B
6     | Timer/Counter1 Overflow
7     | Timer/Counter1 Capture Event*/
#define  ADC_AUTO_TRIGGER_SRC           0

#endif
