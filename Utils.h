#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Utils
{
    static bool isFloatOrDoubleFormGood(string number);
public:
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string number);
    static double convertStringToDouble(string number);
    static string convertDoubleToString(double number);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static string loadLine();
    static char loadChar();
    static int loadInteger();
    static double loadDouble();
    static string changeComaToDot(string wordToChange);
};

#endif
