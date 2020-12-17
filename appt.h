#ifndef APPT_H
#define APPT_H

#include "time.h"

class Appointment
{
        Time startTime;
        Time endTime;
        char *subject;
        char *location;
        static int count;
        public:
                Appointment();
                Appointment(const Appointment &copy);
                ~Appointment();
                static int getCount();
                void read();
                void print();
                bool equal(const char *subject2) const;
                bool lessThan(Appointment *appt);
                void addAppointment();
};

#endif
