#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

Serial pc(USBTX, USBRX);

void Serial_Setup(void)
{
	pc.baud(115200);
	pc.printf("\r\n\r\nTemperature Monitoring System...\r\n");
	pc.printf("For A Microclimate Or Greenhouse...\r\n\r\n");
}

void Serial_Print(int deg)
{
	//Prints temperature in unit of C to emulation terminal
	pc.printf("Temperature = %.2f degC\r\n", temp);

	//Prints fan duty cycle in unit of % to emulation terminal
	pc.printf("Fan Duty Cycle = %.0f %%\r\n", 100 * dcmotor.read());

	//Prints vent angle in unit of deg to emulation terminal
	pc.printf("Vent Angle = %d deg\r\n\r\n", deg);
}
