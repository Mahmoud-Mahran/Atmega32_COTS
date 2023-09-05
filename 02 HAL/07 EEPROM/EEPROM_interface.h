/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void HEEPROM_voidInit(void);
void HEEPROM_voidWriteByte(u8 *cpy_u8Data, u16 cpy_u16ByteAddress);
void HEEPROM_voidWrite16BytePage(u8 cpy_u8Data[16], u8 cpy_u8PageAddress);
void HEEPROM_voidReadByte(u8 *cpy_u8Data, u16 cpy_u16ByteAddress);
void HEEPROM_voidRead16BytePage(u8 cpy_u8Data[16], u8 cpy_u8PageAddress);

#endif
