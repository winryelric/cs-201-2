/**
 * Title: Sorting and Algorithm Efficiency
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 1
 * Description: Prototypes for sorting algorithms
 * auxilary functions and other definitions found
 * useful by the author
 */
#ifndef HW1_SORTING_H
#define HW1_SORTING_H

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function definitions in the homework description
void selectionSort(int* arr, const int size, int& compCount, int& moveCount);
void mergeSort(int* arr, const int size, int& compCount, int& moveCount);
void quickSort(int* arr, const int size, int& compCount, int& moveCount);
void radixSort(int* arr, const int size);
void displayArray(const int *arr, const int& size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void performanceAnalysis();

// Helper functions & definitions
/**
 * Prototype for the sorting algorithms of interest.
 *
 * For radix sort, same algorithm with this signature will be used
 * i.e.
 *      void radixSort(int* arr, const int size, int& compCount, int& moveCount);
 * just calls radixSort(arr, size);
 * making no difference in experiment
 */
typedef  void (*SortType)(int *, const int, int&, int&);

/**
 * Enum for representing the names of the sorting algorithms.
// Useful for implementing display functions in a reusable manner
 */
enum Sort {
    SELECTION = 0,
    MERGE = 1,
    QUICK = 2,
    RADIX = 3
};

/**
 * Enum for each scenario of sorting
 */
enum Order {
    RANDOM = 1,
    ASCENDING = 2,
    DESCENDING = 3,
};

// Helper functions for selection sort
int indexOfLargest(const int* arr, const int& size);
int indexOfLargest(const int* arr, const int& size, int& compCount);
void swap(int& x, int& y);

// Helper functions for merge sort
void mergeSort(int* arr, const int& first, const int& last, int& compCount, int& moveCount);
void merge(int* arr, const int& first, const int& mid, const int& last, int& compCount, int& moveCount);

// Helper functions for quick sort
void quickSort(int* arr, const int& first, const int& last, int& compCount, int& moveCount);
void partition(int* arr, const int& first, const int& last, int& pivotIndex, int& compCount, int& moveCount);

// Helper functions for radix sort
void radixSort(int* arr, const int size, int& compCount, int& moveCount);
int getDigit(const int&x, const int&y);
string toString(const int& x);

// Helper function for copying an array
void copyArr(int* target, const int* source, const int& size);

// Helper functions for displaying the output of an experiment result
void displayHeader(Sort sortName, bool experimentFlag);
void displayRow(const int& size, const int& compCount, const int& moveCount, const double& time);
void displayRow(const int& size, const int& compCount, const int& moveCount);
void displayRow(const int& size, const double& time);
void displayResults(Sort sortName,
                    const int& size,
                    const int& compCount,
                    const int& moveCount,
                    const double& time,
                    bool experimentFlag);

// Helper function for the question in part C
void partC(int*& copy,
           int*& test,
           const int& size,
           Sort sortName,
           int& compCount,
           int& moveCount,
           double& time);

// Helper function that sorts the array and returns the time elapsed
double measureTime(SortType sort, int* arr, const int &size, int& compCount, int& moveCount);
#endif
