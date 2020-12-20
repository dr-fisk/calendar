#include "dayofweek.h"

#include <iomanip>
#include <cstring>

DOW::DOW(int month, int day, int year) : month(month), day(day), year(year) {
}

const bool DOW::operator==(const char c) const {
        switch(c) {
        case 'M':
                return strcmp(dayName, "Monday")    == 0;
        case 'T':
                return strcmp(dayName, "Tuesday")   == 0;
        case 'W':
                return strcmp(dayName, "Wednesday") == 0;
        case 'R':
                return strcmp(dayName, "Thursday")  == 0;
        case 'F':
                return strcmp(dayName, "Friday")    == 0;
        case 'S':
                return strcmp(dayName, "Saturday")  == 0;
        case 'U':
                return strcmp(dayName, "Sunday")    == 0;
        }

        return false;
}

// Month * Day objects per year in DOW.dat
std::istream& operator>>(std::istream &is, DOW &dow) {
        int dateNumber = (dow.month - 1) * 31 + dow.day - 1 + (dow.year - 1990) * 372;
        is.seekg(dateNumber * sizeof(DOW));
        is.read(dow.monthName, 10);
        is.seekg(dateNumber * sizeof(DOW) + 24);
        is.read(dow.dayName, 10);
        return is;
}

std::ostream& operator<<(std::ostream &os, const DOW &dow)  {
        char dayStr[3], yearStr[5], line[80];
        strcpy(line, dow.dayName);
        strcat(line, ", ");
        strcat(line, dow.monthName);
        strcat(line, " ");

          if(dow.day > 9) {
                dayStr[0] = dow.day / 10 + '0';
                dayStr[1] = dow.day % 10 + '0';
                dayStr[2] = '\0';
        }
        else {
                dayStr[0] = dow.day + '0';
                dayStr[1] = '\0';
        }

        strcat(line, dayStr);
        strcat(line, ", ");
        yearStr[0] = dow.year / 1000 + '0';
        yearStr[1] = dow.year % 1000 / 100 + '0';
        yearStr[2] = dow.year % 1000 % 100 / 10 + '0';
        yearStr[3] = dow.year % 1000 % 100 % 10 + '0';
        strcat(line, yearStr);
        os << std::left << std::setw(30) << line << std::right;
        return os;
}