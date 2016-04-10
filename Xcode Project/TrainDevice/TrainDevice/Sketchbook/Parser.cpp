//
// Parser.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		TrainDevice
//
// Created by 	Ignacio Esteban Cossini Benchimol, 13/3/16 2:09
// 				CossiniSoftware
//
// Copyright 	(c) Ignacio Esteban Cossini Benchimol, 2016
// Licence		<#license#>
//
// See 			Parser.h and ReadMe.txt for references
//


// Library header
#include "Parser.h"
//#include <vector>

// Code

Parser::Parser() {
}

std::vector<char *> Parser::split(char str[], char delimiters[]){
    std::vector<char *> internal;
    char * part;
    part = strtok(str, delimiters);
    int i = 0;
    while (part != NULL) {
        internal.push_back(part);
        //Serial.print("Debug: ");
        //Serial.println(part);
        part = strtok(NULL, delimiters);
        i++;
    }
    return internal;
}   

std::vector<std::vector<char *>>  Parser::parse(String message){
    Serial.println("Received string: ");
    Serial.println(message);
    std::vector<char *> internal;
    char command_delimiters[] = {','};
    char values_delimiters[] = ":";
    char commands_string[message.length()+1];
    
    message.toCharArray(commands_string, message.length());
    Serial.println("charArray converted: ");
    Serial.println(commands_string);
    
    internal = split(commands_string,command_delimiters);
    Serial.print("Debug2: ");
    Serial.println(internal[0]);
    
    std::vector<std::vector<char *>> toReturn;
    for (int i = 0; i< internal.size(); i++) {
        std::vector<char *> command = split(internal.at(i),values_delimiters);
        for (int j = 0; j < command.size(); j++) {
            Serial.print("Commands:");
            Serial.print(j);
            Serial.print(":");
            Serial.println(command[j]);
        }
        Serial.println(" ---- ");
        toReturn.push_back(command);
    }
    return toReturn;
}

