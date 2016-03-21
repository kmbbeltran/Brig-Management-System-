//Purpose:   Class definition for collection class CArray; 
//              contains cell collection


#ifndef CARRAY_H
#define CARRAY_H

#include "Cell.h"
#include "Pirate.h"

class CArray
{
  public:
    CArray();
    ~CArray();
    int   getSize();
    Cell* get(int);
    int   add(Cell*);
    int remove(int);
    
  private:
    int    size;
    //MAX_CELLS = 48
    Cell*  elements[MAX_CELLS];
};

#endif
