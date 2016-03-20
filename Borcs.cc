// Purpose:   Function implementation of the entity class Borcs; assigns
//              the amount of space needed for this type of Pirate 

#include "Borcs.h"

Borcs::Borcs()
{
  // space between 5 and 7 units
  space = random(3) + 5;
}

// assigns the Borc pirate a riffle as its weapon  
string Borcs::getWeapon()
{
  return "riffle"; 
}