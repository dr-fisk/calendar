#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#include "appt.h"

int Appointment::count = 0;

Appointment::Appointment() {
        subject = NULL;
        location = NULL;
}

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

int Appointment::getCount() {
        return count;
}

std::istream& operator>>(std::istream& is, Appointment &appt) {
        return appt.read(is);
}

std::istream& Appointment::read(std::istream& is) {
        char line[80];
        is.getline(line, 80, ',');
        subject = new char[strlen(line) + 1];
        strcpy(subject, line);
        is >> startTime;
        is >> endTime;
        is.getline(line, 80);
        location = new char[strlen(line) + 1];
        strcpy(location, line);
        count ++;
        return is;
}

const bool Appointment::operator<(const Appointment &rhs) const {
        return startTime < rhs.startTime;
}

const bool Appointment::operator==(const char *rhs) const {
        return strstr(subject, rhs) != NULL;
}

std::ostream& operator<<(std::ostream& os, const Appointment &appt) {
        os << appt.startTime << appt.endTime
           << std::left << std::setw(13) << appt.subject 
           << appt.location << std::right;
        return os;
}

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

Appointment::~Appointment() {
        if (subject)
                delete[] subject;
        
        if (location)
                delete[] location;
}
