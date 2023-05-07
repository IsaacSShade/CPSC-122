/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: May 6, 2023
 Programming Assignment: PA9                                                          
 Description: Definitions for all of the Linked Lists's class's functions
*/

#include "LinkedList.h"

// ----------- STARTER CODE BLOCK ----------- //

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	
	head = NULL;
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

void LinkedList::appendNode(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
	} 
	else {
		Node * currNode = head;
		while (currNode->next != NULL) {
			currNode = currNode->next;
		}
		currNode->next = newNode;
	}
}

// ------------------------------------------ //

//Input: The next node's memory address, and the current largest number found
//Output: The largest number
int LinkedList::getMaxValueHelper(Node *nodePtr, int largest) {	
	if (nodePtr == NULL) {
		return largest;
	}
	
	if (nodePtr->value > largest) {
		return getMaxValueHelper(nodePtr->next, nodePtr->value);
	}
	else {

		return getMaxValueHelper(nodePtr->next, largest);
	}
}


//Input: N/A
//Output: The largest value
int LinkedList::getMaxValue() {
	if (head == NULL) {
		return -1;
	}
	else {
		return getMaxValueHelper(head, head->value);
	}
}