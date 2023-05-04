#ifndef BITMATH_H
#define BITMATH_H



#define SET_BIT(byte,nbit)     ((byte) |=  (1<<(nbit)))
#define CLEAR_BIT(byte,nbit)   ((byte) &= ~(1<<(nbit)))
#define TOGGLE_BIT(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define GET_BIT(byte,nbit)     ((byte>>nbit)&(1))

#define     NULL_POINTER     ((void*)0)










#endif
