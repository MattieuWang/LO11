/*
 * pmodNav.c
 * 
 * Copyright 2020 Michel Doussot <michel@doussot>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <Arduino.h>
#include <SPI.h>
#include "gpios_def.h"


void setup() {
	Serial.begin(9600);

	pinMode(SS,OUTPUT);
	digitalWrite(SS,HIGH);
	SPI.begin();
	SPI.setBitOrder(MSBFIRST);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x20);
	SPI.transfer(0x80);
	digitalWrite(SS,HIGH);
	delay(15);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x10);
	SPI.transfer(0x0A);
	digitalWrite(SS,HIGH);
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x0F);
	int val = SPI.transfer(0);
	digitalWrite(SS,HIGH);
	Serial.println(val);
	
}

void loop() {
	
	digitalWrite(SS,LOW);
	SPI.transfer(0x21);
	SPI.transfer(0x00);
	digitalWrite(SS,HIGH);
	
	uint8_t octets[3];
	digitalWrite(SS,LOW);
	SPI.transfer(0x28);
	octets[0] = SPI.transfer(0);
	SPI.transfer(0x29);
	octets[1] = SPI.transfer(0);
	SPI.transfer(0x2A);
	octets[2] = SPI.transfer(0);
	digitalWrite(SS,HIGH);
	
	int i = 0;
	for(i=0;i<3;i++)
	{
		Serial.print(octets[i]);
		Serial.print(" ");
	}
	Serial.println();
	
	delay(500);
	
}















