#include "Actor.h";

Actor::Actor( const string aName, const string aBirthPlace, const unsigned int aBirthYear) {
    name = aName;
    birthPlace = aBirthPlace;
    birthYear = aBirthYear;
}

Actor::Actor( const Actor& actorToCopy) {
    name = actorToCopy.getName();
    birthPlace = actorToCopy.getBirthPlace();
    birthYear = actorToCopy.getBirthYear();
}

Actor::~Actor(){}

void Actor::operator=( const Actor& right) {
    if ( this != &right ) {
        name = right.name;
        birthPlace = right.birthPlace;
        birthYear = right.birthYear;
    }
}

string Actor::getName() const {return name;}
string Actor::getBirthPlace() const{return birthPlace;}
unsigned int Actor::getBirthYear() const{return birthYear;}

ostream& operator<<( ostream& out, const Actor& a) {
    out << a.getName() << ", " << a.getBirthPlace()
         << ", " << a.getBirthYear();
    return out;
}
