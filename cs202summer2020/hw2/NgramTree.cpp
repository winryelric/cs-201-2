/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Implementation for n-gram tree class
*/
#include "NgramTree.h"
#include <iostream>
#include <fstream>

NgramTree::NgramTree() {
    root = NULL;
}

NgramTree::~NgramTree(){
    destroyTree(root);
}

void NgramTree::addNgram(string ngram) {
    KeyType word = ngram;
    CountType count = 1;
    TreeItem newItem(word, count);
    insert(root, newItem);
}

int NgramTree::getTotalNgramCount() {
    CountType count = 0;
    countNodes(root, count);
    return count;
}

bool NgramTree::isComplete() {
    int index_lastNode = getTotalNgramCount() - 1;
    isNodeComplete(root, 0, index_lastNode);
}

bool NgramTree::isFull() {
    isNodeFull(root);
}

void NgramTree::generateTree(string fileName, int n) {
    // We don't want the old ngrams in the tree
    if (root != NULL)
        destroyTree(root);

    // Turn fileName string into char*
    char* file_name = new char [fileName.length()];
    for(int i = 0; i < fileName.length(); i++)
        file_name[i] = fileName.at(i);

    ifstream file_(file_name);
    string line;
    if (file_.is_open() ) {
        // Take each line in the file
        // and iterate them
        while( getline(file_, line) ){
            string word = "";
            // Iterate each character in the line
            for (int i = 0; i < line.length(); i++){
                char c = line.at(i);
                bool isLetter = (c != ' ' & c != '\n' && c != '\r');
                if (isLetter && word.length() < n) {
                    // Start processing the word if c is a letter
                    // To make our tree case insensitive, we convert c to lowercase
                    c = tolower(c);
                    word += c;
                    if (word.length() == n) {
                        // If the word have reached n characters, add it to the tree
                        // Then, erase the first string of the word
                        addNgram(word);
                        word.erase(0,1);
                    }
                }
                // release the word if blankspace or end of the line is reached 
                else if ( !isLetter )
                    word = "";
            }
        }
        // Close the file and delete dynamic memory
        file_.close();
        delete [] file_name;
    }
}

ostream& operator <<(ostream& out, NgramTree& tree) {
    tree.inorderTraverse();
    return out;
}

void NgramTree::destroyTree(TreeNode*& treePtr) {
    if (treePtr != NULL) {
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

void NgramTree::insert(TreeNode*& treePtr, const TreeItem& newItem) throw(TreeException) {
    // The item position is found if a pointer of a leaf has been reached
	if (treePtr == NULL) { 
		treePtr = new TreeNode(newItem, NULL, NULL);
		if (treePtr == NULL)
			throw TreeException("TreeException: insert failed");
	}
	// Else search for the insertion position
	else if (newItem.getKey() < treePtr->item.getKey()) 
		insert(treePtr->leftChildPtr, newItem);
	else if (newItem.getKey() > treePtr->item.getKey())
		insert(treePtr->rightChildPtr, newItem);
    // If the item already exists, increase its count
    else
        treePtr->item.incrCount();
}

void NgramTree::countNodes(TreeNode* treePtr, CountType& count) {
    if (treePtr != NULL) {
			countNodes(treePtr->leftChildPtr, count);
			countNodes(treePtr->rightChildPtr, count);
            count += 1;
		}
}

// This function imidates the array representation of BST's. In the array representation of
// a binary tree, the left child of a node has index 2i + 1, and the right child has 2i + 2
// If the tree is not complete, the node that is on the lowest level will have an index 
// more than the number of nodes
bool NgramTree::isNodeComplete(TreeNode* treePtr, int index_firstNode, int index_lastNode) {
    if(root != NULL) {
        // The tree is not complete if index assigned to first node 
        // is larger than the number of nodes
        if(index_firstNode > index_lastNode) {
           return false; 
        }
        // In a complete BST, index of the left child 
        return isNodeComplete(treePtr->leftChildPtr, 2*index_firstNode + 1, index_lastNode)
            && isNodeComplete(treePtr->rightChildPtr, 2*index_firstNode + 2, index_lastNode);
    }
    // If tree is empty, it is complete
    return true;
}

// The function below can't guarentee the following full BST property,
// that all nodes are filled down to the level h
// But it ensures that all nodes have two children
// For example, the left subtree of a root can have height h-1 and the right subtree
// can have  height h-k while both subtrees are full BSTs.
bool NgramTree::isNodeFull(TreeNode* treePtr) {
    if (treePtr != NULL) {
        // A tree is a full BST if it has two children and the children are also full
        if (!treePtr->isLeaf()) {
            if (treePtr->hasTwoChildren()) {
                return isNodeFull(treePtr->leftChildPtr) && isNodeFull(treePtr->rightChildPtr);
            }
            // If one of the nodes in the tree has one child, it is not full.
            return false;
        }
        // If the tree is leaf, it is considered as full.
        return true;
    }
    return true;
}

void NgramTree::inorderTraverse() {
    inorder(root);
}

void NgramTree::inorder(TreeNode* treePtr) {
    if (treePtr != NULL) {
		inorder(treePtr->leftChildPtr);
		cout << "\"" << treePtr->item.getKey() << "\"" << " appears " << treePtr->item.getCount() << " time(s)" << endl;
		inorder(treePtr->rightChildPtr);
	}
}

// Below functions are all common member functions of BSTs but they are not used in hw2
// processLeftmost is a helper function for deletion operation

void NgramTree::retrieve(KeyType searchKey, TreeNode* index) 
                        const throw(TreeException) {
    // If the index is null, the search key doesn't exist
    // in the tree, else, it exists.
    if (index == NULL)
		throw TreeException("TreeException: searchKey not found");

	else if (searchKey < index->item.getKey())
		retrieve(searchKey, index->leftChildPtr);

	else if (searchKey > index->item.getKey())
		retrieve(searchKey, index->rightChildPtr);
}

void NgramTree::searchTreeDelete(KeyType searchKey) 
								throw(TreeException) {
		deleteItem(root, searchKey);
}

void NgramTree::deleteItem(TreeNode * &treePtr, KeyType searchKey)
								throw(TreeException) {
	if (treePtr == NULL) // Empty tree can't be deleted
		throw TreeException("Delete failed"); 
		
	// If the key is on the root node, delete the node
	else if (searchKey == treePtr->item.getKey())
		deleteNode(treePtr);

	// Else check the leftsubtree & right subtree
	else if (searchKey < treePtr->item.getKey())
		deleteItem(treePtr->leftChildPtr, searchKey);
	else
		deleteItem(treePtr->rightChildPtr, searchKey);
}

void NgramTree::deleteNode(TreeNode * &nodePtr) {
	TreeNode *delPtr;
	TreeItem replacementItem;

	// Case 1 == The node is a leaf
	if ( nodePtr->isLeaf() ) {
		delete nodePtr;
		nodePtr = NULL;
	}

    // Case 2 == Single child
	// no left child
	else if (nodePtr->leftChildPtr == NULL){
		delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; 
		delete delPtr;
	}
    // no right child
	else if (nodePtr->rightChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->leftChildPtr;
		delPtr->leftChildPtr = NULL; 
		delete delPtr;
	}

	// Case 3 == The node has two children
	else {
		processLeftmost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}
}

void NgramTree::processLeftmost(TreeNode *&nodePtr, 
						  TreeItem& treeItem) {

	if (nodePtr->leftChildPtr == NULL) {
		treeItem = nodePtr->item;
		TreeNode *delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;
		delete delPtr;
	}
	else
		processLeftmost(nodePtr->leftChildPtr, treeItem);
}



