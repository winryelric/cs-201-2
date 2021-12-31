/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Header file for BinaryTreeNode
 */
#ifndef CODE_BINARYTREENODE_H
#define CODE_BINARYTREENODE_H
#include <cmath>
#include <iostream>
using namespace std;
class BinaryTreeNode {
public:
    bool isLeaf();
    bool isRightOnly();
    bool isLeftOnly();
    bool hasTwoChildren();
    int getData();
private:
    using btn = BinaryTreeNode;
    BinaryTreeNode();
    BinaryTreeNode(const int& data, btn* left = nullptr, btn* right = nullptr);
    int data;
    btn *left, *right;

    friend class BinarySearchTree;
};
#endif
