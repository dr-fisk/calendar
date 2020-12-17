#ifndef DAY_H
#define DAY_H

#include "appt.h"
#include "dayofweek.h"

class Day {
        short day;
        short month;
        short year;
        short apptCount;
        Appointment *appt[8];
        public:
                Day();
                Day(int month, int day, int year);
                bool equal(Day days);
                bool lessThan(Day days);
                void read();
                void subjectSearch(const char *subject) const;
                void print();
                void addAppointment();
                void insertAppointment(Appointment *appts);
                Day& operator=(const Day &rhs);
                ~Day();
};


#endif
