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
        operation.date = DateMethods::loadDate();
        if(operation.date > DateMethods::convertStructDateToIntegerDate(DateMethods::getCurrentLokalDateFromSystem()))
        {
            cout << "UWAGA! Wprowadzona data jest pozniejsza od dnia dzisiejszego." << endl;
            cout << "Moze nie pojawic sie w wyszukiwaniu operacji z tego miesiaca!" << endl;
            system("pause");
        }
        if(operation.date == 0){return operation;}
        break;

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
    cout << "Data: " << DateMethods::convertIntegerDateToStringLine(operation.date) << endl;
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
    int operationCount = 0;

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
    sort(operations.begin(), operations.end(), BudgetManager::compareOperationsByDate);

    cout << title << endl;
    for(int i = 0; i < operations.size(); i++)
    {
        goodDate = DateMethods::findSelectedTimePeriodDates(startDate, endDate, operations[i].date);
        if(goodDate)
        {
            operationCount++;
            cout << "<<<< " << operationCount << " >>>>" << endl;
            cout << "Data:      " << DateMethods::convertIntegerDateToStringLine(operations[i].date) << endl;
            cout << "Wartosc:   " << fixed << setprecision(2) << operations[i].amount << endl;
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
    if(fromDate <= toDate && DateMethods::isIntegerDateGood(fromDate) && DateMethods::isIntegerDateGood(toDate))
    {
        totalIncomes = showOperationsFromATimePeriod(fromDate, toDate, INCOME);
        totalExpenses = showOperationsFromATimePeriod(fromDate, toDate, EXPENSE);
        totalBalance =  totalIncomes - totalExpenses;

        cout << fixed << setprecision(2);
        cout << "Suma przychodow:  " << totalIncomes << endl;
        cout << "Suma wydatkow:    " << totalExpenses << endl;
        cout << "Bilans calkowity: " << totalBalance << endl;
        system("pause");
    }
    else
    {
        cout << "Wystapil blad. Nastapi powrot do menu uzytkownika." << endl; Sleep(3000);
    }
}


void BudgetManager::selectTimePeriodAndShowBalance()
{
    int startDate = 0, endDate = 0;
    system("cls");
    cout << "DATA POCZATKOWA WYBRANEGO OKRESU" << endl << endl;
    startDate = DateMethods::loadDate();
    if(startDate == 0) {return;}

    cout << endl << "DATA KONCOWA WYBRANEGO OKRESU" << endl << endl;
    endDate = DateMethods::loadDate();
    if(endDate == 0) {return;}

    if(startDate > endDate)
    {
        cout << "Data rozpoczecia wyszukiwania jest wieksza od daty koncowej!" << endl;
        Sleep(2500);
    }

    if(startDate <= endDate)
    {
        showBalanceFromTimePeriod(startDate, endDate);
    }
}
