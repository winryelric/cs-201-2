/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Header file for PrintRequest class
 */
#ifndef CODE_PRINTREQUEST_H
#define CODE_PRINTREQUEST_H
#include <iostream>
using namespace std;
class PrintRequest {
public:
    PrintRequest();
    PrintRequest(const PrintRequest&);
    PrintRequest(const int&, const int&, const int&, const int&);
    int getId() const;
    int getPrio() const;
    int getReqTime() const;
    int getProcTime() const;
    PrintRequest& operator=(const PrintRequest&);
    bool operator==(const PrintRequest&) const;
    bool operator<=(const PrintRequest&) const;
    bool operator>=(const PrintRequest&) const;
    bool operator<(const PrintRequest&) const;
    bool operator>(const PrintRequest&) const;
    friend ostream& operator<<(ostream&, const PrintRequest&);
private:
    int id;
    int priority;
    int requestTime;
    int processTime;
};
#endif
