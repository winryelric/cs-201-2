/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Implementation for BinarySearchTree
 */
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &copy) {
    root = nullptr;
    btn* tmp = copy.root;
    copyTree(root, tmp);
}

bool BinarySearchTree::isEmpty() {
    return !root;
}

int BinarySearchTree::getHeight() {
    return getHeight(root);
}

int BinarySearchTree::getNumberOfNodes() {
    return getNumberOfNodes(root);
}

bool BinarySearchTree::add(const int newEntry) {
    return insert(root, newEntry);
}

bool BinarySearchTree::remove(const int anEntry) {
    return removeFind(root, anEntry);
}

bool BinarySearchTree::contains(const int anEntry) {
    return contains(root, anEntry);
}

void BinarySearchTree::preorderTraverse() {
    preorderTraverse(root);
    cout << endl;
}

void BinarySearchTree::inorderTraverse() {
    inorderTraverse(root);
    cout << endl;
}

void BinarySearchTree::postorderTraverse() {
    postorderTraverse(root);
    cout << endl;
}

void BinarySearchTree::levelorderTraverse() {
    levelorderTraverse(root);
    cout << endl;
}

int BinarySearchTree::span(const int a, const int b) {
    return span(root, a, b);
}

void BinarySearchTree::mirror() {
    return mirror(root);
}

void BinarySearchTree::destroyTree(btn *&node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}

void BinarySearchTree::copyTree(btn *&target, btn *&source) {
    if (source != nullptr) {
        target = new btn(source->data);
        copyTree(target->left, source->left);
        copyTree(target->right, source->right);
    }
}

int BinarySearchTree::getHeight(btn *&node) {
    if (!node)
        return 0;
    else
        return 1 + max(getHeight(node->left), getHeight(node->right));
}

int BinarySearchTree::getNumberOfNodes(btn *&node) {
    if (!node)
        return 0;
    else if (node->isLeaf())
        return 1;
    else
        return getNumberOfNodes(node->left) + 1 + getNumberOfNodes(node->right);
}

bool BinarySearchTree::insert(btn *&node, const int &data) {
    if (!node) {
        node = new btn(data);
        return true;
    }
    else if (data < node->data)
        return insert(node->left, data);
    else if (data > node->data)
        return insert(node->right, data);
    else
        return false; // return false if the item already exists
}

bool BinarySearchTree::removeFind(btn *&node, const int &data) {
    if (node) {
        if (data < node->data)
            removeFind(node->left, data);
        else if (data > node->data)
            removeFind(node->right, data);
        else {
            removeNode(node);
            return true;
        }
    }
    return false; // return false if the node doesn't exist
}

void BinarySearchTree::removeNode(btn *&node) {
    BinaryTreeNode* tmp;
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    }
    else if (node->left != nullptr && node->right == nullptr) {
        tmp = node->left;
        delete node;
        node = tmp;
    }
    else if (node->left == nullptr && node->right != nullptr) {
        tmp = node->right;
        delete node;
        node = tmp;
    }
    else {
        int replacementItem;
        processLeftmost(node->right, replacementItem);
        node->data = replacementItem;
    }
}

void BinarySearchTree::processLeftmost(btn *&node, int &replacement) {
    if (node->left == nullptr) {
        replacement = node->data;
        BinaryTreeNode *delPtr = node;
        node = node->right;
        delPtr->right = nullptr;
        delete delPtr;
        delPtr = nullptr;
    }
    else
        processLeftmost(node->left, replacement);
}

bool BinarySearchTree::contains(btn *&node, const int &data) {
    if (node) {
        if (data < node->data)
            return contains(node->left, data);
        else if (data > node->data)
            return contains(node->right, data);
        else
            return true;
    }
    return false;
}

void BinarySearchTree::preorderTraverse(btn *&node) {
    if (node) {
        cout << node->data << " ";
        preorderTraverse(node->left);
        preorderTraverse(node->right);
    }
}

void BinarySearchTree::inorderTraverse(btn *&node) {
    if (node) {
        inorderTraverse(node->left);
        cout << node->data << " ";
        inorderTraverse(node->right);
    }
}

void BinarySearchTree::postorderTraverse(btn *&node) {
    if (node) {
        postorderTraverse(node->left);
        postorderTraverse(node->right);
        cout << node->data << " ";
    }
}

/**
 * Print the tree in level order traversal
 * Using Iterative Breadth First Traversal
 * @param node
 */
void BinarySearchTree::levelorderTraverse(btn *&node) {
    NodeQ queue;
    // set the root as the starting point
    if (node)
        queue.enqueue(node);
    while (!queue.isEmpty()) {
        // uncomment these to print the levels in a seperate line
        //int size = queue.getSize();
        //while (size > 0) {
            // mark tmp as visited
            BinaryTreeNode* tmp = queue.dequeue();
            cout << tmp->data << " ";
            // visit tmp's children
            if (tmp->left)
                queue.enqueue(tmp->left);
            if (tmp->right)
                queue.enqueue(tmp->right);
        //    size--;
        //}
        //cout << endl;
    }
}

int BinarySearchTree::span(btn *&node, const int a, const int b) {
    if (node) {
        int left = 0, right = 0;
        if (node->data < b)
            right = span(node->right, a, b);
        if (node->data > a)
            left = span(node->left, a, b);
        return left + right + ( (node->data >= a && node->data <= b) ? 1 : 0);
    }
    return 0;
}

void BinarySearchTree::mirror(btn *&node) {
    if (node) {
        btn* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        mirror(node->left);
        mirror(node->right);
    }
}
