#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "time.h"

Time::Time() {
}

void Time::read() {
        char *ptr;
        hour = atoi(strtok(NULL, ":"));
        minute = atoi(strtok(NULL, ":"));
        ptr = strtok(NULL, ",");

        if (strchr(ptr, 'P') && hour != 12)
                hour += 12;
        else
                if (strchr(ptr, 'A') && hour == 12)
                        hour = 0;
}

void Time::print() {
  std::cout << std::right << std::setw(2) << std::setfill('0') << hour << ":"
  << std::right << std::setw(2) << std::setfill('0') << minute << ' ';
}

bool Time::lessThan(Time *time) {
        return hour < time->hour || 
                (hour == time->hour && minute < time->minute);
}

void Time::getTime() {
        char userInput[80], *token;
        std::cin.getline(userInput, 80);
        token = strtok(userInput, ":");
        hour = atoi(token);
        token = strtok(NULL, ":");
        minute = atoi(token);
}

Time::~Time() {
}
