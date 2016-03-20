//Purpose:   Class definition for collection class PArray;
//           contains pirate collection

#ifndef PARRAY_H
#define PARRAY_H

#include "Pirate.h"

template <class T> 
class PArray
{
  public:
    PArray();
    ~PArray();
    int     add(T);
    int     getSize();
    T getWithId(int);
    PArray<T>& operator+=(T);
    PArray<T>& operator-=(T);
    T operator[](int);
    bool operator!();
    
  private:
    int     size;
    T elements[MAX_PIRATES];
};

template <class T>
PArray<T>::PArray() : size(0)
{ 
  for (int i=0; i<MAX_PIRATES; ++i){
    elements[i] = 0;
  }  
}

template <class T>
PArray<T>::~PArray() 
{
  for (int i=0; i<size; ++i){ 
    delete elements[i];
  }  
}

//adds a pirate to the array
template <class T>
int PArray<T>::add(T pirate)
{
  if (size == MAX_PIRATES){return C_NOK;}

  elements[size] = pirate;
  size++;
  return C_OK;
}

// gets the pointer of the pirate with that id
template <class T>
T PArray<T>::getWithId(int id)
{
  for (int i=0; i<size; i++) {
    if (elements[i] == 0){continue;}  
    if (elements[i]->getId() == id){return elements[i];}
  }
  return 0;
}

//gets the size of the array
template <class T>
int PArray<T>::getSize() {return size;}

//adds a pirate using the add function
template <class T>
PArray<T>& PArray<T>::operator+=(T pirate)
{
  add(pirate);
  return *this;
}

// removes the pirate from the array
template <class T>
PArray<T>& PArray<T>::operator-=(T pirate)
{
  for (int i = 0; i < size; ++i) {
    if (elements[i] == pirate){
        elements[i] = 0;
        delete pirate; 
      for(i = i+1; i < size; i++){
        elements[i-1] = elements[i];
      }
        elements[size] = 0;
        size--;
      break;
    }
  }
  return *this;
}

//gets the element at that index
template <class T>
T PArray<T>::operator[](int i)
{
  if (i >= 0 && i < size){
    return elements[i];
  }
}

//returns if the array is not empty
template <class T>
bool PArray<T>::operator!() {return size!=0;}

#endif
