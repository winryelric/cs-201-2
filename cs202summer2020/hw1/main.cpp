/**
* Title: Algorithm Efficiency and Sorting
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 1
* Description: Main function for creating large data and experimenting.
*/

#include "sorting.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {

	//Creates 54 arrays, first decide what their order will be
	for ( int j = 0; j < 3; j++ ) {
		if ( j == 0) cout << "== EXPERIMENT FOR RANDOM ORDER ==" <<endl;
		if ( j == 1) cout << "== EXPERIMENT FOR ASCENDING ORDER ==" <<endl;
		if ( j == 2) cout << "== EXPERIMENT FOR DESCENDING ORDER ==" <<endl;

		// Then, decide what their size will be
		for ( int i = 0; i < 6; i++ ) {

			// Create an array with size 10k * (i + 2)
			const int size = (i + 1)*20000;
			int* arrInsertion 	= new int[size];
			int* arrMerge 		= new int[size];
			int* arrQuick 		= new int[size];

			cout << "\tSIZE = " << size <<endl;

			// Initialize the array with the correct order
			// random, ascending or descending
			for ( int x = 0; x < size; x++ ) {
				// random
				if ( j == 0 ) 
					arrInsertion[x] = rand();
				// ascending
				else if ( j == 1 )
					arrInsertion[x] = x;	
				// descending
				else
					arrInsertion[x] = size - x;
				// copy the arrays to use for merge sort & quick sort
				arrMerge[x] = arrInsertion[x];
				arrQuick[x] = arrInsertion[x];
			}

			//Create 3 timers and define compCount & moveCount for 3 algorithms. 
			clock_t startInsertion, startMerge, startQuick;
			double timeInsertion, timeMerge, timeQuick;
			unsigned long long int compInsertion, compMerge, compQuick;
			unsigned long long int moveInsertion, moveMerge, moveQuick;

			// Start the timer, sort the array, stop the timer and record the time passed in ms
			startInsertion = clock();
			insertionSort(arrInsertion, size, compInsertion, moveInsertion);
			timeInsertion = 1000 * (double)(clock() - startInsertion ) / CLOCKS_PER_SEC;

			cout << "\t\t= INSERTION SORT =" << endl;
			cout << "\t\tKey Comparisons : \t" << compInsertion << endl;
			cout << "\t\tData Moves: \t\t" << moveInsertion << endl;
			cout << "\t\tTime Elapsed: \t\t" << timeInsertion << " ms"<< endl;

			startMerge = clock();
			mergeSort(arrMerge, size, compMerge, moveMerge);
			timeMerge = 1000 * (double)(clock() - startMerge ) / CLOCKS_PER_SEC;

			cout << "\t\t= MERGE SORT =" << endl;
			cout << "\t\tKey Comparisons : \t" << compMerge << endl;
			cout << "\t\tData Moves: \t\t" << moveMerge << endl;
			cout << "\t\tTime Elapsed: \t\t" << timeMerge << " ms"<< endl;
				
			startQuick = clock();
			quickSort(arrQuick, size, compQuick, moveQuick);
			timeQuick = 1000 * (double)(clock() - startQuick ) / CLOCKS_PER_SEC;
			cout << "\t\t= QUICK SORT =" << endl;
			cout << "\t\tKey Comparisons : \t" << compQuick << endl;
			cout << "\t\tData Moves: \t\t" << moveQuick << endl;
			cout << "\t\tTime Elapsed: \t\t" << timeQuick << " ms"<< endl;
			
			// delete the arrays
			delete [] arrInsertion;
			delete [] arrMerge;
			delete [] arrQuick;
		}
	}
}