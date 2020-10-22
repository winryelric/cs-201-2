#include "BookCollection.h"

BookCollection::BookCollection() {
	genreCount = 0;
	head = NULL;
}

BookCollection::~BookCollection( ) {
	removeAllGenres();
}

BookCollection::BookCollection(const BookCollection& bcToCopy) {
	genreCount = bcToCopy.genreCount;

	if (genreCount == 0)
		head = NULL;
	else {
		// Copy the first item
		head = new GenreNode;
		head->g = bcToCopy.head->g;

		// Copy the rest
		GenreNode* newPtr = head;
		for (GenreNode* origPtr = bcToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new GenreNode;
			newPtr = newPtr->next;
			newPtr->g = origPtr->g;
		}
		newPtr->next = NULL;
	}
}

void BookCollection::operator=(const BookCollection& right) {
	if (this != &right) {
		removeAllGenres();

		genreCount = right.genreCount;

		if (genreCount == 0)
			head = NULL;
		else {
			// Copy the first item
			head = new GenreNode;
			head->g = right.head->g;

			// Copy the rest
			GenreNode* newPtr = head;
			for (GenreNode* origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
				newPtr->next = new GenreNode;
				newPtr = newPtr->next;
				newPtr->g = origPtr->g;
			}
			newPtr->next = NULL;
		}
	}
}

void BookCollection::addGenre(string genreName) {
	if (findGenre(genreName) != NULL) {
		cout << "Genre " << genreName << " already exists." << endl;
	}
	/* Add to the beginning */
	else {
		// Initialize the node to add
		GenreNode* newPtr = new GenreNode;
		newPtr->g.setGenreName(genreName);

		// Connect the new node with the rest of the list
		newPtr->next = head;
		// Make the first item the new node
		head = newPtr;

		genreCount++;
	}
}

void BookCollection::removeGenre(string genreName) {
	GenreNode* cur = findGenre(genreName);
	if (cur == NULL) {
		cout << "Genre " << genreName << " doesn't exist." << endl;
	}
	else if (cur == head) {
		/*If the item is the first item*/
		head = head->next;
		delete cur;
		genreCount--;
	}
	else {
		// Find the item before the item to be deleted
		GenreNode* prev = head;
		while (prev->next != cur)
			prev = prev->next;

		// Connect the prev to the the item after the item to be deleted
		prev->next = cur->next;

		//Delete everything about cur
		cur->next = NULL;
		delete cur;

		genreCount--;
	}
}

void BookCollection::displayAllGenres() const {
	for (GenreNode* cur = head; cur != NULL; cur = cur->next)
		cout << cur->g.getGenreName() << endl;
}

void BookCollection::addBook(string genreName, string bookName) {
	// Add only if genre exists and book doesn't exist
	GenreNode* cur = findGenre(genreName);
	if (cur != NULL)
		cur->g.addBook(bookName);
	else
		cout << "Genre " << genreName << " doesn't exist. Can't add that book to a nonexistent genre." << endl;
}

void BookCollection::removeBook(string genreName, string bookName) {
	// Remove only if genre and book exists
	GenreNode* cur = findGenre(genreName);
	if (cur != NULL)
		cur->g.removeBook(bookName);
	else
		cout << "Genre " << genreName << " doesn't exist. Can't remove that book from a nonexistent genre." << endl;
}

void BookCollection::addAuthor(string genreName, string bookName, int authorID, string authorName) {
	// Add only if genre and book exists, but author doesn't
	GenreNode* cur = findGenre(genreName);
	if (cur != NULL)
		cur->g.addAuthor(bookName, authorID, authorName);
	else
		cout << "Genre " << genreName << " doesn't exist. Can't add that auhtor to a book of a nonexistent genre." << endl;
}

void BookCollection::removeAuthor(string genreName, string bookName, int authorID) {
	// Remove only if all of them exist
	GenreNode* cur = findGenre(genreName);
	if (cur != NULL)
		cur->g.removeAuthor(bookName, authorID);
	else
		cout << "Genre " << genreName << " doesn't exist. Can't remove that auhtor from a book of a nonexistent genre." << endl;
}

void BookCollection::displayGenre(string genreName) {
	if (findGenre(genreName) != NULL)
		cout << findGenre(genreName)->g;
	else
		cout << "--EMPTY--" << endl;
}

void BookCollection::displayAuthor(int authorID) {
	string authorName;
	// Search through the 3-D LL if the author exists
	for (GenreNode* cur = head; cur != NULL; cur = cur->next) {
		if (cur->g.getAuthor(authorID) != "")
			authorName = cur->g.getAuthor(authorID);
}
	// If the author doesn't exist, print empty and return
	if (authorName == "")
		cout << "--EMPTY--" << endl;
	// If the author exists, print it.
	else {
		cout << authorID << ", " << authorName << endl;
		// Search each Genre (displayBooksWithAuthor(id) function?)
		for (GenreNode* cur = head; cur != NULL; cur = cur->next)
			cur->g.displayBooksWithAuthor(authorID);
	}
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName)
{
	for (GenreNode* cur = head; cur != NULL; cur = cur->next) {
		string currentString = cur->g.getGenreName();

		// If the sizes are equal, check each char
		if (currentString.size() == genreName.size()) {
			int size = currentString.size();
			int i = 0;
			while (i < size) {
				if (toupper((int)currentString.at(i)) != toupper((int)genreName.at(i)))
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

void BookCollection::removeAllGenres() {
	if (head != NULL) {
		while (head->next != NULL) {
			GenreNode* cur = head;
			head = head->next;
			cur->next = NULL;
			delete cur;
		}
		delete head;
	}
}
