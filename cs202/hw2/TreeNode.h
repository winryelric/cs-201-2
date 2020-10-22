/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Interface for tree node
*/
#ifndef __TREENODE_H_
#define __TREENODE_H_
#include "Item.h"

// Define the type of the data in the node as
// "Item", which is a string with a count of it
// has get functions for both,
// count can be incremented&decremented
// but the string can't be changed
typedef Item TreeItem;

class TreeNode {
private:
    TreeNode();
    ~TreeNode();
    TreeNode(const TreeItem& nodeItem, TreeNode* left = NULL, TreeNode* right = NULL);

    bool isLeaf();
    bool hasTwoChildren();

    TreeItem item;
    TreeNode* leftChildPtr;
    TreeNode* rightChildPtr;
    
    friend class NgramTree;
};
#endif
