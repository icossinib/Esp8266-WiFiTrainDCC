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

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <EEPROM.h>

// Prototypes


// Define variables and constants


// Add setup code
void setup()
{
    ;
}

// Add loop code
void loop()
{
    ;
}
