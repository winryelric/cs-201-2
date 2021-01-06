/**
* Title: Heaps and AVL Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 3
* Description:  The global heapsort function and
* the main function to sort the data given in 
* the specific file and print the results
* into a given file
*/
#include "heap.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void heapSort(int arr [], int size, int& keyComp) {
    keyComp = 0;
    // build the array into a heap
    heap h(arr, size, keyComp);
    for (int last_heap = size - 1; last_heap >= 0; last_heap--) {
        // put the max element to the last element of the heap,
        // then update the heap
        arr[last_heap] = h.popMaximum(keyComp);
    }
}

int main( int argc, char** argv ) {
    char* in_filename = argv[1];
    char* out_filename = argv[2];

    // Get the first file, take integers in the array and make an array
    int arr[MAX_SIZE];
    int size = 0;
    int keyComp;

    ifstream in_file(in_filename);
    if (in_file.is_open() ) {
        // Take each line in the file
        // and iterate them
        // assume that a line contains only a single integer
        int index = 0;
        while( !in_file.eof() ) {
            string num_;
            in_file >> num_;

            // Convert the string to int
            int num = 0;
            for (int i = 0; i < num_.size(); i++)
                num = (num_[i] - 48) + (num * 10);

            // add the number if the array is not full and end of the file was not reached
            // if it is the end of the file, num_ == "\n" and the string num_ will have the size 0
            if (size < MAX_SIZE && num_.size() != 0 ) { 
                arr[index] = num;
                size++;
            }
            index++;
        }
        // Close the file
        in_file.close();
    }
    // Sort the array, get the number of key comparisons
    heapSort(arr, size, keyComp);

    // Print the sorted array AND number of key comparisons to the output file
    ofstream out_file(out_filename);
    if (out_file.is_open() ) {
        // Print the results
        out_file << "# Key Comparisons: " << keyComp << endl;
        out_file << "Size of the list: " << size << endl;
        out_file << "===== THE SORTED LIST ====="<< endl;
        for ( int i = 0; i < size; i++ )
            out_file << arr[i] << endl;
        out_file.close();
    }
    return 0;
}
