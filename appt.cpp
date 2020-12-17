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
        : startTime(copy.startTime), endTime(copy.endTime) {
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

void Appointment::read() {
        char *ptr;
        ptr = strtok(NULL, ",");
        subject = new char[strlen(ptr) + 1];
        strcpy(subject, ptr);
        startTime.read();
        endTime.read();
        ptr = strtok(NULL, "\n");
        location = new char[strlen(ptr) + 1];
        strcpy(location, ptr);
        count ++;
}

bool Appointment::lessThan(Appointment *appt) {
        return startTime.lessThan(&appt->startTime);
}

bool Appointment::equal(const char *subject2) const {
        return strstr(subject, subject2) != NULL;
}

void Appointment::print() {
        startTime.print();
        endTime.print();
        std::cout << std::left << std::setw(13) << std::setfill(' ') << subject 
        << location << std::endl;
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
        delete[] subject; 
        delete[] location;
}
