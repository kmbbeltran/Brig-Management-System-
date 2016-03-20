//Purpose:   Function implementations for entity class Brig

#include "Brig.h"
#include <list>
#include <iterator>
#include <algorithm>

Brig::Brig() {}

Brig::~Brig()
{
  list<Cell*>::iterator itr;
  
  for(itr = cells.begin(); 
      itr != cells.end();
      itr++){
    delete *itr;    
  }
}

//gets the cell array
list<Cell*> Brig::getCells() {return cells;}

//adds a new pirate to the group of cells
Brig& Brig::operator+=(Pirate* pir)
{
  int index = -1; 
  list<Cell*>::iterator itr; 

  for(itr = cells.begin(); 
      itr != cells.end();
      itr++){
    
    Cell* temp = *itr;
    if(temp->fits(pir)){
      *temp += pir;
      *temp -= pir->getSpace();
      index = 0;
      break;
    }
  }
  
  if(index != 0){
    Cell* newCell = new Cell;
    *newCell += pir;
    *newCell -= pir->getSpace();
    cells.push_back(newCell);
  }
  return *this;
}

