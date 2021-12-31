/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Implementation for NodeQ
 */
#include "NodeQ.h"

NodeQ::NodeQ() {
    front = nullptr;
}

NodeQ::~NodeQ() {
    while (!isEmpty())
        dequeue();
}

NodeQ::NodeQ(const NodeQ &queue) {
    QNode* thisCur = front = nullptr;
    for (QNode* cur = queue.front; cur != nullptr; cur = cur->next) {
        thisCur = new QNode;
        thisCur->data = cur->data;
        thisCur->next = nullptr;
        thisCur = thisCur->next;
    }
}

bool NodeQ::isEmpty() const {
    return !front;
}

int NodeQ::getSize() const {
    int size = 0;
    for (QNode* cur = front; cur != nullptr; cur = cur->next)
        size++;
    return size;
}

void NodeQ::enqueue(BinaryTreeNode* &item) {
    if (!front) {
        front = new QNode;
        front->data = item;
        front->next = nullptr;
    }
    else {
        QNode *back = front;
        while (back && back->next)
            back = back->next;
        back->next = new QNode;
        back->next->data = item;
        back->next->next = nullptr;
    }
}

BinaryTreeNode* NodeQ::dequeue() {
    QNode* tmp = front;
    front = front->next;
    BinaryTreeNode* data = tmp->data;
    delete tmp;
    tmp = nullptr;
    return data;
}

BinaryTreeNode* NodeQ::getFront() const {
    return front->data;
}
