#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "time.h"

// Default constructor
Time::Time() {
}

// Parses line to contsruct a new time object
std::istream& operator>>(std::istream& is, Time &time) {
        char line[15];
        is.getline(line, 3, ':');
        time.hour = atoi(line);
        is.getline(line, 3, ':');
        time.minute = atoi(line);
        is.getline(line, 6, ',');

        if (time.hour == 12 && strchr(line, 'A'))
                time.hour = 0;

        if (strchr(line, 'P') && time.hour < 12)
                time.hour += 12;

        return is;
}

// Prints out the contents of time object
std::ostream& operator<<(std::ostream& os, const Time &time) {
        os << std::setw(2) << std::setfill('0') << time.hour << ":"
           << std::setw(2) << time.minute << ' ' << std::setfill(' ');
        return os;
}

// Returns true if hour is less than rhs time object
const bool Time::operator<(const Time &rhs) const {
        return hour < rhs.hour || 
                (hour == rhs.hour && minute < rhs.minute);
}

// Gets user input to construct time object
void Time::getTime() {
        char colon;
        std::cin >> hour >> colon >> minute;

        while (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
                std::cout << "Please try again (hh:mm) >> ";
                std::cin >> hour >> colon >> minute;

                if(hour < 0 || hour > 23)
                        std::cout << "Hour must be between 0 and 23.\n";

                if(minute < 0 || minute > 59)
                        std::cout << "Minute must be between 0 and 59.\n";
        }

}

// Destructor
Time::~Time() {
}
