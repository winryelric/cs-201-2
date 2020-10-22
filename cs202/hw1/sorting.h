/**
* Title: Algorithm Efficiency and Sorting
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 1
* Description: Prototypes for sorting functions
*/

void insertionSort(int* arr, const int size,
	unsigned long long int& compCount,
	unsigned long long int& moveCount);

void mergeSort(int* arr, const int size, 
	unsigned long long int& compCount,
	unsigned long long int& moveCount);

void mergeSort(int* arr, const int first, const int last, 
	unsigned long long int& compCount,
	unsigned long long int& moveCount);

void quickSort(int* arr, const int size, 
	unsigned long long int& compCount, 
	unsigned long long int& moveCount);

void quickSort(int* arr, const int first, const int last, 
	unsigned long long int& compCount, 
	unsigned long long int& moveCount);

void merge(int* arr, 
	const int first, const int mid, const int last, 
	unsigned long long int& compCount, 
	unsigned long long int& moveCount);

void partition(int* arr, 
	const int first, const int last, 
	int& pivotIndex, 
	unsigned long long int& compCount, 
	unsigned long long int& moveCount);

void swap(int& x, int& y);