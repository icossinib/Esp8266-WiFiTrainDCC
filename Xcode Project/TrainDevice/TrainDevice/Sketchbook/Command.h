///
/// @file		Command.h
/// @brief		Library header
/// @details	<#details#>
/// @n	
/// @n @b		Project TrainDevice
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Ignacio Esteban Cossini Benchimol
/// @author		CossiniSoftware
///
/// @date		10/4/16 18:59
/// @version	<#version#>
/// 
/// @copyright	(c) Ignacio Esteban Cossini Benchimol, 2016
/// @copyright	<#license#>
///
/// @see		ReadMe.txt for references
///


// Core library for code-sense - IDE-based
#if defined(ESP8266) // mbed specific
#   include "Arduino.h"
#else // error
#   error Platform not defined
#endif // end IDE

#ifndef Command_cpp
#define Command_cpp

class Command {
private:
    String command;
    String value;
    String trimCommand(String str);
public:
    Command (String command_char, String value_char);
    String getCommand();
    String getValue();
};

#endif
