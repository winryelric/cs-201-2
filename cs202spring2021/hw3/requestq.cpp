/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Source file for RequestQ
 */
#include "requestq.h"

RequestQ::RequestQ() = default;

RequestQ::~RequestQ() = default;

RequestQ::RequestQ(const RequestQ &rq) {
    requestQ = rq.requestQ;
}

/**
 * This will be used in simulator
 * @param maxSize
 */
RequestQ::RequestQ(const int &maxSize) {
    requestQ = MyArray<PrintRequest>(maxSize);
}

bool RequestQ::isEmpty() const {
    return requestQ.getSize() == 0;
}

int RequestQ::curRequests() const {
    return requestQ.getSize();
}

void RequestQ::enqueue(const PrintRequest &newRq) {
    // add new item
    requestQ.add(newRq);
    // trickle up
    int newIndex = requestQ.getSize() - 1;
    while (requestQ.at(newIndex) > requestQ.at( (newIndex - 1) / 2)) {
        // swap with parent until there is no heap violation
        PrintRequest tmp = requestQ.at( (newIndex - 1) / 2); // tmp is parent
        requestQ.at( (newIndex - 1) / 2) = requestQ.at(newIndex);
        requestQ.at(newIndex) = tmp;
        // update the item's position
        newIndex = (newIndex - 1) / 2;
    }
}

PrintRequest RequestQ::dequeue() {
    PrintRequest pop;
    if (requestQ.removeFirst(pop))
        heapRebuild(0);
    return pop;
}

void RequestQ::heapRebuild(const int &parent) {
    int largerChild = 2 * parent + 1;
    if (largerChild < curRequests() ) { // if the left child exists there might be heap violation
        bool rightExists = largerChild + 1 < curRequests();
        bool rightLarger = requestQ.at(largerChild + 1).getPrio() > requestQ.at(largerChild).getPrio();
        if (rightExists && rightLarger)
            largerChild++;
        bool violation = requestQ.at(largerChild) > requestQ.at(parent);
        if (violation) {
            PrintRequest tmp = requestQ.at(largerChild);
            requestQ.at(largerChild) = requestQ.at(parent);
            requestQ.at(parent) = tmp;
            heapRebuild(largerChild);
        }
    }
}

RequestQ &RequestQ::operator=(const RequestQ &rhs) {
    if (this != &rhs)
        this->requestQ = rhs.requestQ;
    return *this;
}

void RequestQ::display() const {
    cout << requestQ << endl;
}

