/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Header for all the Stack class's functions
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Stack inherits from LinkedList
class Stack : public LinkedList {
	public:
	   // common stack operations
	   void push(string);
	   string pop();
	   string peek();
	   bool isEmpty();
};

#endif