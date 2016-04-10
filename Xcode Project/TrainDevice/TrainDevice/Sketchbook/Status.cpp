#include "Status.h"
#include "Arduino.h"


Status::Status(int statusValue){
    ledStatus = Status::STATUS_LED;
    ledPeriod = 175;
    currentStatus = statusValue;
    pinMode(ledStatus,OUTPUT);
    showStatus();
}

Status::Status(int statusValue, int statusLed){
    ledStatus = statusLed;
    ledPeriod = 175;
    currentStatus = statusValue;
    pinMode(ledStatus,OUTPUT);
    showStatus();
}

void Status::showStatus() {
    digitalWrite(ledStatus,LOW);
    int i = 0;
    while (i < currentStatus){
        blinkLed();
        delay(ledPeriod);
        i++;
    }
    delay(ledPeriod);
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

