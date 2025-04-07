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
