#include "EepromReader.h"
#include "Arduino.h"
#include <EEPROM.h>

EepromReader::EepromReader() {
    startEeprom( EEPROM_START);
}

void EepromReader::startEeprom(int address) {
    EEPROM.begin(address);
    delay(10);
}

void EepromReader::writeData(const char bssid[], const char password[], const char ip[]) {
    write(bssid,EepromReader::BSSID_MAX_LENGTH);
}

void EepromReader::write(const char data[], const short dataMaxLength) {
    for (int i = 0; i < strlen(data) && i < dataMaxLength; i++) {
        EEPROM.write(i,data[i]);
    }
    EEPROM.commit();
}

const char *EepromReader::read(){
    char bssid [EepromReader::BSSID_MAX_LENGTH] = "Not read";
    for (int i = 0; i < EepromReader::BSSID_MAX_LENGTH && bssid[i] != '\0'; ++i) {
        bssid[i] = char(EEPROM.read(i));
    }
    return bssid;
}

const char *EepromReader::getBssid(){
    return EepromReader::read();
}