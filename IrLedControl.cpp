/// Project name: IrLedControl library
/// Author: Maciej Wiraszka
/// Version: v1.0 27.11.15 
///
/// Library for controlling led light using IR obstacle detector and optionally button (button has higher priority).
///
/// File: IrLedControl.cpp - implementation file for class IrLedControl
///


#include "IrLedControl.h"

IrLedControl::IrLedControl(int ir, int led, int button = 0, boolean buttonPullup = false)
{
	irPin = ir;
	ledPin = led;
	buttonPin = button;
	pullup = buttonPullup;
	
	// Arduino pin initialization
	pinMode(irPin, INPUT);  // IR obstacle detector module (0 - obstacle detected, 1 - otherwise)
	pinMode(ledPin, OUTPUT);  // LED, PWM enable
	
	if(button)
	{
		if(buttonPullup) pinMode(buttonPin, INPUT_PULLUP);		// 0 - pushed, 1 other
		else pinMode(buttonPin, INPUT);							// 1 - pushed, 0 other
	}
}

void IrLedControl::control()
{
	if(buttonPin) monitorButton();	// button priority, if button exists
	monitorIr();
}

void IrLedControl::monitorIr()
{
	if(digitalRead(irPin) == LOW)
	{
		delay(1000);  // for surrounding light detection
    
		if(digitalRead(irPin) == HIGH)
		{
			// led on
			for (int brightness = 0; brightness < 255; brightness++) 
			{
				analogWrite(ledPin, brightness);
				delay(5);
			}
			
			if(buttonPin) 
			{
				if(pullup) while(digitalRead(irPin)==HIGH && digitalRead(buttonPin) == HIGH);
				else       while(digitalRead(irPin)==HIGH && digitalRead(buttonPin) == LOW);
			}
			else while(digitalRead(irPin)==HIGH);
			
			
			// led off
			for (int brightness = 255; brightness >= 0; brightness--) 
			{
				analogWrite(ledPin, brightness);
				delay(5);
			}
		}
	}
}

void IrLedControl::monitorButton()
{
	if((digitalRead(buttonPin) == HIGH && !pullup) || (digitalRead(buttonPin) == LOW && pullup))
	{
		// led on
		for (int brightness = 0; brightness < 255; brightness++) 
		{
			analogWrite(ledPin, brightness);
			delay(5);
		}
    
		if(pullup) while(digitalRead(buttonPin) == HIGH);
		else	   while(digitalRead(buttonPin) == LOW);
    
		// led off
		for (int brightness = 255; brightness >= 0; brightness--) 
		{
			analogWrite(ledPin, brightness);
			delay(5);
		}
	}
}