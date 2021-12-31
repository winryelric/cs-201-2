/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Header file for MyArray<T> class template
 */
#ifndef CODE_MYARRAY_H
#define CODE_MYARRAY_H
#include <iostream>
using namespace std;
template<typename T>
class MyArray{
    friend ostream& operator<<(ostream &out, const MyArray<T>&myArray) {
        for (int i = 0 ; i < myArray.size; i++)
            out << myArray.items[i] << endl;
        return out;
    }
public:
    MyArray();
    ~MyArray();
    MyArray(const MyArray<T>&);
    MyArray(const int&);
    int getSize() const;
    T& at(const int&) const;
    bool add(const T &newT);
    bool remove(const T &);
    bool removeFirst(T &);
    int indexOf(const T&) const;
    MyArray<T>& operator=(const MyArray<T>&);
private:
    T* items;
    int size;
    int MAX_SIZE;
    void copy(MyArray<T>& target) const;
};

#endif
