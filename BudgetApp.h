#ifndef BUDGETAPP_H
#define BUDGETAPP_H
#include <iostream>
#include <windows.h>
#include "Utils.h"
#include "UserManager.h"
#include "BudgetManager.h"
using namespace std;

class BudgetApp
{
    UserManager userManager;
    //BudgetManager *budgetManager;

public:
    //BudgetApp(string userFileName, string incomeFileName, string expenseFileName)

/*~BudgetApp()
     {
         delete budgetManager;
         budgetManager = NULL;
     };*/
    char selectMainMenuOption();
    void registerUser();
    //void logInUser();
    void manageUserOptions();
};

#endif
