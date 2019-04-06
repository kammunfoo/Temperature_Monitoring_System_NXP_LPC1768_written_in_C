#ifndef I2C_functions_h
#define I2C_functions_h

#include "mbed.h"

extern I2C tempsensor;

//Constants for TMP102
extern const float TempSensitivity;  //degC per LSB
extern const int addr_tmp102;  //Default I2C slave address (ADD0 connected to GND), 0x92 (ADD0 connected to 3.3V), 0x94 (ADD0 connected to SDA), 0x96 (ADD0 connected to SCL)

//Variables for TMP102
extern char config[3];  //array to hold pointer register and configuration information
extern char tempread[2];  //array to store temperature reading, 12-bit resolution output
extern float temp;  //float to hold converted temperature reading in degC
extern int ventangle;

void TMP102_Setup(void);
void TMP102_Sample(void);

#endif
