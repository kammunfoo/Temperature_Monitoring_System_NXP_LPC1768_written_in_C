#ifndef PWM_functions_h
#define PWM_functions_h

#include "mbed.h"

extern PwmOut dcmotor;
extern int dcmotor_period_ms;

extern PwmOut servo;
extern int servo_period_ms;

void Fan_Setup(void);
void Servo_Setup(void);

#endif
