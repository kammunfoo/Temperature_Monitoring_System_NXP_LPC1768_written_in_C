#include "TextLCD.h"
#include "TextLCD_functions.h"
#include "LED_functions.h"
#include "PWM_functions.h"
#include "I2C_functions.h"
#include "Serial_functions.h"
#include "Debounce_functions.h"
#include "ISR_functions.h"
#include "OperationStates_functions.h"

I2C tempsensor(p9, p10);  //sda, scl for TMP102

//Constants for TMP102
const float TempSensitivity = 0.0625;  //degC per LSB
const int addr_tmp102 = 0x90;  //Default I2C slave address (ADD0 connected to GND), 0x92 (ADD0 connected to 3.3V), 0x94 (ADD0 connected to SDA), 0x96 (ADD0 connected to SCL)

//Variables for TMP102
char config[3];  //array to hold pointer register and configuration information
char tempread[2];  //array to store temperature reading, 12-bit resolution output
float temp;  //float to hold converted temperature reading in degC
int ventangle = 0;

void TMP102_Setup(void)
{
	//Initialize TMP102
	config[0] = 0x01;  //Set pointer register to "Configuration Register"
	config[1] = 0x60;  //Byte 1 Configuration Register, set temperature register to 12-bit resolution output
	config[2] = 0xA0;  //Byte 2 Configuration Register, set 4Hz temperature conversion rate, AL (Alert Normal, Read Only)
	tempsensor.write(addr_tmp102, config, 3);  //Write 3 bytes to tmp102 at slave address 0x90

	//Start temperature measurements at 4Hz, 12-bit resolution output
	config[0] = 0x00;  //Set pointer register to "Temperature Register (Read Only)"
	tempsensor.write(addr_tmp102, config, 1);  //Set pointer register to "Temperature Register (Read Only)"
}

void TMP102_Sample(void)
{
	//Read temperature into 2 buffers
	tempsensor.read(addr_tmp102, tempread, 2);

	//Combine buffers into 12-bit value and convert to floating point in unit of C
	temp = TempSensitivity * ( ( (tempread[0] << 8) + tempread[1] ) >> 4);
}
