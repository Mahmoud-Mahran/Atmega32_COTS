/*
 * GIE_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../02 GIE/GIE_config.h"
#include "../02 GIE/GIE_interface.h"
#include "../02 GIE/GIE_private.h"


void MGIE_voidEnableGI(void){
	Set_Bit(SREG, I_BIT);
}

void MGIE_voidDisableGI(void){
	Clr_Bit(SREG, I_BIT);
}
