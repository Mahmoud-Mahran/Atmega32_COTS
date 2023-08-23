#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H
#define BUTTON_OK			88
#define BUTTON_OP_FAILED	89
typedef struct{
	u8 port;
	u8 pin;
}BUTTONS;

u8 HBUTTON_u8Init(BUTTONS *butt);
u8 HBUTTON_u8GetValue(BUTTONS *butt, u8 *val);
u8 HBUTTON_u8ConnectIPU(BUTTONS *butt);

#endif
