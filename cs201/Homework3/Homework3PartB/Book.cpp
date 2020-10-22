#include "Book.h"

Book::Book(){
	name = "";
	head = NULL;
}

Book::Book(const string name) {
	this->name = name;
	head = NULL;
}

Book::~Book() {
	removeAllAuthors();
}

Book::Book(const Book& bookToCopy) {
	name = bookToCopy.name;

	if (bookToCopy.head == NULL)
		head = NULL;
	else {
		// Copy the first item
		head = new AuthorNode;
		head->a = bookToCopy.head->a;

		// Copy the rest
		AuthorNode* newPtr = head;
		for (AuthorNode* origPtr = bookToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new AuthorNode;
			newPtr = newPtr->next;
			newPtr->a = origPtr->a;
		}
		newPtr->next = NULL;
	}
}

void Book::operator=(const Book& right) {
	if (this == &right) {
		// Delete the items of lhs first
		removeAllAuthors();

		// Copy properties
		name = right.name;

		// If the rhs is empty
		if (right.head == NULL)
			head = NULL;
		// Else copy the list
		else {
			// Copy the first item
			head = new AuthorNode;
			head->a = right.head->a;

			// Copy the rest
			AuthorNode* newPtr = head;
			for (AuthorNode* origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
				newPtr->next = new AuthorNode;
				newPtr = newPtr->next;
				newPtr->a = origPtr->a;
			}
			newPtr->next = NULL;
		}
	}
}

string Book::getName() const
{
	return name;
}

void Book::setName(const string bookName) {
	name = bookName;
}

bool Book::addAuthor(const int id, const string name) {
	if (findAuthor(id) != NULL) {
		cout << "Author with id " << id << " already exists. Adding failed." << endl;
		return false;
	}
	/* Add to the beginning */
	else {
		// Initialize the node to add
		AuthorNode* newPtr = new AuthorNode;
		newPtr->a.setID(id);
		newPtr->a.setName(name);

		// Connect the new node with the rest of the list
		newPtr->next = head;
		// Make the first item the new node
		head = newPtr;
	}
	return true;
}

bool Book::removeAuthor(const int id) {
	AuthorNode* cur = findAuthor(id);
	if (cur == NULL) {
		cout << "Author with id " << id << " doesn't exist. Removing failed." << endl;
		return false;
	}
	else if (cur == head) {
		/*If the item is the first item*/
		head = head->next;
		delete cur;
		return true;
	}
	else {
		// Find the item before the item to be deleted
		AuthorNode* prev = head;
		while (prev->next != cur)
			prev = prev->next;

		// Connect the prev to the the item after the item to be deleted
		prev->next = cur->next;

		//Delete everything about cur
		cur->next = NULL;
		delete cur;
		return true;
	}
}

void Book::displayAuthors() const {
	if (head == NULL)
		cout << "--EMPTY--" << endl;
	else {
		for (AuthorNode* cur = head; cur != NULL; cur = cur->next) 
			cout << cur->a << endl;
	}
}

ostream& operator<<(ostream& out, const Book& b)
{
	out << b.getName() << endl;
	for (Book::AuthorNode* cur = b.head; cur != NULL; cur = cur->next)
		out << "\t" << cur->a << endl;
	return out;
}

bool Book::contains(const int authorID, string& aName)
{
	for (AuthorNode* cur = head; cur != NULL; cur = cur->next) {
		if (cur->a.getID() == authorID) {
			aName = cur->a.getName();
			return true;
		}
	}
	aName = "";
	return false;
}

Book::AuthorNode* Book::findAuthor(int id)
{
	for (AuthorNode* cur = head; cur != NULL; cur = cur->next) {
		if (cur->a.getID() == id)
			return cur;
	}
	return NULL;
}

void Book::removeAllAuthors() {
	if (head != NULL) {
		while (head->next != NULL) {
			AuthorNode* cur = head;
			head = head->next;
			cur->next = NULL;
			delete cur;
		}
		delete head;
	}
}

