/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Implementation for BinaryTreeNode
 */
#include "BinaryTreeNode.h"
BinaryTreeNode::BinaryTreeNode() {
    data = -1;
    left = right = nullptr;
}

BinaryTreeNode::BinaryTreeNode(const int &data, BinaryTreeNode::btn *left, BinaryTreeNode::btn *right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

bool BinaryTreeNode::isLeaf() {
    return !left && !right;
}

bool BinaryTreeNode::isRightOnly() {
    return !left && right;
}

bool BinaryTreeNode::isLeftOnly() {
    return left && !right;
}

bool BinaryTreeNode::hasTwoChildren() {
    return left && right;
}

int BinaryTreeNode::getData() {
    return data;
}
