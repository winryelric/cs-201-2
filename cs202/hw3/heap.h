/**
* Title: Heaps and AVL Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 3
* Description: Interface for heap class, a max heap
*/
#ifndef __HEAP_H_
#define __HEAP_H_
using namespace std;
#include <string>
#include <iostream>

const int MAX_SIZE = 10000;

class heap {
public:
    heap();
    heap(int arr[], int size, int& keyComp);
    void insert(const int newInt);
    int maximum();
    int popMaximum();
    int popMaximum(int& keyComp);
protected:
    void heapRebuild(int root_index, int& keyComp);
private:
    int items[MAX_SIZE];
    int size;
};

#endif