void fireCamera() {
  // camera-ir-code
  firing = true;
  goTo(31);
  LCD.print("*");
  delay(500);
  goTo(31);
  LCD.print(" ");
  delay(500);
  firing = false;
}
