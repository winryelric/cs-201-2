/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Header file for RequestQ class
 *
 * A Heap Based Priority Queue (max heap) to keep track of
 * print requests
 */
#ifndef CODE_REQUESTQ_H
#define CODE_REQUESTQ_H
#include "printrequest.h"
#include "myarray.cpp"
#include <fstream>
class RequestQ {
public:
    RequestQ();
    ~RequestQ();
    RequestQ(const RequestQ&);
    RequestQ(const int&);
    bool isEmpty() const;
    int curRequests() const;
    void enqueue(const PrintRequest&);
    PrintRequest dequeue();
    void display() const;
    RequestQ& operator=(const RequestQ& rhs);
private:
    MyArray<PrintRequest> requestQ;

    void heapRebuild(const int&);
};
#endif
