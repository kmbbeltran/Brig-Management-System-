//Purpose:   Class definition for control class BrigManager


#ifndef BRIG_MANAGER_H
#define BRIG_MANAGER_H

#include "defs.h"
#include "UImanager.h"
#include "Brig.h"

class UImanager;

class BrigManager 
{
  public:
    BrigManager();
    ~BrigManager();
    void launch();
    void addPirates(int);
    int removePirate(int);
  private:
    UImanager *view;
    Brig      *brig;
};

#endif

