/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Main file
 */
#include <iostream>
#include "WordNetwork.h"
int main(int argc, char** argv) {
    string vFile = argv[1], eFile = argv[2];

    WordNetwork graph(vFile, eFile);

    graph.listNeighbors("roger");
    graph.listNeighbors("oofsize");

    graph.listNeighbors("tutor", 2);
    graph.listNeighbors("setup", 2);
    graph.listNeighbors("ideal", 2);
    graph.listNeighbors("piece", 2);
    graph.listNeighbors("roger", 2);
    graph.listNeighbors("rover", 2);
    graph.listNeighbors("tutor", 2);

    graph.listConnectedComponents();

    graph.findShortestPath("cover", "roper");
    graph.findShortestPath("roger", "rivet");
    graph.findShortestPath("nodes", "graph");
}
