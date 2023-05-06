/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 25, 2023
 Programming Assignment: PA78                                                          
 Description: The header file for the Doubly Linked Queue class's functions
*/

#ifndef DOUBLY_LINKED_QUEUE_H
#define DOUBLY_LINKED_QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class DoublyLinkedQueue : public DoublyLinkedList {
    public:    
		// common queue operations
		// implementation provided
		void displayQueue();

		// implementations not provided
		void enqueue(int);
		int dequeue();
		void clear();
		bool isEmpty();
		int size();

		// sieve specific queue operation
		// implementation not provided
		void removeDivisibleBy(int);

};

#endif