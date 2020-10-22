#include "Film.h"

Film::Film( const string fTitle, const string fDirector,
            const unsigned int fYear, const unsigned int fDuration ) {
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
    size = noOfActors = 0;
    actors = NULL;
}

Film::Film( const Film& filmToCopy ) {
    title = filmToCopy.getFilmTitle();
    director = filmToCopy.getFilmDirector();
    year = filmToCopy.getFilmYear();
    duration = filmToCopy.getFilmDuration();
    if ( filmToCopy.actors != NULL ) {
        actors = new Actor[filmToCopy.size];
        size = filmToCopy.size;
        noOfActors = 0;
        for ( int i = 0; i < filmToCopy.size ; i++ ) {
            actors[i] = filmToCopy.actors[i];
            noOfActors++;
        }
    }
    else {
        size = noOfActors = 0;
        actors = NULL;
    }
}

Film::~Film() {delete [] actors;}

void Film::operator=( const Film& right ) {
    if ( this != &right ) {
        title = right.getFilmTitle();
        director = right.getFilmDirector();
        year = right.getFilmYear();
        duration = right.getFilmDuration();
        if ( right.actors != NULL ) {
            delete [] actors;
            actors = new Actor[right.size];
            size = right.size;
            noOfActors = 0;
            for ( int i = 0; i < right.size ; i++ ) {
                actors[i] = right.actors[i];
                noOfActors++;
            }
        }
        else {
            size = noOfActors = 0;
            delete [] actors;
            actors = NULL;
        }
    }
}

string Film::getFilmTitle() const { return title; }
string Film::getFilmDirector() const { return director; }
unsigned int Film::getFilmYear() const { return year; }
unsigned int Film::getFilmDuration() const { return duration; }

unsigned int Film::calculateAverageActorAge() const {
    unsigned int sum = 0;
    if ( noOfActors == 0 ) return 0;
    else {
        for ( int i = 0; i < noOfActors; i++ ) {
            sum += getFilmYear() - actors[i].getBirthYear();
        }
        return sum / noOfActors;
    }
}

bool Film::addActor(const string aName, const string aBirthPlace,
					const unsigned int aBirthYear) {
	int index = getIndex(aName);
	if (index > 0) return false;
	else if (size > 0) {
		Actor* temp = actors;
		actors = new Actor[size + 1];
		for (int i = 0; i < size; i++)
			actors[i] = temp[i];
		Actor a(aName, aBirthPlace, aBirthYear);
		actors[size] = a;
		delete[] temp;
		size++;
		noOfActors++;
		return true;
	}
	else {
		if (actors != NULL) delete[] actors;
		actors = new Actor[1]; // the size is being set from 0 to 1
		size = 1;
		Actor a(aName, aBirthPlace, aBirthYear);
		actors[0] = a;
		noOfActors++;
		return true;
	}
}

bool Film::removeActors() {
	if (size != 0) {
		delete[] actors;
		actors = NULL;
		size = noOfActors = 0;
		return true;
	}
	else return false;
}

int Film::getIndex(const string aName) {
	for (int i = 0; i < size; i++) {
		if (aName == actors[i].getName())
			return i;
	}
	return -1;
}

// Either getActors function or addActor&removeActors functions are necesarry
// to have
unsigned int Film::getActors(Actor*& actorptr) const {
	if (size == 0)
		actorptr = NULL;
	else {
		actorptr = new Actor[size];
		for (int i = 0; i < size; i++)
			actorptr[i] = actors[i];
	}
	return noOfActors;
}

ostream& operator<<( ostream& out, const Film& f ) {
	out << f.getFilmTitle() << ", " << f.getFilmDirector()
		<< ", " << f.getFilmYear() << ", " << f.getFilmDuration() << " min" << endl;
	Actor* actorptr;
	int noOfActors = f.getActors(actorptr);
    for ( int i = 0; i < noOfActors; i++ )
        out << "\t" << actorptr[i] << endl;
	return out;
}
