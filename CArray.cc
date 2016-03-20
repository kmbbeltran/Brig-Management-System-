//Purpose:   Function implementations for collection class CArray


#include <iostream>
#include <string>
using namespace std;

#include "CArray.h"

CArray::CArray() : size(0)
{ 
  for (int i=0; i<MAX_CELLS; ++i){
    elements[i] = 0;
  }
}

CArray::~CArray() 
{
  for (int i=0; i<size; ++i){
    delete elements[i];
  }
}

int CArray::getSize() { return size; }

//gets the element at that position in the array
Cell* CArray::get(int index)
{
  if (index >= 0 && index < size){
    return elements[index];
  }
  return 0;
}

//adds a cell to the array replaced by +=
int CArray::add(Cell* cell)
{
  if (size == MAX_CELLS){
    return C_NOK;
  }  

  elements[size] = cell;
  size++;
  return C_OK;
}

// adds a cell to the end of the array
CArray& CArray::operator+=(Cell* cell)
{
    if (size != MAX_CELLS){
    elements[size] = cell;
    size++;
    }
  return *this;
}

// gets the cell at the index using the previous get method
Cell* CArray::operator[](int i){return get(i);}
