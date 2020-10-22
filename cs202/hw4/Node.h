/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Interface for the tree node
*/
#ifndef __NODE_H_
#define __NODE_H_
#include "UniqueWord.h"

class Node {
private:
    Node()
        :left(NULL), right(NULL){}

    ~Node(){
        if (left)  delete left;
        if (right) delete right;
    }

    Node(const UniqueWord& nodeWord, Node* leftPtr = NULL, Node* rightPtr = NULL) 
        : word(nodeWord), left(leftPtr), right(rightPtr) {}

    bool isLeaf() const{
        return (left == NULL) && (right == NULL);
    }

    bool hasTwoChildren() const{
        return (left != NULL) && (right != NULL);
    }

    // returns true if the node has only the left child
    bool hasLeftChild() const{
        return (left != NULL) && (right == NULL);
    }

    // returns true of the node gas only the right child
    bool hasRightChild() const{
        return (left == NULL) && (right != NULL);
    }

    UniqueWord word;
    Node* left;
    Node* right;
    
    friend class UniqueWordTree;
};
#endif
