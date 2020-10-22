#ifndef __GENRE_H
#define __GENRE_H

#include <string>
#include "Book.h"
using namespace std;

class Genre {
public:
	Genre(const string gname = "");
	~Genre();
	Genre(const Genre& genreToCopy);
	void operator=(const Genre& right);
	string getGenreName() const;
	void setGenreName(const string gName);
	bool addBook(const string bookName);
	bool removeBook(const string bookName);
	bool addAuthor(const string bookName, const int id, const string name);
	bool removeAuthor(const string bookName, const int id);
	void displayBooks();
	//Additionals
	friend ostream& operator<<(ostream& out, const Genre& g);
	void displayBooksWithAuthor(const int aID);
	string getAuthor(const int aID);
	//End of additionals
private:
	string genreName;
	struct BookNode {
		Book b;
		BookNode* next;
	};
	BookNode* head;
	BookNode* findBook(string bookName);
	void removeAllBooks(); // Additional auxilary function
};
#endif