/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Source file for MyArray<T> class template
 */
#include "myarray.h"

template<typename T>
MyArray<T>::MyArray() {
    MAX_SIZE = 10;
    items = new T[MAX_SIZE];
    size = 0;
}

template<typename T>
MyArray<T>::~MyArray() {
    delete [] items;
    items = nullptr;
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T> &copyArr) {
    this->items = nullptr;
    this->size = 0;
    MAX_SIZE = 0;
    copyArr.copy(*this);
}

/**
 * Initialize an empty array with given maximum size
 * @tparam T
 * @param maxSize
 */
template<typename T>
MyArray<T>::MyArray(const int &maxSize) {
    MAX_SIZE = maxSize;
    items = new T[MAX_SIZE];
    size = 0;
}

template<typename T>
int MyArray<T>::getSize() const{
    return size;
}

template<typename T>
T &MyArray<T>::at(const int &i) const {
    return items[i];
}

template<typename T>
bool MyArray<T>::add(const T &newT) {
    if (size < MAX_SIZE) {
        items[size] = newT;
        size++;
        return true;
    }
    return false; // don't allow insertion if the maximum size is reached, for now
}

template<typename T>
bool MyArray<T>::remove(const T &del) {
    int delIndex = indexOf(del);
    if (delIndex != -1) {
        for (int i = delIndex; i < size - 1; i++)
            items[i] = items[i + 1];
        size--;
        return true;
    }
    return false;
}

/**
 * Remove the first item from the array in O(1) time
 * Don't preserve the order
 * @tparam T
 * @return
 */
template<typename T>
bool MyArray<T>::removeFirst(T &first) {
    if (size > 0) {
        first = items[0];
        items[0] = items[size-1]; // for size = 1, we assume that T prevents self assignment
        size--;
        return true;
    }
    else
        return false;
}

template<typename T>
int MyArray<T>::indexOf(const T &item) const {
    for (int i = 0; i < size; i++) {
        if (items[i] == item)
            return i;
    }
    return -1;
}

template<typename T>
void MyArray<T>::copy(MyArray<T> &target) const {
    if (target.items != nullptr)
        delete [] target.items;
    target.MAX_SIZE = MAX_SIZE;
    target.items = new T[MAX_SIZE];
    target.size = size;
    for (int i = 0; i < size; i++)
        target.items[i] = items[i];
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &rhs) {
    if (this != &rhs)
        rhs.copy(*this);
    return *this;
}

