#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// LinkedList class needed for task 4
// no need for any changes here
class LinkedList {
	private:
	   struct Node {
		  int value;
		  struct Node * next;
	   }; 

	   Node * head;
	   
	   // task 4 prototype
	   int getMaxValueHelper(Node *, int);

	public:
	   LinkedList(); 
	   ~LinkedList(); 
	   void insertAtFront(int);
	   void displayList();
	   void appendNode(int);
	   
	   // task 4 prototype
	   int getMaxValue();
};

#endif