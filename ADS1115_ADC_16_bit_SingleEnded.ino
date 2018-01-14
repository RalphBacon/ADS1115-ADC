#include "Arduino.h"
#include "Wire.h"
#define I2Caddress 0x48

// Running average
unsigned int readings[20] = {0};
unsigned char readCnt = 0;

void setup()
{
	Serial.begin(9600);

	// Join the I2C bus as a master (call this only once)
	Wire.begin();

	Serial.println("Setup completed.");
}

void loop()
{
	// Step 1: Point to Config register - set to continuous conversion
	Wire.beginTransmission(I2Caddress);

	// Point to Config Register
	Wire.write(0b00000001);

	// Write the MSB + LSB of Config Register
	// MSB: Bits 15:8
	// Bit  15		0=No effect, 1=Begin Single Conversion (in power down mode)
	// Bits 14:12 	How to configure A0 to A3 (comparator or single ended)
	// Bits	11:9 	Programmable Gain 000=6.144v 001=4.096v 010=2.048v .... 111=0.256v
	// Bits	8 		0=Continuous conversion mode, 1=Power down single shot
	Wire.write(0b01000010);

	// LSB:	Bits 7:0
	// Bits 7:5	Data Rate (Samples per second) 000=8, 001=16, 010=32, 011=64,
	//			100=128, 101=250, 110=475, 111=860
	// Bit 	4 	Comparator Mode 0=Traditional, 1=Window
	// Bit	3 	Comparator Polarity 0=low, 1=high
	// Bit	2 	Latching 0=No, 1=Yes
	// Bits	1:0	Comparator # before Alert pin goes high
	//			00=1, 01=2, 10=4, 11=Disable this feature
	Wire.write(0b00000010);

	// Send the above bytes as an I2C WRITE to the module
	Wire.endTransmission();

	// ====================================

	// Step 2: Set the pointer to the conversion register
	Wire.beginTransmission(I2Caddress);

	//Point to Conversion register (read only , where we get our results from)
	Wire.write(0b00000000);

	// Send the above byte(s) as a WRITE
	Wire.endTransmission();

	// =======================================

	// Step 3: Request the 2 converted bytes (MSB plus LSB)
	Wire.requestFrom(I2Caddress, 2);

	// Read two bytes and convert to full 16-bit int
	uint16_t convertedValue;

	// Read the the first byte (MSB) and shift it 8 places to the left then read
	// the second byte (LSB) into the last byte of this integer
	convertedValue = (Wire.read() << 8 | Wire.read());

	// Debug the value
	//Serial.println(convertedValue >> 6 << 6);
	//Serial.println(map(convertedValue, 0, 32767, 0, 5000));
	//Serial.println(convertedValue);
	readings[readCnt] = convertedValue;
	readCnt = readCnt == 19 ? 0 : readCnt + 1;

	// Get the average
	unsigned long totalReadings = 0;
	for (unsigned char cnt = 0; cnt < 20; cnt++){
		totalReadings += readings[cnt];
	}
	Serial.print(convertedValue); Serial.print("\t"); Serial.println(totalReadings / 20);

	delay(250);
}
