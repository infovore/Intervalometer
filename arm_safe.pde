void arm() {
  armed = true;
  backlightOff();
  delay(10);
  recalculateStartCountInSeconds();
  timedAction.setInterval(startCountInSeconds * 1000);
}

void safe() {
  armed = false;
  backlightOn();
}
