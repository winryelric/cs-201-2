/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Source file for WordNetwork
 */
#include "WordNetwork.h"
#include <climits>

/**
 * Template display function for testing purposes
 * @tparam T
 * @param arr
 * @param size
 */
template <typename T>
void displayArr(T* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size-1)
            cout << ", ";
    }
    cout << "]" << endl;
}

WordNetwork::WordNetwork() {
    // create a graph with 5757 vertices
    // where none of the vertices are connected
    adjMatrix = new int*[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        adjMatrix[i] = new int[NUM_OF_WORDS];
        for (int j = 0; j < NUM_OF_WORDS; j++)
            adjMatrix[i][j] = 0;
    }
}

WordNetwork::~WordNetwork() {
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;
}

WordNetwork::WordNetwork(const string& vertexFile, const string& edgeFile) {

    // 0- Create an empty graph
    adjMatrix = new int*[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        adjMatrix[i] = new int[NUM_OF_WORDS];
        for (int j = 0; j < NUM_OF_WORDS; j++)
            adjMatrix[i][j] = 0;
    }
    // 1- Read the vertex file and create a hash table
    ifstream file(vertexFile);
    if (file.is_open()) {
        int lineNo = 0;
        while (!file.eof()) {
            string cur;
            file >> cur;
            if (cur.size() == 5)
                indices.insert(cur, lineNo);
            lineNo++;
        }
        file.close();
    }

    // 2- Read the edge file and initialize the graph
    ifstream edges(edgeFile);
    if (edges.is_open()) {
        while (!edges.eof()) {
            string cur; // each string will be two words separated by a comma
            edges >> cur; // which will be always the 6th character
            if (cur.size() == 11) {
                const char* cur_ar = cur.c_str();
                string first, second;
                first = string(cur_ar, 5); // the first word
                second = string(cur_ar + 6, 5); // the second word
                int first_addr = indices.vertexIndex(first);
                int second_addr = indices.vertexIndex(second);
                addEdge(first_addr, second_addr);
            }
        }
        edges.close();
    }
}

/**
 * Simply search the vth row of the adjMatrix
 * @param word
 */
void WordNetwork::listNeighbors(const string& word) {
    int index = indices.vertexIndex(word);
    if (index != -1) {
        cout << "Neighbors of " << word << " :" << endl;
        for (int j = 0; j < NUM_OF_WORDS; j++) {
            if (isAdjacentTo(index, j)) // if j is adjacent to the word
            cout << indices.word(j) << endl; // print it
        }
    }
    else
        cout << "The word \"" << word << "\" does not exist in the graph" << endl;
}

/**
 * Use recursive BFS (Breadth First Search) to find
 * neighbours at max distance
 * @param word
 * @param distance
 */
void WordNetwork::listNeighbors(const string& word, int distance) {
    int index = indices.vertexIndex(word);
    if (index != -1) {
        cout << "Neighbors of " << word << " at distance " << distance << ":" << endl;
        bool* visited = new bool[NUM_OF_WORDS];
        for (int i = 0; i < NUM_OF_WORDS; i++)
            visited[i] = false;
        visited[index] = true;
        depthFirstTraversal(distance, index, visited);
        delete [] visited;
    }
    else
        cout << "The word \"" << word << "\" does not exist in the graph" << endl;
}

void WordNetwork::listConnectedComponents() {
    int count = 0;
    bool* visited = new bool[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++)
        visited[i] = false;
    for (int v = 0; v < NUM_OF_WORDS; v++) {
        if (!visited[v]) {
            count++;
            cout << "Connected component " << count << ":" << endl;
            depthFirstTraversal(v, visited);
        }
    }
    delete [] visited;
}

void WordNetwork::findShortestPath(const string& word1, const string& word2) {
    int a = indices.vertexIndex(word1);
    int b = indices.vertexIndex(word2);
    // use dijkstra's & prim's algorithm
    // to find the MST containing a
    if (a != -1 && b != -1) {
        cout << "Shortest path from " << word1 << " to " << word2 << ":" << endl;
        int* mst = getMST(a);
//        cout << "MST generated successfully" << endl;
//        displayArr<int>(mst, NUM_OF_WORDS);
        mstTrace(mst, b);
        delete [] mst;
    }
    else {
        if (a == -1)
            cout << "The word \"" << word1 << "\" does not exist in the graph" << endl;
        if (b == -1)
            cout << "The word \"" << word2 << "\" does not exist in the graph" << endl;
    }
}

bool WordNetwork::isAdjacentTo(int v, int u) {
    return adjMatrix[v][u] && adjMatrix[u][v];
}

void WordNetwork::addEdge(int vIndex, int uIndex) {
    adjMatrix[vIndex][uIndex] = 1; // undirected graph
    adjMatrix[uIndex][vIndex] = 1; // so both of them are adjacent to each other
}


