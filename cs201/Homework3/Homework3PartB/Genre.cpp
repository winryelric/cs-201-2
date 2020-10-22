#include "Genre.h"

Genre::Genre(const string gname) {
	genreName = gname;
	head = NULL;
}

Genre::~Genre() {
	removeAllBooks();
}

Genre::Genre(const Genre& genreToCopy) {
	genreName = genreToCopy.genreName;

	if (genreToCopy.head == NULL)
		head = NULL;
	else {
		// Copy the first item
		head = new BookNode;
		head->b = genreToCopy.head->b;

		// Copy the rest
		BookNode* newPtr = head;
		for (BookNode* origPtr = genreToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new BookNode;
			newPtr = newPtr->next;
			newPtr->b = origPtr->b;
		}
		newPtr->next = NULL;
	}
}

void Genre::operator=(const Genre& right) {
	if (this != &right) {
		removeAllBooks();
		genreName = right.genreName;

		if (right.head == NULL)
			head = NULL;
		else {
			head = new BookNode;
			head->b = right.head->b;

			// Copy the rest
			BookNode* newPtr = head;
			for (BookNode* origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
				newPtr->next = new BookNode;
				newPtr = newPtr->next;
				newPtr->b = origPtr->b;
			}
			newPtr->next = NULL;
		}
	}
}

string Genre::getGenreName() const {
	return genreName;
}

void Genre::setGenreName(const string gName) {
	genreName = gName;
}

bool Genre::addBook(const string bookName) {
	if (findBook(bookName) != NULL) {
		cout << "Book " << bookName << " already exists. Can't add that book again." << endl;
		return false;
	}
	/* Add to the beginning */
	else {
		// Initialize the node to add
		BookNode* newPtr = new BookNode;
		newPtr->b.setName(bookName);

		// Connect the new node with the rest of the list
		newPtr->next = head;
		// Make the first item the new node
		head = newPtr;
	}
	return true;
}

bool Genre::removeBook(const string bookName) {
	BookNode* cur = findBook(bookName);
	if (cur == NULL) {
		cout << "Book " << bookName << " doesn't exist. Can't remove something that already DNE." << endl;
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
		BookNode* prev = head;
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

bool Genre::addAuthor(const string bookName, const int id, const string name) {
	BookNode* cur = findBook(bookName);
	// If the book doesn't exist, return false
	if (cur == NULL) {
		cout << "Book " << bookName << " doesn't exist. Can't add author to a book that doesn't exist." << endl;
		return false;
	}
	// If the book exists and also author exists, return false
	// If the book exists but author doesn't, add author and return true
	return cur->b.addAuthor(id, name);
}

bool Genre::removeAuthor(const string bookName, const int id) {
	BookNode* cur = findBook(bookName);
	// If the book desn't exist, return false
	if (cur == NULL) {
		cout << "Book  " << bookName << " doesn't exist. Can't remove author from a book that doesn't exist." << endl;
		return false;
	}
	// If the book exists and also author exists, remove author and return true
	// If the book exists but author doesn't, return false
	return cur->b.removeAuthor(id);
}

void Genre::displayBooks() {
	if (head == NULL)
		cout << "--EMPTY--" << endl;
	else {
		for (BookNode* cur = head; cur != NULL; cur = cur->next)
			cout << cur->b;
	}
}

ostream& operator<<(ostream& out, const Genre& g)
{
	out << g.genreName << endl;
	for (Genre::BookNode* cur = g.head; cur != NULL; cur = cur->next)
		out << cur->b;
	return out;
}

void Genre::displayBooksWithAuthor(const int aID) {
	int numOfBooksPrinted = 0;
	string authName;
	for (BookNode* cur = head; cur != NULL; cur = cur->next) {
		if (cur->b.contains(aID, authName)) {
			if (numOfBooksPrinted == 0)
				cout << getGenreName() << endl;
			cout << "\t" << cur->b.getName() << endl;
			numOfBooksPrinted++;
		}
	}
}

string Genre::getAuthor(const int aID)
{
	string authName;
	for (BookNode* cur = head; cur != NULL; cur = cur->next) {
		if (cur->b.contains(aID, authName))
			return authName;
	}
	return authName;
}

Genre::BookNode* Genre::findBook(string bookName)
{
	for (BookNode* cur = head; cur != NULL; cur = cur->next) {
		string currentString = cur->b.getName();

		// If the sizes are equal, check each char
		if (currentString.size() == bookName.size()) {
			int size = currentString.size();
			int i = 0;
			while (i < size) {
				if (toupper((int)currentString.at(i)) != toupper((int)bookName.at(i)))
					break;
				i++;
			}
			// If all characters are checked and all of them were equal, the strings are same
			if (i == size)
				return cur;
		}
	}
	return NULL;
}

void Genre::removeAllBooks() {
	if (head != NULL) {
		while (head->next != NULL) {
			BookNode* cur = head;
			head = head->next;
			cur->next = NULL;
			delete cur;
		}
		delete head;
	}
}
