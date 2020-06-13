
#include <Arduino.h>
#include <Wire.h>
#include "gpios_def.h"



int readTemp()
{
	uint8_t octet[4];
	Wire.beginTransmission(0x40);
	Wire.write(0x00);
	Wire.endTransmission();
	delay(15);
	Wire.requestFrom(0x40,2);
	if(Wire.available() == 2)
	{
		int i=0;
		for(i=0;i<2;i++)
		{
			octet[i] = Wire.read();
			Serial.println(octet[i]);
		}
		Serial.println("---------");
	}
	
	uint16_t temp = ((unsigned int)(octet[0] << 8 | octet[1]));
	Serial.println(temp);
	double temp_reel = (double)(temp)/(65536)*165-40;
	Serial.print("temp= ");
	Serial.println((int)temp_reel);

	return (int)temp_reel;
}

void showSingle(int n)
{
	digitalWrite(LED0,LOW);
	digitalWrite(LED1,LOW);
	digitalWrite(LED2,LOW);
	digitalWrite(LED3,LOW);
	int pair = n%2;
	int rest = n - pair;
	if(n == 0)
	{
	}
	if(pair == 1)
	{
		digitalWrite(LED0,HIGH);
	}
	if(rest == 2)
	{
		digitalWrite(LED1,HIGH);
	}
	else if(rest == 4)
	{
		digitalWrite(LED2,HIGH);
	}
	else if(rest == 6)
	{
		digitalWrite(LED2,HIGH);
		digitalWrite(LED1,HIGH);
	}
	else if(rest == 8)
	{
		digitalWrite(LED3,HIGH);
	}
}

void showTens(int n)
{
	digitalWrite(LED4,LOW);
	digitalWrite(LED5,LOW);
	digitalWrite(LED6,LOW);
	digitalWrite(LED7,LOW);
	int pair = n%2;
	int rest = n - pair;
	if(n == 0)
	{
	}
	if(pair == 1)
	{
		digitalWrite(LED4,HIGH);
	}
	if(rest == 2)
	{
		digitalWrite(LED5,HIGH);
	}
	else if(rest == 4)
	{
		digitalWrite(LED6,HIGH);
	}
	else if(rest == 6)
	{
		digitalWrite(LED6,HIGH);
		digitalWrite(LED5,HIGH);
	}
	else if(rest == 8)
	{
		digitalWrite(LED7,HIGH);
	}
	
}


void setup() {
	Serial.begin(9600);
	Serial.println("TEST");
	int k = 6;
	for(k=6;k<=13;k++)
	{
		pinMode(k,OUTPUT);
		digitalWrite(k,LOW);
	}
	Wire.begin();
}

void loop() {
	Wire.beginTransmission(0x40);
	Wire.write(0x00);
	Wire.endTransmission();
	int temp = readTemp();
	int single = temp%10;
	int tens = temp/10;
	showSingle(single);
	showTens(tens);
	delay(1000);
}
