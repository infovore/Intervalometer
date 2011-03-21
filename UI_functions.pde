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
    if(startCountNumber == 1) {
      sprintf(buffer,"%d Minute    ",startCountNumber);   
    } else {
      sprintf(buffer,"%d Minutes   ",startCountNumber);   
    }
  
  } else {
    if(startCountNumber ==1) {
      sprintf(buffer,"%d Second    ",startCountNumber);   
    } else {
      sprintf(buffer,"%d Seconds   ",startCountNumber);   
    }
  }
  LCD.print(buffer);
}

void checkButtonPush() {
  debouncer.update();
  buttonState = debouncer.read();

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
