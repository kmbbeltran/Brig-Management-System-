//Purpose:   Function implementations for control class BrigManager


#include <iostream>
#include "BrigManager.h"
#include "Dorcs.h"
#include "Porcs.h"
#include "Borcs.h"
#include <cstdlib>

using namespace std;

BrigManager::BrigManager()
{
  view = new UImanager;
  brig = new Brig;
}

BrigManager::~BrigManager()
{
  delete view;
  delete brig;
}

//starts the loop that runs the menu choices and calls the appropriate functions
void BrigManager::launch()
{
  int    choice1 = -1;
  int    choice2 = -1;
  int    id      = -1;
  int    rc;

  while (choice1 != 0) {
    view->mainMenu(&choice1);
    if (choice1 == 0) {
      break;
    }
    else if (choice1 == 1) {
      choice2 = -1;
      while (choice2 != 0) {
        view->pirateMenu(&choice2);
        if (choice2 == 0) {
          break;
        }
        else if (choice2 == 1) {
          int num;
          view->getNumPirates(&num);
          addPirates(num);
        }
        else if (choice2 == 2) {
          int num;
          view->getPirateId(&num);
          removePirate(num);
        }
        else if (choice2 == 3){
          int id1, id2;
          view->fight(&id1, &id2); 
          fight(id1, id2); 
        }
      }
    }
    else if (choice1 == 2) {
      view->printBrig(brig);
    }
    if (choice2 != 0)
      view->pause();
  }
}

// removes the pirate with that id
int BrigManager::removePirate(int id)
{
    Cell *temp;
    Pirate *pir;
    list<Cell*> ca = brig->getCells(); 
    
    list<Cell*>::iterator itr; 
    for(itr = ca.begin();
        itr != ca.end(); 
        itr++){
        
      temp = *itr; 
      PArray<Pirate*>& pa = temp->getPirates();

      if(pa.getSize() != 0){
        pir = pa.getWithId(id); 
        if(pir != 0){
          *temp += pir->getSpace(); 
          temp->getPirates() -= pir; 
          return C_OK; 
        }
      }  
    }
    return C_NOK;
}

//adds numPirates new pirates the the brig
void BrigManager::addPirates(int numPirates)
{
  Pirate*   newPirate;

  while (numPirates > 0) {
 
    int choice = random(3); 
  
    if(choice == 0){
      newPirate = new Dorcs; 
    }else if(choice == 1){
      newPirate = new Borcs;
    }else{
      newPirate = new Porcs; 
    }
    *brig += newPirate;
    --numPirates;
  }   
}

// allows the user to choose 2 pirates to "fight"
// somewhat in a rock, paper, scissor manner 
void BrigManager::fight(int pid1, int pid2)
{
  Pirate* p1;
  Pirate* p2; 
  Cell* temp; 
  int c = random(2);
  
  list<Cell*> ca = brig->getCells(); 
  list<Cell*>::iterator itr; 
  for(itr = ca.begin();
      itr != ca.end(); 
      itr++){
      
    temp = *itr; 
    
    PArray<Pirate*>& pa = temp->getPirates(); 
    for(int j = 0; j < pa.getSize(); j++){
      if(pa.getWithId(pid1) != 0){
        p1 = pa.getWithId(pid1); 
      }
      
      if(pa.getWithId(pid2) != 0){
        p2 = pa.getWithId(pid2); 
      }
    }  
  }    
  
  //if p1 and p2 are the same pirate, random choose which pirate wins 
  if(p1->getWeapon() == p2->getWeapon()){
    if(c % 2 == 0){
      view->printWinner(*p1,*p2);
    }
    else{
      view->printWinner(*p2,*p1);
    }
    return;
  }
  
  // sword beats cannon
  if(p1->getWeapon() == "sword"){
    if(p2->getWeapon() == "cannon"){
      view->printWinner(*p1,*p2);
    }else{
      view->printWinner(*p2,*p1);
    }  
    return;
  }
  
  // cannon beats riffle
  if(p1->getWeapon() == "cannon"){
    if(p2->getWeapon() == "riffle"){
      view->printWinner(*p1,*p2);
    }else{
      view->printWinner(*p2,*p1);
    }  
    return;  
  }
  
  // riffle beats sword
  if(p1->getWeapon() == "riffle"){
    if(p2->getWeapon() == "sword"){
      view->printWinner(*p1,*p2);
    }else{
      view->printWinner(*p2,*p1);
    }  
    return;
  }
  return;
}
