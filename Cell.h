//Purpose:   Class definition for entity class Cell; manages pirate collection


#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
//#include "PArray.h"
#include "Queue.h" 

class Cell 
{
  public:
    //MAX_CELL_SPACE = 7 
    Cell(int=MAX_CELL_SPACE);
    bool    fits(Pirate*);
    Queue& getPirates();
    int     getSpace();
    void    reduceSpace(int);
    void    increaseSpace(int);
  private:
    static int  nextId;
    int         cellNumber;
    int         spaceRemaining;
    //PArray      pirates;
    Queue       queue; 
};

#endif

