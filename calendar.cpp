#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#include "calendar.h"

Calendar::Calendar() : size(30), count(0) {
        days = new Day[30];
}

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
                pos = calendar.findDay(month, day, year);
                is >> calendar.days[pos];
        }

        return is;
}

int Calendar::findDay(int month, int day, int year) {
        int pos;
        Day dayTemp = Day(month, day, year); 

        for (pos =  0; pos < count && !(days[pos] == dayTemp); pos++);

        if (pos == count) {
                if(count == size)
                        resize();

                for (pos = count - 1; pos >= 0 && (dayTemp < days[pos]) ; pos--)
                        days[pos + 1] = days[pos];

                days[++pos] = dayTemp;
                count++;
        }

        return pos;
}

// Future update can possibly add invalid input detection
void Calendar::addAppointment() {
        int month, dia, year, pos;
        getDate(&month, &dia, &year);
        pos = findDay(month, dia, year);
        days[pos].addAppointment();
}

void Calendar::resize() {
        size = size * 2;
        Day *temp = new Day[size];

        for (int i = 0; i < count; i++)
                temp[i] = days[i];

        delete[] days;
        days = temp;
}

void Calendar::getDate(int *month, int *day, int *year)
{
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

        if ((*day >= 1 && *day <= 31) && (*month >= 1 && *month <= 12) 
                && (*year >= 1000 && *year <= 2017))
                break;

        std::cout << date2 << " is not a valid date.\nPlease try again.\n";
        } 
}

void Calendar::subjectSearch() const {
        char subject[80];
        std::cout << "Please enter the subject >> ";
        fgets(subject, 80, stdin);

        if (subject > 0)
                subject[strlen(subject) - 1] = 0;

        std::cout << std::left << std::setw(30) << "Date" << std::right << "Start End   Subject      Location\n";

        for (int i = 0; i < count; i++)
                days[i].subjectSearch(subject);

        std::cout << '\n';
}

void Calendar::dateSearch() {
        int month = -1, day = -1, year = -1;
        getDate(&month, &day, &year);
        Day dayTemp = Day(month, day, year);

        for (int i = 0; i < count; i++)
                if (dayTemp == days[i]) {
                        std::cout << days[i];
                        return;
                }
}

Calendar::~Calendar() {
        if (days)
                delete[] days;
}
