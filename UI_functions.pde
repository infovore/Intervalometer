char* stateString() {
  if(armed) {
    char output[5] = " ARM";
    return output;
  } else {
    char output[5] = "SAFE";
    return output;
  }
}

void lcdSetup() {
  clearLCD();
  backlightOn();
  backlightIsOn = true;
  lastTouch = millis();  
  delay(10);
  goTo(0);
  LCD.print("Interval");
}

void updateLcd() {
  goTo(12);
  LCD.print(stateString());
  selectLineTwo();
  
  char buffer[12];
  if(isMinutes) {
    sprintf(buffer,"%d Minutes   ",startCountNumber);   
  } else {
    sprintf(buffer,"%d Seconds   ",startCountNumber);   
  }
  LCD.print(buffer);
}

void touchControl() {
  if(backlightIsOn) {
  } else {
    backlightOn();
    backlightIsOn = true;
  }
}

void checkButtonPush() {
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    if(armed) {
      safe();
    } else {
      arm();
    }
  } 
}

void blankBacklight() {
  if(backlightIsOn) {
    backlightIsOn = false;
    backlightOff();
    delay(10);
  }
}

void tickAnimation() {
  if(armed && !firing) {
    goTo(31);
    LCD.print(".");
    delay(500);
    goTo(31);
    LCD.print(" ");
    delay(500);
  }
}
