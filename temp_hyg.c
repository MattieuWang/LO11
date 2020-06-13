#include <Arduino.h>
#include <SPI.h>
#include "gpios_def.h"

uint8_t octets[3];
uint16_t temp;
uint32_t pres;

void setup() {
	Serial.begin(115200);

	pinMode(SS,OUTPUT);
	SPI.begin();
	digitalWrite(SS,HIGH);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x0F);
	int data = SPI.transfer(0x00);
	digitalWrite(SS,HIGH);
	Serial.println(data);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x21);
	SPI.transfer(0x08);
	digitalWrite(SS,HIGH);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x10);
	SPI.transfer(0x0A);
	digitalWrite(SS,HIGH);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x20);
	SPI.transfer(0x80);
	digitalWrite(SS,HIGH);
	Serial.println("Hello");
	
}

void loop() {
	unsigned int adr = 0x28;
	
	int i=0;
	digitalWrite(SS,LOW);
	for(i=0;i<3;i++)
	{
		SPI.transfer(adr);
		delay(15);
		octets[i] = SPI.transfer(0);
		adr++;
	}
	digitalWrite(SS,HIGH);
	pres = octets[0] << 16 | octets[1]<<8 | octets[2];
	int reel_pres = pres / 4096;
	adr = 0x2B;
	digitalWrite(SS,LOW);
	for(i=0;i<2;i++)
	{
		SPI.transfer(adr);
		delay(15);
		octets[i] = SPI.transfer(0);
		adr++;
	}
	digitalWrite(SS,HIGH);
	temp = octets[0] << 8 | octets[1];
	int reel_temp = temp/480.0 + 42.5;
	Serial.print("pression=");
	Serial.println(reel_pres);
	
	Serial.print("temp=");
	Serial.println(reel_temp);
	
	delay(1000);

}

