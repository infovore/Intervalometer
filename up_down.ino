void nudgeUp() {
 if(!armed) {
    if(isMinutes) {
      if(startCountNumber == 15) {
        // do nothing, that's our maximum
      } else {
        startCountNumber += 1;
      }
    } else {
      if(startCountNumber == 90) {
        isMinutes = true;
        startCountNumber = 2;
      } else {
        startCountNumber += 1;
      }
    }
 }
}

void nudgeDown() {
 if(!armed) {
    if(isMinutes) {
      if(startCountNumber == 2) {
        isMinutes = false;
        startCountNumber = 90;
      } else {
        startCountNumber -= 1;
      }
    } else {
      if(startCountNumber == 1) {
        // do nothing, can't go lower
      } else {
        startCountNumber -= 1;
      }
    }
 }
}

void recalculateStartCountInSeconds() {
  if(isMinutes) {
    startCountInSeconds = startCountNumber * 60;
  } else {
    startCountInSeconds = startCountNumber;
  }
//  Serial.println("start count in seconds is now");
//  Serial.println(startCountInSeconds);
}
