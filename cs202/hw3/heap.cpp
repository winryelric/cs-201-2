/**
* Title: Heaps and AVL Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 3
* Description: Implementation for heap class
*/
#include "heap.h"

heap::heap() : size(0){}

// Constructor that builds a maxheap out of a random array
// with size arr_size. Counts the # key comparisons during
// the construction
heap::heap(int arr[], int arr_size, int& keyComp) {
    // Create the array with MAX_SIZE
    if  (arr_size <= MAX_SIZE)  size = arr_size;
    else                        size = MAX_SIZE;
    
    // make a complete binary tree out of the array
    for (int i = 0; i < size; i++)
        items[i] = arr[i];

    // convert it to a max-heap
    for (int i = size/2 - 1; i >= 0; i--)
        heapRebuild(i, keyComp);

    keyComp += size + 1 + (size/2);
}

void heap::insert(const int newInt) {
    if (size < MAX_SIZE) {
        // place the item to the end
        items[size] = newInt;
        // trickle the item so that the new tree is a maxheap
        int curr_index = size;
        int parent = (curr_index - 1) / 2;
        bool curr_gt_parent = items[curr_index] > items[parent];
        while (curr_index > 0 && curr_gt_parent) {
            // swap the parent with child because the child is larger, it should be the parent
            int temp = items[parent];
            items[parent] = items[curr_index];
            items[curr_index] = temp;

            // proceed to the upper level
            curr_index = parent;
            parent = (curr_index - 1) / 2;
            curr_gt_parent =  items[curr_index] > items[parent];
        }
        size++;
    }
}

int heap::maximum() {
    return items[0];
}

int heap::popMaximum() {
    int keyComp = 0;
    return popMaximum(keyComp);
}

int heap::popMaximum(int& keyComp) {
    // delete the first item in the array
    int del = items[0];
    size--;
    items[0] = items[size];
    // rebuild the heap
    heapRebuild(0, keyComp);
    // return the deleted item
    return del;
}

void heap::heapRebuild(int root_index, int& keyComp) {
    int child = 2 * root_index + 1; 
    // currently, child is the left child
    // assume the left child is larger
    // child + 1 index will be the right child if it exists
    // if the left child exists
    if ( child < size ) {
        keyComp++;
        // check if the right child exists.
        // if the right child is larger than left child
        // update the larger child
        if ( (child + 1) < size && items[child + 1] > items[child] ) {
            keyComp += 2;
            child = child + 1;
        }
        // if the parent is smaller than larger child, swap.
        // the larger subtree was changed during the swap
        // so rebuild that heap
        if (items[root_index] < items[child] ) {
            int temp = items[child];
            items[child] = items[root_index];
            items[root_index] = temp;
            keyComp++;
            heapRebuild(child, keyComp);
        }
    }
}