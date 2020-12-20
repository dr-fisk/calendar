#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "calendar.h"

Calendar::Calendar() : days(30){
}

// Adds user created appointment to calendar
void Calendar::addAppointment() {
        int month, dia, year, pos;
        getDate(&month, &dia, &year);
        Day dayTemp(month, dia, year);
        pos = days += dayTemp;
        days[pos].addAppointment();
}

// Prompts user to enter a valid date to search
void Calendar::getDate(int *month, int *day, int *year) const {
        while (true) {
                char date[80], date2[80], *ptr;
                std::cout << "Please enter the month, day, and year (mm/dd/yyyy) >> ";

                if (!std::cin.getline(date, 80))
                        std::cout << " is not a valid date. \nPlease try again.\n\n";
                else {
                        strtok(date, "\n");
                        strcpy(date2, date);
                        ptr = strtok(date, "/");

                        if (ptr) {
                                *month = atoi(ptr);
                                ptr =  strtok(NULL, "/");

                                if (ptr) {
                                        *day = atoi(ptr);
                                        ptr = strtok(NULL, "\n");

                                        if (ptr)
                                                *year = atoi(ptr);
                                }
                        }
                }

        // Dates from 1000-2017 exist in DOW.dat since it is a little outdated
        if ((*day >= 1 && *day <= 31) && (*month >= 1 && *month <= 12) 
                && (*year >= 1000 && *year <= 2017))
                break;

        std::cout << date2 << " is not a valid date.\nPlease try again.\n";
        } 
}

// Prompts user to enter a specific subject to search in the calendar
void Calendar::subjectSearch() const {
        char subject[80];
        std::cout << "Please enter the subject >> ";
        fgets(subject, 80, stdin);

        if (subject > 0)
                subject[strlen(subject) - 1] = 0;

        std::cout << std::left << std::setw(30) << "Date" << std::right << "Start End   Subject      Location\n";

        for (int i = 0; i < days.getCount(); i++)
                days[i].subjectSearch(subject);

        std::cout << '\n';
}

// After user inputs date to find in calendar, find and print the appointments 
// On that date
void Calendar::dateSearch() const {
        int month = -1, day = -1, year = -1;
        getDate(&month, &day, &year);
        Day dayTemp = Day(month, day, year);

        for (int i = 0; i < days.getCount(); i++)
                if (dayTemp == days[i]) {
                        std::cout << days[i];
                        return;
                }
}

// Create all appointments necessary when it is a series of appointments with the same
// Time, subject, location
void Calendar::createSeries(const Weekly &weekly, int month, int day, int year) {
        std::ifstream fp("DOW.dat", std::ios::binary);

        for(int i = 1; i < weekly.getCount(); ) {
                if (++day > 31) {
                        day = 1;
                        
                        if (++month > 12) {
                                month = 1;
                                year ++;
                        }
                }

                DOW dow(month, day, year);
                fp >> dow;

                for (const char* ptr = weekly.getSeries(); *ptr; ptr++) {
                        if (dow == *ptr) {
                                Day dayTemp(month, day, year);
                                int pos = days += dayTemp;
                                days[pos] += weekly;
                                i ++;
                                break;
                        }
                }
        }

        fp.close();
}

// Read from appts.csv and parse lines to store into calendar
std::istream& operator>>(std::istream& is, Calendar &calendar) {
        int month, day, year, pos;
        char buffer[80]; 
        is.getline(buffer, 80);

        while (is.getline(buffer, 80, '/')) {
                month = atoi(buffer);
                is.getline(buffer, 80, '/');
                day = atoi(buffer);
                is.getline(buffer, 80, ',');
                year = atoi(buffer);
                Day dayTemp(month, day, year);
                pos = calendar.days += dayTemp;

                // Checks to see if the appointment is of the child class Weekly
                const Weekly *weekly = dynamic_cast<const Weekly*> (is >> calendar.days[pos]);

                // If so then create the series of appointments
                if (weekly)
                        calendar.createSeries(*weekly, month, day, year);
        }

        return is;
}
