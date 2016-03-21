//Purpose:   Function implementations for entity class Cell


#include "Cell.h"

int Cell::nextId = 1;

Cell::Cell(int size)
      : spaceRemaining(size)
{
  cellNumber = nextId++;
}

Queue& Cell::getPirates() { return queue;}
int     Cell::getSpace()   { return spaceRemaining; }


bool Cell::fits(Pirate* pirate)
{
  if ((spaceRemaining - pirate->getSpace()) < 0)
    return false;

  return true;
}

void Cell::reduceSpace(int pSpace)   { spaceRemaining -= pSpace; }

void Cell::increaseSpace(int pSpace) { spaceRemaining += pSpace; }

