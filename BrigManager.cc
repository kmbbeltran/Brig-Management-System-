//Purpose:   Function implementations for control class BrigManager


#include <iostream>
#include "BrigManager.h"
#include "Dorcs.h"
#include "Porcs.h"
#include "Borcs.h"

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
//starts the loop that runs the menu choices and calls the apropriate functions
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
    for(int i = 0; i < brig->getCells().getSize(); i++){
        temp=brig->getCells()[i];
        if(!temp->getPirates()){
        pir=temp->getPirates().getWithId(id);
        if(pir!=0){
            *temp+=pir->getSpace();
            temp->getPirates()-=pir;
            
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


