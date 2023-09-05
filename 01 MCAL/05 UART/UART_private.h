/*
 * UART_private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UDR                *( (volatile u8*)0x2C)
#define UCSRA              *( (volatile u8*)0x2B)
#define MPCM               0                     // Multi-processor Communication Mode
#define U2X                1                     // Double the USART Transmission Speed
#define PE                 2                     // Parity Error
#define DOR                3                     // Data OverRun
#define FE                 4                     // Frame Error
#define UDRE               5                     // USART Data Register Empty
#define TXC                6                     // USART Transmit Complete
#define RXC                7                     // USART Receive Complete

#define UCSRB              *( (volatile u8*)0x2A)
#define TXB8               0                     // Transmit Data Bit 8
#define RXB8               1                     // Receive Data Bit 8
#define UCSZ2              2                     // Character Size bit 2
#define TXEN               3                     // Transmitter Enable
#define RXEN               4                     // Receiver Enable
#define UDRIE              5                     // USART Data Register Empty Interrupt Enable
#define TXCIE              6                     // TX Complete Interrupt Enable
#define RXCIE              7                     // RX Complete Interrupt Enable

#define UCSRC              *( (volatile u8*)0x40)

#define UCPOL              0                     // Clock Polarity
#define UCSZ0              1                     // Character Size bit 0
#define UCSZ1              2                     // Character Size bit 1
#define USBS               3                     // Stop Bit Select
#define UPM0               4                     // Parity Mode bit 1
#define UPM1               5                     // Parity Mode bit 0
#define UMSEL              6                     // USART Mode Select
#define URSEL              7                     // Register Select

#define UBRRH              *( (volatile u8*)0x40)
#define UBRRL              *( (volatile u8*)0x29)


#define ENABLE             1
#define DISABLE            0
#define BIT_8              3
#define BIT_9              1
#define EVEN               2
#define ODD                3
#define BIT_1              0
#define BIT_2              1
#define TX_RISING          0
#define TX_FALLING         1
#endif
