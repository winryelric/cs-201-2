/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Header file for WordNetwork
 */
#ifndef CODE_WORDNETWORK_H
#define CODE_WORDNETWORK_H
#include <string>
#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;
class WordNetwork {
public:
    WordNetwork();
    ~WordNetwork();
    WordNetwork(const string& vertexFile, const string& edgeFile);
    void listNeighbors(const string& word);
    void listNeighbors(const string& word, int distance);
    void listConnectedComponents();
    void findShortestPath(const string& word1, const string& word2);

private:
    int** adjMatrix;
    HashTable indices;

    bool isAdjacentTo(int v, int u);
    void addEdge(int vIndex, int uIndex);
    void depthFirstTraversal(int v, bool *visited);
    void depthFirstTraversal(int distance, int v, bool *visited);

    int* getMST(int A);
    static int  minDistance(const int *weight, const bool *vertexSet);
    void mstTrace(int *mst, int b);
};
#endif