void fireCamera() {
  nikon.shutterNow();
  delay(10);
  firing = true;
  lcd.setCursor(2,16);
  lcd.print("*");
  delay(500);
  lcd.setCursor(2,16);
  lcd.print(" ");
  delay(500);
  firing = false;
}
