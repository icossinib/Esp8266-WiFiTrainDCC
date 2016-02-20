#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP port;

char packetBuffer[255];
unsigned int localPort = 9999;
int valueRead = 0;
int output1 = 14;
int output2 = 13;
int freq_input = A0;
IPAddress ip;

void setup() {
  Serial.begin(9600);
  WiFi.begin("Black", "navara77");
  port.begin(localPort);
  Serial.println("Connected");
  Serial.print("Ip: ");
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  analogWriteFreq(1000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to wifi");
    
  }
  ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println("Connected");
}
int i = 0;
int frequ = 1000;
void loop() {
  int packetSize = port.parsePacket();
  /*frequ = analogRead(freq_input);
  analogWriteFreq(frequ);
  /*if (i > 1000) {
    Serial.print("Input in pot: ");
    Serial.println(frequ);
    i = 0;
  }
  i++;*/
  // Serial.println(packetSize);
  if (packetSize) {
    int len = port.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;
    valueRead = atoi(packetBuffer);
    digitalWrite(output2, LOW);
    analogWrite(output1, valueRead);
    Serial.print("Received: ");
    Serial.println(valueRead);    
  }
}

