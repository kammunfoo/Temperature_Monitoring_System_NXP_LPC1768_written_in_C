#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

InterruptIn killswitch(p18);
volatile bool emergency_flag = false;

void ISR_Setup(void)
{
	killswitch.rise(&ISR_rise);
	killswitch.fall(&ISR_fall);
}

void ISR_rise(void)
{
	debounce_fall.reset();
	if (debounce_rise.read_us() > 300)  //300us ok for rise
	{
		emergency_flag = true;
	}
	debounce_rise.reset();
}


void ISR_fall(void)
{
	debounce_rise.reset();
	if (debounce_fall.read_us() > 300)
	{
		emergency_flag = false;
	}
	debounce_fall.reset();
}
