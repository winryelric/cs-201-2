/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Header file for Simulator class
 *
 * Exectues a simulation to find minimum number of print requests needed
 * in a library
 */
#ifndef CODE_SIMULATOR_H
#define CODE_SIMULATOR_H
#include "requestq.h"
#include "printer.h"

double simulate(const string& fileName, const int& noOfPrinters, const bool& finished = false);
int findMinNoOfPrinters(const string& logFile, const int& maxAvgWaitingTime);
int findFirstAvailablePrinter(const MyArray<Printer> &printers);
void simNextMin(int& time, MyArray<Printer>& printers);
int print(RequestQ& queue, const int& time, const bool& finished,
          MyArray<Printer>& printers, int& availableIndex);
#endif
