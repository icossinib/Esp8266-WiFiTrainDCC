//
// WifiManager.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		TrainDevice
//
// Created by 	Ignacio Esteban Cossini Benchimol, 5/3/16 22:12
// 				CossiniSoftware
//
// Copyright 	(c) Ignacio Esteban Cossini Benchimol, 2016
// Licence		<#license#>
//
// See 			WifiManager.h and ReadMe.txt for references
//


#include "WifiManager.h"
#include <ESP8266WiFi.h>

WifiManager::WifiManager() {
    status = new Status(0);
}

int WifiManager::getStatus() {
    if (status->getStatus() == Status::WIFI_CONNECTING) {
        if (WiFi.status() != WL_CONNECTED){
            return status->getStatus();
        } else {
            status->setStatus(Status::WIFI_CONNECTED);
            ip = WiFi.localIP();
            return Status::WIFI_CONNECTED;
        }
    }
    else {
        return status->getStatus();
    }
}

void WifiManager::connect(String bssid, String password){
    WiFi.begin(bssid.c_str(),password.c_str());
    WifiManager::port.begin(WifiManager::portNumber);
    status->setStatus(1);
}

void WifiManager::setPort(int newPort){
    WifiManager::portNumber = newPort;
}

int WifiManager::getPort(){
    return WifiManager::portNumber;
}

IPAddress WifiManager::getIp() {
    return ip;
}

String WifiManager::readPacket() {
    char packetBuffer[255];
    int packetSize = port.parsePacket();
    if (packetSize) {
        int dataLength = port.read(packetBuffer,255);
        if (dataLength > 0) {
            packetBuffer[dataLength] = 0;
        }
        String toReturn(packetBuffer);
        return toReturn;
    }
    else {
        return "";
    }
}
