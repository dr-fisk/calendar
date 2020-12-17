#ifndef TIME_H
#define TIME_H

class Time
{
  short hour;
  short minute;
  public:
    Time();
    ~Time();
    void read();
    void print();
    bool lessThan(Time *time);
    void getTime();
};


#endif
