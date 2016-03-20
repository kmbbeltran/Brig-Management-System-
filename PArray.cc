//Purpose:   Function implementations for collection class PArray


#include <iostream>
#include <string>
using namespace std;

#include "PArray.h"

PArray::PArray() : size(0)
{ 
  for (int i=0; i<MAX_PIRATES; ++i){
    elements[i] = 0;
  }  
}

PArray::~PArray() 
{
  for (int i=0; i<size; ++i){ 
    delete elements[i];
  }  
}

//adds a pirate to the array
int PArray::add(Pirate *pirate)
{
  if (size == MAX_PIRATES){return C_NOK;}

  elements[size] = pirate;
  size++;
  return C_OK;
}

// gets the pointer of the pirate with that id
Pirate* PArray::getWithId(int id)
{
  for (int i=0; i<size; ++i) {
    if (elements[i] == 0){continue;}  
    if (elements[i]->getId() == id){return elements[i];}
  }

  return(0);
}

//gets the pirate at the index
Pirate* PArray::get(int index)
{
  if (index >= 0 && index < size){
    return elements[index];
  }
  return 0;
}

//gets the size of the array
int PArray::getSize() { return size; }

//adds a pirate using the add function
PArray& PArray::operator+=(Pirate* pirate)
{
  add(pirate);
  return *this;
}

// removes the pirate from the array
PArray& PArray::operator-=(Pirate* pirate)
{
  for (int i=0; i<size; ++i) {
    if (elements[i]== pirate){
        elements[i]=0;
        delete pirate;
      for(i=i+1;i<size;i++){
        elements[i-1]=elements[i];
      }
        elements[size]=0;
        size--;
      break;
    }
  }
  return *this;
}

//gets the element at that index
Pirate* PArray::operator[](int i){return elements[i];}

//returns if the array is not empty
bool PArray::operator!() {return size!=0;}

