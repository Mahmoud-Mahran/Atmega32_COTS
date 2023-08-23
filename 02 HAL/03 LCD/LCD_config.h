#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*    Choose Port for control pins*/
//options are: { DIO_PORT_A, DIO_PORT_B, DIO_PORT_C, DIO_PORT_D }
#define  LCD_RS_PORT		DIO_PORT_C
#define  LCD_RW_PORT		DIO_PORT_C
#define  LCD_EN_PORT		DIO_PORT_C
/*    Choose PIN number for control pins*/
//options are: { DIO_PIN0 : DIO_PIN7 }
#define  LCD_RS_PIN		    DIO_PIN0
#define  LCD_RW_PIN		    DIO_PIN1
#define  LCD_EN_PIN		    DIO_PIN2
/*    Choose Port for Data pins*/
//options are: { DIO_PORT_A, DIO_PORT_B, DIO_PORT_C, DIO_PORT_D }
#define  LCD_D0_PORT        DIO_PORT_C
#define  LCD_D1_PORT        DIO_PORT_C
#define  LCD_D2_PORT        DIO_PORT_C
#define  LCD_D3_PORT        DIO_PORT_C
#define  LCD_D4_PORT        DIO_PORT_C
#define  LCD_D5_PORT        DIO_PORT_C
#define  LCD_D6_PORT        DIO_PORT_C
#define  LCD_D7_PORT        DIO_PORT_C
/*    Choose PIN number for Data pins*/
//options are: { DIO_PIN0 : DIO_PIN7 }
#define  LCD_D0_PIN         DIO_PIN0
#define  LCD_D1_PIN         DIO_PIN1
#define  LCD_D2_PIN         DIO_PIN2
#define  LCD_D3_PIN         DIO_PIN3
#define  LCD_D4_PIN         DIO_PIN4
#define  LCD_D5_PIN         DIO_PIN5
#define  LCD_D6_PIN         DIO_PIN6
#define  LCD_D7_PIN         DIO_PIN7
/*    Choose LCD operating mode*/
//options are: { LCD_8_BIT : LCD_4_BIT }
#define  LCD_MODE		    LCD_4_BIT
#endif
