#include "DateMethods.h"

int DateMethods::convertStringDateToIntegerLine(string dateLine)
{
    int value = 0;
    int characterPosition = 0;
    string number = "";
    while(characterPosition < dateLine.length())
    {
        if(isdigit(dateLine[characterPosition]))
        {
            number += dateLine[characterPosition];
        }
        characterPosition++;
    }
    value = atoi(number.c_str());
    return value;
}


bool DateMethods::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}


int DateMethods::getDaysInAMonth(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11) {return 30;}
	if (month == 2) {return isLeapYear(year) ? 29 : 28;}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {return 31;}
	if (month < 1 || month > 12) {throw invalid_argument("Invalid month");}
}


bool DateMethods::isSingleDateGood(Date singleDate)
{
    if(singleDate.year < 2000 || singleDate.year > getCurrentLokalDateFromSystem().year
       || singleDate.month > 12 || singleDate.month < 1
       || (singleDate.month > getCurrentLokalDateFromSystem().month && singleDate.year == getCurrentLokalDateFromSystem().year)
       || singleDate.day < 1 || singleDate.day > getDaysInAMonth(singleDate.month, singleDate.year))
    {
        return false;
    }
    return true;
}


bool DateMethods::isDateFormatGood(string dateLine)
{
    if(dateLine.length() != 10)
    {
        return false;
    }
    if(dateLine[4] != '-' || dateLine[7] != '-')
    {
        return false;
    }
    for(int i = 0; i < dateLine.length(); i++)
    {
        if(!isdigit(dateLine[i]) && i != 4 && i != 7)
        {
            return false;
        }
    }
    return true;
}


bool DateMethods::isIntegerDateGood(int dateValue)
{
    Date date;
    if(dateValue >= 10000000)
    {
        date.day = dateValue % 100;
        date.month = (dateValue / 100) % 100;
        date.year = dateValue / 10000;

        if(isSingleDateGood(date))
        {
            return true;
        }
    }
    return false;
}

bool DateMethods::findSelectedTimePeriodDates(int fromDate, int toDate, int checkDate)
{
    if(checkDate >= fromDate && checkDate <= toDate)
    {
        return true;
    }
    return false;
}


Date DateMethods::getCurrentLokalDateFromSystem()
{
    Date currentDate;
    SYSTEMTIME currentLocalDate;
	GetLocalTime(&currentLocalDate);
	currentDate.year = currentLocalDate.wYear;
	currentDate.month = currentLocalDate.wMonth;
	currentDate.day = currentLocalDate.wDay;
	return currentDate;
}


int DateMethods::getPreviousMonthLastDate()
{
    int lastDayOfMonthDate = 0;
    Date currentDate, lastMonthDate;
    currentDate = getCurrentLokalDateFromSystem();

    if(currentDate.month == 1)
    {
        lastMonthDate.year = currentDate.year - 1;
        lastMonthDate.month = 12;
        lastMonthDate.day = 31;
    }
    else
    {
        lastMonthDate.year = currentDate.year;
        lastMonthDate.month = currentDate.month - 1;
        lastMonthDate.day = getDaysInAMonth(lastMonthDate.month, lastMonthDate.year);
    }

    lastDayOfMonthDate = convertStructDateToIntegerDate(lastMonthDate);
    return lastDayOfMonthDate;
}

int DateMethods::getPreviousMonthFirstDayDate()
{
    int firstDayOfMonthDate = 0, lastDayOfMonthDate = 0;
    lastDayOfMonthDate = getPreviousMonthLastDate();
    firstDayOfMonthDate = lastDayOfMonthDate - (lastDayOfMonthDate % 100) + 1;
    return firstDayOfMonthDate;
}


int DateMethods::getCurrentMonthFirstDate()
{
    int firstDayOfMonthDate = 0;
    Date currentDate;
    currentDate = getCurrentLokalDateFromSystem();
    currentDate.day = 1;
    firstDayOfMonthDate = DateMethods::convertStructDateToIntegerDate(currentDate);
    return firstDayOfMonthDate;
}


int DateMethods::convertStructDateToIntegerDate(Date date)
{
    int dateValue = 0;
    dateValue = (date.year * 10000) + (date.month * 100) + date.day;
    return dateValue;
}


int DateMethods::loadDate()
{
    int dateValue = 0;
    string dateDashLine = "";

    cout << "Wprowadz date w formacie RRRR-MM-DD" << endl;
    cout << "Aby anulowac wcisnij wprowadz 0 i potwierdz" << endl;
    while(true)
    {
        dateDashLine = Utils::loadLine();

        if(dateDashLine == "0")
        {
            return 0;
        }

        if(isDateFormatGood(dateDashLine))
        {
            dateValue = convertStringDateToIntegerLine(dateDashLine);
            if(isIntegerDateGood(dateValue))
            {
                return dateValue;
            }
            else
            {
                cout << "Podana data jest niepoprawna! Wpisz ponownie." << endl; system("pause");
            }
        }
        else
        {
            cout << "Zly format daty! Wpisz ponownie." << endl; system("pause");
        }
    }
}


string DateMethods::convertIntegerDateToStringLine(int dateValue)
{
    string date = "", formattedDate = "";
    date = Utils::convertIntegerToString(dateValue);
    formattedDate = date.substr(6, 2) + "." + date.substr(4, 2) + "." + date.substr(0, 4);
    return formattedDate;
}
