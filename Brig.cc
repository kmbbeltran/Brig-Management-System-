//Purpose:   Function implementations for entity class Brig


#include "Brig.h"

Brig::Brig() { }

//adds pirates to the cell is no longer used now that there are overloaded opperators
int Brig::addPirate(Pirate* pirate)
{
  Cell* newCell;
  int index = -1;
  int rc;

  for (int i=0; i<cells.getSize(); ++i){ 
    if (cells.get(i)->fits(pirate)){ 
      index = i;
    }  
  }
    
  if (index >= 0){

   cells[index]->getPirates() += pirate;  
   rc = C_OK;
   if (rc != C_OK){return C_NOK;}

   *cells[index] -= pirate->getSpace(); 
  }else{
    newCell = new Cell;
    cells += newCell; 

    newCell->getPirates() += pirate; 
    rc = C_OK; 
    if (rc != C_OK){return C_NOK;}

    *newCell -= pirate->getSpace(); 
  }
  return C_OK;
}

//gets the cell array
CArray& Brig::getCells() { return cells; }

//adds a new pirate to the group of cells
Brig& Brig::operator+=(Pirate* pir)
{
  int index = -1;
    
  for (int i=0; i<cells.getSize(); i++){
    if (cells[i]->fits(pir)){
      index = i;
    }
  }
    if(index<0){
        Cell* newCell = new Cell;
        cells+=newCell;
        index=cells.getSize()-1;
    }
    
  if(index >= 0){
      *cells[index]+=pir;
      *cells[index] -= pir->getSpace();
  }
    
  return *this;
}

