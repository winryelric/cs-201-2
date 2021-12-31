/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Header file for a generic LinkedList
 */
#ifndef CODE_LINKEDLIST_H
#define CODE_LINKEDLIST_H
#include "Exception.h"
#include <iostream>
using namespace std;
template <typename Key, typename Item>
class LinkedList {
    friend ostream& operator<<(ostream& out, const LinkedList<Key, Item>& list) {
        list.display(out);
        return out;
    };
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<Key, Item>& list);
    void display() const;
    bool isEmpty() const;
    int getSize() const;
    Key getKeyAt(int index) const noexcept(false);
    Item getItemAt(int index) const noexcept(false);
    bool getItemFor(const Key &key, Item &out) const;
    bool getKeyFor(const Item& item, Key& out) const;
    void addHead(const Key &key, const Item &item);
    void addTail(const Key &key, const Item &item);
    int indexOf(const Key& key);
    bool removeHead();
    bool removeTail();
    bool remove(const Key& item);
    void destroyList();
private:
    /**
     * A Pair intended to map a key to an data
     */
    struct Pair {
        Key key;
        Item item;

        Pair(const Pair& copy) :key(copy.key), item(copy.item) {}
        Pair(const Key& key1, const Item& item1 ) :key(key1), item(item1) {}

        Pair &operator=(const Pair &rvalue) {
            if (this != &rvalue) {
                this->next = nullptr;
                this->data = rvalue.data;
            }
            return *this;
        }

        friend ostream& operator<<(ostream& out, const Pair& pair) {
            return out << pair.key << "-" << pair.item;
        };
    };
    /**
     * Nodes consist of pairs
     */
    struct Node{
        Node* next;
        Pair data;

        Node() :next(nullptr), data(NULL) {}
        Node(const Node& node) : next(nullptr), data(node.data) {}
        explicit Node(const Pair& item, Node* next = nullptr) : next(next), data(item) {}

        Node &operator=(const Node &rvalue) {
            if (this == &rvalue) // self assignment
                return *this;
            else {
                this->next = nullptr; // copy only the data, not the rest of the links
                this->data = rvalue.data;
            }
            return *this;
        }

        friend ostream& operator<<(ostream& out, const Node& node) {
            out << node.data;
            if (node.next != nullptr)
                out << " -> ";
            return out;
        };
    };

    Node* head;
    int size;

    void display(ostream& out) const;
    Node* getTail() const;
    Node* getAddr(int index) const;
};
#endif
