#ifndef Debounce_functions_h
#define Debounce_functions_h

#include "mbed.h"

extern Timer debounce_rise;
extern Timer debounce_fall;

void Debounce_Setup(void);

#endif
