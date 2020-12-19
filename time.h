#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
  short hour;
  short minute;
  public:
    Time();
    ~Time();
    friend std::ostream& operator<<(std::ostream& os, const Time &time);
    friend std::istream& operator>>(std::istream& is, Time &time);
    const bool operator<(const Time &time) const;
    void getTime();
};


#endif
