//Purpose:   Function implementations for UI class UImanager


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

UImanager::UImanager() { }

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

#ifndef TEST_MODE
  system("clear");
#endif

  cout<< "\n\n\n                   WELCOME TO THE BRIG MANAGEMENT SYSTEM \n\n";
  cout << "( 1 )  Manage pirates" << endl;
  cout << "( 2 )  View brig" << endl;
  cout << "( 0 )  Exit" << endl;

  while (*choice < 0 || *choice > 2) {
    cout << "Enter your selection:  ";
    getline(cin, str);
    stringstream ss(str);
    ss >> *choice;
  }
}

void UImanager::pirateMenu(int* choice)
{
  string str;

  *choice = -1;

#ifndef TEST_MODE
  system("clear");
#endif

  cout<< "\n\n\n                   PIRATE MANAGEMENT MENU \n\n";
  cout << "( 1 )  Add pirate" << endl;
  cout << "( 2 )  Remove pirate" << endl; 
  cout << "( 0 )  Exit" << endl;

  while (*choice < 0 || *choice > 2) {
    cout << "Enter your selection:  ";
    getline(cin, str);
    stringstream ss(str);
    ss >> *choice;
  }
}

void UImanager::getNumPirates(int* numPirates)
{
  string    str;

  cout << endl << "Enter the number of pirates:   ";
  getline(cin, str);
  stringstream ss1(str);
  ss1 >> *numPirates;
}

/*
  when removing a pirate, gets the pirate id for the pirate you wish to remove 
*/
void UImanager::getPirateId(int* id)
{
  string str; 
  
  cout << endl << "Enter the id of the pirate you wish to remove:      "; 
  getline(cin, str); 
  stringstream ss2(str); 
  ss2 >> *id;
}

/*
- loop through the CArray
- look at each cell
- copy each queue = temp
- print temp, then call pop
*/
void UImanager::printBrig(Brig* brig)
{
 
  
  CArray& ca = brig->getCells();
  
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"Brig: #cells=" << ca.getSize() << endl;
  
  for(int i = 0; i < ca.getSize(); i++){
    cout << "--Cell " << i << ":space remaining =" << ca.get(i)->getSpace() << endl;
    Queue* temp = new Queue(ca.get(i)->getPirates());
    
    while(!(temp->emptyQueue())){
      cout <<"----Pirate id: "<< temp->front()->getId()
           <<"    space: " << temp->front()->getSpace() << endl;
      temp->popPirate();
    }
  }

  
}

void UImanager::showError(string err)
{
  cout << err << " -- press enter to continue...";
  cin.get();
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

