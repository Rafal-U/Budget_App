#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "Utils.h"
#include "UserFile.h"
using namespace std;

class UserManager
{
    //UserFile userFile
    int loggedInUserId;
    vector <User> users;
    bool loginExist(string login);
    bool isNameGood(string name);
    bool isPasswordGood(string password);
    bool isLoginGood(string login);
    bool isNewUserGood(User user);
    int getNewUserID();
    User addNewUserData();

public:
    //UserManager();
    char selectUserMenuOption();
    void registerUser();
    //void signInUser();
    //void changePasswordOfLoggedInUser();
    //bool isUserLoggedIn();
    //void signOutUser();
};

#endif
