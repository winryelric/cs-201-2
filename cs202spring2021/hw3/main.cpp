/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Main file
 */
#include "printer.h"
#include "simulator.h"
int main(int argc, char** argv) {
    //cout << "Hello, World!" << std::endl;

    // Test for printers
//    Printer p1(1);
//    MyArray<Printer> printers(4);
//    printers.add(Printer(0));
//    printers.add(Printer(1));
//    printers.add(Printer(2));
//    printers.add(Printer(3));
//    cout << "p1.getId(): " << p1.getId() << endl;
//    cout << "p1.isAvailable(): " << p1.isAvailable() << endl;
//    Printer p2;
//    p2 = p1;
//    cout << p2 << endl << endl;
//    cout << printers << endl;
//    printers.remove(Printer(2));
//    cout << printers << endl;
//    printers.add(Printer(50));
//    cout << printers << endl;
//    cout << ( (printers.add(Printer(20)) ) ? "Success" : "Max is reached" ) << endl;
//    cout << printers << endl;
//
//    RequestQ q;
//    q.enqueue(PrintRequest(1, 2, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(2, 1, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(3, 2, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(4, 4, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(5, 8, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(6, 9, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(7, 33, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(8, 40, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(9, 14, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(10, 20, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(11, 27, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(12, 6, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(13, 2, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(14, 15, 3, 4));
//    q.display();
//    q.enqueue(PrintRequest(15, 21, 3, 4));
//
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;
//    cout << q.dequeue() << endl;

    string logF = argv[1];
    int maxAvgWaitTime = atoi(argv[2]);
    int K = findMinNoOfPrinters(logF, maxAvgWaitTime);
    cout << endl << "Minimum number of printers required: " << K << endl << endl;
    simulate(logF, K, true);
    return 0;
}
