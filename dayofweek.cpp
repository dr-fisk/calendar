#include "dayofweek.h"

#include <iomanip>
#include <cstring>

DOW::DOW(int month, int day, int year) : month(month), day(day), year(year) {
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
        char dayStr[3], line[80];
        strcpy(line, dow.dayName);
        strcat(line, ", ");
        strcat(line, dow.monthName);
        strcat(line, " ");

          if(dow.day > 9) {
                dayStr[0] = dow.day / 10 + '0';
                dayStr[1] = dow.day % 10 + '0';
                dayStr[2] = '\0';
        } // if day > 9
        else {
                dayStr[0] = dow.day + '0';
                dayStr[1] = '\0';
        } // else day < 10

        strcat(line, dayStr);
        os << std::left << std::setw(30) << line << std::right;
        return os;
}