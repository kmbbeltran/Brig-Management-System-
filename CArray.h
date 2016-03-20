//Purpose:   Class definition for collection class CArray; 
//           contains cell collection


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
    
    CArray& operator+=(Cell*);
    Cell* operator[](int);
    
  private:
    int    size;
    Cell*  elements[MAX_CELLS];
};

#endif
