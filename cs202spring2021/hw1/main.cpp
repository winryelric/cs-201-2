/**
 * Title: Sorting and Algorithm Efficiency
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 1
 * Description: Main file that outputs the results of the experiment
 */
#include "sorting.h"

int main() {
    cout << "= INITIAL TESTING =" << endl << endl;
    // initialize dynamically allocated array using an initializer list
    const int size = 16;
    int* test{ new int[size]{12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8} };
    // create a copy of this array
    int* copy = new int[size];
    copyArr(copy, test, size);

    int compCount, moveCount;
    double time = 0;

    partC(copy, test, size, SELECTION, compCount, moveCount, time);
    partC(copy, test, size, MERGE, compCount, moveCount, time);
    partC(copy, test, size, QUICK, compCount, moveCount, time);
    cout << "Analysis for Radix Sort" << endl;
    partC(copy, test, size, RADIX, compCount, moveCount, time);

    delete [] test;
    delete [] copy;
    performanceAnalysis();
}
