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
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    BudgetApp(string userFileName/*, string incomeFileName, string expenseFileName*/)
    : userManager(userFileName)//, INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        //budgetManager = NULL;
    };

/*~BudgetApp()
     {
         delete budgetManager;
         budgetManager = NULL;
     };*/
    char selectMainMenuOption();
    void registerUser();
    void logInUser();
    void manageUserOptions();

    void showUsers();
};

#endif
