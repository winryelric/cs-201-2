/**
* Title: Trees
* Author: Zübeyir Bodur
* ID: 21702382
* Assignment: 2
* Description: Interface for exceptions in NgramTree class
*/
#ifndef __TREEEXCEPTION_H_
#define __TREEEXCEPTION_H_
#include <string>
using namespace std;

class TreeException : public exception {

private:
    string msg;

public:
	virtual const char* what() const throw() {
	    return msg.c_str();
	}
   TreeException(const string& message ="")
        :exception(), msg(message) {};
	~TreeException() throw() {};
};

#endif