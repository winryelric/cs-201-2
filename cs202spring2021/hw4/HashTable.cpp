/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Source file for HashTable
 */
#include "HashTable.h"

HashTable::HashTable() = default;

HashTable::HashTable(const HashTable& copy) {
    for (int i = 0; i < TABLE_SIZE; i++)
        items[i] = LinkedList<string, int>(copy.items[i]);
}

/**
 * Compute the vertex index of a given word
 *
 * Basically, whole purpose of the Hash Table;
 * to perform this efficiently
 * Complexity : O(1 + a)
 * @param word
 * @return
 */
int HashTable::vertexIndex(const string &word) {
    int index = -1;
    items[hash(word)].getItemFor(word, index);
    return index;
}

/**
 * An inefficient way of finding the word
 * associated with its index in the graph network
 * complexity : O(N)
 * @param vertexIndex
 * @return
 */
string HashTable::word(int vertexIndex) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        string word;
        if (items[i].getKeyFor(vertexIndex, word))
            return word;
    }
    return "";
}

void HashTable::insert(const string &word, int index) {
    items[hash(word)].addTail(word, index);
}

void HashTable::remove(const string &word) {
    items[hash(word)].remove(word);
}

/**
 * Hash function in slides, slide 40, Hash Function 3
 * @param key
 * @return
 */
int HashTable::hash(const string &key) {
    int hashVal = 0;
    for (char i : key)
        hashVal = 37 * hashVal + i;
    hashVal %= TABLE_SIZE;
    while (hashVal < 0)
        hashVal += TABLE_SIZE;
    return hashVal;
}

void HashTable::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!items[i].isEmpty()) {
            cout << i << " = ";
            items[i].display();
        }
    }
}
