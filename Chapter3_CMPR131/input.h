//update to match oop style.
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <algorithm>
#include <string>

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character
std::string inputString(std::string prompt, bool spaces);

//PreCondition: valid string of options
//PostCondition: returns an uppercase of the option (char)
char inputChar(std::string prompt, std::string options);

//PreCondition: start (char) and end (char) and x(char)
//PostCondition: returns a character value between start and end or equal to x
char inputCharS(std::string prompt, char start, char end, char x);

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase yes (char) or no (char)
char inputChar(std::string prompt, char yes, char no);

//PreCondition: valid string of options
//PostCondition: if allowDigit true, also allows return return of digit character. otherwise, only alphabetic chars allowed
char inputChar(std::string prompt, std::string options, bool allowDigit);

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(std::string prompt, bool alphaOrDigit);

//PreCondition: NA
//PostCondition: returns any character
char inputChar(std::string prompt);

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(std::string prompt);

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(std::string prompt, bool posNeg);

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(std::string prompt, int start, bool greater);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRange and endRange)
int inputInteger(std::string prompt, int startRange, int endRange);

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(std::string prompt);

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(std::string prompt, bool posNeg);

//PreCondition: start(double) and posNeg(boolean true or false)
//PostCondition: returns a double value greater than start (posNeg = true) or lesser than start (poseNeg = false)
double inputDouble(std::string prompt, double start, bool posNeg);

//PreCondition: startRange (double) and endRange (double)
//PostCondition: returns a double value within range (startRange and endRange)
double inputDouble(std::string prompt, double startRange, double endRange);

#endif // INPUT_H