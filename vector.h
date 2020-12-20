#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
        int size;
        int count;
        T *array;
        public:
                Vector<T>(int size);
                ~Vector<T>();
                const int getCount() const;
                const T& operator[](int index) const;
                T& operator[](int index);
                const int operator+=(const T &arr);
};

#include "vector.cpp"
#endif