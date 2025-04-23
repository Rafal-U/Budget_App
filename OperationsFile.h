#ifndef OPERATIONSFILE_H
#define OPERATIONSFILE_H
#include <iostream>
#include <vector>
#include "Operation.h"
#include "File.h"
#include "Type.h"
using namespace std;

class OperationsFile :public File
{
public:
    OperationsFile(string fileName) : File(fileName){;}
    vector<Operation> loadOperationsFromFile(const int loggedUserId);
    void addOperationToFile(Operation singleOperation, const Type &type);
};

#endif
