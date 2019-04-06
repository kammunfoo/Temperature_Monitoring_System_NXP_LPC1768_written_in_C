#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

DigitalOut redled(p30);
DigitalOut greenled(p29);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


void Red_Green_LED_Reset(void)
{
	redled = 0, greenled = 0;
}
