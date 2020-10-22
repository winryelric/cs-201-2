#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

int sequentialSearch(int* arr, int size, int key) {
	for (int i = 0; i < size; i++)
		if (arr[i] == key)
			return i;
	return -1;
}

int binarySearch(int* arr, int size, int key) {
	int low = 0, high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < key)
			low = mid + 1;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main(){
	const int numOfArrays = 7;
	int** arrContainer = new int* [numOfArrays];
	// Initialize arrays in sizes of 10, 100... and 10^6
	for (int i = 0; i < numOfArrays; i++) {
		const int sizeOfI = (int)pow(10, i);
		arrContainer[i] = new int[sizeOfI];
		for (int j = 0; j < sizeOfI; j++) {
			arrContainer[i][j] = j + 1;
		}
	}

	const int numOfKeys = 4;
	int** keyContainer = new int* [numOfArrays];
	for (int i = 0; i < numOfArrays; i++) {
		keyContainer[i] = new int[numOfKeys];
		keyContainer[i][0] = 1;							// First key is the first item of the arrays
		keyContainer[i][1] = (int)pow(10, i) / 2;		// Second key is the midpoint of the array
		keyContainer[i][2] = (int)pow(10, i);			// Third key is in the last element of the array
		if (i == 0) keyContainer[i][1] = keyContainer[i][2] = 1;
		keyContainer[i][3] = -1;						// Last key is -1, which none of the arrrays contain
	}

	//Search arrays
	for (int i = 0; i < numOfArrays; i++) {
		// M is the repetiton time for sequantial search
		int M = 1000; 
		int length = (int)pow(10, i);
		cout << "The array with size " << length << endl;
		for (int j = 0; j < numOfKeys; j++) {
			cout << "Case " << j + 1 << endl;

			// SEQUANTIAL SEARCH

			// The best case scenario is very short so repeat it so many times
			if (j == 0)					M = 10000000;
			// The default repetiton
			else if (j != 0 && i >= 3)	M = 1000;
			// If the array is too small, repeat it so many times
			else if (i < 3)				M = 10000000;

			double duration;
			clock_t startTime = clock();
			for (int k = 0; k < M; k++)
				sequentialSearch(arrContainer[i], length, keyContainer[i][j]);
			duration = 1000 * ( (double)clock() - startTime) / CLOCKS_PER_SEC;
			duration = duration / M;
			cout << "Sequantial search took " << duration << " ms." << endl;

			// BINARY SEARCH

			// L is the repetiton time for binary search
			cout << binarySearch(arrContainer[i], length, keyContainer[i][j]) << endl;
			int L = 10000000;
			startTime = clock();
			for (int k = 0; k < L; k++)
				binarySearch(arrContainer[i], length, keyContainer[i][j]);
			duration = 1000 * ((double)clock() - startTime) / CLOCKS_PER_SEC;
			duration = duration / L;
			cout << "Binary search took " << duration << " ms." << endl;
		}
	}
	// Avoid memory leak
	for (int i = 0; i < numOfArrays; i++) {
		delete[] keyContainer[i];
		delete[] arrContainer[i];
	}

}
