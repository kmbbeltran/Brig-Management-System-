//Purpose:   Class definition for entity class Porcs; a derived class of Pirate


#ifndef PORCS_H
#define PORCS_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Pirate.h"

class Porcs : public Pirate
{
  public:
    Porcs();
    virtual string getWeapon(); 
};
#endif