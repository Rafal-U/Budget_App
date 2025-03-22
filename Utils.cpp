#include "Utils.h"

bool Utils::isFloatOrDoubleFormGood(string number)
{
    bool isGood = true;
    int dotCount = 0;

    for(int i = 0; i < number.length(); i++)
    {
        if(number[i] == '.')
        {
            dotCount++;
        }
        if((!isdigit(number[i]) && number[i] != '.') || number[0] == '.' || dotCount > 1)
        {
            isGood = false;
        }
    }
    return isGood;
}

string Utils::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


int Utils::convertStringToInteger(string number)
{
    int integer;
    istringstream iss(number);
    iss >> integer;
    return integer;
}


float Utils::convertStringToFloat(string number)
{
    float value = (float)atof(number.c_str());
    return value;
}


string Utils::convertFloatToString(float value)
{
    ostringstream ss;
    ss << value;
    return ss.str();
}


string Utils::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


string Utils::loadLine()
{
    string input;
    getline(cin, input);
    return input;
}


char Utils::loadChar()
{
    string input = "";
    char character = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}


int Utils::loadInteger()
{
    string input;
    int number;
    while(true)
    {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> number)
        {
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie" << endl;
    }
    return number;
}


float Utils::loadFloat()
{
    float value = 0.0;
    string line = "";

    while(true)
    {
        line = loadLine();
        line = changeComaToDot(line);
        if(isFloatOrDoubleFormGood(line))
        {
            value = convertStringToFloat(line);
            return value;
        }
        else
        {
            cout << "Wprowadzone dane sa niepoprawne. Wpisz liczbe ponownie." << endl;
        }
    }
}


string Utils::changeComaToDot(string wordToChange)
{
    for(int i = 0; i < wordToChange.length(); i++)
    {
        if(wordToChange[i] == ',')
        {
            wordToChange[i] = '.';
        }
    }
    return wordToChange;
}
