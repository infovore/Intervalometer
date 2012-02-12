#include <Debounce.h>
#include <SoftwareSerial.h>
#include <multiCameraIrControl.h>
#include <TimedAction.h>

/* pin setups */

/* serial configuration */
SoftwareSerial LCD(2,1); //LCD Rx -> Pin 1
long baudRate = 9600;

/* Encoder setup */

#define encoder0PinA  2
#define encoder0PinB  4

byte buttonPin = 6;
Debounce debouncer = Debounce( 50 , buttonPin ); 

/* camera setup */

Nikon nikon(13);

/* variables setup */
boolean armed = false;
boolean isMinutes = false;
boolean firing = false;
int startCountNumber = 5;
int startCountInSeconds = 5;
int countTime = 0;
int numberToPrint = 0;
int buttonState = 0;         // variable for reading the pushbutton status

int encoder0Pos = 0;

TimedAction timedAction = TimedAction(1000,fireCamera);
TimedAction ticker = TimedAction(1000,tickAnimation);

void setup()
{
  countTime = startCountInSeconds;
  
  // Turn on pullup resistors for encoder
  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  pinMode(buttonPin, INPUT);
  
  // setup camera pin (not needed given we have nikon library
//  pinMode(cameraIrPin, OUTPUT);
  
  LCD.begin(baudRate);

  lcdSetup();  
//  arm(); // for debug
  updateLcd();
}

void loop()
{ 
  checkButtonPush();
  if(armed) {
    timedAction.check();
    ticker.check();
    updateLcd();
  } else {
    recalculateStartCountInSeconds();
    updateLcd();
  }
}
