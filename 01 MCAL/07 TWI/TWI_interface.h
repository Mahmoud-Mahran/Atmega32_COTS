#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

void MTWI_voidInit(void);
void MTWI_voidSendStart(void);
void MTWI_voidSendRepeatedStart(void);
void MTWI_voidSendSlaveAddress(u8 cpy_u8Address, u8 cpy_u8Mode);
void MTWI_voidData(u8 *u8Byte, u8 cpy_u8Mode);
void MTWI_voidSendStop(void);

#define TWI_WRITE      0
#define TWI_READ       1
#endif
