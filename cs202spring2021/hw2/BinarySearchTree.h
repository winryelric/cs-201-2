/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Header file for BinarySearchTree
 */
#ifndef HW2_BINARYSEARCHTREE_H
#define HW2_BINARYSEARCHTREE_H
#include "NodeQ.h"
class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& copyTree);
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void levelorderTraverse();
    int span(const int a, const int b);
    void mirror();
private:
    using btn = BinaryTreeNode;
    btn* root;

    void destroyTree(btn*& node);
    void copyTree(btn*& target, btn*& source);
    int getHeight(btn*& node);
    int getNumberOfNodes(btn*& node);
    bool insert(btn*& node, const int& data);
    bool removeFind(btn*& node, const int& data);
    void removeNode(btn*& node);
    void processLeftmost(btn*& node, int &replacement);
    bool contains(btn*& node, const int& data);
    void preorderTraverse(btn*& node);
    void inorderTraverse(btn*& node);
    void postorderTraverse(btn*& node);
    void levelorderTraverse(btn*& node);
    int span(btn*& node, const int a, const int b);
    void mirror(btn*& node);
};
#endif
