#include "UserManager.h"

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}


char UserManager::selectUserMenuOption()
{
    char option;
    system ("cls");
    cout << "               MENU UZYTKOWNIKA" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Wyswietl bilans z biezacego miesiaca" << endl;
    cout << "4. Wyswietl bilans z poprzedniego miesiaca" << endl;
    cout << "5. Wyswietl bilans z wybranego okresu" << endl;
    cout << "6. Zmien swoje haslo" << endl;
    cout << "7. Wyloguj sie" << endl << endl;
    cout << "Wybierz opcje wpisujac numer stojacy przy danej opcji" << endl;
    option = Utils::loadChar();
    return option;
}


void UserManager::registerUser()
{
    char confirm;
    User singleUser = addNewUserData();
    if(isNewUserGood(singleUser))
    {
        system("cls");
        cout << "Sprawdz swoje dane zanim zatwierdzisz." << endl;
        cout << "Imie:       " << singleUser.name << endl;
        cout << "Nazwisko:   " << singleUser.surname << endl;
        cout << "Login:      " << singleUser.login << endl;
        cout << "Haslo:      " << singleUser.password << endl;
        cout << "Aby potwierdzic dane wcisnij: t lub T. Inny dowolny znak, aby anulowac" << endl;
        confirm = Utils::loadChar();
        if(confirm == 't' || confirm == 'T')
        {
            users.push_back(singleUser);
            userFile.addUserToFile(singleUser);
            cout << endl << "Konto zalozono pomyslnie. Nastapi przekierowanie do menu glownego" << endl; Sleep(2000);
        }
        else
        {
            system("cls");
            cout << "Nie zalozono konta. Nastapi przekierowanie do menu glownego" << endl; Sleep(2000);
        }
    }
}


User UserManager::addNewUserData()
{
    User user;
    user.userId = getNewUserID();

    do
    {
        system("cls");
        cout << "Aby anulowac i wrocic do menu glownego wcisnij: 0" << endl << endl;
        cout << "Podaj imie: " << endl;
        user.name = Utils::loadLine();
        if(user.name == "0") {return user;}
    }
    while (!isNameGood(user.name));
    user.name = Utils::changeFirstLetterForUpperCaseAndOthersForLowerCase(user.name);

    do
    {
        system("cls");
        cout << "Aby anulowac i wrocic do menu glownego wcisnij: 0" << endl << endl;
        cout << "Podaj nazwisko: " << endl;
        user.surname = Utils::loadLine();
        if(user.surname == "0") {return user;}
    }
    while (!isNameGood(user.surname));
    user.surname = Utils::changeFirstLetterForUpperCaseAndOthersForLowerCase(user.surname);

    do
    {
        system("cls");
        cout << "Aby anulowac i wrocic do menu glownego wcisnij: 0" << endl;
        cout << "Login powinien zawierac co najmniej 5 znakow i brak spacji." << endl << endl;
        cout << "Podaj login: " << endl;
        user.login = Utils::loadLine();
        if(user.login == "0") {return user;}
    }
    while (!isLoginGood(user.login));

    do
    {
        system("cls");
        cout << "Aby anulowac i wrocic do menu glownego wcisnij: 0" << endl;
        cout << "Haslo musi zawierac co najmniej 6 znakow w tym:" << endl;
        cout << "2 cyfry" << endl << "2 duze i male litery" << endl << "brak spacji" << endl << endl;
        cout << "Podaj haslo: " << endl;
        user.password = Utils::loadLine();
        if(user.password == "0") {return user;}
    }
    while (!isPasswordGood(user.password));

    return user;
}


bool UserManager::loginExist(string login)
{
    for (User sigleUser : users)
	{
		if(login == sigleUser.login)
        {
            cout << "Nie mozna ustawic tego loginu. Wymysl inny login." << endl; Sleep(3000);
            return true;
        }
	}
	return false;
}


bool UserManager::isNameGood(string name)
{
    if(name.length() < 2)
    {
        cout << "Dane sa za krotkie!" << endl; Sleep(3000);
        return false;
    }
    for(int i = 0; i < name.length(); i++)
    {
        if(isdigit(name[i]) || name[i] == ' ')
        {
            cout << "Dane zawieraja liczbe lub spacje!" << endl; Sleep(3000);
            return false;
        }
    }
    return true;
}


