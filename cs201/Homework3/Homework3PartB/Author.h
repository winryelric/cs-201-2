#ifndef __AUTHOR_H
#define __AUTHOR_H

#include <string>
#include <iostream>
using namespace std;

class Author {
public:
	Author();
	Author(const int id, const string name);
	int getID() const;
	void setID(const int id);
	string getName() const;
	void setName(const string name);
	// Additionals
	void operator=(const Author& right);
	friend ostream& operator<<(ostream& out, const Author& a);
	// End of aditionals
private:
	string name;
	int id;
};
#endif