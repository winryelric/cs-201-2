#include "Author.h"

Author::Author() {
	id = 0;
	name = "";
}

Author::Author(const int id, const string name) {
	this->id = id;
	this->name = name;
}

int Author::getID() const {
	return id;
}

void Author::setID(const int id) {
	this->id = id;
}

string Author::getName() const {
	return name;
}

void Author::setName(const string name) {
	this->name = name;
}

void Author::operator=(const Author& right) {
	if (this != &right) {
		id = right.id;
		name = right.name;
	}
}

ostream& operator<<(ostream& out, const Author& a)
{
	out << a.getID() << ", " << a.getName();
	return out;
}