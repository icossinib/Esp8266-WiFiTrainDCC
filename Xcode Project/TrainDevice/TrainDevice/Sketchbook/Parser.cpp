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

std::vector<String> Parser::split(char str[], char delimiters[]){
    std::vector<String> internal;
    char * part;
    part = strtok(str, delimiters);
    int i = 0;
    while (part != NULL) {
        String pushed(part);
        pushed.trim();
        internal.push_back(pushed);
        part = strtok(NULL, delimiters);
        i++;
    }
    return internal;
}   

void  Parser::parseMessage(String message){
    char command_delimiters[] = ",";
    char * commandsArray = stringToCharArray(message);
    
    commands = split(commandsArray,command_delimiters);
    
    currentMessage = 0;
    
    lastMessage = commands.size();
}

Command * Parser::getNextCommand(){
    char values_delimiters[] = ":";
    if (currentMessage < lastMessage) {
        char * next_command = stringToCharArray(trimCommand(commands[currentMessage]));
        
        std::vector<String> command_parts = split(next_command,values_delimiters);

        Command * command = new Command(command_parts.front(),command_parts.back());
        
        currentMessage++;
        
        return command;
    } else {
        return nullptr;
    }
    
}

char * Parser::stringToCharArray(String str){
    char * newCharArray = new char[str.length() +1 ];
    str.toCharArray(newCharArray,str.length() + 1);
    return newCharArray;
}

int Parser::getMessagesCount() {
    return lastMessage;
}

String Parser::trimCommand(String &str) {
    str.trim();
    if (str.endsWith("}") && str.startsWith("{")){
        str.setCharAt(0, ' ');
        str.setCharAt(str.length()-1, ' ');
        str.trim();
        return str;
    } else {
        return "";
    }
}
