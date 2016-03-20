//Purpose:   Class definition for entity class Brig; manages cell collection


#ifndef BRIG_H
#define BRIG_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "defs.h"
#include "Pirate.h"
#include "Cell.h"

class Brig 
{
  public:
    Brig();
    ~Brig();
    list<Cell*> getCells();    
    Brig& operator+=(Pirate*);  
    
  private:
    list<Cell*> cells;
};

#endif

