// Purpose:   Function implementations for entity class Pirate

#include "Pirate.h"
#include "Dorcs.h"
#include "Borcs.h"
#include "Porcs.h"

int Pirate::nextId = 1001;

Pirate::Pirate() 
{
  id = nextId++;
}

int Pirate::getId()    {return id;}
int Pirate::getSpace() {return space;}


