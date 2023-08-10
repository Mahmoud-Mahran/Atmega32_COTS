#ifndef 	BIT_MATH
#define 	BIT_MATH

#define     Set_Bit(Var, BitNo)			( Var |=  (1<<BitNo) )
#define     Clr_Bit(Var, BitNo)			( Var &= ~(1<<BitNo) )
#define     Tgl_Bit(Var, BitNo)		    ( Var ^=  (1<<BitNo) )
#define     Get_Bit(Var, BitNo)		    ((Var>>BitNo) & 0x01 )

#endif
