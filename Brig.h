//Purpose:   Class definition for entity class Brig; manages cell collection


#ifndef BRIG_H
#define BRIG_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Pirate.h"
#include "CArray.h"

class Brig 
{
  public:
    Brig();
    int addPirate(Pirate*);
    CArray& getCells();
  private:
    CArray cells;
};

#endif

