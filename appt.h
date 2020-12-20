#ifndef APPT_H
#define APPT_H

#include "time.h"
#include <iostream>

class Appointment
{
        Time startTime;
        Time endTime;
        char *subject;
        char *location;
        static int count;
        public:
                Appointment();
                virtual ~Appointment();
                Appointment(const Appointment &copy);
                void addAppointment();
                static int getCount();
                void incrementCount(const int num);
                virtual Appointment* clone() const;
                virtual std::istream& read(std::istream &is);
                virtual std::ostream& write(std::ostream &os) const;
                friend std::ostream& operator<<(std::ostream &os, const Appointment &appt);
                friend std::istream& operator>>(std::istream &is, Appointment &appt);
                const bool operator==(const char *rhs) const;
                const bool operator<(const Appointment &rhs) const;
};

#endif
