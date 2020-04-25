/*
 * chenillard.c
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

#include "gpios_def.h"

int  nums [8]={10,11,12,13,6,7,8,9};

void setup() {
	Serial.begin(9600);
	int i;
	for(i=0;i<8;i++)
	{
		pinMode(nums[i],OUTPUT);
	}
}

void loop() {
	int i;
	for(i=7;i>=0;i--)
	{
		digitalWrite(nums[i],HIGH);
		delay(500);
		digitalWrite(nums[i],LOW);
	}
	for(i=0;i<8;i++)
	{
		digitalWrite(nums[i],HIGH);
		delay(500);
		digitalWrite(nums[i],LOW);
	}

}


