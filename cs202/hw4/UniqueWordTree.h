/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Interface for the AVL tree
*/
#ifndef __UNIQUEWORDTREE_H_
#define __UNIQUEWORDTREE_H_
#include "Node.h"
#include "TreeException.h"

class UniqueWordTree {
    public:
        UniqueWordTree();
        ~UniqueWordTree();
        void addWord(const string&);
        void generateTree(const char*&);
        void printHeight(ofstream&);
        void printTotalWordCount(ofstream&);
        void printWordFrequencies(ofstream&);
        void printLeastFrequent(ofstream&);
        void printMostFrequent(ofstream&);
        void printStandardDeviation(ofstream&);
    private:
        Node* root;

        // Private helper functions
        Node* addWord(Node*&, const Word&) throw(TreeException);
        int getTotalWordCount(Node*&);
        void printWordFrequencies(Node*&, ofstream&);
        Node* getLeastFrequent(Node*&);
        Node* getMostFrequent(Node*&);
        Node* lessFreq(Node*, Node*);
        Node* moreFreq(Node*, Node*);
        Frequency sumOfFrequencies(Node*&);
        double sumOfSquaredDifferences(Node*&, const double&);

        // AVL Tree operations
        int getHeight(Node*&);
        int getBalance(Node*&);
        Node* leftRotate(Node*&);
        Node* rightRotate(Node*&);
        void destroyTree(Node*&);
};
#endif