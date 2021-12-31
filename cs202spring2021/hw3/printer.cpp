/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Source file for Printer
 */
#include "printer.h"

Printer::Printer() {
    id = 1;
    timeLeft = 0;
}

Printer::Printer(const Printer &printer) {
    id = printer.id;
    timeLeft = printer.timeLeft;
}

Printer::Printer(const int &id, const int &timeLeft) {
    this->id = id;
    this->timeLeft = timeLeft;
}

int Printer::getId() const {
    return id;
}

bool Printer::isAvailable() const {
    return timeLeft == 0;
}

void Printer::assign(const int &processTime) {
    timeLeft = processTime;
}

void Printer::nextMinute() {
    if (timeLeft > 0)
        timeLeft--;
}

int Printer::getTimeLeft() const {
    return timeLeft;
}

Printer& Printer::operator=(const Printer &rhs) {
    if (this != &rhs){
        id = rhs.id;
        timeLeft = rhs.timeLeft;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Printer &printer) {
    return out << "Printer " << printer.id << " - available in: " << printer.timeLeft;
}

/**
 * Assuming every ID is distinct
 * Equals operator returns true if the ID's are the same
 * @param rhs
 * @return
 */
bool Printer::operator==(const Printer &rhs) const {
    return rhs.id == id;
}


