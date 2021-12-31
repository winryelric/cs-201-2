/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Header file for HashTable
 */
#ifndef CODE_HASHTABLE_H
#define CODE_HASHTABLE_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.cpp"
using namespace std;
/**
 * table size is about 1:3 of max. num of keys
 */
const int NUM_OF_WORDS = 5757;
const int TABLE_SIZE = NUM_OF_WORDS / 3;
/**
 * Hash table to store strings
 * As well as map them to integers
 */
class HashTable {
public:
    HashTable();
    HashTable(const HashTable& copy);
    int vertexIndex(const string& word);
    string word(int vertexIndex);
    void insert(const string &word, int index);
    void remove(const string &word);
    static int hash(const string& key);
    void display();
private:

    /**
     * Each location in the table is a linked list
     */
    LinkedList<string, int> items[TABLE_SIZE];
};
#endif
