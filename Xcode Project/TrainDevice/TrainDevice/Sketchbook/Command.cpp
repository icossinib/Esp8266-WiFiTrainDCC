//
// Command.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		TrainDevice
//
// Created by 	Ignacio Esteban Cossini Benchimol, 10/4/16 18:59
// 				CossiniSoftware
//
// Copyright 	(c) Ignacio Esteban Cossini Benchimol, 2016
// Licence		<#license#>
//
// See 			Command.h and ReadMe.txt for references
//


// Library header
#include "Command.h"

// Code
Command::Command(String command_char, String value_char){
    Serial.println(command_char);
    command = String(command_char);
    Serial.println(command);
    command = trimCommand(command);
    Serial.println(command);
    Serial.println(value_char);
    value = String(value_char);
    Serial.println(value);
    value = trimCommand(value);
    Serial.println(value);
    Serial.print("Command:C: ");
    Serial.println(command);
    Serial.print("Command:V: ");
    Serial.println(value);
}

String Command::getCommand() {
    return command;
}

String Command::getValue() {
    return value;
}

String Command::trimCommand(String str) {
    str.trim();
    if (str.endsWith("\"") && str.startsWith("\"")){
        str.setCharAt(0, ' ');
        str.setCharAt(str.length()-1, ' ');
        str.trim();
    }
    return str;
}