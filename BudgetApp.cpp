#include "BudgetApp.h"

char BudgetApp::selectMainMenuOption()
{
    char choice;
    system ("cls");
    cout << "         MENU GLOWNE" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Zarejestruj sie" << endl;
    cout << "2. Zaloguj sie" << endl;
    cout << "3. Zamknij program" << endl << endl;
    cout << "Wybierz numer stojacy przy danej opcji i zatwierdz Enter" << endl;
    cout << endl << endl << "Wybierasz opcje:   ";
    choice = Utils::loadChar();
    return choice;
}


void BudgetApp::manageUserOptions()
{
    while(true)
    {
        char choice;
        choice = userManager.selectUserMenuOption();
        switch(choice)
        {
            case '1': ; break;
            case '2': ; break;
            case '3': ; break;
            case '4': ; break;
            case '5': ; break;
            case '6': ; break;
            case '7': ; break;
            default: cout << endl << "Nie ma takiej opcji! Wybierz ponownie!" << endl; Sleep(3000);
        }
    }
}


void BudgetApp::registerUser()
{
    userManager.registerUser();
}
