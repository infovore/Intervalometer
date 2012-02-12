void arm() {
  armed = true;
  backlightOff();
  delay(10);
  recalculateStartCountInSeconds();
  timedAction.setInterval(startCountInSeconds * 1000);
  timedAction.enable();
  ticker.enable();
  updateLcd();
}

void safe() {
  armed = false;
  backlightOn();
  delay(10);
  timedAction.disable();
  ticker.disable();
  goTo(31);
  LCD.print(" ");
  updateLcd();
  delay(1000);
}
