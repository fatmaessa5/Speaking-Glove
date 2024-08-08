
#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef unsigned char 				u8;
typedef signed char 				s8;
typedef unsigned short int 			u16;
typedef signed short int 			s16;
typedef unsigned long int		 	u32;  
typedef signed long int		 		s32;
typedef float					 	f32;
typedef double					 	f64;


#define NULL							((volatile void *) 0x00)
#define LIB_SREG						 (*((volatile u8 *)0x5F))

#endif /* LIB_STD_TYPES_H_ */
