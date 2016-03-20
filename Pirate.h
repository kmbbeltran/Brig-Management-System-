//Purpose:   Class definition for entity class Pirate

#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"

class Pirate 
{
  public:
    Pirate();
    int getId();
    int getSpace();
    virtual string getWeapon() = 0;
   
  private:
    static int  nextId;
    int         id;
  
  protected:
    int space; 
    string weapon; 
};

#endif

