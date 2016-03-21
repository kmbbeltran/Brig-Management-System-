/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//Purpose:   Function implementations for control class BrigManager


#include <iostream>
#include "BrigManager.h"

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
        } else if (choice2 == 2){
          int id;
          view->getPirateId(&id); 
          removePirate(id); 
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

void BrigManager::addPirates(int numPirates)
{
  Pirate*   newPirate;

  while (numPirates > 0) {

    newPirate = new Pirate;

    brig->addPirate(newPirate);

    --numPirates;
  }
}

/*
- loop through the CArray
- look into each cell 
- loop through the queue to check the id 
*/
int BrigManager::removePirate(int id)
{
  for(int i = 0; i < brig->getCells().getSize(); i++){
    if(brig->getCells().remove(id) == C_OK){
      return C_OK;
    }else{
      break;
    }
  }
  return C_NOK;
}

