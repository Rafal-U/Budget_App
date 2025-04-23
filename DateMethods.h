#ifndef DATEMETHODS_H
#define DATEMETHODS_H
#include <iostream>
#include <windows.h>
#include "Utils.h"
#include "Date.h"
using namespace std;

class DateMethods
{
    static int getDaysInAMonth(int month, int year);
    static int convertStringDateToIntegerLine(string dateLine);
    static bool isLeapYear(int year);
    static bool isDateFormatGood(string dateLine);
    static bool isSingleDateGood(Date singleDate);

public:
    static bool findSelectedTimePeriodDates(int fromDate, int toDate, int checkDate);
    static bool isIntegerDateGood(int dateValue);
    static Date getCurrentLokalDateFromSystem();
    static int loadDate();
    static int convertStructDateToIntegerDate(Date date);
    static int getPreviousMonthLastDate();
    static int getPreviousMonthFirstDayDate();
    static int getCurrentMonthFirstDate();
    static string convertIntegerDateToStringLine(int dateValue);
};

#endif
