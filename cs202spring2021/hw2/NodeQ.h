/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Header file for NodeQ
 */
#ifndef HW2_NODEQ_H
#define HW2_NODEQ_H
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
class NodeQ {
public:
    NodeQ();
    ~NodeQ();
    NodeQ(const NodeQ& queue);
    bool isEmpty() const;
    int getSize() const;
    void enqueue(BinaryTreeNode*& item);
    BinaryTreeNode* dequeue();
    BinaryTreeNode* getFront() const;
private:
    struct QNode {
        QNode* next;
        BinaryTreeNode* data;
    };
    QNode* front;
};
#endif
