void selectLineOne(){  //puts the cursor at line 0 char 0.
   LCD.print(0xFE, BYTE);   //command flag
   LCD.print(128, BYTE);    //position
}
void selectLineTwo(){  //puts the cursor at line 0 char 0.
   LCD.print(0xFE, BYTE);   //command flag
   LCD.print(192, BYTE);    //position
}
void goTo(int position) { 
  //position = line 1: 0-15, line 2: 16-31, 31+ defaults back to 0
  if (position<16) { 
    LCD.print(0xFE, BYTE);   //command flag
    LCD.print((position+128), BYTE);    //position
  } else if (position<32) {
    LCD.print(0xFE, BYTE);   //command flag
    LCD.print((position+48+128), BYTE);    //position 
  } else { 
    goTo(0); 
  }
}

void clearLCD(){
   LCD.print(0xFE, BYTE);   //command flag
   LCD.print(0x01, BYTE);   //clear command.
}
void backlightOn(){  //turns on the backlight
    LCD.print(0x7C, BYTE);   //command flag for backlight stuff
    LCD.print(157, BYTE);    //light level.
}
void backlightOff(){  //turns off the backlight
    LCD.print(0x7C, BYTE);   //command flag for backlight stuff
    LCD.print(128, BYTE);     //light level for off.
}
void serCommand(){   
  //a general function to call the command flag for issuing all other commands   
  LCD.print(0xFE, BYTE);
}
