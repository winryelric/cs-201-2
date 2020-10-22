#include "SimpleBookCollection.h"
#include <iostream>

BookCollection::BookCollection() {
	name = "";
	genreCount = 0;
	head = NULL;
}

BookCollection::~BookCollection() {
	while (genreCount != 1) {
		GenreNode* cur;
		--genreCount;
		cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
	delete head;
}

BookCollection::BookCollection(const BookCollection& bcToCopy) {
	name = bcToCopy.name;
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

void BookCollection::operator=(const BookCollection& right)
{
	if (this != &right) {
		// Delete the items of lhs
		while (genreCount != 1) {
			GenreNode* cur;
			--genreCount;
			cur = head;
			head = head->next;
			cur->next = NULL;
			delete cur;
			cur = NULL;
		}
		delete head;

		// Copy name and size
		name = right.name;
		genreCount = right.genreCount;

		// If the rhs is not empty, copy them to the lhs
		if (genreCount != 0)
		{
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
		else
			head = NULL;
	}
}

void BookCollection::displayGenres() const
{
	if (genreCount == 0)
		cout << "---EMPTY---" << endl;
	else {
		for (GenreNode* cur = head; cur != NULL; cur = cur->next) {
			cout << cur->g.getGenreName() << endl;
		}
	}
}

bool BookCollection::addGenre(const string genreName)
{
	if (findGenre(genreName) != NULL) {
		cout << "Genre " << genreName << " already exists." << endl;
		return false;
	}
	else {
		/* Add to the beginning */

		// Initialize the node to add
		GenreNode* newPtr = new GenreNode;
		newPtr->g.setGenreName(genreName);

		// Connect the new node with the rest of the list
		newPtr->next = head;
		// Make the first item the new node
		head = newPtr;
		genreCount++;
	}
	return true;
}

bool BookCollection::removeGenre(const string genreName) {
	if (findGenre(genreName) == NULL) {
		cout << "Genre " << genreName << " doesn't exist." << endl;
		return false;
	}
	else if (findGenre(genreName) == head){
		/*If the item is the first item*/
		GenreNode* cur = head;
		head = head->next;
		delete cur;
	}
	else {
		// Search the item
		GenreNode* cur = findGenre(genreName);

		// Find the item before the item to be deleted
		GenreNode* prev = head;
		while (prev->next != cur)
			prev = prev->next;

		// Connect the prev to the the item after the item to be deleted
		prev->next = cur->next;

		//Delete everything about cur
		cur->next = NULL;
		delete cur;
	}
}

string BookCollection::getName() const {
	return name;
}

void BookCollection::setName(const string bcName) {
	name = bcName;
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName) {
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
