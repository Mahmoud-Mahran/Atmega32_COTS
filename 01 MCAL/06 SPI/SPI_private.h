#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPCR         *((volatile u8*)0x2D)// SPI Control Register
#define SPIE         7                    //SPI Interrupt Enable
#define SPE          6                    //SPI Enable
#define DORD         5                    //Data Order
#define MSTR         4                    //Master/Slave Select
#define CPOL         3                    //Clock Polarity
#define CPHA         2                    //Clock Phase
#define SPR1         1                    //SPI Clock Rate Select 1
#define SPR0         0                    //SPI Clock Rate Select 0
#define SPSR         *((volatile u8*)0x2E)// SPI Status Register
#define SPIF         7                    //SPI Interrupt Flag
#define WCOL         6                    //Write COLlision Flag
#define SPI2X        0                    //Double SPI Speed Bit
#define SPDR         *((volatile u8*)0x2F)//SPI Data Register


#define ENABLE                       1
#define DISABLE                      0
#define LSB_FIRST                    0x20
#define MSB_FIRST                    0x00
#define RISING_FALLING               0x00
#define FALLING_RISING               0x08
#define SAMPLE_SETUP                 0x00
#define SETUP_SAMPLE                 0x04
#define CLK_4                        0x00
#define CLK_16                       0x01
#define CLK_64                       0x02
#define CLK_128                      0x03
#define DOUBLE_SPD_CLK_2             0x04
#define DOUBLE_SPD_CLK_8             0x05
#define DOUBLE_SPD_CLK_32            0x06
#define DOUBLE_SPD_CLK_64            0x07

#endif
