/*
 * STD_TYPES.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Mahmoud Mahran
 *     Version: 0.1
 */
#ifndef 	STD_TYPES
#define 	STD_TYPES

typedef  	unsigned char			     u8;
typedef  	unsigned short int		    u16;
typedef  	unsigned long  int		    u32;
typedef  	unsigned long long  int		u64;

typedef  	signed char				     s8;
typedef  	signed short int		    s16;
typedef  	signed long  int		    s32;
typedef  	signed long long  int	    s64;

typedef  	float					     f32;
typedef  	double					     f64;
typedef  	long double					f128;

void delay_ms(u32 ticks);
u64 power(u64 num, u8 pow);

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