/**
 * Perform DFT algorithm to find a connected component that contains v
 * @param dist
 * @param v
 * @param visited
 */
void WordNetwork::depthFirstTraversal(int v, bool *visited) {
    // 1 - Mark v as visited
    cout << indices.word(v) << endl;
    visited[v] = true;
    // 2 - for (each unvisited vertex u adjacent to v) {
    //      dft(u)
    for (int u = 0; u < NUM_OF_WORDS; u++) {
        if (isAdjacentTo(v, u) && !visited[u])
            depthFirstTraversal(u, visited);
    }
}

/**
 * Perform DFT algorithm to find the neighbours of v at distance K
 * If the graph has cycles, the ideal output may not be the case
 * @param dist
 * @param v
 * @param visited
 */
void WordNetwork::depthFirstTraversal(int distance, int v, bool *visited) {
    if (distance < 0)
        return;
    if (distance == 0)
        cout << indices.word(v) << endl;
    // 1 - Mark v as visited
    visited[v] = true;
    // 2 - for (each unvisited vertex u adjacent to v) {
    //      dft(u)
    for (int u = 0; u < NUM_OF_WORDS; u++) {
        if (isAdjacentTo(v, u) && !visited[u])
            depthFirstTraversal(distance - 1, u, visited);
    }
}

/**
 * Returns the array representation of the Minimal Spanning Tree
 * @param A
 * @return
 */
int* WordNetwork::getMST(int A) {
    // weight[i] holds the length of the shortest path from A to i
    // initialize all weight values to "infinity" == 0x7fff ffff
    int* weight = new int[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++)
        weight[i] = INT_MAX;
    weight[A] = 0; // distance from A to A is 0 by definition

    // Create a vertexSet, initially empty
    bool* vertexSet = new bool[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++)
        vertexSet[i] = false;

    // Create a set parent that contains the parent of v
    // to represent the minimal spanning tree of the graph
    // i.e. parent[v] will return the parent of v
    // parent[A] will return -1 since it's the root
    //
    // initialize all parent pointers to null
    int* parent = new int[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++)
        parent[i] = -1;

//    cout << "Initial testing of initialization" << endl;
//    cout << "Weight: ";
//    displayArr<int>(weight, NUM_OF_WORDS);
//    cout << "VertexSet: ";
//    displayArr<bool>(vertexSet, NUM_OF_WORDS);
//    cout << "MST: ";
//    displayArr<int>(parent, NUM_OF_WORDS);

    // Steps 1 through n
    for (int step = 1; step <= NUM_OF_WORDS; step++) {
        //  Find the smallest weight[v] s.t. v is not in vertexSet;
        int smallest = minDistance(weight, vertexSet);
//        cout << "Smallest: " << smallest << endl;
//        cout << "weight[smallest]: " << weight[smallest] << endl << endl;
        if (smallest == -1) break; // for a disconnected graph
        //  Add it to vertexSet;
        vertexSet[smallest] = true;
        for (int u = 0; u < NUM_OF_WORDS; u++) {// for all vertices u such that:
            if (!vertexSet[u] // not in the vertex set
                    && isAdjacentTo(u, smallest) // adjacent to the smallest
                    && weight[u] > weight[smallest] + adjMatrix[smallest][u]) // has a shorter path-sum
            {
//                cout << endl << "==ITERBEGIN" << endl;
//                cout << "smallest: " << smallest << endl;
//                cout << "weight[" << u << "]: " << weight[u] << endl;
//                cout << "weight[" << smallest << "]: " << weight[smallest] << endl;
//                cout << "u: " << u << endl;
//                cout << "parent[" << u << "]: " << parent[u] << endl;
                parent[u] = smallest; // parent of u is the smallest
                weight[u] = weight[smallest] + adjMatrix[smallest][u];
            }
        }

//        cout << "Step " << step << " ends: " << endl;
//        cout << "WEIGHTS: ";
//        displayArr<int>(weight, NUM_OF_WORDS);
//        cout << "MST: ";
//        displayArr<int>(parent, NUM_OF_WORDS);
//        cout << "VERTEX SET: " << endl;
//        for (int i = 0; i < NUM_OF_WORDS; i++) {
//            if (vertexSet[i])
//                cout << i << ", ";
//        }
//        cout << endl << endl;

    }
    delete [] vertexSet;
    delete [] weight;
    return parent;
}

/**
 * Find the vertex with minimum distance which is not
 * included in the vertex set yet
 * If the index is still -1, then it's concluded that entire
 * connected component is visited
 * @param weight
 * @param vertexSet
 * @return
 */
int WordNetwork::minDistance(const int* weight, const bool* vertexSet) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < NUM_OF_WORDS; v++) {
        if (!vertexSet[v] && weight[v] < min) {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}

void WordNetwork::mstTrace(int *mst, int b) {
    if (b != - 1) {
        mstTrace(mst, mst[b]);
        cout << indices.word(b) << endl;
    }
}
