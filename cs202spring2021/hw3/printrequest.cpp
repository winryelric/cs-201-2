/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Source file for PrintRequest
 */
#include "printrequest.h"

PrintRequest::PrintRequest() = default;

PrintRequest::PrintRequest(const PrintRequest & pr) {
    id = pr.id;
    priority = pr.priority;
    requestTime = pr.requestTime;
    processTime = pr.processTime;
}

PrintRequest::PrintRequest(const int &id, const int &priority, const int &requestTime, const int &processTime) {
    this->id = id;
    this->priority = priority;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

int PrintRequest::getId() const {
    return id;
}

int PrintRequest::getPrio() const {
    return priority;
}

int PrintRequest::getReqTime() const {
    return requestTime;
}

int PrintRequest::getProcTime() const {
    return processTime;
}

PrintRequest &PrintRequest::operator=(const PrintRequest &rhs) {
    if (this != &rhs) {
        this->id = rhs.id;
        this->priority = rhs.priority;
        this->requestTime = rhs.requestTime;
        this->processTime = rhs.processTime;
    }
    return *this;
}

ostream &operator<<(ostream &out, const PrintRequest &pr) {
    return out << "print request " << pr.id << " - prio : " << pr.priority
    << " - rq time : " << pr.requestTime << " - proc time: " << pr.processTime;
}

bool PrintRequest::operator==(const PrintRequest &rhs) const {
    // check the priority first, then check their request time
    // if they are equal, the entries are considered to be equal
    return priority == rhs.priority && requestTime == rhs.requestTime;
}

bool PrintRequest::operator<=(const PrintRequest &rhs) const {
    // check the priority first, then check their request time
    // if they are less than or equal, the entries are considered to be less than or equal
    return !(*this > rhs);
}

bool PrintRequest::operator>=(const PrintRequest &rhs) const {
    // check the priority first, then check their request time
    // if they are greater than or equal, the entries are considered to be greater than or equal
    return !(*this < rhs);
}

bool PrintRequest::operator<(const PrintRequest &rhs) const {
    // check the priority first, then check their request time
    // if they are greater than or equal, the entries are considered to be greater than or equal
    return priority < rhs.priority || priority == rhs.priority && requestTime > rhs.requestTime;
}

bool PrintRequest::operator>(const PrintRequest &rhs) const {
    // check the priority first, then check their request time
    // if they are greater than or equal, the entries are considered to be greater than or equal
    return priority > rhs.priority || priority == rhs.priority && requestTime < rhs.requestTime;
}
