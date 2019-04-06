#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

PwmOut dcmotor(p21);
int dcmotor_period_ms = 20;  //period in ms

PwmOut servo(p22);
int servo_period_ms = 20;

void Fan_Setup(void)
{
	//Initialize fan (dc motor) period to 20ms and duty cycle to 0%
	dcmotor.period_ms(dcmotor_period_ms);
	dcmotor = 0.0;
}

void Servo_Setup(void)
{
	//Initialize vent (servo) period to 20ms and pulsewidth to 480us (0 deg)
	servo.period_ms(servo_period_ms);
	servo.pulsewidth_us(480);
}
