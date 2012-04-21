void arm() {
  armed = true;
  lcd.setBrightness(1);
  recalculateStartCountInSeconds();
  timedAction.setInterval(startCountInSeconds * 1000);
  timedAction.enable();
  ticker.enable();
  updateLcd();
}

void safe() {
  armed = false;
  lcd.setBrightness(30);
  timedAction.disable();
  ticker.disable();
  lcd.setCursor(2,16);
  lcd.print(" ");
  updateLcd();
  delay(1000);
}
