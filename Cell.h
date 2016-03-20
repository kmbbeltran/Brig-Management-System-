//Purpose:   Class definition for entity class Cell; manages pirate collection


#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "PArray.h"

class Cell 
{
  public:
    Cell(int=MAX_CELL_SPACE);
    bool    fits(Pirate*);
    PArray& getPirates();
    int     getSpace();
    void    reduceSpace(int);
    void    increaseSpace(int);
    
    // overloading operators
    int operator+=(int); 
    int operator-=(int); 
    Cell& operator+=(Pirate*);
    
  private:
    static int  nextId;
    int         cellNumber;
    int         spaceRemaining;
    PArray      pirates;
};

#endif

