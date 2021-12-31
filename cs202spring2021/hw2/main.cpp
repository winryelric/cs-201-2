/**
 * Title: Binary Search Trees
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Section: 2
 * Assignment: 2
 * Description: Main function
 */
#include "BinarySearchTree.h"
int main() {
    cout << endl << "BEGINNING OF BST TEST" << endl;
    BinarySearchTree searchTree;
    searchTree.inorderTraverse();
    searchTree.add(38);
    searchTree.inorderTraverse();
    searchTree.add(27);
    searchTree.inorderTraverse();
    searchTree.add(67);
    searchTree.inorderTraverse();
    searchTree.add(15);
    searchTree.inorderTraverse();
    searchTree.add(32);
    searchTree.inorderTraverse();
    searchTree.add(54);
    searchTree.inorderTraverse();
    searchTree.add(107);
    searchTree.inorderTraverse();
    cout << searchTree.add(19) << endl;// should remain after removals
    searchTree.inorderTraverse();
    searchTree.add(28);
    searchTree.inorderTraverse();
    searchTree.add(37);
    searchTree.inorderTraverse();
    searchTree.add(47);
    searchTree.inorderTraverse();
    searchTree.add(87);
    searchTree.inorderTraverse();
    searchTree.add(29);
    searchTree.inorderTraverse();
    searchTree.add(36);
    searchTree.inorderTraverse();
    searchTree.add(49);
    searchTree.inorderTraverse();
    searchTree.add(98);
    searchTree.inorderTraverse();
    searchTree.add(50); // should remain after removals
    searchTree.inorderTraverse();
    searchTree.add(91);
    cout << "is Empty ? : " << (searchTree.isEmpty() ? "Yes" : "No") << endl;
    cout << "size : " << searchTree.getNumberOfNodes() << endl;
    cout << "height: " << searchTree.getHeight() << endl;
    cout << "contains 98? : " << (searchTree.contains(98) ? "Yes" : "No") << endl;;
    cout << "contains 1000? : " << (searchTree.contains(1000) ? "Yes" : "No") << endl;
    cout << "span 30-40 : " << searchTree.span(30, 40) << endl;
    cout << "after one call to mirror(): ";
    searchTree.mirror();
    searchTree.levelorderTraverse();
    cout << "after two calls to mirror(): ";
    searchTree.mirror();
    searchTree.levelorderTraverse();
    cout << "END OF INSERTION" << endl << endl;
    searchTree.levelorderTraverse();
    cout << endl;
    searchTree.inorderTraverse();
    searchTree.remove(38);
    searchTree.inorderTraverse();
    searchTree.remove(67);
    searchTree.inorderTraverse();
    searchTree.remove(107);
    searchTree.inorderTraverse();
    searchTree.remove(29);
    searchTree.inorderTraverse();
    searchTree.remove(15);
    searchTree.inorderTraverse();
    searchTree.remove(87);
    searchTree.inorderTraverse();
    searchTree.remove(54);
    searchTree.inorderTraverse();
    searchTree.remove(49);
    searchTree.inorderTraverse();
    cout << searchTree.remove(59) << endl; // should be no change
    searchTree.inorderTraverse();
    searchTree.remove(47);
    searchTree.inorderTraverse();
    searchTree.remove(37);
    searchTree.inorderTraverse();
    searchTree.remove(36);
    searchTree.inorderTraverse();
    searchTree.remove(28);
    searchTree.inorderTraverse();
    searchTree.remove(91);
    searchTree.inorderTraverse();
    searchTree.remove(32);
    searchTree.inorderTraverse();
    searchTree.remove(27);
    searchTree.inorderTraverse();
    searchTree.remove(98);
    searchTree.inorderTraverse();
    cout << endl;
    cout << "END OF BST TEST" << endl;
}
