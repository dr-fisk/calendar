#include "vector.h"

// This is a templated vector class specialized for the calendar program


// Construct a new vector with given size
template <typename T>
Vector<T>::Vector(int size) : size(size), count(0) {
        array = new T[size];
}

// Returns value at a given index, program is unable to change this value
template <typename T>
const T& Vector<T>::operator[](int index) const {
        return array[index];
}

// Returns value reference at a given index, program is able to change this value
template <typename T>
T& Vector<T>::operator[](int index) {
        return array[index];
}

// Adds item to the vector and resizes when necessary, no seg faults when adding!
template <typename T>
const int Vector<T>::operator+=(const T &arr) {
        int pos;

        // Checks to see if the item exists within vector
        for (pos =  0; pos < count && !(array[pos] == arr); pos++);

        // Only add item to vector if it doesn't exist, 
        if (pos == count) {
                // Resize if current vector is full
                if (count == size) {
                                size = size * 2;
                                T *temp = new T[size];

                                for (int i = 0; i < count; i++)
                                        temp[i] = array[i];

                                delete[] array;
                                array = temp;
                }

                // Reorder vector of days to go from earlier dates to later dates
                for (pos = count - 1; pos >= 0 && arr < array[pos]; pos--)
                        array[pos + 1] = array[pos];

                array[++pos] = arr;
                count ++;
        }

        return pos;
}

// Returns the number of items in the vector
template <typename T>
const int Vector<T>::getCount() const {
        return count;
}

// Deallocates memory of vector
template <typename T>
Vector<T>::~Vector() {
        if (array)
                delete array;
}