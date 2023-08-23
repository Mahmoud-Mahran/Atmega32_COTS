#include "STD_TYPES.h"

void delay_ms(u32 ticks){
	for(u32 i = 0; i < (ticks * 500); i++){
		asm("NOP");
	}
}
u64 power(u64 num, u8 pow){
	if(pow == 0) return 1;
	while(pow > 1){
		num *= num;
		pow--;
	}
	return num;
}
