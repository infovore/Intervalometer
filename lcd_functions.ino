void selectLineOne(){  //puts the cursor at line 0 char 0.
   LCD.write(0xFE);   //command flag
   LCD.write(128);    //position
}
void selectLineTwo(){  //puts the cursor at line 0 char 0.
   LCD.write(0xFE);   //command flag
   LCD.write(192);    //position
}
void goTo(int position) { 
  //position = line 1: 0-15, line 2: 16-31, 31+ defaults back to 0
  if (position<16) { 
    LCD.write(0xFE);   //command flag
    LCD.write((position+128));    //position
  } else if (position<32) {
    LCD.write(0xFE);   //command flag
    LCD.write((position+48+128));    //position 
  } else { 
    goTo(0); 
  }
}

void clearLCD(){
   LCD.write(0xFE);   //command flag
   LCD.write(0x01);   //clear command.
}
void backlightOn(){  //turns on the backlight
    LCD.write(0x7C);   //command flag for backlight stuff
    LCD.write(157);    //light level.
}
void backlightOff(){  //turns off the backlight
    LCD.write(0x7C);   //command flag for backlight stuff
    LCD.write(128);     //light level for off.
}
void serCommand(){   
  //a general function to call the command flag for issuing all other commands   
  LCD.write(0xFE);
}
