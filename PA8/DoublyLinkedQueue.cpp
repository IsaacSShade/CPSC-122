/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 25, 2023
 Programming Assignment: PA78                                                          
 Description: Definitions for all the Doubly Linked Queue class's functions
*/

#include "DoublyLinkedQueue.h"

// ----------- STARTER CODE BLOCK ----------- //

void DoublyLinkedQueue::displayQueue() {
	Node * currNode = head;
	
	while (currNode != NULL) {
		cout << currNode->value << " ";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << endl;
}

// ------------------------------------------ //

//Input: A numeric value
//Output: Adds that value to back of the queue
void DoublyLinkedQueue::enqueue(int newValue) {
	addToEnd(newValue);
}

//Input: N/A
//Output: The value of the front of the queue
int DoublyLinkedQueue::dequeue() {
	return deleteAtFront();
}

//Input: N/A
//Output: Destroys the entire list
void DoublyLinkedQueue::clear() {
	destroyList();
}

//Input: N/A
//Output: Returns true if it's empty, false if not.
bool DoublyLinkedQueue::isEmpty() {
	if (head == NULL) {
		return true;
	}

	return false;
}

//Input: N/A
//Output: The size of the queue
int DoublyLinkedQueue::size() {
	Node * curr = head;
	int size = 0;

	while (curr != NULL) {
		curr = curr->next;
		size++;
	}

	return size;
}

//Input: A number to check
//Output: Deletes all nodes that can be divided by the inputted number
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	Node * curr = head, * temp = NULL;
	
	while (curr != NULL) {
		if (curr->value % p == 0 ) {
			temp = curr->next;
			deleteNode(curr->value);
			curr = temp;
		}
		else {
			curr = curr->next;
		}
	}
}
