//Purpose:   Function implementations for entity class Cell


#include "Cell.h"

int Cell::nextId = 1;

Cell::Cell(int size)
      : spaceRemaining(size)
{
  cellNumber = nextId++;
}

PArray& Cell::getPirates() { return pirates; }
int     Cell::getSpace()   { return spaceRemaining; }

//checks to see if the pirate can fit in the cell
bool Cell::fits(Pirate* pirate)
{
  if ((spaceRemaining - pirate->getSpace()) < 0){return false;}
  return true;
}

// reduces the space available
void Cell::reduceSpace(int pSpace)   { spaceRemaining -= pSpace; }
// increases the space available
void Cell::increaseSpace(int pSpace) { spaceRemaining += pSpace; }

// increases the space available
int Cell::operator+=(int space)
{ 
  increaseSpace(space);
    
  return spaceRemaining;
}

// reduces the space available
int Cell::operator-=(int space)
{ 
  reduceSpace(space);
  return spaceRemaining; 
}

//adds a pirate to that cell
Cell& Cell::operator+=(Pirate* newPir)
{
  if(fits(newPir)){
      pirates+=newPir;
  }
  return *this; 
}


