/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 25, 2023
 Programming Assignment: PA78                                                          
 Description: Definitions for all the Doubly Linked List class's functions
*/

#include "DoublyLinkedList.h"

// ----------- STARTER CODE BLOCK ----------- //

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
	// free each Node's memory in the list
	destroyList();
}

Node * DoublyLinkedList::getHead() const {
	return head;
}

Node * DoublyLinkedList::getTail() const {
	return tail;
}

void DoublyLinkedList::setHeadAndTail(Node * newHead, Node * newTail) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
	tail = newTail;
}

void DoublyLinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
	if (tail != NULL) {
		cout << "tail->" << tail->value << endl;
	}
	else {
		cout << "tail->NULL" << endl;
	}
}

// ------------------------------------------ //

//Input: Value to be assigned to the new node
//Output: Adds the node to the end of the list.
void DoublyLinkedList::addToEnd(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->prev = tail;
	newNode->next = NULL;

	//If the list is empty
	if (tail == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

//Input: N/A
//Output: Value of the node that was deleted
int DoublyLinkedList::deleteAtFront() {
	int value = 0;
	Node * newHead = NULL;

	if (head == NULL) {
		return -1;
	}
	
	value = head->value;
	newHead = head->next;
	if (newHead != NULL) {
		newHead->prev = NULL;
	}
	
	delete head;
	head = newHead;

	return value;
}

//Input: Value to search for
//Output: Deletes the first node with that value, and returns that value.
int DoublyLinkedList::deleteNode(int targetValue) {
	Node * curr = head;

	while (curr != NULL) {
		if (curr->value == targetValue) {
			//If deleting head or tail
			if (curr->prev == NULL) {
				return deleteAtFront();
			}
			else if (curr->next == NULL) {
				return deleteAtEnd();
			}
			else {
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
		
				delete curr;
				return targetValue;
			}
		}
		curr = curr->next;
	}
	//If not found
	return -1;
}

//Input: Value for the new node
//Output: Adds a node to the front of the list
void DoublyLinkedList::addToFront(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = head;
	newNode->prev = NULL;

	//If the list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		head = newNode;
	}
}

//Input: N/A
//Output: Value of the node that was deleted
int DoublyLinkedList::deleteAtEnd() {
	int value = 0;
	Node * newTail = NULL;

	if (tail == NULL) {
		return -1;
	}
	
	value = tail->value;
	newTail = tail->prev;
	newTail->next = NULL;

	delete tail;
	tail = newTail;

	return value;
}

//Input: Value to insert
//Output: Inserts a new node in the list sorted by lowest to highest
void DoublyLinkedList::insertInOrder(int newValue) {
	Node * newNode = new Node;
	Node * curr = head;
	newNode->value = newValue;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	while (curr != NULL) {
		//Assuming order is lowest to highest, it is not specified on the document!!!!
		if (curr->value > newValue) {
			//If replacing head or tail
			if (curr->prev == NULL) {
				addToFront(newValue);
				delete newNode;
			}
			else if (curr->next == NULL) {
				addToEnd(newValue);
				delete newNode;
			}
			else {
				newNode->prev = curr->prev->next;
				curr->prev->next = newNode;
				newNode->next = curr;
				curr->prev = newNode;
			}

			return;
		}

		curr = curr->next;
	}
}