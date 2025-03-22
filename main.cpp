#include <iostream>
#include "Utils.h"
using namespace std;

int main()
{
    string wyraz = "";
    float liczba = 0.0;

    wyraz = "Hej";
    liczba = Utils::loadFloat();
    cout << "Wyraz: " << wyraz << endl;
    cout << "Liczba: " << liczba << endl;


    return 0;
}
