#include "../00 LIB/STD_TYPES.h"
#include "../00 LIB/BIT_MATH.h"
#include "../01 MCAL/07 TWI/TWI_interface.h"

int main(void){
	MTWI_voidInit();
	MTWI_voidSendStart();
	MTWI_voidSendSlaveAddress((15<<1), TWI_WRITE);
	u8 data = 'H';
	//u8 dummy = 0x00;
	//MTWI_voidData(&dummy, TWI_WRITE);
	MTWI_voidData(&data, TWI_WRITE);
	MTWI_voidSendStop();
	while(1){

	}
	return 0;
}
