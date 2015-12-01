/// Project name: IrLedControl library
/// Author: Maciej Wiraszka
/// Version: v1.0 27.11.15 
///
/// Library for controlling led light using IR obstacle detector and optionally button (button has higher priority).
///
/// File: IrLedControl.h - heather file for class IrLedControl
///

#ifndef IR_LED_CONTROL
#define IR_LED_CONTROL

#include "Arduino.h"

class IrLedControl
{
public:
	IrLedControl(int ir, int led, int button = 0, boolean buttonPullup = true); // constructor, button and buttonPullup are optional
	~IrLedControl() {}												 // destructor
	
	void control();			// main, controlling function
	void monitorIr();
	void monitorButton();
	
private:
	int irPin;		// digital pin number
	int ledPin;		// PWM pin number, led output
	
	int buttonPin;	// (optional) digital pin number, MUST BE OTHER THAN "0"
	boolean pullup;	// (optional) determines button push state: false - typical button, true - pullup button
};

#endif