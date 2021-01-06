/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Interface for n-gram tree class
*/
#ifndef __NGRAMTREE_H_
#define __NGRAMTREE_H_
#include "TreeNode.h"
#include "TreeException.h"

class NgramTree {
public :
    NgramTree();
    ~NgramTree();
    void addNgram (string ngram);
    int getTotalNgramCount ();
    bool isComplete ();
    bool isFull ();
    void generateTree(string fileName, int n);
private :
    TreeNode* root;

    void destroyTree(TreeNode*& treePtr);
    void insert(TreeNode*& treePtr, const TreeItem& newItem) throw(TreeException);
    void countNodes(TreeNode* treePtr, CountType& count);
    bool isNodeComplete(TreeNode* treePtr, int index_firstNode, int index_lastNode);
    bool isNodeFull(TreeNode* treePtr);
    void inorderTraverse();
    void inorder(TreeNode* treePtr);

    // Other BST functions, not used in hw2.cpp 
    void retrieve(KeyType searchKey, TreeNode* index) const throw(TreeException);
    void searchTreeDelete(KeyType searchKey) throw(TreeException);
    void deleteItem(TreeNode*& treePtr, KeyType searchKey) throw(TreeException);
    void deleteNode(TreeNode*& nodePtr);
    void processLeftmost(TreeNode*& nodePtr, TreeItem& item);

    // global friend prototype, << operator
    friend ostream& operator <<(ostream& out, NgramTree& tree);
};
#endif