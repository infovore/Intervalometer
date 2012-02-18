void doEncoder(){
  if (digitalRead(encoder0PinA) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encoder0PinB) == LOW) {  // check channel B to see which way
                                             // encoder is turning
      encoder0Pos = encoder0Pos - 1;         // CCW
      if(encoder0Pos % 4 == 0) {
        nudgeUp();
      }
    } 
    else {
      encoder0Pos = encoder0Pos + 1;         // CW
      if(encoder0Pos % 4 == 0) {
        nudgeDown();
      }
    }
  }
  else                                        // found a high-to-low on channel A
  { 
    if (digitalRead(encoder0PinB) == LOW) {   // check channel B to see which way
                                              // encoder is turning  
      encoder0Pos = encoder0Pos + 1;          // CW
      if(encoder0Pos % 4 == 0) {
        nudgeDown();
      }
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
      if(encoder0Pos % 4 == 0) {
        nudgeUp();
      }
    }
  }
}
