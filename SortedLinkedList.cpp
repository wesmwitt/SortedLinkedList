#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

//Constructor
SortedLinkedList::SortedLinkedList(){
  
  count = 0;

}

//Destructor
SortedLinkedList::~SortedLinkedList(){

  ListNode* current = head;
  
    while (current != NULL){
      ListNode* delNode = current->next;
      delete current;
      current = delNode;
    }
  
    head = NULL;
    count = 0;

}

//Insert Item into List
void SortedLinkedList::insertItem(DataType &item){

  //making a new node from the data in item
  ListNode* newNode = new ListNode(item);

  //insert item
  if(length()==0){ //insert at head (empty list)

    //cout << "insert at head (empty list)" << endl;
    head = newNode;

  }
  else { //insert node (not empty list)

    //cout << "List not empty. Let's iterate through." << endl;
    ListNode* current = head;
    ListNode* trail = NULL;

    //iterate through list
    while (current != NULL){
      //check if item is <= the head
      if(((current->item).compareTo(item) == GREATER)){
	break;
      }
      else {
	trail = current;
	current = current->next;
      }
    }
    
    if (current == head){
      //cout << "new node inserted at head" << endl;
      newNode->next = head;
      head = newNode;
    }
    else { //insert after head
      //cout <<"new node inserted after head" << endl;

      newNode->next = current;
      trail->next = newNode;
      
    }

  }//else

  count++;

}

//Delete item from list
void SortedLinkedList::deleteItem(DataType &item){

  ListNode* tempNode = head;
  ListNode* delNode = head->next;

  int loc = searchItem(item);

  if (loc == -1){ //not in list, delete nothing
    return;
  }
  else if (loc == 0){ //delete from first spot

    head = head->next;
    delete tempNode;

  }
  else if (loc == (count-1)){ //delete from last spot
    
    for (int i = 0; i < (loc-1); i++){
      tempNode = tempNode->next;
      delNode = delNode->next;
    }

    tempNode->next = NULL;  
    delete delNode;
  
  }
  else { //delete from middle

    for (int i = 0; i < (loc-1); i++){
      tempNode = tempNode->next;
      delNode = delNode->next;

    }
    tempNode->next = (tempNode->next)->next;
    delete delNode;

  }

  count--;

}

//Search item in list
int SortedLinkedList::searchItem(DataType &item){

  if (count == 0){
    return -1;
  }

  ListNode* current = head;
  int pos = 0;

  while (((current->item).getValue() != item.getValue()) && (pos < (count-1))){
      current = current->next;
      pos++;
  }

  if ((current->item).getValue() != item.getValue()){
    return -1;
  }

  return pos;

}

//clear the list
void SortedLinkedList::clear(){

  ListNode* current = head;

  while (current != NULL){
    ListNode* delNode = current->next;
    delete current;
    current = delNode;
  }

  head = NULL;
  count = 0;

}

//return length of list
int SortedLinkedList::length() const{
  return count;
}

//print out the list
void SortedLinkedList::printList(){

  //if empty
  if (count == 0){
    cout << endl;
    return;
  }

  ListNode* current = head;

  cout << current->item.getValue() << " ";

  for (int i=1; i < (count); i++){
  current = current->next;
  cout << current->item.getValue() << " ";
  }
  
  cout << endl;
}

//iterate through the list
int SortedLinkedList::iterate(){

  ListNode* current = head;

  if (itPos < length()){

    for (int i = 0; i < itPos; i++){
      current = current->next;
    }

  itPos++;

  return (current->item).getValue();


  }
  else {
    cout << "ERROR: No next value." << endl;
    return 0;
  }

}

void SortedLinkedList::resetIterator(){

  itPos = 0;;

}
