//Purpose:   Function implementation of the entity class Dorcs; assigns
//              the amount of space needed for this type of Pirate 


#include "Dorcs.h"

Dorcs::Dorcs() 
{
  // space between 4 and 6 units
  space = random(3) + 4;
}

// assigns the Dorc pirate a sword as its weapon 
string Dorcs::getWeapon()
{
  return "swords"; 
}