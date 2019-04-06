#ifndef OperationStates_functions_h
#define OperationStates_h

#include "mbed.h"

void StateInit(void);
void StateTooCold(void);
void StateCold(void);
void StateNormal(void);
void StateHot(void);
void StateTooHot(void);
void StateEmergency(void);
void StateResume(void);

#endif
