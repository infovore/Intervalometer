#include <NewSoftSerial.h>
#include <nikonIrControl.h>
#include <TimedAction.h>

/* pin setups */

/* serial configuration */
NewSoftSerial LCD=NewSoftSerial(2,1); //LCD Rx -> Pin 1
long baudRate = 9600;

/* Encoder setup */

#define encoder0PinA  2
#define encoder0PinB  4

byte switchPin = 6;

/* LED setup */
byte cameraIrPin = 7; // LED connected to digital pin 13

/* variables setup */
boolean armed = false;
boolean isMinutes = false;
boolean firing = false;
unsigned long lastTouch = 0;
int startCountNumber = 5;
int startCountInSeconds = 5;
int countTime = 0;
int backlightTimeout = 5; // timeout in seconds for LCD
boolean backlightIsOn = true;
int numberToPrint = 0;

unsigned long millisArmedAt = 0;
unsigned long millisSecondStartedAt = 0;
int secondsRemainingInInterval = 0;

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

  // turn on pullup for switch
  pinMode(cameraIrPin, INPUT);
  digitalWrite(switchPin, HIGH);
  
  // setup camera pin
  pinMode(cameraIrPin, OUTPUT);
  
  LCD.begin(baudRate);

  lcdSetup();  
  arm(); // for debug
  updateLcd();

}

void loop()
{ 
  //    checkButtonPush();
  if(armed) {
    timedAction.check();
    ticker.check();
    updateLcd();
  } else {
    recalculateStartCountInSeconds();
    updateLcd();
  }
}
