#include "BudgetManager.h"

int BudgetManager::getNewOperationId(const Type &type)
{
    switch(type)
    {
    case INCOME:
        if (incomesFile.getLastId() < 1)
        {
            return 1;
        }
        else
        {
            return incomesFile.getLastId() + 1;
        }
        break;

    case EXPENSE:
        if (expensesFile.getLastId() < 1)
        {
            return 1;
        }
        else
        {
            return expensesFile.getLastId() + 1;
        }
        break;
    }
}


void BudgetManager::addOperation(const Type &type)
{
    Operation singleOperation;
    singleOperation = addOperationDetails(type);
    if(singleOperation.date > 0 && singleOperation.amount > 0.0 && singleOperation.item != "0")
    {
        switch(type)
        {
        case INCOME:
            incomes.push_back(singleOperation);
            incomesFile.addOperationToFile(singleOperation, type);
            cout << "Pozytywnie dodano przychod." << endl; Sleep(3000); break;
        case EXPENSE:
            expenses.push_back(singleOperation);
            expensesFile.addOperationToFile(singleOperation, type);
            cout << "Pozytywnie dodano wydatek." << endl; Sleep(3000); break;
        }
    }
}

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    char choice;
    string operationType = "";

    switch (type)
    {
    case INCOME:
        operationType = "przychod";
        operation.operationId = getNewOperationId(type);
        break;

    case EXPENSE:
        operationType = "wydatek";
        operation.operationId = getNewOperationId(type);
        break;
    }
    operation.userId = LOGGED_USER_ID;

    system("cls");
    cout << "Kiedy nastapil " << operationType << "?" << endl;
    choice = selectOptionFromAddingOperationMenu();

    switch(choice)
    {
    case '1':
        operation.date = DateMethods::convertStructDateToIntegerDate(DateMethods::getCurrentLokalDateFromSystem()); break;
    case '2':
        cout << "Aby anulowac wcisnij 0 i potwierdz" << endl;
        operation.date = DateMethods::loadDate();
        if(operation.date == 0){return operation;} break;
    default:
        operation.date = 0; return operation;
    }

    system("cls");
    cout << "Aby anulowac wcisnij 0 i potwierdz" << endl;
    cout << "Czego dotyczy " << operationType << "?" << endl;
    operation.item = Utils::loadLine();
    if(operation.item == "0"){return operation;}

    system("cls");
    cout << "Aby anulowac wcisnij 0 i potwierdz" << endl;
    cout << "Wprowadz kwote:" << endl;
    operation.amount = Utils::loadDouble();
    if(operation.amount == 0){return operation;}

    system("cls");
    cout << "Czy na pewno chcesz dodac " << operationType << "?" << endl;
    cout << "Data: " << operation.date << endl;
    cout << "Opis: " << operation.item << endl;
    cout << "Wartosc: " << Utils::convertDoubleToString(operation.amount) << endl << endl;
    cout << "Aby potwierdzic wprowadz t lub T, aby anulowac inny dowolny znak." << endl;
    choice = Utils::loadChar();
    if(choice != 't' && choice != 'T')
    {
        operation.amount = 0; operation.date = 0; operation.item = "0";
    }
    return operation;
}


char BudgetManager::selectOptionFromAddingOperationMenu()
{
    char selection;
    cout << "1. Dzisiaj" << endl;
    cout << "2. Inna data (od 01.01.2000 do ostatniego dnia biezacego miesiaca)" << endl;
    cout << "Aby anulowac nacisnij inny dowolny znak" << endl;
    selection = Utils::loadChar();
    return selection;
}


void BudgetManager::showVector()
{
    system("cls");
    cout << "ID|UserID|Data|Opis|Wartosc" << endl;
    cout << endl << "PRZYCHODY" << endl;
    for(int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].operationId <<"|"<< incomes[i].userId <<"|"<< incomes[i].date <<"|"<< incomes[i].item <<"|"<< incomes[i].amount <<endl;
    }
    cout << endl << "WYDATKI" << endl;
    for(int i = 0; i < expenses.size(); i++)
    {
        cout << expenses[i].operationId <<"|"<< expenses[i].userId <<"|"<< expenses[i].date <<"|"<< expenses[i].item <<"|"<< expenses[i].amount <<endl;
    }
    system("pause");
}


bool BudgetManager::compareOperationsByDate(const Operation &a, const Operation &b)
{
    return a.date < b.date;
}


double BudgetManager::showOperationsFromATimePeriod(int startDate, int endDate, const Type &type)
{
    vector<Operation> operations;
    string title = "", totalTitle = "";
    double total = 0;
    bool goodDate = true;

    switch(type)
    {
    case INCOME:
        operations = incomes;
        title = "PRZYCHODY";
        break;

    case EXPENSE:
        operations = expenses;
        title = "WYDATKI";
        break;
    }
    //sort(operations.begin(), operations.end(), compareOperationsByDate);

    cout << title << endl;
    for(int i = 0; i < operations.size(); i++)
    {
        goodDate = DateMethods::findSelectedTimePeriodDates(startDate, endDate, operations[i].date);
        if(goodDate)
        {
            cout << "<<<< " << i << " >>>>" << endl;
            cout << "Data:      " << DateMethods::convertIntegerDateToStringLine(operations[i].date) << endl;
            cout << "Wartosc:   " << operations[i].amount << endl;
            cout << "Opis:      " << operations[i].item << endl << endl;
            total += operations[i].amount;
        }
    }
    cout << "-------------------------------------" << endl << endl;

    return total;
}


void BudgetManager::showBalanceFromTimePeriod(int fromDate, int toDate)
{
    double totalIncomes = 0, totalExpenses = 0, totalBalance = 0;

    system("cls");
    totalIncomes = showOperationsFromATimePeriod(fromDate, toDate, INCOME);
    totalExpenses = showOperationsFromATimePeriod(fromDate, toDate, EXPENSE);
    totalBalance =  totalIncomes - totalExpenses;

    cout << "Suma przychodow:  " << totalIncomes << endl;
    cout << "Suma wydatkow:    " << totalExpenses << endl;
    cout << "Bilans calkowity: " << totalBalance << endl;
    system("pause");
}
