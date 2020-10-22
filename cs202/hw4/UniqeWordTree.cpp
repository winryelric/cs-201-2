/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Implementation of the AVL tree
*/
#include "UniqueWordTree.h"
#include <fstream>
#include <cmath>

UniqueWordTree::UniqueWordTree(): root(NULL) {}

UniqueWordTree::~UniqueWordTree() {
    destroyTree(root);
}

// Adds the word to the tree
// TreeException is handled in this scope
void UniqueWordTree::UniqueWordTree::addWord(const Word& new_word) {
    try {
        root = addWord(root, new_word);
    } catch (const TreeException& tree_exc) {
        cout << tree_exc.what() << endl;
    }
}

// Generates a tree of the unique words in the file
void UniqueWordTree::generateTree(const char*& file_name) {
    // We don't want the old tree
    if (root != NULL)
        destroyTree(root);

    ifstream file(file_name);
    if ( file.is_open() ) {
        while( !file.eof() ) {
            // Get each string seperated by a blankspace or a new line
            Word unseperated_word;
            file >> unseperated_word;
            Word word = "";
            // Ignore punctuation and capitalization
            for (int i = 0; i < unseperated_word.length(); i++) {
                char c = unseperated_word.at(i);
                bool isLetter = (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
                // If c is a letter, it is a part of a word
                // Make the tree case insensitive
                if (isLetter) {
                    c = tolower(c);
                    word += c;
                }
                // if c is not a letter and size of the word is not zero
                // this means the unseperated word contains at leats one punctuation
                // at index != 0
                // add the word before the punctuation
                else if (word.length() > 0) {
                    addWord(word);
                    word = "";
                }
            }
            // The algorithm above will ignore the last unseperated word
            // as there is no detection if the skipped word is actually the last
            // Make the insertion for the last word in the unseperated word
            if (word.length() > 0)
                addWord(word);
        }
        file.close();
    }
}

// Prints height to the output file
void UniqueWordTree::printHeight(ofstream& out_file) {
    out_file << "Tree Height: " << getHeight(root) << endl;
}

// Prints the number of items in the tree to the output file
void UniqueWordTree::printTotalWordCount(ofstream& out_file) {
    out_file << "Total Word Count: " << getTotalWordCount(root) << endl;
}

// Prints the unique words with its frequencies in the input file 
// to the output file in alphabetical order
void UniqueWordTree::printWordFrequencies(ofstream& out_file) {
    printWordFrequencies(root, out_file);
}

// Prints the word with least count. If there are multiple words with least count,
// The last in alphabetical order is considered to be least frequent
void UniqueWordTree::printLeastFrequent(ofstream& out_file) {
    out_file << "Least Frequent: " << getLeastFrequent(root)->word << endl;
}

// Prints the word with least count. If there are multiple words with least count,
// The last in alphabetical order is considered to be most frequent
void UniqueWordTree::printMostFrequent(ofstream& out_file) {
    out_file << "Most Frequent: " << getMostFrequent(root)->word << endl;
}

// Standard deviation is defined as the following:
//    _________________		The numerator is calculated
//    |				in sumOfSquaredDifferences.
// _  | Σ(x_i - mean)^2		N, number of items is also 
//  \ | ==============		calculated in getTotalWordCount.
//   \|       N
void UniqueWordTree::printStandardDeviation(ofstream& out_file) {
    int wordCount = getTotalWordCount(root);
    double mean = (double)sumOfFrequencies(root) / wordCount;
    out_file << "Standrad Deviation: " << sqrt( (sumOfSquaredDifferences(root, mean) ) / wordCount);
}

// Private helper functions

// Function performing the AVL Tree insertion operation
// Apart from the standard AVL Tree insertion,
// it adds 1 to the item's count if it already exists
Node* UniqueWordTree::addWord(Node*& node, const Word& new_word) throw(TreeException) {
    // Insert to the proper position
    if (node == NULL)  {
        UniqueWord temp(new_word);
        Node* new_node = new Node(temp);
        if (new_node == NULL) 
            throw TreeException("TreeException: Insertion of \"" + new_word + "\" failed.");
        return new_node;  
    }
    // Find the insertion position recursively
    else if (new_word < node->word.getWord())
        node->left = addWord(node->left, new_word);
    else if (new_word > node->word.getWord())
            node->right = addWord(node->right, new_word);
    else
        node->word.incrCount(); // the word appeared again, add 1 to its count

    // Perform the proper rotation on the "place" of the insertion

    int balance = getBalance(node); // compute the balance factor
   
    // Left Left Case = Single Right Rotate 
    if (balance > 1 && new_word < node->left->word.getWord())
        return rightRotate(node);  
   
    // Right Right Case = Single Left Rotate 
    if (balance < -1 && new_word > node->right->word.getWord())
        return leftRotate(node);

    // Left Right Case  = Double Left-Right Rotate
    if (balance > 1 && new_word > node->left->word.getWord()) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
   
    // Right Left Case  = Double Right-Left Rotate
    if (balance < -1 && new_word < node->right->word.getWord()) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }
    return node;
}


// Recursive private function that returns the number of items in the tree
int UniqueWordTree::getTotalWordCount(Node*& node) {
    if (node == NULL)
        return 0;
    else if (node->isLeaf())
        return 1;
    else
        return getTotalWordCount(node->left) + 1 + getTotalWordCount(node->right);
}

