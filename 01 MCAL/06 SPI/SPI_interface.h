#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
void MSPI_voidMasterInit(u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin);
void MSPI_voidSlaveInit(void);
void MSPI_voidMasterTRansmitReceive(u8 *cpy_u8Data,u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin);
void MSPI_voidSlaveReceive(u8 *cpy_u8Data);

#endif
