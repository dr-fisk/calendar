#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#include "appt.h"

// Number of appointments in calendar
int Appointment::count = 0;

// Default constructor
Appointment::Appointment() {
        subject = NULL;
        location = NULL;
}

// Copy constructor for appointment object
Appointment::Appointment(const Appointment &copy) 
        : startTime(copy.startTime), endTime(copy.endTime),
          subject(NULL), location(NULL){
        if (copy.location) {
                location = new char[strlen(copy.location) + 1];
                strcpy(location, copy.location);
        }

        if (copy.subject) {
                subject = new char[strlen(copy.subject) + 1];
                strcpy(subject, copy.subject);
        }
}

// Returns the number of appointments in calendar
int Appointment::getCount() {
        return count;
}

// Adds a new appointment from user
void Appointment::addAppointment() {
        char userInput[80];
        std::cout << "Subject >> ";
        std::cin.getline(userInput, 80);
        subject = new char[strlen(userInput) + 1];
        strcpy(subject, userInput);
        std::cout << "Location >> ";
        std::cin.getline(userInput, 80);
        location = new char[strlen(userInput) + 1];
        strcpy(location, userInput);
        std::cout << "Start time (hh:mm) >> ";
        startTime.getTime();
        std::cout << "End time (hh:mm) >> ";
        endTime.getTime();
        count ++;
}

// Returns a deep copy of appointment object
Appointment* Appointment::clone() const {
        return new Appointment(*this);
}

// Parses line and constructs appointment object 
std::istream& operator>>(std::istream &is, Appointment &appt) {
        return appt.read(is);
}

// Prints out the contents of an appointment
std::ostream& operator<<(std::ostream &os, const Appointment &appt) {
        return appt.write(os);
}

// Parses line and constructs appointment object 
std::istream& Appointment::read(std::istream &is) {
        char line[80];
        is.getline(line, 80, ',');
        subject = new char[strlen(line) + 1];
        strcpy(subject, line);
        is >> startTime;
        is >> endTime;
        is.getline(line, 80, ',');
        location = new char[strlen(line) + 1];
        strcpy(location, line);
        count ++;
        return is;
}

// Prints out the contents of an appointment
std::ostream& Appointment::write(std::ostream &os) const {
        os << startTime << endTime
           << std::left << std::setw(13) << subject << std::setw(26)
           << location << std::right;
           return os;
}

void Appointment::incrementCount(const int num) {
        count += num;
}

// Returns true if start time for an appointment is less than the rhs appointment
const bool Appointment::operator<(const Appointment &rhs) const {
        return startTime < rhs.startTime;
}

// Returns true if the subjects of the appointments are equivalent
const bool Appointment::operator==(const char *rhs) const {
        return strstr(subject, rhs) != NULL;
}

// Deallocates memory from appointments
Appointment::~Appointment() {
        if (subject)
                delete[] subject;
        
        if (location)
                delete[] location;
}
