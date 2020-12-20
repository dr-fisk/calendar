#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#include "day.h"
#include "dayofweek.h"

// Default constructor
Day::Day() {
}

// Construct a new day for the calendar with given parameters
Day::Day(int month, int day, int year): day(day), month(month), year(year) {
}

// Returns true if days are equivalent
const bool Day::operator==(const Day &rhs) const {
        if(day == rhs.day && month == rhs.month && year == rhs.year)
                return true;

        return false;
}

// Return true if day is of an earlier date to the rhs day
const bool Day::operator<(const Day &rhs)  const {
        if (year < rhs.year || (year == rhs.year && month < rhs.month)
                || (year == rhs.year && month == rhs.month && day < rhs.day))
                return true;

        return false;
}

// Sets a day to the value of the rhs day by simple callind Day1 = Day2
Day& Day::operator=(const Day& rhs) {
        if (this == &rhs)
                return *this;

        month = rhs.month;
        day   = rhs.day;
        year  = rhs.year;
        appt = rhs.appt;
        return *this;
}

// Adds a new weekly appointment to the linked list
Day& Day::operator+=(const Weekly &weekly) {
        appt += new Weekly(weekly);
        return *this;
}

// Returns an appointment* for checking if the appointment is a weekly appointment
// Parses lines to construct an Appointment
const Appointment* operator>>(std::istream &is, Day &day) {
        char line[80];
        Appointment *appts;
        is.getline(line, 80, ',');
        
        if (atoi(line) == 1) {
                appts = new Weekly;
                is >> *appts;
        } else {
                appts = new Appointment;
                is >> *appts;
                is.getline(line, 80);
        }

        day.appt += appts;
        return appts;
}

// Prints the contents of a day
std::ostream& operator<<(std::ostream &os, const Day &day) {
        os << "Start End   Subject      Location\n";
        os << day.appt << '\n';
        return os;
}

// Searches appointments to find a match with the given subject if found
// Print out the contents of the appointment
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

// Adds an appointment to the linked list
void Day::addAppointment() {
        Appointment *newAppointment = new Appointment;
        newAppointment->addAppointment();
        appt += newAppointment;
}
