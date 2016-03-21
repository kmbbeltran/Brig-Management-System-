#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string> 

#include "Pirate.h"

class Queue
{
  class Node
  {
    friend class Queue; 
    
    private:
      Pirate* data; 
      Node* next;
      Node* prev;
  };
  
  public:
    Queue();
    ~Queue();
    Queue(const Queue&);
    
    int pushPirate(Pirate*); 
    void popPirate(); 
    Pirate* front(); 
    bool emptyQueue(); 
    Pirate& find(int); 
    int remove(int); 
    
    
    int getSize();
    
  private:
    Node* head; 
    int size; 
    //Pirate pirate; 
};

#endif
