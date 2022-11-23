#pragma once

#include <iostream>
#include <limits>
#include <string>

/*
 *A header file for free floating utility functions
*/

//Prints a line of stars
void Divider(std::streambuf*);

//Invokes the system clear command
bool ClearScreen();

//For use after cin>> or get, extra input is ignored and cleared
void Safety(std::streambuf*);

//validation
bool allNum(std::string);
bool allLet(std::string);
bool rightSize(std::string, int min, int max);