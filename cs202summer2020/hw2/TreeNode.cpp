/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Implementation for tree node
*/
#include "TreeNode.h"

TreeNode::TreeNode(){}

TreeNode::~TreeNode() {
    if (leftChildPtr) delete leftChildPtr;
    if (rightChildPtr) delete rightChildPtr;
}

TreeNode::TreeNode(  const TreeItem& nodeItem,
                    TreeNode *left ,
                    TreeNode *right) {
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

bool TreeNode::isLeaf() {
    return leftChildPtr == NULL && rightChildPtr == NULL;
}

bool TreeNode::hasTwoChildren() {
    return leftChildPtr != NULL && rightChildPtr != NULL;
}