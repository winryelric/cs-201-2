/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Main executable
*/
#include "UniqueWordTree.h"
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    const char* in_filename = argv[1];
    const char* out_filename_1 = "wordfreqs.txt";
    const char* out_filename_2 = "statistics.txt";
    UniqueWordTree tree;
    tree.generateTree(in_filename);
    
    ofstream out_file1(out_filename_1);
    if (out_file1.is_open() ) {
        // Print the tree to the file
        tree.printWordFrequencies(out_file1);
        out_file1.close();
    }

    ofstream out_file2(out_filename_2);
    if (out_file2.is_open() ) {
        // Print the statistics to the file
        tree.printTotalWordCount(out_file2);
        tree.printHeight(out_file2);
        tree.printMostFrequent(out_file2);
        tree.printLeastFrequent(out_file2);
        tree.printStandardDeviation(out_file2);
        out_file2.close();
    }
    return 0;
}