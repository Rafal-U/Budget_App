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
    static bool isIntegerDateGood(int dateValue);
    static bool isSingleDateGood(Date singleDate);
    static bool isTimePeriodGood(int startDate, int endDate);

public:
    static Date getCurrentLokalDateFromSystem();
    static int loadDate();
    static int convertStructDateToIntegerDate(Date date);
    static bool findSelectedTimePeriodDates(int fromDate, int toDate, int checkDate);
    static bool findLastMonthDates(int checkDate);
    static bool findThisMonthDates(int checkDate);
    static string convertIntegerDateToStringLine(int dateValue);
};

#endif
