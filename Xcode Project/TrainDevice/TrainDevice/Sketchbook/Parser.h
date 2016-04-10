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
#include <vector>


class Parser {
private:
    String message;
    std::vector<char *> split(char str[], char delimiters[]);
public:
    Parser();
    std::vector<std::vector<char *>> parse(String message);
};

#endif
