///
/// @file		Parser.h
/// @brief		Library header
/// @details	<#details#>
/// @n	
/// @n @b		Project TrainDevice
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Ignacio Esteban Cossini Benchimol
/// @author		CossiniSoftware
///
/// @date		13/3/16 2:09
/// @version	<#version#>
/// 
/// @copyright	(c) Ignacio Esteban Cossini Benchimol, 2016
/// @copyright	<#license#>
///
/// @see		ReadMe.txt for references
///

#ifndef Parser_cpp
#define Parser_cpp

#include "Arduino.h"
#include "Command.h"
#include <vector>


class Parser {
private:
    int currentMessage;
    int lastMessage;
    std::vector<String> commands;
    char * stringToCharArray(String str);
    std::vector<String> split(char str[], char delimiters[]);
    String trimCommand(String & str);
public:
    Parser();
    void parseMessage(String message);
    Command * getNextCommand();
    int getMessagesCount();
};

#endif
