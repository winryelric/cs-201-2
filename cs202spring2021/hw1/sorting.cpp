/**
 * Title: Sorting and Algorithm Efficiency
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 1
 * Description: Implementations for the sorting algorithms
 * And all the rest of the implementation
 */
#include <iomanip>
#include "sorting.h"

void selectionSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = moveCount = 0;
    for (int last = size - 1; last >= 1; last--) {
        int largest = indexOfLargest(arr, last + 1, compCount);
        swap(arr[largest], arr[last]);
        moveCount += 3;
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}


void radixSort(int *arr, const int size) {
    // Compute the d value for the array
    // That is the maximum number of digits of an item
    int max = arr[indexOfLargest(arr, size)];
    string maxStr = toString(max);
    int d = maxStr.size();

    for (int j = d; j > 0; j--) {
        //Initialize 10 groups to empty
        int** group = new int*[10];
        // worst case is that a group contains all of the elements in the array
        for (int i = 0; i < 10; i++) {
            // each group has maximum size of N
            // initially 0
            group[i] = new int[size];
        }

        //Initialize a size counter for each group to 0
        int counter[10] = {0};

        for (int i = 0; i < size; i++) {
            //k = jth digit of theArray[i]
            int j_prime = d + 1 - j;
            int k = getDigit(arr[i], j_prime);
            //Place theArray[i] at the end of group k
            group[k][counter[k]] = arr[i];
            //Increase kth counter by 1
            counter[k]++;
        }
        for (int groupNo = 0; groupNo < 10; groupNo++) {
            // iterate the group_i and copy it to the original array
            int offset = 0;
            // offset = sum off all counters until current group
            for (int i = 0; i < groupNo; i++)
                offset = offset + counter[i];
            for (int k = 0; k < counter[groupNo]; k++) {
                // k is the index of the each group
                // offset + k gives the index of the element in the array
                // replace the kth element of a group to this index in the array
                arr[offset + k] = group[groupNo][k];
            }
        }
        // Deallocate memory
        for (int i = 0; i < 10; i++) {
            // delete each group
            delete [] group[i];
        }
        // delete all groups
        delete [] group;
    }
}

/**
 * Display an array in a single line
 * @param arr
 * @param size
 */
void displayArray(const int *arr, const int& size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) cout << ", ";
    }
    cout << "]";
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = rand();
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = i + 1;
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = size - i;
}

/**
 * Performs the sorting analysis and prints the outputs
 * First, it creates 4 identical arrays for each scenario
 * Then, those identical arrays are sorted one by one for the sizes
 * 6 000, 10 000, ... to 30 000
 * While performing sorting, results for each sort is stored in automatic arrays
 * Then, after a scenario is finished, All of the outputs are printed at once
 * Then next scenario is conducted
 */
void performanceAnalysis() {
    for (int scenario = RANDOM; scenario <= DESCENDING; scenario++) {
        // four identical arrays
        int* selection;
        int* merge;
        int* quick;
        int* radix;
        // result of the experiments
        int compCount[4][7];
        int moveCount[4][7];
        double time[4][7];
        // determine the order
        string order;
        switch (scenario) {
            case RANDOM:
                order = "RANDOM";
                break;
            case ASCENDING:
                order = "ASCENDING";
                break;
            case DESCENDING:
                order = "DESCENDING";
                break;
        }
        cout << "= EXPERIMENT FOR " << order << " ORDER = " << endl << endl;
		cout << "Please wait for at least 10 seconds..."<< endl;
        for (int i = 0; i < 7; i++) {
            const int size = i * 4000 + 6000;
            // initialize the arrays
            // allocate only 4 array at a time
            selection = new int[size];
            merge = new int[size];
            quick = new int[size];
            radix = new int[size];
            // create four identical arrays
            switch (scenario) {
                case RANDOM:
                    createRandomArrays(selection, merge, quick, radix, size);
                    break;
                case ASCENDING:
                    createAscendingArrays(selection, merge, quick, radix, size);
                    break;
                case DESCENDING:
                    createDescendingArrays(selection, merge, quick, radix, size);
                    break;
            }
            time[0][i] = measureTime(&selectionSort, selection, size, compCount[0][i], moveCount[0][i]);
            delete [] selection;
            time[1][i] = measureTime(&mergeSort, merge, size, compCount[1][i], moveCount[1][i]);
            delete [] merge;
            time[2][i] = measureTime(&quickSort, quick, size, compCount[2][i], moveCount[2][i]);
            delete [] quick;
            time[3][i] = measureTime(&radixSort, radix, size, compCount[3][i], moveCount[3][i]);
            delete [] radix;
        }
        for (int sort = SELECTION; sort <= RADIX; sort++) {
            Sort sortName = (Sort)sort;
            displayHeader(sortName, true);
            for (int sizeIndex = 0; sizeIndex < 7; sizeIndex++) {
                displayResults(sortName,
                               sizeIndex*4000 + 6000,
                               compCount[sort][sizeIndex],
                               moveCount[sort][sizeIndex],
                               time[sort][sizeIndex],
                               true);
            }
        }
    }
}

