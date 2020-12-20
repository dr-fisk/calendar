#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "appt.h"
#include <iostream>

template <typename T> class List;

template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &list);


template <typename T>
class Node {
        Node<T> *next;
        T data;
        friend List<T>;
        friend std::ostream& operator<< <T> (std::ostream &os, const List<T> &list);
        Node<T>(Node<T> *next, T data);
        ~Node<T>();
};

template <typename T>
class List {
        Node<T> *head;
        public: 
                List<T>();
                ~List<T>();
                const T find(const char *subject) const;
                List<T>& operator=(const List<T> &list);
                List<T>& operator+=(T appt);
                const T operator[](int index) const;
                friend std::ostream& operator<< <T> (std::ostream &os, const List<T> &list);
};

#include "linkedlist.cpp"

#endif