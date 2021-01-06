/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Interface for the UniqueWord object
* which contains a word and its count (frequency)
*/
#ifndef __UNIQUEWORD_H_
#define __UNIQUEWORD_H_
#include <string>
#include <iostream>
using namespace std;

// Type for the unique word, string
typedef string Word;
// Type for the count of the word, integer
typedef int Frequency;

class UniqueWord {
public:
    UniqueWord()
        :word(""), count(0) {}

	UniqueWord(const Word& keyWord, const Frequency& keyCount = 1)
        :word(keyWord), count(keyCount) {}

	Word getWord() const {
		return word;
	}

    Frequency getCount() const {
        return count;
    }

    void incrCount() {
        count++;
    }

    void decrCount() {
        if (count > 0) count--;
    }

    UniqueWord& operator=(const UniqueWord& rhs) {
        if (this != &rhs) {
            word = rhs.word;
            count = rhs.count;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, UniqueWord& unqW) {
       out << unqW.word << " " << unqW.count;
       return out;
    }
private:
	Word word;
    Frequency count;
};
#endif