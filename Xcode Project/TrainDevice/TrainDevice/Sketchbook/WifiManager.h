///
/// @file		WifiManager.h
/// @brief		Library header
/// @details	<#details#>
/// @n	
/// @n @b		Project TrainDevice
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Ignacio Esteban Cossini Benchimol
/// @author		CossiniSoftware
///
/// @date		5/3/16 22:12
/// @version	<#version#>
/// 
/// @copyright	(c) Ignacio Esteban Cossini Benchimol, 2016
/// @copyright	<#license#>
///
/// @see		ReadMe.txt for references
///

#include "Arduino.h"
#include "Status.h"
#include <WiFiUdp.h>

#ifndef WifiManager_cpp
#define WifiManager_cpp

class WifiManager {
private:
    const static int DEFAULT_PORT_NUMBER = 9999;
    int portNumber = DEFAULT_PORT_NUMBER;
    WiFiUDP port;
    IPAddress ip;
    Status *status;
public:
    WifiManager();
    void connect(String bssid, String password);
    int getStatus();
    void setPort(int newPort);
    int getPort();
};

#endif
