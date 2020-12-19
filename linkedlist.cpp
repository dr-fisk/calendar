#include "linkedlist.h"

Node::Node(Node *next, Appointment *data) : next(next), data(data) {
}

Node::~Node() {
        if (data)
                delete data;
}

List::List() : head(NULL) {
}

const Appointment* List::find(const char *subject) const {
        static Node *current = NULL;

        if (!current)
                current = head;
        else
                current = current->next;

        for (; current; current = current->next)
                if (*current->data == subject)
                        return current->data;

        return NULL;
}

List& List::operator=(const List &list) {
        if (this == &list)
                return *this;

        Node *tail = NULL;

        for (Node *current = head; current; current = head) {
                head = current->next;
                delete current;
        }

        for (Node *current = list.head; current; current = current->next) {
                if (tail)
                        tail = tail->next = new Node(NULL, new Appointment(*current->data));
                else
                        tail = head = new Node(NULL, new Appointment(*current->data));
        }

        return *this;
}

const Appointment* List::operator[](int index) const {
        int i;
        Node *current = NULL;

        for (i = 0, current = head; i < index && current; i++, current = current->next);

        if (i == index && current)
                return current->data;

        return NULL;
}

Appointment*& List::operator[](int index) {
        int i;
        Node *current = NULL, *tail = NULL;

        for (i = 0, current = head; i < index && current; i++, current = current->next)
                tail = current;

        if (!current) {
                if (tail)
                        tail = tail->next = new Node(NULL, NULL);
                else
                        tail = head = new Node(NULL, NULL);

                return tail->data;
        }

        return current->data;
}

List& List::operator+=(Appointment *appt) {
        Node *current = NULL, *prev = NULL;
        
        for (current = head; current && *current->data < *appt; current = current->next)
                prev = current;

        if (prev)
                prev->next = new Node(current, appt);
        else
                head = new Node(current, appt);

        return *this;
}

std::ostream& operator<<(std::ostream& os, const List &list) {
        for (Node *current = list.head; current; current = current->next)
                os << *current->data << '\n';

        return os;
}

List::~List() {
        for (Node *current = head; current; current = head) {
                head = current->next;
                delete current;
        }
}