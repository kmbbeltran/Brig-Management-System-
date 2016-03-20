//Purpose:   Function implementations for entity class Pirate


#include <stdlib.h> 
/*
 rand function taken from :http://www.cplusplus.com/reference/cstdlib/rand/
*/
#include "Pirate.h"
#include "Dorcs.h"
#include "Borcs.h"
#include "Porcs.h"

int Pirate::nextId = 1001;

Pirate::Pirate() 
{
  id = nextId++;
}

int Pirate::getId()    { return id; }
int Pirate::getSpace() { return space; }


