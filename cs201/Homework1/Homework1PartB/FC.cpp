#include "FC.h";

FC::FC() {
    size = noOfFilms = 0;
    films = NULL;
}

FC::FC(const FC& fcToCopy) {
	size = fcToCopy.size;
	noOfFilms = fcToCopy.noOfFilms;
	if (size != 0) {
		films = new Film[size];
		for (int i = 0; i < noOfFilms; i++)
			films[i] = fcToCopy.films[i];
	}
	else films = NULL;
}

FC::~FC() {
    delete [] films;
}

void FC::operator=(const FC& right) {
	if (this != &right) {
		size = right.size;
		noOfFilms = right.noOfFilms;
		delete [] films;
		if (size != 0) {
			films = new Film[size];
			for (int i = 0; i < noOfFilms; i++)
				films[i] = right.films[i];
		}
		else films = NULL;
	}
}

bool FC::addFilm( const string fTitle, const string fDirector,
				  const unsigned int fYear,
				  const unsigned int fDuration) {
	if ( getIndex(fTitle, fDirector) >= 0 )
		return false;
	else if (size > 0) {
		Film* temp = films;
		films = new Film[size + 1];
		size++;
		for (int i = 0; i < size - 1; i++) {
			films[i] = temp[i];
		}
		Film f(fTitle, fDirector, fYear, fDuration);
		films[size - 1] = f;
		noOfFilms++;
		delete[] temp;
		return true;
	}
	else {
		if (films != NULL) delete[] films;
		films = new Film[1]; // the size is being set from 0 to 1
		size = 1;
		Film f(fTitle, fDirector, fYear, fDuration);
		films[0] = f;
		noOfFilms++;
		return true;
	}
}

bool FC::removeFilm(const string fTitle, const string fDirector) {
	int index = getIndex(fTitle, fDirector);
	if (index < 0)
		return false;
	else if (size > 1) {
		Film* temp = films;
		films = new Film[size - 1];
		size--;
		for (int i = 0; i < index; i++)
			films[i] = temp[i];
		noOfFilms--;
		for (int i = index + 1; i < size + 1; i++)
			films[i - 1] = temp[i];
		delete[] temp;
		return true;
	}
	else {
		delete[] films;
		films = NULL;
		size = noOfFilms = 0;
		return true;
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

bool FC::addActor(const string fTitle, const string fDirector, 
				  const string aName, const string aBirthPlace, 
				  const unsigned int aBirthYear) {
	int indexOfFilm = getIndex(fTitle, fDirector);
	if (indexOfFilm < 0)
		return false;
	else
		return (films[indexOfFilm].addActor(aName, aBirthPlace, aBirthYear));
}

bool FC::removeActors(const string fTitle, const string fDirector)
{
	int indexOfFilm = getIndex(fTitle, fDirector);
	return films[indexOfFilm].removeActors();
}

unsigned int FC::calculateAverageDuration() const
{
	unsigned int sum = 0;
	if (noOfFilms == 0) return 0;
	else {
		for (int i = 0; i < noOfFilms; i++)
			sum += films[i].getFilmDuration();
		return sum / noOfFilms;
	}
	return 0;
}

int FC::getIndex(const string fTitle, const string fDirector)
{
	for (int i = 0; i < size; i++) {
		if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
			return i;
	}
	return -1;
}
