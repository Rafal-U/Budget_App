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
    while(userManager.isUserLoggedIn())
    {
        char choice;
        choice = userManager.selectUserMenuOption();
        switch(choice)
        {
            case '1': budgetManager ->addOperation(INCOME); break;
            case '2': budgetManager ->addOperation(EXPENSE); break;
            case '3': budgetManager ->showOperationsFromATimePeriod(DateMethods::findThisMonthDates())); break;
            case '4': budgetManager ->showOperationsFromATimePeriod(DateMethods::findLastMonthDates()); break;
            case '5': budgetManager ->showOperationsFromATimePeriod(DateMethods::findSelectedTimePeriodDates()); break;
            case '6': userManager.changePasswordOfLoggedInUser(); break;
            case '7': userManager.signOutUser(); break;
            default: cout << endl << "Nie ma takiej opcji! Wybierz ponownie!" << endl; Sleep(3000);
        }
    }
}


void BudgetApp::registerUser()
{
    userManager.registerUser();
}


void BudgetApp::logInUser()
{
    userManager.signInUser();
    if(userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void BudgetApp::showUsers()
{
    userManager.showUsers(); system("pause");
}
