/*
 * LED_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#include "../../00 LIB/STD_TYPES.h"
#include "../../01 MCAL/00 DIO/DIO_Interface.h"
#include "../00 LED/LED_config.h"
#include "../00 LED/LED_interface.h"

u8 HLED_init(LEDS *led)
{
	if (MDIO_intInit(led->port, led->pin, DIO_OUTPUT) == DIO_OK)
	{
		led->state = 0;
		return	LED_OK;
	}
	return LED_OPERATION_FAILED;
}
u8 HLED_on(LEDS *led)
{
	if (MDIO_intWrite(led->port, led->pin, DIO_HIGH) == DIO_OK)
		{
			led->state = 2;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
}
u8 HLED_off(LEDS *led)
{
	if (MDIO_intWrite(led->port, led->pin, DIO_LOW) == DIO_OK)
		{
			led->state = 1;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
}
u8 HLED_toggle(LEDS *led)
{
	if (MDIO_intToggle(led->port, led->pin) == DIO_OK)
		{
			if(led->state == 1) led->state = 2;
			if(led->state == 2) led->state = 1;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
	
}
