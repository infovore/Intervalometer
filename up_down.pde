void nudgeUp() {
//  if(!armed) {
  touchControl();
    if(isMinutes) {
      if(startCountNumber == 15) {
        // do nothing, that's our maximum
      } else {
        startCountNumber++;
      }
    } else {
      if(startCountNumber == 89) {
        isMinutes = true;
        startCountNumber = 2;
      } else {
        startCountNumber++;
      }
    }
//  }
}

void nudgeDown() {
//  if(!armed) {
  touchControl();
    if(isMinutes) {
      if(startCountNumber == 2) {
        isMinutes = false;
        startCountNumber = 89;
      } else {
        startCountNumber--;
      }
    } else {
      if(startCountNumber == 1) {
        // do nothing, can't go lower
      } else {
        startCountNumber--;
      }
    }
//  }
}

void recalculateStartCountInSeconds() {
  if(isMinutes) {
    startCountInSeconds = startCountNumber * 60;
  } else {
    startCountInSeconds = startCountNumber;
  }
}
