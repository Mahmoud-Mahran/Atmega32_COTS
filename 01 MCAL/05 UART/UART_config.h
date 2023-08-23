#ifndef UART_CONFIG_H
#define UART_CONFIG_H
#define F_CPU                    8000000UL
//choose baud rate
#define BAUDE_RATE               9600
//enable or disable double speed
//options: { ENABLE, DISABLE }
#define DOUBLE_SPEED             DISABLE
//enable or disable receive complete interrupt
//options: { ENABLE, DISABLE }
#define RX_INTERRUPT             DISABLE
//enable or disable transmit complete interrupt
//options: { ENABLE, DISABLE }
#define TX_INTERRUPT             DISABLE
//enable or disable data register empty interrupt
//options: { ENABLE, DISABLE }
#define REG_EMPTY_INTERRUPT      DISABLE
//enable or disable receive functionality
//options: { ENABLE, DISABLE }
#define UART_RX                  ENABLE
//enable or disable transmit functionality
//options: { ENABLE, DISABLE }
#define UART_TX                  ENABLE
//choose character size(data frame)
//options: { BIT_8, BIT_9 }
#define CHAR_SIZE                BIT_8
//choose to enable or disable parity and select mode
//options: { DISABLE, EVEN, ODD }
#define PARITY                   DISABLE
//select how many stop bits to use
//options: { BIT_1, BIT_2 }
#define STOP_BITS                BIT_1
//choose sampling polarity
//options: { TX_RISING, TX_FALLING }
#define POLARITY                 TX_RISING

#endif
