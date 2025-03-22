#ifndef NAZWAPLIKU_H
#define NAZWAPLIKU_H
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Utils
{
    static bool isFloatOrDoubleFormGood(string number);
public:
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string number);
    static float convertStringToFloat(string number);
    static string convertFloatToString(float number);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static string loadLine();
    static char loadChar();
    static int loadInteger();
    static float loadFloat();
    static string changeComaToDot(string wordToChange);
};

#endif
