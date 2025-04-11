#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "File.h"
#include "User.h"
#include "Utils.h"
using namespace std;

class UserFile :public File
{
public:
    UserFile(string fileName) : File(fileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changePasswortInFile(int id, string newPassword);
};

#endif
