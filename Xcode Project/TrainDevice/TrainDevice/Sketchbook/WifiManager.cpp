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
    /*
    if (status->getStatus() == Status::WIFI_CONNECTING) {
        if (WiFi.status() == WL_CONNECTED){
            status->setStatus(Status::WIFI_CONNECTED);
            ip = WiFi.localIP();
        }
    } else {
        status->setStatus(WiFi.status());
    }*/
    status->setStatus(WiFi.status());
    if (WiFi.status() != WL_CONNECTED){
        status->showStatus();
    }
    return status->getStatus();
}

void WifiManager::connect(String bssid, String password){
    WiFi.begin(bssid.c_str(),password.c_str());
    WifiManager::port.begin(WifiManager::portNumber);
    status->setStatus(Status::WIFI_CONNECTING);
}

void WifiManager::setPort(int newPort){
    WifiManager::portNumber = newPort;
}

int WifiManager::getPort(){
    return WifiManager::portNumber;
}

IPAddress WifiManager::getIp() {
    if (WiFi.status() == WL_CONNECTED) {
        ip = WiFi.localIP();
    }
    return ip;
}

String WifiManager::readPacket() {
    char packetBuffer[512];
    int packetSize = port.parsePacket();
    if (packetSize) {
        int dataLength = port.read(packetBuffer,512);
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
