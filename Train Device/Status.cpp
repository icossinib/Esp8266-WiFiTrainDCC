#include "Status.h"
#include "Arduino.h"

Status::Status() {
  currentStatus = 1;
  ledPeriod = 300;
}

void Status::showStatus() {
  digitalWrite(ledStatus,LOW);
  int i = 0;
  while (i < currentStatus){
    blinkLed();
    delay(ledPeriod);
    i++;
  }
}

void Status::blinkLed() {
  digitalWrite(ledStatus,HIGH);
  delay(ledPeriod);
  digitalWrite(ledStatus,LOW);
}

int Status::getStatus() {
   return currentStatus;
}

void Status::setStatus(int status){
  currentStatus = status;
}

