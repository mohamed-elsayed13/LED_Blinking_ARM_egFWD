/*
 * STD_MACROS.h
 *
 * Created: 8/5/2022 11:57:06 AM
 *  Author: Mohamed Elsayed
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SETBIT(REG,BIT) (REG |= (1<<BIT))
#define CLRBIT(REG,BIT) (REG &=~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^=(1<<BIT))
#define GETBIT(REG,BIT) ((REG>>BIT)&1)


#endif /* STD_MACROS_H_ */