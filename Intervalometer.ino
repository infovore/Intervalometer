#include <Bounce.h>
#include <SoftwareSerial.h>
#include <serLCD.h>
#include <multiCameraIrControl.h>
#include <TimedAction.h>

/* pin setups */

/* serial configuration */
serLCD lcd(4);

/* Encoder setup */

#define encoder0PinA  2
#define encoder0PinB  3

byte buttonPin = 10;
Bounce debouncer = Bounce( buttonPin, 50 ); 

/* camera setup */

Nikon nikon(13);

/* variables setup */
boolean armed = false;
boolean isMinutes = false;
boolean firing = false;
int startCountNumber = 10;
int startCountInSeconds = 10;
int countTime = 0;
int numberToPrint = 0;
int buttonState = 0;         // variable for reading the pushbutton status

int encoder0Pos = 0;

TimedAction timedAction = TimedAction(1000,fireCamera);
TimedAction ticker = TimedAction(1000,tickAnimation);

void setup()
{
  Serial.begin(9600);
  countTime = startCountInSeconds;
  
  // Turn on pullup resistors for encoder
  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  pinMode(buttonPin, INPUT);
  
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
