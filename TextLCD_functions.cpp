#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

TextLCD lcd(p11, p12, p5, p6, p7, p8); // rs, e, d4-d7

void TextLCD_Greeting(void)
{
	lcd.locate(0,0); lcd.printf("Microclimate or");  //Greetings on LCD 1602 display
	lcd.locate(2,1); lcd.printf("Greenhouse");
	wait(2);
}

void TextLCD_Print(int deg)
{
	//Prints temperature in unit of C to LCD 1602 display
	//Prints fan duty cycle in unit of  % to LCD 1602 display
	lcd.cls();
	lcd.locate(0,0); lcd.printf("Temp");
	lcd.locate(7,0); lcd.printf("Fan");
	lcd.locate(12,0); lcd.printf("Vent");
	lcd.locate(0,1); lcd.printf("%.2fC", temp);
	lcd.locate(7,1); lcd.printf("%.0f%%", 100 * dcmotor.read());
	lcd.locate(12,1); lcd.printf("%d%c", deg, 0xDF);
}
