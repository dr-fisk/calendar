#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#include "day.h"
#include "dayofweek.h"

Day::Day() {
}

Day::Day(int month, int day, int year): day(day), month(month), year(year) {
}

const bool Day::operator==(const Day &rhs) const {
        if(day == rhs.day && month == rhs.month && year == rhs.year)
                return true;

        return false;
}

const bool Day::operator<(const Day &rhs)  const {
        if (year < rhs.year || (year == rhs.year && month < rhs.month)
                || (year == rhs.year && month == rhs.month && day < rhs.day))
                return true;

        return false;
}

std::istream& operator>>(std::istream& is, Day &day) {
        Appointment *appts = new Appointment;
        is >> *appts;
        day.appt += appts;
        return is;
}

std::ostream& operator<<(std::ostream& os, const Day &day) {
        os << "Start End   Subject      Location\n";
        os << day.appt << '\n';
        return os;
}

void Day::subjectSearch(const char *subject) const {
                const Appointment *appointment;

        while ((appointment = appt.find(subject))) {
                        std::ifstream fp("DOW.dat", std::ios::binary);
                        DOW dow(month, day, year);
                        fp >> dow;
                        std::cout << dow;
                        std::cout << *appointment;
                        std::cout << '\n';
                        fp.close();
        }
}

void Day::addAppointment() {
        Appointment *newAppointment = new Appointment;
        newAppointment->addAppointment();
        appt += newAppointment;
}

Day& Day::operator=(const Day& rhs) {
        if (this == &rhs)
                return *this;

        month = rhs.month;
        day   = rhs.day;
        year  = rhs.year;
        appt = rhs.appt;
        return *this;
}