int indexOfLargest(const int *arr, const int &size) {
    int compCount = 0;
    return indexOfLargest(arr, size, compCount);
}

int indexOfLargest(const int *arr, const int &size, int& compCount) {
    int index = 0;
    for (int cur = 1; cur < size; cur++) {
        compCount++;
        if (arr[cur] > arr[index])
            index = cur;
    }
    return index;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void mergeSort(int *arr, const int &first, const int &last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void merge(int *arr, const int &first, const int &mid, const int &last, int &compCount, int &moveCount) {
    const int size = last - first + 1;
    int* temp = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    // start merging
    while((first1 <= last1) && (first2 <= last2)) {

        // if the first sub arrays element is smaller, copy it to the temp
        compCount++;
        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            first1++;
        }
        // else, copy the second sub array is smaller, so copy it to the temp
        else {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
        moveCount++;
    }

    // if there are items skipped in the first sub array, put them into temp
    while (first1 <= last1)  {
        temp[index] = arr[first1];
        first1++;
        index++;
        moveCount++;
    }

    // if there are items skipped in the second sub array, put them into temp
    while (first2 <= last2)  {
        temp[index] = arr[first2];
        first2++;
        index++;
        moveCount++;
    }
    // finalize the sorting by copying the sorted array (temp) into our array
    for (int i = 0; i < size; i++) {
        arr[i + first] = temp[i];
        moveCount++;
    }
    delete [] temp;
}

void quickSort(int *arr, const int &first, const int &last, int &compCount, int &moveCount) {
    int pivotIndex;
    if (first < last) {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void partition(int *arr, const int &first, const int &last, int &pivotIndex, int &compCount, int &moveCount) {
    pivotIndex = first; // choose first item as the pivot
    int lastS1 = first;
    int firstUnknown;
    for (firstUnknown = first + 1; firstUnknown <= last; firstUnknown++) {
        // if first unknown is located before the pivot, it belongs to S1
        compCount++;
        if (arr[firstUnknown] < arr[pivotIndex]) {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
        // else it belongs to S2, no operation is required
    }
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
}

void radixSort(int *arr, const int size, int &compCount, int &moveCount) {
    radixSort(arr, size);
}

/**
 * Finds the yth digit of x,
 * where the least significant digit of X is the 1st digit.
 *
 * If y is larger than # of digits in X, it will still return 0
 * As if X is zero extended
 * @param x
 * @param y
 * @return
 */
int getDigit(const int &x, const int &y) {
    int temp = x;
    for (int i = 0; i < y - 1; i++)
        temp /= 10;
    return temp % 10;
}


/**
 * Even though C++11 has to_string function
 * This was necessarry to be implemented since
 * dijkstra machine doesn't support to_string
 * @param x
 * @return
 */
string toString(const int& x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

/**
 * Set the contents of target array into contents of source array
 * Both arrays must be of the same "size"
 * @param source
 * @param target
 * @param size
 */
void copyArr(int* target, const int* source, const int& size) {
    for (int i = 0; i < size; i++)
        target[i] = source[i];
}

void displayHeader(Sort sortName, bool experimentFlag) {
    // don't display anything in radix sort for the question 2 part c
    if (sortName != RADIX || experimentFlag) {
        cout << "----------------------------------------------------------------------------------------" << endl;
        string name;
        switch (sortName) {
            case SELECTION:
                name = "Selection";
                break;
            case MERGE:
                name = "Merge";
                break;
            case QUICK:
                name = "Quick";
                break;
            case RADIX:
                name = "Radix";
                break;
        }
        cout << "Analysis of " << name << " Sort" << endl;
    }
    // performanceAnalysis header for the first three sort
    if (experimentFlag && sortName != RADIX)
        cout << setw(24) << left << "Array Size"
             << setw(24) << left << "Elapsed time (ms)"
             << setw(24) << left << "compCount"
             << setw(24) << left << "moveCount" << endl;
        // performanceAnalysis header for radix sort
    else if (experimentFlag)
        cout << setw(24) << left << "Array Size"
             << setw(24) << left << "Elapsed time (ms)"  << endl;
        // headers for part c
    else if (sortName != RADIX)
        cout << setw(24) << left << "Array Size"
             << setw(24) << left << "compCount"
             << setw(24) << left << "moveCount" << endl;
    // don't print anything for part c radix sort
}

void displayRow(const int& size, const int& compCount, const int& moveCount, const double& time) {
    cout << setw(24) << left << size
         << setw(24) << left << time
         << setw(24) << left << compCount
         << setw(24) << left << moveCount << endl;
}

void displayRow(const int& size, const int& compCount, const int& moveCount) {
    cout << setw(24) << left << size
         << setw(24) << left << compCount
         << setw(24) << left << moveCount << endl;
}

void displayRow(const int& size, const double& time) {
    cout << setw(24) << left << size
         << setw(24) << left << time << endl;
}

/**
 * Display a single row of data
 * Since for each sorting algorithm in different questions
 * has different sets of data outputs, a general function
 * managing all of the decision making could be handy
 * @param sortName
 * @param size
 * @param compCount
 * @param moveCount
 * @param time
 * @param experimentFlag
 */
void displayResults(Sort sortName,
                    const int& size,
                    const int& compCount,
                    const int& moveCount,
                    const double& time,
                    bool experimentFlag) {
    // display results for performanceAnalysis for the first three sort
    if (experimentFlag && sortName != RADIX)
        displayRow(size, compCount, moveCount, time);
        // display results for performanceAnalysis for radix sort
    else if (experimentFlag)
        displayRow(size, time);
        // display results for part c
    else if (sortName != RADIX)
        displayRow(size, compCount, moveCount);
    // don't display radix sort in part c
}

/**
 * Performs & displays the sorting experiment
 * and the results in part C for a
 * given sorting algorithm
 * @param copy
 * @param test
 * @param size
 * @param sortName
 * @param compCount
 * @param moveCount
 * @param time
 */
void partC(int*& copy,
           int*& test,
           const int& size,
           Sort sortName,
           int& compCount,
           int& moveCount,
           double& time) {
    // display the array before sorting
    cout << "before sorting : ";
    displayArray(copy, size);
    cout << endl;
    // perform sort
    switch (sortName) {
        case SELECTION:
            selectionSort(copy, size, compCount, moveCount);
            break;
        case MERGE:
            mergeSort(copy, size, compCount, moveCount);
            break;
        case QUICK:
            quickSort(copy, size, compCount, moveCount);
            break;
        case RADIX:
            radixSort(copy, size, compCount, moveCount);
            break;
    }
    // display the results
    displayHeader(sortName, false);
    displayResults(sortName, size, compCount, moveCount, time, false);
    // display the array after sorting
    cout << "after sorting : ";
    displayArray(copy, size);
    cout << endl << endl;
    // revert the array
    copyArr(copy, test, size);
}

/**
 * Measure the time elapsed,
 * important key comparisons and data moves
 * for one sorting call in ms
 *
 * This time measurement method is not OS dependent as CLOCKS_PER_SEC
 * parameter will be different in each computer and is defined seperately
 * for each computer/ system in c++ standards
 *
 * To improve precision, any sorting algorithm will be called many times
 * so that sum of the time elapsed for all calls are at least 500 ms
 * By counting number of calls, exact time elapsed for a call is computed
 * @param sort
 * @param arr
 * @param size
 * @param order
 * @param compCount
 * @param moveCount
 * @return time passed in ms
 */
double measureTime(SortType sort, int* arr, const int &size, int& compCount, int& moveCount) {
    double timePassed = 0;
    int noOfCalls = 0;
    // execute sort function for 1 second
    do {
        // by sorting the copy of the array many many times
        // and counting the number of calls
        // we can compute the time specifications more precisely
        int* copy = new int[size];
        copyArr(copy, arr, size);
        // start counting
        clock_t start = clock();
        // sort the copy
        sort(copy, size, compCount, moveCount);
        // stop counting
        timePassed = timePassed + ( (double)(clock() - start) / (CLOCKS_PER_SEC) ) * 1000.0;
        noOfCalls++;
        // delete the copy
        delete [] copy;
    } while (timePassed < 500.0);
    return (timePassed / noOfCalls);
}
