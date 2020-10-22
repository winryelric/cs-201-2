/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Interface for Item class,
* which contains a string and the count of that string
*/
#ifndef __ITEM_H_
#define __ITEM_H_
#include <string>
using namespace std;

// string can be changed to any data type.
// For this assignment, we need strings because an n-gram
// has multiple characters, and therefore is a string.
typedef string KeyType;

// we also need another key type to store the count of the n-gram
typedef int CountType;

class Item {
public:
	Item(){} 
	Item(const KeyType& keyValue, const CountType& keyCount) 
        :searchKey(keyValue), count(keyCount) {}

	KeyType getKey() const {
		return searchKey;
	}

    CountType getCount() const {
        return count;
    }

    void incrCount() {
        count++;
    }

    void decrCount() {
        if (count > 0) count--;
    }
private:
	KeyType searchKey;
    CountType count;
};
#endif