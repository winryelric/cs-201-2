/**
* Title: AVL Trees
* Author: Zubeyir Bodur
* ID: 21702382
* Assignment: 4
* Description: Interface for exceptions in
*/
#ifndef __TREEEXCEPTION_H_
#define __TREEEXCEPTION_H_
#include <string>
using namespace std;

class TreeException : public exception {

private:
    string msg;

public:
    // Override the what() function so that when the exception occurs
    // exception message 'msg' is returned
	virtual const char* what() const throw() {
	    return msg.c_str();
	}
    
	~TreeException() throw() {}

    // If an exception occurs, exception message will be set.
    TreeException(const string& message ="")
        :exception(), msg(message) {}
};
#endif