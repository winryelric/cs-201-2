#include "SimpleFC.h";

FC::FC() {
    noOfFilms = size = 0;
    films = NULL;
}

FC::FC( const FC& fcToCopy) {
    noOfFilms = fcToCopy.noOfFilms;
    size = fcToCopy.size;
    if ( size > 0 ) {
        films = new Film[size];
        for ( int i = 0; i < noOfFilms; i++ )
            films[i] = fcToCopy.films[i];
    }
    else
        films = NULL;
}

FC::~FC() {
    if ( films != NULL )
        delete [] films;
}

void FC::operator=(const FC& right) {
    if ( right.size > 0 ) {
        noOfFilms = right.noOfFilms;
        size = right.size;
        delete [] films;
        films = new Film[size];
        for ( int i = 0; i < size; i++ )
            films[i] = right.films[i];
    }
    else {
        noOfFilms = size = 0;
        films = NULL;
    }
}

bool FC::addFilm(const string fTitle, const string fDirector,
                 const unsigned int fYear,
                 const unsigned int fDuration) {
    if ( size > 0 ) {
        int index = getIndex(fTitle, fDirector);
        // Don't add it if it is already in the collection
        if ( index >= 0 )
            return false;
        else {
            // Create a copy of the current collection in temp
            // Create a new collection
            // Copy items in the temp to the new collection
            Film* temp = films;
            films = new Film[size + 1];
            size++;
            for ( int i = 0; i < size - 1; i++ )
                films[i] = temp[i];
            // Add the film to the temp
            Film f(fTitle, fDirector, fYear, fDuration);
            films[size - 1] = f;
            noOfFilms++;
            // Delete temp to avoid memory leak
            delete [] temp;
            return true;
        }
    }
    // Corner case, when the collection is empty
    else if ( size == 0) {
        if ( films != NULL )
            delete [] films;
        films = new Film[1];
        size++;
        Film f(fTitle, fDirector, fYear, fDuration);
        films[0] = f;
        noOfFilms++;
        return true;
    }
    return false;
}

bool FC::removeFilm(const string fTitle, const string fDirector) {
    // Find index
    int index = getIndex(fTitle, fDirector);
    // Don't remove if it doesn't exist
    if ( index < 0 )
        return false;
    else {
        // Corner case, where the array has one element
        if ( size == 1 ) {
            delete [] films;
            films = NULL;
            noOfFilms = size = 0;
            return true;
        }
        else if ( size > 1 ) {
            Film* temp = films;
            films = new Film[size - 1];
            size--;
            for ( int i = 0; i < index; i++ )
                films[i] = temp[i];
            for ( int i = index + 1; i < size + 1; i++ )
                films[i - 1] = temp[i];
            noOfFilms--;
            delete [] temp;
            return true;
        }
        return false;
    }
}

unsigned int FC::getFilms(Film*& allFilms) const {
	if (size == 0)
		allFilms = NULL;
	else {
		allFilms = new Film[size];
		for (int i = 0; i < size; i++)
			allFilms[i] = films[i];
	}
    return noOfFilms;
}

int FC::getIndex(const string fTitle, const string fDirector) {
    for ( int i = 0; i < size; i++) {
        if ( films[i].getTitle() == fTitle && films[i].getDirector() == fDirector )
            return i;
    }
    return -1;
}
