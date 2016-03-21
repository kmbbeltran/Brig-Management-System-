//Purpose:   Function implementations for entity class Brig


#include "Brig.h"

Brig::Brig() { }

int Brig::addPirate(Pirate* pirate)
{
  Cell* newCell;
  int index = -1;
  int rc;

  for (int i=0; i<cells.getSize(); ++i) 
    if (cells.get(i)->fits(pirate)) 
      index = i;

   
  if (index >= 0) {
    
    rc = cells.get(index)->getPirates().pushPirate(pirate);
    
    if (rc != C_OK)
      return C_NOK;
    cells.get(index)->reduceSpace(pirate->getSpace());
  }
  else {
    newCell = new Cell;
    cells.add(newCell);
    rc = newCell->getPirates().pushPirate(pirate);
    
    if (rc != C_OK)
      return C_NOK;
    newCell->reduceSpace(pirate->getSpace());
  }
  return C_OK;
}

CArray& Brig::getCells() { return cells; }

