#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H

#include <iostream>

class DOW {
        char monthName[10];
        int month;
        int day;
        int year;
        char dayName[10];
        public:
                DOW(int month, int day, int year);
                const bool operator==(const char c) const;
                friend std::ostream& operator<<(std::ostream &os, const DOW &dow);
                friend std::istream& operator>>(std::istream &is, DOW &dow);
};

#endif