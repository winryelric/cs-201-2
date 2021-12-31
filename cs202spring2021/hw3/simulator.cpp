/**
 * Title: Heaps
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 3
 * Description: Source file for Simulator
 */
#include "simulator.h"

/**
 * Each call to simulate computes the avg. waiting time of printing requests,
 * If given # of printers were to be used in such case given in the log file
 * @param file
 * @param noOfprinters
 * @return
 */
double simulate(const string &fileName, const int &noOfPrinters, const bool &finished) {
    // PROPERTIES
    MyArray<Printer> printers(noOfPrinters);
    for (int i = 0; i < noOfPrinters; i++)
        printers.add(Printer(i));

    ifstream file(fileName);
    int max;
    file >> max; // read the first word, it's # of requests

    RequestQ queue(max); // priority queue for printing requests
    int time = 0; // current time
    int waitingTimeSoFar = 0; // total waiting time

    if (finished)
        cout << "Simulation with " << noOfPrinters <<  " printers: " << endl << endl;

    if(file.is_open()) {
        while (!file.eof()) {
            PrintRequest cur;
            int i = 0;
            int mem[4] = {0}; // cells for members for a print request
            while (i < 4) {
                file >> mem[i];
                i++;
            }
            // instance of a printing request at hand
            cur = PrintRequest(mem[0], mem[1], mem[2], mem[3]);
            // if the printing request has arrived, enqueue it
            if (time == cur.getReqTime() )
                queue.enqueue(cur);
            else {
                // if the printing request request time is different than current time
                // it means that previous requests should be processed first, then the time should
                // be processed so that current request time is reached
                // print the requests until there is no printer available
                int availableIndex = findFirstAvailablePrinter(printers);
                while (!queue.isEmpty() && availableIndex > -1) {
                    waitingTimeSoFar += print(queue, time, finished,printers,availableIndex);
                    availableIndex = findFirstAvailablePrinter(printers);
                }

                // fast forward the time until current printing request's time arrives
                int t_old = time;
                while (time != cur.getReqTime() ) {
                    simNextMin(time, printers);
                    availableIndex = findFirstAvailablePrinter(printers);
                    // after forwarding the time,
                    // if reached the current request time
                    // enqueue it and move on to next request
                    // postpone dequeue
                    if (t_old != time && time == cur.getReqTime() ) {
                        queue.enqueue(cur);
                        break;
                        // if enqueue, don't dequeue; the rest can be dequeued
                        // in the next iteration above
                    }
                    // there is a chance that some printers
                    // available while time is being fast forwarded
                    while (!queue.isEmpty() && availableIndex > - 1) {
                        waitingTimeSoFar += print(queue,time, finished, printers, availableIndex);
                        availableIndex = findFirstAvailablePrinter(printers);
                    }
                }
            }
        }
    }
    // print remaining requests,
    // as end of reading from the file doesn't mean that
    // printing operations are completed
    while (!queue.isEmpty()) {
        int availableIndex = findFirstAvailablePrinter(printers);
        if (availableIndex > - 1)
            waitingTimeSoFar += print(queue, time, finished,printers,availableIndex);
        else
            simNextMin(time, printers);
    }
    if (finished)
        cout << endl << "Average waiting time: " << (double) waitingTimeSoFar / max << endl;
    return (double) waitingTimeSoFar / max;
}

/**
 * Computes the min. # of printers, K such that:
 * simulate(file, K) <= maxAvgWaitingTime
 *
 * K is found by calling simulate from 1 to K, exactly K times.
 * @param logFile
 * @param maxAvgWaitingTime
 * @return
 */
int findMinNoOfPrinters(const string &logFile, const int &maxAvgWaitingTime) {
    int K = 0;
    double avgWaitingTime;
    do {
        K++;
        avgWaitingTime = simulate(logFile, K, false);
    } while (avgWaitingTime > maxAvgWaitingTime);
    return K;
}

/**
 * We assume that id of the printers are sorted in ascending order
 * and put as following:
 * 0, 1, 2, 3, ... , n-1 \n
 *
 * return the index of the printer w/ lowest id
 *
 * return -1 if none available
 * @param printers
 * @return
 */
int findFirstAvailablePrinter(const MyArray<Printer> &printers) {
    for (int i = 0; i < printers.getSize(); i++) {
        if (printers.at(i).isAvailable())
            return i;
    }
    return -1;
}

/**
 * increase the time of simulator
 * decrease the remaining time of the printers
 * @param time
 * @param printers
 */
void simNextMin(int &time, MyArray<Printer> &printers) {
    time++;
    for (int j = 0; j < printers.getSize(); j++)
        printers.at(j).nextMinute();
}

/**
 * Print the next printing request
 * returns the waiting time for this request
 *
 * Current time and index of the first available printer needs to be passed
 * @param queue
 * @param time
 * @param finished
 * @param printers
 * @param availableIndex
 * @return
 */
int print(RequestQ& queue, const int& time, const bool& finished,
          MyArray<Printer>& printers, int& availableIndex) {
    PrintRequest del = queue.dequeue();
    // compute the waiting time
    // t_wait =  t_dequeue - t_enqueue
    // where t_enqueue is always equal to t_request
    int curWaitTime = time - del.getReqTime();
    // assign the printer with the task
    printers.at(availableIndex).assign(del.getProcTime());
    // show in the simulation that printer started to print a given printing request
    // if it was intended to be shown
    if (finished) {
        cout << "Printer " << printers.at(availableIndex).getId()
             << " prints print request " << del.getId() << " at minute " << time
             << " (wait: " << curWaitTime << " mins)"<< endl;
    }
    availableIndex = findFirstAvailablePrinter(printers);
    return curWaitTime;
}
