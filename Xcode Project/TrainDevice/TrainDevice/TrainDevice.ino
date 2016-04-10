//
// TrainDevice
//
// Code for EsP8266-12 device for controlling an H0 train
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Ignacio Esteban Cossini Benchimol
// 				CossiniSoftware
//
// Date			3/3/16 22:06
// Version		<#version#>
//
// Copyright	© Ignacio Esteban Cossini Benchimol, 2016
// Licence		<#licence#>
//
// See         ReadMe.txt for references
//


// Core library for code-sense - IDE-based
#if defined(ESP8266) // ESP8266 specific
#   include "Arduino.h"
#else // error
#   error Platform not defined
#endif // end IDE

// Include application, user and local libraries

/*#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Status.h"*/
#include "EepromReader.h"
#include "WifiManager.h"
#include "Parser.h"
// Prototypes


// Define variables and constants
/*
static int EEPROM_START_ADDRESS = 0;

int output1 = 14;
int statusLed = 13;

WiFiUDP port;
IPAddress ip;
unsigned int localPort = 9999;
String ssid;
char pass[64];

char packetBuffer[255];

Status *status = new Status(statusLed, 1);

void startEeprom() {
    EEPROM.begin(512);
    delay(10);
}

void readEeprom() {
    String esid;
    for (int i = 0; i < 33; ++i)
    {
        esid += char(EEPROM.read(i));
    }
    Serial.print("SSID: ");
    Serial.println(esid);
    //ssid = esid.c_str();
}

void writeEeprom() {
    ssid = "012345678901234567890123456789ab";
    for (int i = 0; i < 33; ++i)
    {
        EEPROM.write(i, ssid[i]);
        Serial.print("Wrote: ");
        Serial.println(ssid[i]);
    }
    EEPROM.commit();
}
void connectWifi() {
    WiFi.begin("Black", "navara77");
    port.begin(localPort);
    status->setStatus(2);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting to wifi");
        status->showStatus();
        delay(700);
    }
    status->setStatus(3);
    status->showStatus();
    ip = WiFi.localIP();
    Serial.println(ip);
    Serial.println("Connected");
}

void serialSetup() {
    Serial.begin(9600);
}

void setup() {
    pinMode(output1, OUTPUT);
    serialSetup();
    connectWifi();
    startEeprom();
    //readEeprom();
    //writeEeprom();
    //readEeprom();
}

int valueRead = 0;
void loop() {
    int packetSize = port.parsePacket();
    if (packetSize) {
        int len = port.read(packetBuffer, 255);
        if (len > 0) packetBuffer[len] = 0;
        valueRead = atoi(packetBuffer);
        analogWrite(output1, valueRead);
        Serial.print("Received: ");
        Serial.println(valueRead);
    }
}

*/

EepromReader eepromReader = EepromReader();
/*
WiFiUDP port;
IPAddress ip;
unsigned int localPort = 9999;

void connectWifi() {
    WiFi.begin("Black", "navara77");
    port.begin(localPort);
    status->setStatus(2);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting to wifi");
        status->showStatus();
        delay(700);
    }
    status->setStatus(3);
    status->showStatus();
    ip = WiFi.localIP();
    Serial.println(ip);
    Serial.println("Connected");
}
*/

WifiManager wifimanager = WifiManager();

void setup() {
    wifimanager.connect("ID","pocholeremito");
    Serial.begin(9600);
    Serial.println("connection started");
    while (wifimanager.getStatus() != 3){
        Serial.println("Connecting");
        delay(1000);
    }
    Serial.println("Connected");
    Serial.print("Ip: ");
    Serial.println(wifimanager.getIp());
}

String dataRead = "";
Parser parser = Parser();

void loop()  {
    if (wifimanager.getStatus() == 3)
    {
        dataRead = wifimanager.readPacket();
        if (dataRead.length() != 0){
            Serial.print("data: ");
            std::vector<std::vector<char * >> result(parser.parse(dataRead));
            
            std::vector<char*> vector1 = (std::vector<char *>)result[0];
            
            char * value = vector1[0];
            
            char * value2 = vector1[1];
            
            std::vector<char *> vector2 = (std::vector<char *>) result[1];
            
            char* value3 = vector1[0];
            
            char * value4 = vector1[1];

            Serial.println(value);
            Serial.println(value2);
            Serial.println(value3);
            Serial.println(value4);
        }
    }
}