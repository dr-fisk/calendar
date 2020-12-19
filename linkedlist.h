#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "appt.h"
#include <iostream>

class List;

class Node {
        Node *next;
        Appointment *data;
        friend List;
        friend std::ostream& operator<<(std::ostream& os, const List &list);
        Node(Node *next, Appointment *data);
        ~Node();
};

class List {
        Node *head;
        public: 
                List();
                ~List();
                const Appointment* find(const char *subject) const;
                List& operator=(const List &list);
                List& operator+=(Appointment* appt);
                const Appointment* operator[](int index) const;
                Appointment*& operator[](int index);
                friend std::ostream& operator<<(std::ostream& os, const List &list);
};

#endif