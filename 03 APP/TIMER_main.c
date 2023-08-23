//#include "../00 LIB/STD_TYPES.h"
//#include "../00 LIB/BIT_MATH.h"
//#include "../01 MCAL/00 DIO/DIO_Interface.h"
//#include "../01 MCAL/04 TIMER/TIMER_interface.h"
//#include "../01 MCAL/03 GIE/GIE_interface.h"
//#include "../02 HAL/03 LCD/LCD_interface.h"
//u8 cnt_overflows = 0;
//u8 event_cnt = 0;
//u16 vals[3] = { 0 };
//u16 freq = 0;
//u16 Ton = 0;
//void my_cb(void);
//void test_servo(u8 angle);
//int main(void) {
//	MDIO_intInit(DIO_PORT_A, DIO_PIN7, DIO_OUTPUT);
//	MDIO_intWrite(DIO_PORT_A, DIO_PIN7, DIO_LOW);
//	HLCD_voidInit();
//	MDIO_intInit(DIO_PORT_B, DIO_PIN3, DIO_OUTPUT);
//	MDIO_intInit(DIO_PORT_D, DIO_PIN6, DIO_INPUT);
//	MDIO_intInit(DIO_PORT_D, DIO_PIN5, DIO_OUTPUT);
//	MTIMER_voidInit();
//	MTIMER_voidload(150, TIMER_TM0);
//	//MTIMER_voidSetCallBack(TIMER1_CAPT, my_cb);
//	//MTIMER_voidSetCallBack(TIMER1_OVF, test_ovf);
//	MTIMER_voidload(20000, TIMER_TM1_ICR);
//	//MTIMER_voidload(100, TIMER_TM1_CH_B);
//	MTIMER_voidGenerateNonPwmSignal(TIMER_TM0);
//	MTIMER_voidGenerateFastPwmSignal(TIMER_TM1_CH_A);
//	//MTIMER_voidGenerateFastPwmSignal(TIMER_TM1_CH_B);
//	MTIMER_voidStart(TIMER_TM0);
//	MTIMER_voidStart(TIMER_TM1);
//	//MGIE_voidEnableGI();
//	int i = 0;
//	while (1) {
//		while(i <= 180){
//			test_servo(i);
//			delay_ms(10);
//			i++;
//		}
//		while(i >= 0){
//			test_servo(i);
//			delay_ms(10);
//			i--;
//		}
////		HLCD_voidSendCommand(LCD_CLEAR_SC);
////		HLCD_voidSendString("FREQ=");
////		HLCD_voidSendCommand(LCD_NEXT_LINE);
////		HLCD_voidSendString("Ton=");
////		HLCD_voidGoToCursor(1, 6);
////		HLCD_voidSendNum(freq);
////		HLCD_voidGoToCursor(2, 5);
////		HLCD_voidSendNum(Ton);
////		for(int i = 400; i < 2200; i+=100){
////			MTIMER_voidload(i, TIMER_TM1_CH_A);
////			delay_ms(100);
////		}
////		for(int i = 2200; i > 400; i-=100){
////			MTIMER_voidload(i, TIMER_TM1_CH_A);
////			delay_ms(100);
////		}
//
//	}
//	return 0;
//}
//void test_servo(u8 angle){
//	u16 val = (u16)( ( (f32)angle/180.0)*2164.0 )+413;
//	MTIMER_voidload(val, TIMER_TM1_CH_A);
//}
//void my_cb(void) {
//	MDIO_intToggle(DIO_PORT_A, DIO_PIN7);
//	switch (event_cnt) {
//	case 0:
//		MTIMER_voidGetICU(&vals[0]);
//		MTIMER_voidSetICUEdge(TIMER_1_IC_FALLING);
//		event_cnt++;
//		break;
//	case 1:
//		MTIMER_voidGetICU(&vals[1]);
//		MTIMER_voidSetICUEdge(TIMER_1_IC_RISING);
//		event_cnt++;
//		break;
//	case 2:
//		MTIMER_voidGetICU(&vals[2]);
//		MTIMER_voidSetICUEdge(TIMER_1_IC_FALLING);
//		event_cnt = 0;
//		freq = vals[2] - vals[0];
//		Ton  = vals[1] - vals[0];
//		MTIMER_voidStop(TIMER_TM1);
//		break;
//	}
//}