// Recursive private function that prints the words and their frequencies to the output file
void UniqueWordTree::printWordFrequencies(Node*& node, ofstream& out_file) {
    if (node != NULL) {
        if (node->isLeaf())
            out_file << node->word << endl;
        else {
            printWordFrequencies(node->left, out_file);
            out_file << node->word << endl;
            printWordFrequencies(node->right, out_file);
        }
    }
}

// Recursive private function that gets the least frequent word in the tree
Node* UniqueWordTree::getLeastFrequent(Node*& node) {
    if (node == NULL)
        return NULL;
    else if (node->isLeaf())
        return node;
    else
        // Minimum element of a binary tree can be defined recursively as
        // min_t = min (root, min(left_st, right_st))
        return lessFreq( node, 
                lessFreq( getLeastFrequent(node->left), getLeastFrequent(node->right) ) );
}

// Recursive private function that gets the most frequent word in the tree
Node* UniqueWordTree::getMostFrequent(Node*& node) {
    if (node == NULL)
        return NULL;
    else if (node->isLeaf())
        return node;
    else
        // Maximum element of a binary tree can be defined recursively as
        // max_t = max (root, max(left_st, right_st))
        return moreFreq( node, 
                moreFreq( getMostFrequent(node->left), getMostFrequent(node->right) ) );
}

// Helper function that gets the less frequent node out of given nodes
Node* UniqueWordTree::lessFreq(Node* node1, Node* node2) {
    // return null if both are null
    if (node1 == NULL && node2 == NULL)
        return NULL;
    // If one of the nodes being compared is null
    // return the one that is not null
    else if ( (node1 != NULL) != (node2 != NULL) )
        return (node1 != NULL) ? node1 : node2;
    // If both are not null
    // return the one w/ less count
    else
        // If frequencies are equal, return node2
        return (node1->word.getCount() < node2->word.getCount()) ? node1 : node2;
}

// Helper function that gets the more frequent node out of given nodes
Node* UniqueWordTree::moreFreq(Node* node1, Node* node2) {
    // return null if both are null
    if (node1 == NULL && node2 == NULL)
        return NULL;
    // If one of the nodes being compared is null
    // return the one that is not null
    else if ( (node1 != NULL) != (node2 != NULL) )
        return (node1 != NULL) ? node1 : node2;
    // If both are not null
    // return the one w/ more count
    else
        // If frequencies are equal, return node2
        return (node1->word.getCount() > node2->word.getCount()) ? node1 : node2;
}

// Helper function that computes sum of frequencies of nodes
Frequency UniqueWordTree::sumOfFrequencies(Node*& node) {
    if (node == NULL)
        return 0;
    else if (node->isLeaf())
        return node->word.getCount();
    else
        return sumOfFrequencies(node->left) + sumOfFrequencies(node->right) + node->word.getCount();
}

// Helper function that calculates (x_i - mean)^2 with given mean
double UniqueWordTree::sumOfSquaredDifferences(Node*& node, const double& mean) {
    if (node == NULL)
        return 0;
    else if (node->isLeaf())
        return pow((node->word.getCount() - mean), 2);
    else
        return sumOfSquaredDifferences(node->left, mean) + sumOfSquaredDifferences(node->right, mean) + pow((node->word.getCount() - mean), 2);
}

// AVL Tree Operations

// Gets the height of a tree with the root called 'node'
int UniqueWordTree::getHeight(Node*& node) {
    if (node == NULL)
        return 0;
    else if (node->isLeaf())
        return 1;
    else {
        // The height of a node is defined as H = 1 + max(H_lst, H_rst);
        return 1 + (int)fmax(getHeight(node->left), getHeight(node->right));
    }
}

// Gets the height difference between leftsubtree & right subtree
// If difference is larger than 1, it is left-high
// If difference is smaller than -1, it is right-high
// Else, it is balanced
int UniqueWordTree::getBalance(Node*& node) {
    if (node != NULL)
        return getHeight(node->left) - getHeight(node->right);
    else
        return 0;
}

// Performs left rotate operation on the tree with root 'node'
Node* UniqueWordTree::leftRotate(Node*& node) {
    Node* right_st = node->right;  
    Node* left_st_of_right_st = right_st->left;

    // Left rotate the root
    // Right subtree becomes the new root,
    //
    // with the old root becoming the left sub tree of the new root
    //
    // left sub tree of the old right sub tree becomes
    // the right subtree of the old root
    right_st->left = node;  
    node->right = left_st_of_right_st;
    return right_st; // return the new root
}

// Performs right rotate operation on the tree with root 'node'
Node* UniqueWordTree::rightRotate(Node*& node) {
    Node* left_st = node->left;  
    Node* right_st_of_left_st = left_st->right;

    // Right rotate the root
    // Left subtree becomes the new root,
    //
    // with the old root becoming the right sub tree of the new root
    //
    // right sub tree of the old left sub tree becomes
    // the left subtree of the old root
    left_st->right = node;  
    node->left = right_st_of_left_st;
    return left_st; // return the new root
}

// Private helper function that deletes the tree with root 'node', used in destructor
void UniqueWordTree::destroyTree(Node*& node) {
    if (node != NULL) {
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
		node = NULL;
	}
}
