#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"
#include "dayofweek.h"
#include "vector.h"

class Calendar {
        Vector <Day> days;
        public:
                Calendar();
                void createSeries(const Weekly &weekly, int month, int day, int year);
                void dateSearch() const;
                void subjectSearch() const;
                void addAppointment();
                void getDate(int *month, int *day, int * year) const;
                friend std::istream& operator>>(std::istream &is, Calendar &calendar);
};


#endif
