#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"
#include "GIE_config.h"


void MGIE_voidEnableGI(void){
	Set_Bit(SREG, I_BIT);
}

void MGIE_voidDisableGI(void){
	Clr_Bit(SREG, I_BIT);
}
