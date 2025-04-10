#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
    if (!fileExist("Users.xml"))
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("USERS");
    }
    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("User");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("ID", user.userId);
    xmlDoc.AddElem("Login", user.login);
    xmlDoc.AddElem("Password", user.password);
    xmlDoc.AddElem("Name", user.name);
    xmlDoc.AddElem("Surname", user.surname);

    xmlDoc.Save("Users.xml");
}


vector<User> UserFile::loadUsersFromFile()
{
    vector<User> allUsers;
    User singleUser;
    if(fileExist("Users.xml"))
    {
        xmlDoc.FindElem("USERS");
        xmlDoc.IntoElem();
        while(xmlDoc.FindElem("User"))
        {
            xmlDoc.IntoElem();
            xmlDoc.FindElem("ID");
            singleUser.userId = Utils::convertStringToInteger(xmlDoc.GetData());
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
