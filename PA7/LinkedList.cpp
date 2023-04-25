/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Definitions for all the LinkedList class's functions
*/

#include "LinkedList.h"

// ----------- STARTER CODE BLOCK ----------- //

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

// ------------------------------------------ //

//Input: Value for the node
//Output: Creates a node at the top of the linked list stack
void LinkedList::insertAtFront(string newValue) {
	Node * newNode = new Node;

	newNode->value = newValue;
	newNode->next = head;

	head = newNode;
}

//Input: N/A
//Output: Deletes the node at the front and returns the value of that node.
string LinkedList::deleteAtFront() {
	string nodeValue = "";
	Node * oldhead = NULL;

	
	if (head == NULL) {
		return "";
	}
	else {
		nodeValue = head->value;
		oldhead = head;
		head = head->next;
		delete oldhead;
		return nodeValue;
	}
}