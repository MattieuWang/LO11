
#include <Arduino.h>
#include <SPI.h>
#include "gpios_def.h"


void setup() {
	Serial.begin(9600);
	SPI.begin();
	SPI.setDataMode(SPI_MODE0);
	SPI.setClockDivider(SPI_CLOCK_DIV16);
	

}

void loop() {
	uint8_t recu[2];
	int i;
	for(i=0;i<2;i++)
	{
		recu[i] = SPI.transfer(0);
	}
	
	for(i=0;i<2;i++)
	{
		Serial.print("recu=");
		Serial.print(recu[i]);
	}
	Serial.print("	");
	int lum = (recu[0]<<4)|(recu[1]>>4);
	double lum_reel = lum * 0.65;
	Serial.print("lum = ");
	Serial.println((int)lum_reel);
	delay(500);
	
}
