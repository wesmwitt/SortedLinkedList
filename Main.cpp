#include <iostream>
#include <fstream>
#include "SortedLinkedList.h"
using namespace std;

int main(int argc, char** argv){

  //printing commands
  cout << "Commands:" << endl;
  cout << "\t" << "(i) - Insert value" << endl;
  cout << "\t" << "(d) - Delete value" << endl;
  cout << "\t" << "(s) - Search value" << endl;
  cout << "\t" << "(n) - Print next iterator value" << endl;
  cout << "\t" << "(r) - Reset iterator" << endl;
  cout << "\t" << "(p) - Print list" << endl;
  cout << "\t" << "(l) - Print length" << endl;
  cout << "\t" << "(c) - Clear list" << endl;
  cout << "\t" << "(q) - Quit program" << endl;

  //put input into list
  SortedLinkedList list1;
  int x;
  ifstream input;
  
  input.open(argv[1]);

  if(!input){
    cout << "Error opening file" << endl;
  }

  //inserting numbers from data into list
  while (input >> x){
    DataType data(x);
    list1.insertItem(data);
  }

  input.close();

  //loop of taking user commands
  while(true){
    char command;

    cout << "Enter a command: ";

    cin >> command;

    if (command == 'i'){ //insert value
      int myNum;
      cout << "Enter number: ";
      cin >> myNum;
      DataType myData(myNum);
      list1.insertItem(myData);
    }
    else if (command == 'd'){ //delete value
      int myNum;
      cout << "Enter value to delete: ";
      cin >> myNum;
      DataType myData(myNum);
      list1.deleteItem(myData);
    }
    else if (command == 's'){ //search value
      int myNum;
      cout << "Enter value to search: ";
      cin >> myNum;
      DataType myData(myNum);
      cout << "Index of the item is " << list1.searchItem(myData) << endl;

    }
    else if (command == 'n'){ //print next iterator value
      cout << "next value is " << list1.iterate() << endl;
    }
    else if (command == 'r'){ //reset iterator
      list1.resetIterator();
      cout << "Iterator reset." << endl;
    }
    else if (command == 'p'){ //print list
      list1.printList();
    }
    else if (command == 'l'){ //print length
      cout << "List Length is " << list1.length() << endl;
    }
    else if (command == 'c'){ //clear list
      list1.clear();
      cout << "List cleared" << endl;
    }
    else if (command == 'q'){ //quit program
      cout << "Quitting program.." << endl;
      exit(0);
    }

  }//end while loop



  
}
