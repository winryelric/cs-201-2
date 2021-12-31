/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Source file for a generic LinkedList
 */
#include "LinkedList.h"

template<typename Key, typename Item>
LinkedList<Key, Item>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<typename Key, typename Item>
LinkedList<Key, Item>::~LinkedList() {
    destroyList();
}

/**
 * Copy constructor
 * Complexity: O(n^2)
 * @tparam T
 * @param list
 */
template<typename Key, typename Item>
LinkedList<Key, Item>::LinkedList(const LinkedList<Key, Item> &list) {
    head = nullptr;
    size = 0;
    if (!list.isEmpty()) {
        for (Node* cur = list.head; cur != nullptr; cur = cur->next)
            addTail(cur->data.key, cur->data.item);
    }
}

/**
 * Display LL iteratively
 * @tparam T
 */
template<typename Key, typename Item>
void LinkedList<Key, Item>::display() const {
    display(cout);
    cout << endl;
}

/**
 * Check if LL is empty
 * @tparam T
 * @return true if head is nullptr
 */
template<typename Key, typename Item>
bool LinkedList<Key, Item>::isEmpty() const {
    return (head == nullptr) && (size == 0);
}

template<typename Key, typename Item>
int LinkedList<Key, Item>::getSize() const {
    return size;
}

/**
 * Gets the data at given index
 * @tparam T
 * @param index
 * @return the value at index
 */
template<typename Key, typename Item>
Key LinkedList<Key, Item>::getKeyAt(int index) const noexcept(false) {
    Node* addr = getAddr(index);
    if (addr == nullptr) {
        throw Exception("OutOfBoundsException");
    }
    else {
        return addr->data.key;
    }
}

/**
 * Gets the data at given index
 * @tparam T
 * @param index
 * @return the value at index
 */
template<typename Key, typename Item>
Item LinkedList<Key, Item>::getItemAt(int index) const noexcept(false) {
    Node* addr = getAddr(index);
    if (addr == nullptr) {
        throw Exception("OutOfBoundsException");
    }
    else {
        return addr->data.item;
    }
}

template<typename Key, typename Item>
bool LinkedList<Key, Item>::getItemFor(const Key &key, Item &out) const {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data.key == key) {
            out = cur->data.item;
            return true;
        }
    }
    return false;
}

template<typename Key, typename Item>
bool LinkedList<Key, Item>::getKeyFor(const Item& item, Key& out) const {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data.item == item) {
            out = cur->data.key;
            return true;
        }
    }
    return false;
}


/**
 * Insert data from the head Node
 * @tparam T Key type of the data
 * @param key data to be inserted
 * @return true in successful insertion
 */
template<typename Key, typename Item>
void LinkedList<Key, Item>::addHead(const Key &key, const Item &item) {
    if (head == nullptr)
        head = new Node( Pair(key, item) );
    else {
        Node* oldHead = head;
        head = new Node(Pair(key, item), oldHead);
    }
    size++;
}

/**
 * Add an data to LL from its tail
 * Complexity: O(n)
 * @tparam T
 * @param item
 */
template<typename Key, typename Item>
void LinkedList<Key, Item>::addTail(const Key &key, const Item &item) {
    Node* tail = getTail();
    if (tail != nullptr) // if the list is not empty
        tail->next = new Node(Pair(key, item));
    else
        head = new Node(Pair(key, item));
    size++;
}

/**
 * Gets the index of the first occurrence of the data
 * @tparam T
 * @param key
 * @return
 */
template<typename Key, typename Item>
int LinkedList<Key, Item>::indexOf(const Key &key) {
    int index = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data.key == key)
            return index;
        index++;
    }
    return -1;
}

/**
 * Removes the head Node
 * @tparam T
 * @return
 */
template<typename Key, typename Item>
bool LinkedList<Key, Item>::removeHead() {
    if (head == nullptr)
        return false;
    else if (head->next == nullptr) {
        delete head;
        head = nullptr; // solve the dangling ptr problem
        size--;
        return true;
    }
    else {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }
}

template<typename Key, typename Item>
bool LinkedList<Key, Item>::removeTail() {
    if (size > 1) {
        Node* tailPrev = getAddr(size - 2);
        delete tailPrev->next;
        tailPrev->next = nullptr;
        size--;
        return true;
    }
    else
        return removeHead();
}

template<typename Key, typename Item>
bool LinkedList<Key, Item>::remove(const Key &item) {
    Node* cur_prev = nullptr;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->data.key == item) {
            if (cur == head) {
                head = head->next;
            }
            else {
                cur_prev->next = cur->next;
            }
            delete cur;
            cur = nullptr;
            return true;
        }
        cur_prev = cur;
    }
    return false;
}

template<typename Key, typename Item>
void LinkedList<Key, Item>::display(ostream &out) const {
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        out << *cur;
}

template<typename Key, typename Item>
typename LinkedList<Key, Item>::Node* LinkedList<Key, Item>::getTail() const {
    if (head == nullptr)
        return nullptr;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->next == nullptr)
            return cur;
    }
    return nullptr;
}

template<typename Key, typename Item>
typename LinkedList<Key, Item>::Node* LinkedList<Key, Item>::getAddr(int index) const {

    if (index < getSize() && index > -1) {
        Node* target = head;
        for (int i = 0; i < index; i++)
            target = target->next;
        return target;
    }
    return nullptr;
}

/**
 * Private function that deletes the LL
 * Complexity: O(n)
 * @tparam T
 */
template<typename Key, typename Item>
void LinkedList<Key, Item>::destroyList() {
    while (removeHead()) {}
}
