#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "Markup.h"
using namespace std;

class File
{
    const string FILE_NAME;

protected:
    File(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    CMarkup xmlDoc;

public:
    int getLastId();
    bool fileExist(string xmlFileName);
};


#endif
