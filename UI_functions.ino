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
  lcd.clear();
  delay(50);
  lcd.setBrightness(30);
  lcd.home();
  lcd.print("Interval");
}

void updateLcd() {
  lcd.setCursor(1,13);
  lcd.print(stateString());
  lcd.setCursor(2,1);
  
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
  lcd.print(buffer);
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
    lcd.setCursor(2,16);
    lcd.print(".");
    delay(500);
    lcd.setCursor(2,16);
    lcd.print(" ");
    delay(500);
  }
}
