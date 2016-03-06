#include "EepromReader.h"
#include <EEPROM.h>

EepromReader::EepromReader() {
    EepromReader::startEeprom( EepromReader::EEPROM_START);
}

void EepromReader::startEeprom(int address) {
    EEPROM.begin(address);
    delay(10);
}

void EepromReader::writeData(String bssid, String password, String ip) {
    write(bssid,EepromReader::BSSID_MAX_LENGTH);
}

void EepromReader::write(String data, const short dataMaxLength) {
    int i = 0;
    for (i = 0; i < data.length() && i < dataMaxLength; i++) {
        EEPROM.write(i,data[i]);
        Serial.print(data[i]);
        Serial.print(" ");
        Serial.println(int(data[i]));
    }
    Serial.print("Data writen");
    Serial.println(i);
    EEPROM.commit();
    delay(10);
}

String EepromReader::read(){
    EepromReader::startEeprom(EepromReader::EEPROM_START);
    char bssid [EepromReader::BSSID_MAX_LENGTH] = "Not read";
    int i = 0;
    for (i = 0; i < EepromReader::BSSID_MAX_LENGTH && bssid[i] != '\0'; ++i) {
        bssid[i] = char(EEPROM.read(i));
        Serial.print(bssid[i]);
        Serial.print("-");
        Serial.println(int(EEPROM.read(i)));
        Serial.print(int(bssid[i]));
        Serial.print(" ");
        Serial.println(int(EEPROM.read(i)));
        
    }
    Serial.println("data read: ");
    Serial.println(i);
    Serial.println(bssid);
    String a(bssid);
    return a;
}

String EepromReader::getBssid(){
    return EepromReader::read();
}
