#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

int main()
{
	StateInit();

	while (1)
	{
		if (!emergency_flag)
		{
			Red_Green_LED_Reset();
			while (!emergency_flag && temp < 20.0)
				StateTooCold();
			Red_Green_LED_Reset();

			while (!emergency_flag && temp >= 19.0 && temp < 25.0)
				StateCold();
			Red_Green_LED_Reset();

			while (!emergency_flag && temp >= 24.0 && temp < 30.0)
				StateNormal();
			Red_Green_LED_Reset();

			while (!emergency_flag && temp >= 29.0 && temp < 35.0)
				StateHot();
			Red_Green_LED_Reset();

			while (!emergency_flag && temp >= 34.0)
				StateTooHot();
			Red_Green_LED_Reset();
		}

		else
		{
			while (emergency_flag)
				StateEmergency();
			StateResume();
		}
	}
}

