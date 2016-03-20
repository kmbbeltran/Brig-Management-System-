//Purpose:   Function implementations for UI class UImanager
//           Has all of the user interface implementation to display text to the user 
//           and receive user input


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

UImanager::UImanager() { }

//displays the main menu and gives the choice the selected value
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


//asks for a pirate id, and gives the id the  value
void UImanager::getPirateId(int* id)
{
    string str;
    
    cout << endl << "Enter the id of the pirate you wish to remove:    ";
    getline(cin, str);
    stringstream ss2(str);
    ss2 >> *id;
}

//displays the pirate menu and gives the choice the selected value
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
    cout << "( 3 )  Make the Pirates fight" << endl;
    cout << "( 0 )  Exit" << endl;
    
    while (*choice < 0 || *choice > 4) {
        cout << "Enter your selection:  ";
        getline(cin, str);
        stringstream ss(str);
        ss >> *choice;
    }
}

//displays has the user press enter before continuing
void UImanager::showError(string err)
{
  cout << err << " -- press enter to continue...";
  cin.get();
}

//displays has the user press enter before continuing
void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

//asks for a numebr of pirates and gives the value to numPirates
void UImanager::getNumPirates(int* numPirates)
{
    string    str;
    
    cout << endl << "Enter the number of pirates:   ";
    getline(cin, str);
    stringstream ss1(str);
    ss1 >> *numPirates;
}

//prints out all of the cells and pirates in the brig
void UImanager::printBrig(Brig* brig)
{
    int i = 0; 
    list<Cell*> ca =  brig->getCells();    
    list<Cell*>::iterator itr;
    for(itr = ca.begin(); 
        itr != ca.end(); 
        itr++){
        Cell* temp=*itr;
       
      cout<<endl<<"--Cell "<<i<<": space remaining= "<<temp->getSpace()<<endl;
      PArray<Pirate*>& pa = temp->getPirates(); 
      
      for(int j = 0; j < pa.getSize(); j++){
        if(pa[j] == 0){continue;}
        
        cout << "-----Pirate id: " <<pa[j]->getId() 
             << "  space: " << pa[j]->getSpace() << endl; 
      }
      i++;
    }
}

// chooses two pirates to fight 
void UImanager::fight(int* pir1, int* pir2)
{ 
  string str;
  cout << "Enter the pirate ID separately..." << endl; 
  cout << endl;
  
  cout << "First pirate IDs:  ";
  getline(cin, str);
  stringstream ss1(str);
  ss1 >> *pir1; 
  
  cout << "Second pirate IDs:  ";
  getline(cin, str);
  stringstream ss2(str);
  ss2 >> *pir2;
}

//printing out who won the fight
void UImanager::printWinner(Pirate& winner, Pirate& loser)
{
  cout << endl << "And the winner of the fight is.... " << endl; 
  cout << endl << "Pirate " << winner.getId() << " with the " 
       << winner.getWeapon() << " against Pirate " << loser.getId()
       << " with the " << loser.getWeapon() << endl; 
}

