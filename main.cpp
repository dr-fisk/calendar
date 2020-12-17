#include <iostream>
#include "calendar.h"
#include "appt.h"

int getChoice() {
        int choice;
        char line[80];
        std::cout << "0. Done\n";
        std::cout << "1. Search for date.\n";
        std::cout << "2. Search for subject.\n";
        std::cout << "3. Add an appointment.\n";
        std::cout << "4. Print appointment count\n\n";
        std::cout << "Your choice >> "; 
        std::cin >> choice;
        std::cin.getline(line, 80);
        return choice;
}

int main(int argv, char **argc) {
        int choice;
        Calendar *calendar;
        calendar = new Calendar();
        calendar->readFile();

        while (true) {
                choice = getChoice();

                switch (choice) {
                case 0:
                        return 0;
                case 1:
                        calendar->dateSearch();
                        break;
                case 2:
                        calendar->subjectSearch();
                        break;
                case 3:
                        calendar->addAppointment();
                        break;
                case 4:
                        std::cout << "Appointment count: " << Appointment::getCount() << '\n';
                        break;
                default:
                        std::cout << "Choice must be between 0 and 4. Please try again.\n" << std::endl;
                }
        }
}
