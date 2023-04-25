/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Definitions for all the Stack class's functions
*/

#include "Stack.h"

//Input: Value to push on the stack
//Output: Adds a node to the top of the stack
void Stack::push(string newValue) {
	return insertAtFront(newValue);
}

//Input: N/A
//Output: Value of the node on the top of the stack
string Stack::pop() {
	return deleteAtFront();
}

//Input: N/A
//Output: Returns value at top of stack
string Stack::peek() {
	return head->value;
}

//Input: N/A
//Output: Returns true if stack is empty, returns false if not.
bool Stack::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}