#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

void StateInit(void)
{
	Debounce_Setup();
	ISR_Setup();
	ventangle = 0;
	Serial_Setup();
	TMP102_Setup();
	Fan_Setup();
	Servo_Setup();
	TextLCD_Greeting();
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateTooCold(void)
{
	greenled = !greenled;
	dcmotor = 0.1;
	servo.pulsewidth_us(617);
	ventangle = 15;
	wait(.1);
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateCold(void)
{
	greenled = !greenled;
	dcmotor = 0.25;
	servo.pulsewidth_us(753);
	ventangle = 30;
	wait(1.0);
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateNormal(void)
{
	redled = !redled;
	greenled =!greenled;
	dcmotor = 0.5;
	servo.pulsewidth_us(890);
	ventangle = 45;
	wait(1.0);
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateHot(void)
{
	redled = !redled;
	dcmotor = 0.75;
	servo.pulsewidth_us(1026);
	ventangle = 60;
	wait(1.0);
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateTooHot(void)
{
	redled = !redled;
	dcmotor = 1.0;
	servo.pulsewidth_us(1163);
	ventangle = 75;
	wait(.1);
	TMP102_Sample();
	Serial_Print(ventangle);
	TextLCD_Print(ventangle);
}

void StateEmergency(void)
{
	led1 = !led1, led3 = !led3;
	dcmotor = 0.0;
	servo.pulsewidth_us(480);
	pc.printf("Emergency Shutdown!\r\n");
	lcd.cls();
	lcd.locate(3,0); lcd.printf("Emergency");
	lcd.locate(3,1); lcd.printf("Shutdown!");
	wait(1.0);
	led2 = !led2, led4 = !led4;
}

void StateResume(void)
{
	led1 = led2 = led3 = led4 = 0;
	pc.printf("\r\nResuming Operation...\r\n\r\n");
	lcd.cls();
	lcd.locate(2,0); lcd.printf("Resuming");
	lcd.locate(2,1); lcd.printf("Operation...");
	wait(1.0);
}
