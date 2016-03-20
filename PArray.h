//Purpose:   Class definition for collection class PArray;
//              contains pirate collection


#ifndef PARRAY_H
#define PARRAY_H

#include "Pirate.h"

class PArray
{
  public:
    PArray();
    ~PArray();
    int     add(Pirate*);
    int     getSize();
    Pirate* getWithId(int);
    Pirate* get(int);
    
    PArray& operator+=(Pirate*);
    PArray& operator-=(Pirate*);
    Pirate* operator[](int);
    bool operator!();
  private:
    int     size;
    Pirate* elements[MAX_PIRATES];
};

#endif
