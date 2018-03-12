#include "ListNode.h"

class SortedLinkedList{

 private:
  int count;
  ListNode *head;
  int itPos;
  
 public:
  int length() const;
  SortedLinkedList();
  ~SortedLinkedList();
  void insertItem(DataType &item);
  void deleteItem(DataType &item);
  int searchItem(DataType &item);
  void clear();
  void printList();
  int iterate();
  void resetIterator();

};
