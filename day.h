#ifndef DAY_H
#define DAY_H

#include "linkedlist.h"
#include "weeklyappointment.h"
#include <iostream>

class Day {
        short day;
        short month;
        short year;
        List<Appointment *> appt;
        public:
                Day();
                Day(int month, int day, int year);
                void subjectSearch(const char *subject) const;
                void addAppointment();
                friend std::ostream& operator<<(std::ostream& os, const Day &day);
                friend const Appointment* operator>>(std::istream& is, Day &day);
                const bool operator<(const Day &rhs) const;
                const bool operator==(const Day &rhs) const;
                Day& operator+=(const Weekly &weekly);
                Day& operator=(const Day &rhs);
};


#endif
