#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "day.h"

Day::Day() {

}

Day::Day(int month, int day, int year): day(day), month(month), year(year), apptCount(0) {
}

bool Day::equal(Day days) {
        if(day == days.day && month == days.month && year == days.year)
                return true;

        return false;
}

bool Day::lessThan(Day days) {
        if (year < days.year || (year == days.year && month < days.month) 
                || (year == days.year && month == days.month && day < days.day))
                return true;

        return false;
}

void Day::read() {
        Appointment *appts = new Appointment;
        appts->read();
        insertAppointment(appts);
}

void Day::insertAppointment(Appointment *appts) {
        int pos = 0;
  
        for (pos = apptCount - 1; pos >= 0 
                && appts->lessThan(appt[pos]); pos--)
                appt[pos + 1] = appt[pos]; 

        appt[pos + 1] = appts;
        apptCount ++;
}

void Day::print() {
        std::cout << "Start End   Subject      Location\n";

        for (int i = 0; i < apptCount; i++)
                appt[i]->print();

        std::cout << std::endl;
}

void Day::subjectSearch(const char *subject) const {
        for (int i = 0; i < apptCount; i++)
                if (appt[i]->equal(subject)) {
                        DOW dow;
                        dow.read(month, day, year);
                        dow.print();
                        appt[i]->print();
                }
}

void Day::addAppointment() {
        Appointment *newAppointment = new Appointment;
        newAppointment->addAppointment();
        insertAppointment(newAppointment);
}

Day& Day::operator=(const Day& rhs) {
        if (this == &rhs)
                return *this;
 
        month = rhs.month;
        day   = rhs.day;
        year  = rhs.year;
        apptCount = rhs.apptCount;

        for (int i = 0; i < rhs.apptCount; i ++) {
                appt[i]  = rhs.appt[i];
        }

        return *this;
}

Day::~Day() {
}
