/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: May 6, 2023
 Programming Assignment: PA9                                                          
 Description: Header file for all of the Linked Lists's class's functions
*/

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