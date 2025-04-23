#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
    if (!fileExist(getFileName()))
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("USERS");
    }
    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("User");
    xmlDoc.AddAttrib("ID", user.userId);
    xmlDoc.IntoElem();
    xmlDoc.AddElem("Login", user.login);
    xmlDoc.AddElem("Password", user.password);
    xmlDoc.AddElem("Name", user.name);
    xmlDoc.AddElem("Surname", user.surname);

    xmlDoc.Save(getFileName());
}


vector<User> UserFile::loadUsersFromFile()
{
    vector<User> allUsers;
    User singleUser;
    if(fileExist(getFileName()))
    {
        xmlDoc.FindElem("USERS");
        xmlDoc.IntoElem();
        while(xmlDoc.FindElem("User"))
        {
            singleUser.userId = Utils::convertStringToInteger(xmlDoc.GetAttrib("ID"));
            xmlDoc.IntoElem();
            xmlDoc.FindElem("Login");
            singleUser.login = xmlDoc.GetData();
            xmlDoc.FindElem("Password");
            singleUser.password = xmlDoc.GetData();
            xmlDoc.FindElem("Name");
            singleUser.name = xmlDoc.GetData();
            xmlDoc.FindElem("Surname");
            singleUser.surname = xmlDoc.GetData();
            xmlDoc.OutOfElem();
            allUsers.push_back(singleUser);
        }
    }
    return allUsers;
}


void UserFile::changePasswortInFile(int id, string newPassword)
{
    if(fileExist(getFileName()))
    {
        xmlDoc.FindElem("USERS");
        xmlDoc.IntoElem();
        while(xmlDoc.FindElem("User"))
        {
            if(Utils::convertStringToInteger(xmlDoc.GetAttrib("ID")) == id)
            {
                xmlDoc.IntoElem();
                if(xmlDoc.FindElem("Password"))
                {
                    xmlDoc.SetData(newPassword);
                }
                xmlDoc.OutOfElem(); break;
            }
        }
        xmlDoc.Save(getFileName());
    }
}
