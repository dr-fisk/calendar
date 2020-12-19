#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"

class Calendar
{
  Day *days;
  int size;
  int count;

  public:
    Calendar();
    ~Calendar();
    friend std::istream& operator>>(std::istream& is, Calendar &calendar);
    void resize();
    void dateSearch();
    void subjectSearch() const;
    void addAppointment();
    int findDay(int month, int day, int year);
    void getDate(int *month, int *day, int * year);
};


#endif
