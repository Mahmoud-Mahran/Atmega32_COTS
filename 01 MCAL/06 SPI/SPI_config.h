/*
 * SPI_config.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
//enable or disable SPI Interrrupts
//options: { ENABLE, DISABLE }
#define SPI_INTERRUPT      DISABLE
//choose data alignment
//options: { MSB_FIRST, LSB_FIRST }
#define SPI_DATA_ORDDER    MSB_FIRST
//choose clock polarity
/*options:
 * RISING_FALLING   //(rising on leading edge, falling on trailing)
 * FALLING_RISING   //(falling on leading edge, rising on trailing)
 * */
#define SPI_CLK_POL        RISING_FALLING
//choose clock phase
/*options:
*SAMPLE_SETUP  //(sample on leading edge, setup on trailing)
*SETUP_SAMPLE  //(setup on leading edge, sample on trailing)
* */
#define SPI_CLK_PHA        SAMPLE_SETUP
//choose spi clock prescaler
/*options:
 * CLK_4                //(Fosc/4)
 * CLK_16               //(Fosc/16)
 * CLK_64               //(Fosc/64)
 * CLK_128              //(Fosc/128)
 * DOUBLE_SPD_CLK_2     //(Fosc/2)
 * DOUBLE_SPD_CLK_8     //(Fosc/8)
 * DOUBLE_SPD_CLK_32    //(Fosc/16
 * DOUBLE_SPD_CLK_64    //(Fosc/64)
 * */
#define SPI_CLK            CLK_4

#endif
