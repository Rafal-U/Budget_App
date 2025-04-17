#include "OperationsFile.h"

void OperationsFile::addOperationToFile(Operation singleOperation, const Type &type)
{
    string secondStepElement = "", title = "", fileTitle = "";

    switch(type)
    {
    case INCOME:
        title = "INCOMES";
        secondStepElement = "Income";
        break;
    case EXPENSE:
        title = "EXPENSES";
        secondStepElement = "Expense";
        break;
    }
    fileTitle = getFileName();

    if (!fileExist(fileTitle))
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem(title);
    }
    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem(secondStepElement);
    xmlDoc.AddAttrib("ID", singleOperation.operationId);
    xmlDoc.IntoElem();
    xmlDoc.AddElem("UserID", singleOperation.userId);
    xmlDoc.AddElem("Date", singleOperation.date);
    xmlDoc.AddElem("Item", singleOperation.item);
    xmlDoc.AddElem("Amount", Utils::convertFloatToString(singleOperation.amount));

    xmlDoc.Save(fileTitle);
}


vector<Operation> OperationsFile::loadOperationsFromFile(const int loggedUserId)
{
    vector<Operation> allOperations;
    Operation singleOperation;

    if(fileExist(getFileName()))
    {
        xmlDoc.FindElem();
        xmlDoc.IntoElem();
        while(xmlDoc.FindElem())
        {
            singleOperation.operationId = Utils::convertStringToInteger(xmlDoc.GetAttrib("ID"));
            xmlDoc.IntoElem();
            xmlDoc.FindElem("UserID");
            if(Utils::convertStringToInteger(xmlDoc.GetData()) == loggedUserId)
            {
                singleOperation.userId = loggedUserId;
                xmlDoc.FindElem("Date");
                singleOperation.date = Utils::convertStringToInteger(xmlDoc.GetData());
                xmlDoc.FindElem("Item");
                singleOperation.item = xmlDoc.GetData();
                xmlDoc.FindElem("Amount");
                singleOperation.amount = Utils::convertStringToFloat(xmlDoc.GetData());
                allOperations.push_back(singleOperation);
            }
            xmlDoc.OutOfElem();
        }
    }
    return allOperations;
}
