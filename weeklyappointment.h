#ifndef WEEKLYAPPOINTMENT_H
#define WEEKLYAPPOINTMENT_H

#include "appt.h"

class Weekly : public Appointment {
        char series[8];
        int seriesCount;
        public:
                Weekly();
                Weekly(const Weekly &rhs);
                const int getCount() const ;
                const char* getSeries() const;
                virtual ~Weekly();
                virtual std::istream& read(std::istream &is);
                virtual std::ostream& write(std::ostream &os) const;
                virtual Appointment* clone() const;
};

#endif