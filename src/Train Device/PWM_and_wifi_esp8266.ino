#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Status.h"
#include <EEPROM.h>

static int EEPROM_START_ADDRESS = 0;

int output1 = 14;
int statusLed = 13;

WiFiUDP port;
IPAddress ip;
unsigned int localPort = 9999;
String ssid;
char pass[64];

char packetBuffer[255];

Status *status = new Status(statusLed,1);

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

