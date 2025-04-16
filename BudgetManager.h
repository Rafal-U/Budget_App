#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "Operation.h"
#include "OperationsFile.h"
#include "UserManager.h"
#include "Type.h"
#include "DateMethods.h"
#include "Utils.h"
using namespace std;

class BudgetManager
{
    //OperationsFile incomesFile;
    //OperationFile expensesFile;
    const int LOGGED_USER_ID;
    vector<Operation> expenses;
    vector<Operation> incomes;
    char selectOptionFromAddingOperationMenu();
    Operation addOperationDetails(const Type &type);
    //float calculateTotalIncomesFromATimePeriod();
    //float calculateTotalExpensesFromATimePeriod();
    //float calculateTotalBalance();
    //void sortOperationsByDate();

public:
    BudgetManager(/*string incomeFileName, string expenseFileName*/ int loggedUserId) : LOGGED_USER_ID(loggedUserId)
    {
        //incomes = loadOperationsFromFile(LOGGED_USER_ID);
        //expenses = loadOperationsFromFile(LOGGED_USER_ID);
    };
    void addOperation(const Type &type);
    //void showOperationsFromATimePeriod(string startDate, string endDate);

    void showVector();
};


#endif
