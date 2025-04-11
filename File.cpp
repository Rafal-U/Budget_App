#include "File.h"

string File::getFileName()
{
    return FILE_NAME;
}

bool File::fileExist(string xmlFileName)
{
    return xmlDoc.Load(xmlFileName);
}
