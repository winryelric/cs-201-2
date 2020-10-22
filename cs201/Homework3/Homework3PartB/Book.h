#ifndef __BOOK_H
#define __BOOK_H

#include <string>
using namespace std;
#include "Author.h"

class Book {
public:
	Book();
	Book(const string name);
	~Book();
	Book(const Book& bookToCopy);
	void operator=(const Book& right);
	string getName() const;
	void setName(const string bookName);
	bool addAuthor(const int id, const string name);
	bool removeAuthor(const int id);
	void displayAuthors() const;
	// Additionals
	friend ostream& operator<<(ostream& out, const Book& b);
	bool contains(const int authorID, string& aName);
	// End of additionals
private:
	struct AuthorNode {
		Author a;
		AuthorNode* next;
	};
	AuthorNode* head;
	string name;
	AuthorNode* findAuthor(int id);
	void removeAllAuthors(); // Additional auxilary function
};
#endif