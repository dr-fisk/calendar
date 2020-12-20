#include "weeklyappointment.h"

#include <cstring>
#include <iomanip>

// Default constructor
Weekly::Weekly() {
}

// Copy constructor for Weekly object
Weekly::Weekly(const Weekly &rhs) : Appointment(rhs), seriesCount(rhs.seriesCount) {
        if (rhs.series)
                strcpy(series, rhs.series);
}

// Returns the number of appointments in the series of appointments
const int Weekly::getCount() const {
        return seriesCount;
}

// Returns the days that the series of appointments occurs on
const char* Weekly::getSeries() const {
        return series;
}

// Returns a deep copy of a weekly object
Appointment* Weekly::clone() const {
        return new Weekly(*this);
}

// Parses line to construct a weekly object
std::istream& Weekly::read(std::istream &is) {
        char line[80];
        Appointment::read(is);
        is.getline(line, 80, ',');
        strcpy(series, line);
        is.getline(line, 80);
        seriesCount = atoi(line);

        // Counts the regular appointment twice so subtract 1
        Appointment::incrementCount(seriesCount - 1);
        return is;
}

// Prints out the contents of the Weekly appointment
std::ostream& Weekly::write(std::ostream &os) const {
        Appointment::write(os);
        os << std::left << std::setw(8) << series << '(' << seriesCount << ')';
        return os;
}

// Destructor
Weekly::~Weekly() {
}
