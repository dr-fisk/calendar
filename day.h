#ifndef DAY_H
#define DAY_H

#include "linkedlist.h"
#include <iostream>

class Day {
        short day;
        short month;
        short year;
        List appt;
        public:
                Day();
                Day(int month, int day, int year);
                void subjectSearch(const char *subject) const;
                void addAppointment();
                friend std::ostream& operator<<(std::ostream& os, const Day &day);
                friend std::istream& operator>>(std::istream& is, Day &day);
                const bool operator<(const Day &rhs) const;
                const bool operator==(const Day &rhs) const;
                Day& operator=(const Day &rhs);
};


#endif
