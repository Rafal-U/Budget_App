#include "File.h"

string File::getFileName()
{
    return FILE_NAME;
}

bool File::fileExist(string xmlFileName)
{
    return xmlDoc.Load(xmlFileName);
}


int File::getLastId()
{
    int currentID = 0, lastId = 0;

    if(fileExist(getFileName()))
    {
        xmlDoc.FindElem();
        xmlDoc.IntoElem();
        while(xmlDoc.FindElem())
        {
            currentID = Utils::convertStringToInteger(xmlDoc.GetAttrib("ID"));
            if(currentID > lastId)
            {
                lastId = currentID;
            }
        }
    }
    return lastId;
}
