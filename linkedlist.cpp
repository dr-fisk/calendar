#include "linkedlist.h"

// Constructs the node of a list
template <typename T>
Node<T>::Node(Node<T> *next, T data) : next(next), data(data) {
}

// Dellocates memory from node object
template <typename T>
Node<T>::~Node() {
        if (data)
                delete data;
}

// Default constructor for list
template <typename T>
List<T>::List() : head(NULL) {
}

// Finds the appointments in linked list that matches the subject
template <typename T>
const T List<T>::find(const char *subject) const {
        static Node<T> *current = NULL;

        if (!current)
                current = head;
        else
                current = current->next;

        for (; current; current = current->next)
                if (*current->data == subject)
                        return current->data;

        return NULL;
}

// Assigns new list to old list, but dellocates all nodes of old list first
template <typename T>
List<T>& List<T>::operator=(const List<T> &list) {
        if (this == &list)
                return *this;

        Node<T> *tail = NULL;

        for (Node<T> *current = head; current; current = head) {
                head = current->next;
                delete current;
        }

        for (Node<T> *current = list.head; current; current = current->next) {
                if (tail)
                        tail = tail->next = new Node<T>(NULL, current->data->clone());
                else
                        tail = head = new Node<T>(NULL, current->data->clone());
        }

        return *this;
}

// Returns the value at the given index of linked list
template <typename T>
const T List<T>::operator[](int index) const {
        int i;
        Node<T> *current = NULL;

        for (i = 0, current = head; i < index && current; i++, current = current->next);

        if (i == index && current)
                return current->data;

        return NULL;
}

// Adds a new node to the list
template <typename T>
List<T>& List<T>::operator+=(T appt) {
        Node<T> *current = NULL, *prev = NULL;
        for (current = head; current && *current->data < *appt; current = current->next)
                prev = current;

        if (prev)
                prev->next = new Node<T>(current, appt);
        else
                head = new Node<T>(current, appt);

        return *this;
}

// Prints out the contents of the linked list
template <typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &list) {
        for (Node<T> *current = list.head; current; current = current->next)
                os << *current->data << '\n';

        return os;
}

// Dellocates memory used by the nodes of a list
template <typename T>
List<T>::~List() {
        for (Node<T> *current = head; current; current = head) {
                head = current->next;
                delete current;
        }
}