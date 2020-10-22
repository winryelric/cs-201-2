/**
* Title: Algorithm Efficiency and Sorting
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 1
* Description: Class definition for sorting.h
*/

#include "sorting.h"
#include <iostream>
using namespace std;

void insertionSort(int* arr, const int size,
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {
    
    compCount = 0; moveCount = 0;
    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        int j = unsorted;

        while( (j > 0) && (arr[j - 1] > nextItem) ) {
            arr[j] = arr[j - 1];
            j--;
            compCount += 2;
            moveCount += 2;
        }
        arr[j] = nextItem;
        compCount += 2;
        moveCount += 4;
    }
    compCount++;
}

void mergeSort(int* arr, const int size, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {
    compCount = 0; moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void mergeSort(int* arr, 
    const int first, const int last, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {

    if (first < last) {
        int mid = (first + last) / 2;
        compCount++;
        moveCount++;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void quickSort(int* arr, 
    const int size, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {
    compCount = 0; moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int* arr, 
    const int first, const int last, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {

    if (first < last) {
        int pivotIndex;
        compCount++;

        partition(arr, first, last, pivotIndex, compCount, moveCount);
        quickSort(arr, first, pivotIndex, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void merge(int* arr, 
    const int first, int mid, const int last, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {
    
    const int size = last - first + 1;
    
    int temp[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;
    moveCount += 6;

    // start merging
    while( (first1 <= last1) && (first2 <= last2) ) {
        
        // if the first sub arrays element comes first, copy it to the temp
        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            first1++;
        }
        // else, copy the second sub arrays element
        else {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
        compCount += 4;
        moveCount +=3;
    }

    // if there are items skipped in the first sub array, put them into temp
    while ( first1 <= last1 )  {
        temp[index] = arr[first1];
        first1++;
        compCount++;
        moveCount += 3;
    }

    // if there are items skipped in the second sub array, put them into temp
    while ( first2 <= last2 )  {
        temp[index] = arr[first2];
        first2++;
        compCount++;
        moveCount += 3;
    }
    
    for (int i = first; i <= size; i++) {
        arr[i] = temp[i];
        compCount++;
        moveCount += 2;
    }
    compCount += 4;
    moveCount++;
}

void partition(int* arr, 
    const int first, const int last, 
    int& pivotIndex, 
    unsigned long long int& compCount, 
    unsigned long long int& moveCount) {
    
    pivotIndex = 0;
    int pivot = arr[first]; // take first item as pivot 

    // initially, everything but pivot is unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item until unknown is distributed to S1 & S2
    while (firstUnknown <= last) {

        // move item from unknown
        if (arr[firstUnknown] < pivot) { // belongs to S1
            lastS1++;
            compCount++;
            swap( arr[firstUnknown], arr[lastS1]);
            moveCount += 4;
        }   // else belongs to S2
        firstUnknown++;
        compCount++;
        moveCount++;
    }
    // place pivot after S1 and save index
    swap( arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 7;
    compCount++;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
