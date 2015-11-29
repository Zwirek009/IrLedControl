/// Project name: IntelliLight Desk
/// Author: Maciej Wiraszka
/// Version: v0.1    22.11.15
///          v0.1a   27.11.15 (minor touch button bug fix)
///          v0.2    27.11.15 (brand new IrLedControl library)
///
/// Smart light for keeping your workspace lighted
/// according to actual situation. Supported by my
/// library IrLedControl.
///
/// TODO:
///  - wireless information receiver
///

#include <IrLedControl.h>  // for control of LEDs using 
                           // IR obstacle detectors and
                           // optional buttons
                           
IrLedControl led1(2, 9, 3, false); // irPin, ledPin, buttonPin,
                                   // button without pullup
void setup() {}

void loop() {
  led1.control();  // main, led1 controlling function
}

/* v0.1a (without IrLedControl library)
const int ir = 2;
const int touch = 3;
const int led = 9;

void setup() {
  pinMode(ir, INPUT);  // IR obstacle detector module 
                       // (0 - obstacle detected, 1 otherwise)
  pinMode(touch, INPUT);  // Touch sensor (1 - pushed, 0 oth)
  pinMode(led, OUTPUT);   // LED diod, PWM enable
}

void loop() {
  // touch priority
  if(digitalRead(touch) == HIGH)
  {
    // led on
    for (int brightness = 0; brightness < 255; brightness++) 
    {
      analogWrite(led, brightness);
      delay(5);
    }
    
    while(digitalRead(touch) == LOW);
    
    // led off
    for (int brightness = 255; brightness >= 0; brightness--) 
    {
      analogWrite(led, brightness);
      delay(5);
    }
  }
  
  // IR
  if(digitalRead(ir) == LOW)
  {
    delay(1000);  // for surrounding light detection
    
    if(digitalRead(ir) == HIGH)
     {
      // led on
      for (int brightness = 0; brightness < 255; brightness++) 
      {
        analogWrite(led, brightness);
        delay(5);
      }
      
      // touch priority 
      while(digitalRead(ir)==HIGH && digitalRead(touch)==LOW);
      
      // led off
      for (int brightness = 255; brightness >= 0; brightness--) 
      {
        analogWrite(led, brightness);
        delay(5);
      }
    }
  }
}

*/


