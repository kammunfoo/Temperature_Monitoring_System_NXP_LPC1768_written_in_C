#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

Timer debounce_rise;
Timer debounce_fall;

void Debounce_Setup(void)
{
	debounce_rise.stop();
	debounce_fall.stop();
	debounce_rise.reset();
	debounce_fall.reset();
	debounce_rise.start();
	debounce_fall.start();
}
