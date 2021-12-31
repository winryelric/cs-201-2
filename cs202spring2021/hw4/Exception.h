/**
 * Title : Balanced Search Trees , Hashing and Graphs
 * Author : Zubeyir Bodur
 * ID: 21702382
 * Section : 2
 * Assignment : 4
 * Description : Header file for HashTable
 */
#ifndef CODE_EXCEPTION_H_
#define CODE_EXCEPTION_H_
#include <string>
#include <utility>
using namespace std;

class Exception : public exception {

private:
    string msg;

public:
    const char* what() const noexcept override {
        return msg.c_str();
    }
    explicit Exception(string  message = "")
            : exception(), msg(std::move(message)) {};
    Exception(const Exception& e)
            : exception(), msg(e.msg) {};
    ~Exception() noexcept override = default;;

};
#endif
