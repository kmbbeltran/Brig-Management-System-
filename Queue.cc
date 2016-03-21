#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

#include "Queue.h" 
#include "defs.h" 

using namespace std; 

// constructor and destructor taken from example code in class 
Queue::Queue()
{
  head = NULL;
  size = 0;
}

Queue::~Queue()
{
 Node* currNode = head;
 Node*  nextNode;
 
 while(currNode != NULL){
   nextNode = currNode->next;
   delete currNode;
   currNode = nextNode; 
 }
}

Queue::Queue(const Queue& other)
{
  head = other.head;
    size= other.size;
    
}

int Queue::getSize(){return size;}

/*
take a pirate pointer and adds the pirate of the back of the queue
  - similar to PArray::add(pirate*)
*/
int Queue::pushPirate(Pirate* pir)
{
  
  if(size == MAX_PIRATES){return C_NOK;}
  
  Node* currNode; 
  Node* newPir; 
    
  newPir = new Node;
  newPir->data = pir;
  newPir->next = NULL;

    if(head==NULL){
        head=newPir;
        size++;
        return C_OK;
    }
  currNode = head;
  
  // if head isn't the only node in the list 
  while(currNode != NULL){
    // reached the end of the queue
    if(currNode->next = NULL){
      currNode->next = newPir; 
      newPir->prev = currNode; 
      currNode = currNode->next;
        size++;
        return C_OK;
    }
    
    //currNode->prev = currNode;
    currNode = currNode->next; 
   
  }
  
  return C_OK;  
}

/*
returns the pirate at the front of the queue
*/
Pirate* Queue::front()
{
    if(size==0)
        return NULL;
  Node* frontNode;
  frontNode = head;
  return frontNode->data; 
  
  //return head->next; 
}

/*
removes the pirate at the front of the queue
*/
void Queue::popPirate()
{
  
  Node* temp;
  
    if(head == NULL)
        return;
    
    temp=head->next;
    delete head;
    head= temp;
    if(head!= NULL)
        head->prev=NULL;
    
    size--;
    
    
  
}

/*
indicates whether the queue is empty or not
*/
bool Queue::emptyQueue()
{
  
  if(head != NULL){return false;}
  return true; 
}


/*
finds a particular pirate with the given id 
  - similar to the PArray::get(int)
*/
Pirate& Queue::find(int id)
{
  Node* currNode;
  
  currNode = head;
  
  //the head is the only node
  if(currNode->data->getId() == id){
    return *currNode->data;
  }else{
    
  }
  
  while(currNode != NULL){
    if(currNode->data->getId() == id){
      return *currNode->data; 
    }
    
    currNode->prev = currNode;
    currNode = currNode->next; 
  }
   
}

/*
removes the pirate with the given id 
*/
int Queue::remove(int id)
{
  Node* currNode;
  
  currNode = head;
  
  //the head is the only node
  if(size==1){
    if(currNode->data->getId() == id){
      delete currNode;
      head=NULL;
      size--;
      return C_OK;
    }else{
      return C_NOK;
    }
  }
  
  while(currNode != NULL){
    if(currNode->data->getId() == id){
      currNode->prev = currNode->next;
      currNode->next->prev = currNode->prev;
      
      delete currNode; 
      
      size -= 1;
      return C_OK;
    }
    
    //currNode->prev = currNode;
    currNode = currNode->next; 
  }
  return C_NOK;
}
