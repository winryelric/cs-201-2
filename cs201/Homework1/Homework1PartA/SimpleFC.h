#ifndef __SIMPLE_FC_H
#define __SIMPLE_FC_H

#include "SimpleFilm.h"

class FC {
public:
    FC();
    FC(unsigned int i);
    FC(const FC& fcToCopy);
    ~FC();
    void operator=(const FC& right);
    bool addFilm(const string fTitle, const string fDirector,
                 const unsigned int fYear,
                 const unsigned int fDuration);
    bool removeFilm(const string fTitle, const string fDirector);
    unsigned int getFilms(Film*& allFilms) const;
    int getIndex(const string fTitle, const string fDirector);
private:
    Film* films;
    unsigned int noOfFilms;
    unsigned int size;
};
#endif
