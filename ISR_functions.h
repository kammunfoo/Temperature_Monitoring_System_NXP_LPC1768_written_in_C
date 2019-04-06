#ifndef Interrupt_functions_h
#define Interrupt_functions_h

#include "mbed.h"

extern InterruptIn killswitch;
extern volatile bool emergency_flag;

void ISR_Setup(void);
void ISR_rise(void);
void ISR_fall(void);

#endif
