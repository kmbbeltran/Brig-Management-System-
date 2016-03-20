// Purpose:   Class definition for entity class Borcs; a derived class of Pirate

 
#ifndef BORCS_H
#define BORCS_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Pirate.h"

class Borcs : public Pirate
{
  public:
    Borcs();
    virtual string getWeapon(); 
};
#endif