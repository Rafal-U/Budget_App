#include <iostream>
#include "BudgetApp.h"
using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml"/*, "Incomes.xml", "Expenses.xml*/);
    char mainChoice;

    while(true)
    {
        mainChoice = budgetApp.selectMainMenuOption();
        switch(mainChoice)
        {
            case '1': budgetApp.registerUser(); break;
            case '2':
                //budgetApp.logInUser();
                //budgetApp.manageUserOptions();
                budgetApp.showUsers();
                break;
            case '3': exit(0); break;
            default: cout << "Nie ma takiej opcji! Wybierz ponownie!" << endl; Sleep(3000);
        }
    }
    return 0;
}
