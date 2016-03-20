//Purpose:   Class definition for entity class Dorcs; a derived class of Pirate


#ifndef DORCS_H
#define DORCS_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Pirate.h"

class Dorcs : public Pirate
{
  public:
    Dorcs();
    virtual string getWeapon(); 
};
#endif
