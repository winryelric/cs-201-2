/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Header file for Printer class
 */
#ifndef CODE_PRINTER_H
#define CODE_PRINTER_H
#include <iostream>
using namespace std;
class Printer {
public:
    Printer();
    Printer(const Printer&);
    explicit Printer(const int&, const int& timeLeft = 0); // avoid implicit conversion for int
    int getId() const;
    bool isAvailable() const;
    void assign(const int&);
    void nextMinute();
    int getTimeLeft() const;
    Printer& operator=(const Printer&);
    bool operator==(const Printer& rhs) const;
    friend ostream& operator<<(ostream&, const Printer&);
private:
    int id;
    int timeLeft;
};
#endif
