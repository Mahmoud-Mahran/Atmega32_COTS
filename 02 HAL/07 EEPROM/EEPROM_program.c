/*
 * EEPROM_program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "../../01 MCAL/07 TWI/TWI_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"
#include "EEPROM_config.h"

void HEEPROM_voidInit(void){
	MTWI_voidInitMaster();
}

void HEEPROM_voidWriteByte(u8 *cpy_u8Data, u16 cpy_u16ByteAddress){
	    u8 local_u8SlavePageAdd = 0x50 | (cpy_u16ByteAddress>>8);
		u8 local_u8ByteAdd = (u8)(cpy_u16ByteAddress & 0x00FF);
		MTWI_voidSendStart();
		MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_WRITE);
		MTWI_voidMasterData(&local_u8ByteAdd, TWI_WRITE);
		MTWI_voidMasterData(cpy_u8Data, TWI_WRITE);
		MTWI_voidSendStop();
}
void HEEPROM_voidWrite16BytePage(u8 cpy_u8Data[16], u8 cpy_u8PageAddress){
	if(cpy_u8PageAddress >= 0 && cpy_u8PageAddress <64){
	    u16 local_u16ByteAddress = 0x0000;
	    local_u16ByteAddress += 16 * cpy_u8PageAddress;
	    u8 local_u8SlavePageAdd = 0x50 | (local_u16ByteAddress>>8);
		u8 local_u8ByteAdd = (u8)(local_u16ByteAddress & 0x00FF);
		MTWI_voidSendStart();
		MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_WRITE);
		MTWI_voidMasterData(&local_u8ByteAdd, TWI_WRITE);
		for(int i = 0; i < 16; i++){
			MTWI_voidMasterData(&cpy_u8Data[i], TWI_WRITE);
		}
		MTWI_voidSendStop();
	} else {
		//error
	}
}

void HEEPROM_voidReadByte(u8 *cpy_u8Data, u16 cpy_u16ByteAddress){
    u8 local_u8SlavePageAdd = 0x50 | (cpy_u16ByteAddress>>8);
	u8 local_u8ByteAdd = (u8)(cpy_u16ByteAddress & 0x00FF);
	MTWI_voidSendStart();
	MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_WRITE);
	MTWI_voidMasterData(&local_u8ByteAdd, TWI_WRITE);
	MTWI_voidSendRepeatedStart();
	MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_READ);
	MTWI_voidMasterData(cpy_u8Data, TWI_READ);
	MTWI_voidSendStop();
}
void HEEPROM_voidRead16BytePage(u8 cpy_u8Data[16], u8 cpy_u8PageAddress){
	if(cpy_u8PageAddress >= 0 && cpy_u8PageAddress <64){
	    u16 local_u16ByteAddress = 0x0000;
	    local_u16ByteAddress += 16 * cpy_u8PageAddress;
	    u8 local_u8SlavePageAdd = 0x50 | (local_u16ByteAddress>>8);
		u8 local_u8ByteAdd = (u8)(local_u16ByteAddress & 0x00FF);
		MTWI_voidSendStart();
		MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_WRITE);
		MTWI_voidMasterData(&local_u8ByteAdd, TWI_WRITE);
		MTWI_voidSendRepeatedStart();
		MTWI_voidSendSlaveAddress(local_u8SlavePageAdd, TWI_READ);
		for(int i = 0; i < 16; i++){
			MTWI_voidMasterData(&cpy_u8Data[i], TWI_READ);
		}
		MTWI_voidSendStop();
	} else {
		//error
	}

}
