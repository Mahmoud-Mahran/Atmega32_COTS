#include "../../00 LIB/STD_TYPES.h"
#include "../../00 LIB/BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
void MSPI_voidMasterInit(u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin){
	MDIO_intInit(DIO_PORT_B, DIO_PIN5, DIO_OUTPUT);
	MDIO_intInit(DIO_PORT_B, DIO_PIN6, DIO_INPUT);
	MDIO_intInit(DIO_PORT_B, DIO_PIN7, DIO_OUTPUT);
	MDIO_intInit(cpy_u8SS_Port, cpy_u8SS_Pin, DIO_OUTPUT);
	MDIO_intWrite(cpy_u8SS_Port, cpy_u8SS_Pin, DIO_HIGH);
	SPCR = 0x00;
	SPCR = (1<<SPE) | (SPI_INTERRUPT<<SPIE) | SPI_DATA_ORDDER | (1<<MSTR) | SPI_CLK_POL | SPI_CLK_PHA | (SPI_CLK & 0x03);
	SPSR = ((SPSR & 0x00) | (SPI_CLK>>2));

}
void MSPI_voidSlaveInit(void){
	MDIO_intInit(DIO_PORT_B, DIO_PIN4, DIO_INPUT);
	MDIO_intInit(DIO_PORT_B, DIO_PIN5, DIO_INPUT);
	MDIO_intInit(DIO_PORT_B, DIO_PIN6, DIO_OUTPUT);
	MDIO_intInit(DIO_PORT_B, DIO_PIN7, DIO_INPUT);
	SPCR = (1<<SPE) |(0<<MSTR);
}
void MSPI_voidMasterTRansmitReceive(u8 *cpy_u8Data,u8 cpy_u8SS_Port, u8 cpy_u8SS_Pin){
MDIO_intWrite(cpy_u8SS_Port, cpy_u8SS_Pin, DIO_LOW);
/* Start transmission */
SPDR = *cpy_u8Data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
*cpy_u8Data = SPDR;
MDIO_intWrite(cpy_u8SS_Port, cpy_u8SS_Pin, DIO_HIGH);
}
void MSPI_voidSlaveReceive(u8 *cpy_u8Data){
SPDR = *cpy_u8Data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
*cpy_u8Data = SPDR;
}
