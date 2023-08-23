#ifndef TWI_CONFIG_H
#define TWI_CONFIG_H
//options: { PRE_1, PRE_4, PRE_16, PRE_64}
#define PRESCALER         PRE_4
//options: { ENABLE, DISABLE }
#define GENERATE_ACK      ENABLE
//options: { ENABLE, DISABLE }
#define INTERRUPTS        DISABLE
//options: { ENABLE, DISABLE }
#define GENERAL_CALL      DISABLE

#define F_CPU             8000000UL
#define FREQ              200000UL
#endif