bool UserManager::isPasswordGood(string password)
{
    int numbersOfCapitalLetters = 0;
    int numberOfSmallLetters = 0;
    int numberOfDigits = 0;

    if(password.length() < 6)
    {
        cout << "Haslo jest za krotkie!" << endl; Sleep(3000);
        return false;
    }

    for(int i = 0; i < password.length(); i++)
    {
        if(password[i] == ' ')
        {
            cout << "Haslo zawiera spacje!" << endl; Sleep(3000);
            return false;
        }
        if(isdigit(password[i]))
        {
            numberOfDigits++;
        }
        if(islower(password[i]))
        {
            numberOfSmallLetters++;
        }
        if(isupper(password[i]))
        {
            numbersOfCapitalLetters++;
        }
    }

    if(numberOfDigits < 2 || numberOfSmallLetters < 2 || numbersOfCapitalLetters < 2)
    {
        cout << "Haslo ma niewymagajaca ilosc znakow konkretnego typu!" << endl; Sleep(3000);
        return false;
    }
    return true;
}


bool UserManager::isLoginGood(string login)
{
    if(login.length() < 5)
    {
        cout << "Login jest za krotki!" << endl; Sleep(3000);
        return false;
    }

    for(int i = 0; i < login.length(); i++)
    {
        if(login[i] == ' ')
        {
            cout << "Login zawiera spacje!" << endl; Sleep(3000);
            return false;
        }
    }
    if(loginExist(login))
    {
        return false;
    }
    return true;
}


int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return userFile.getLastId() + 1;
}


bool UserManager::isNewUserGood(User user)
{
    if(user.name == "0" || user.surname == "0" || user.login == "0" || user.password == "0")
    {
        return false;
    }
    return true;
}


void UserManager::signInUser()
{
    system("cls");
    User user;
    string triedLogin = "", triedPassword = "";

    cout << "Aby anulowac logowanie i wrocic do menu glownego wcisnij 0" << endl << endl;
    cout << endl << "Podaj login: ";
    triedLogin = Utils::loadLine();
    if (triedLogin == "0") {return;}

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> login == triedLogin)
        {
            for (int tries = 3; tries > 0; tries--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tries << ": ";
                triedPassword = Utils::loadLine();
                if (triedPassword == "0") {return;}

                if (itr -> password == triedPassword)
                {
                    loggedInUserId = itr -> userId;
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo. Nastapi przekierowanie do menu glownego." << endl;
            Sleep(3000);
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}


bool UserManager::isUserLoggedIn()
{
    if(loggedInUserId > 0)
    {
        return true;
    }
    return false;
}


void UserManager::signOutUser()
{
    loggedInUserId = 0;
}


void UserManager::changePasswordOfLoggedInUser()
{
    string newPassword = "";
    char confirmation;
    do
    {
        system("cls");
        cout << "Aby anulowac i wrocic do menu glownego wcisnij: 0" << endl;
        cout << "Haslo musi zawierac co najmniej 6 znakow w tym:" << endl;
        cout << "2 cyfry" << endl << "2 duze i male litery" << endl << "brak spacji" << endl << endl;
        cout << "Podaj haslo: " << endl;
        newPassword = Utils::loadLine();
        if(newPassword == "0") {return;}
    }
    while (!isPasswordGood(newPassword));

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].userId == loggedInUserId)
        {
            cout << "Czy na pewno chesz zmienic haslo?" << endl;
            cout << "Aby potwierdzic haslo wcisnij t lub T i potwierdz, aby wyjsc wybierz dowolny inny znak i potwierdz." << endl;
            confirmation = Utils::loadChar();
            if(confirmation == 't' || confirmation == 'T')
            {
                cout << "Pomyslnie zmieniono haslo. Nastapi powrot do menu uzytkownika." << endl;
                users[i].password = newPassword; Sleep(3000);
                userFile.changePasswortInFile(loggedInUserId, newPassword);
            }
            else
            {
                return;
            }
        }
    }
}
