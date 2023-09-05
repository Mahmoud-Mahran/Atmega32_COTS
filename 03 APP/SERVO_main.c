//#include "../00 LIB/STD_TYPES.h"
//#include "../00 LIB/BIT_MATH.h"
//#include "../01 MCAL/04 TIMER/TIMER_interface.h"
//#include "../02 HAL/05 SERVO/SERVO_interface.h"
//
//int main(void){
//	HSERVO_voidInit();
//	HSERVO_voidSelectChannel(TIMER_TM1_CH_A);
//	u8 ang = 0;
//	while(1){
//		while(ang < 181){
//			HSERVO_voidWriteAngle(ang, TIMER_TM1_CH_A);
//			ang++;
//			delay_ms(5);
//		}
//		while(ang > 0){
//			HSERVO_voidWriteAngle(ang, TIMER_TM1_CH_A);
//			ang--;
//			delay_ms(5);
//		}
//	}
//	return 0;
//}
