/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Definitions for all the Calculator class's functions
*/

#include "Calculator.h"

//Input: Table of values and their corresponding character
//Output: Updates the class's own symbol table
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

//Input: The operator on the top of the stack, and an operator to compare it to
//Output: Returns true if the operator on the stack has higher precedence than the current operator, false if otherwise
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
	if (precedenceAssigner(operatorOnStack,  false) > precedenceAssigner(currentOperator, true)) {
		return true;
	}
	else {
		return false;
	}
	
}

//Input: Value to check, true if this item is not already on the stack and false if on the stack.
//Output: The precedence value assigned to that operator - returns -1 if not an operator
int precedenceAssigner(string value, bool notOnStack) {
	if (value == "(") {
		return 100 * static_cast<int>(notOnStack);
	}
	else if (value == ")") {
		return 0;
	}
	else if (value == "^") {
		return 5 + static_cast<int>(notOnStack);
	}
	else if (value == "*") {
		return 4 - static_cast<int>(notOnStack);
	}
	else if (value == "/") {
		return 4 - static_cast<int>(notOnStack);
	}
	else if (value == "%") {
		return 4 - static_cast<int>(notOnStack);
	}
	else if (value == "+") {
		return 2 - static_cast<int>(notOnStack);
	}
	else if (value == "-") {
		return 2 - static_cast<int>(notOnStack);
	}
	else {
		//If not an operator then it is an operand and returns -1
		return -1;
	}
}

//Input: Operator, the right side value, and the left side value
//Output: Calculation of equation using the operator specified
string calculateValue(string operation, string rightValue, string leftValue) {
	long endResult = 0, rightNumber = stoi(rightValue), leftNumber = stoi(leftValue);


	if (operation == "^") {
		endResult = pow(leftNumber, rightNumber);
	}
	else if (operation == "*") {
		endResult = leftNumber * rightNumber;
	}
	else if (operation == "/") {
		endResult = leftNumber / rightNumber;
	}
	else if (operation == "%") {
		endResult = leftNumber % rightNumber;
	}
	else if (operation == "+") {
		endResult = leftNumber + rightNumber;
	}
	else if (operation == "-") {
		endResult = leftNumber - rightNumber;
	}

	return to_string(endResult);
}

//Input: Infix string
//Output: Postfix string
string Calculator::convertInfixToPostfix(string infix) {
	
	string postfix = "", checkValue = "", poppedValue = "";

	for (int i = 0; i < infix.length(); i++) {
		checkValue = infix[i];  

		if (precedenceAssigner((checkValue), true) == -1) {  //character is an operand
			postfix += checkValue;
		}
		else {     //character is an operator
			if ((stack.isEmpty() == true) || (precedenceAssigner(checkValue, true) == 100)) {
				//If there's nothing in the list or if value is "("
				stack.push(checkValue);
			}
			else if (precedenceAssigner(checkValue, true) == 0) {
				//If value is ")"
				poppedValue = "";  //Resetting for multiple for loops
				while (!(poppedValue == "(")) {
					postfix += poppedValue;
					poppedValue = stack.pop();
				}
			}
			else {
				while ((stack.isEmpty() == false) && checkOperatorOnStackPrecedence(stack.peek(), checkValue)) {
					postfix += stack.pop();	
				}
				
				stack.push(checkValue);
			}
		}
	}

	//Pushing last bit of stack if there is any
	while (stack.isEmpty() == false) {
		postfix += stack.pop();
	}
	
	return postfix;
}

//Input: Postfix string
//Output: Calculation of Postfix equation
string Calculator::evaluatePostfix(string postfix) {
	string checkValue = "", calculation = "";

	for(int i = 0; i < postfix.length(); i++) {
		checkValue = postfix[i];

		if (precedenceAssigner(checkValue, true) == -1) {
			//checkValue is an operand
			stack.push(symbolTable[postfix[i]]);
		}
		else {
			//checkValue is an operator
			calculation = calculateValue(checkValue, stack.pop(), stack.pop());
			stack.push(calculation);
		}
	}

	return stack.pop();
}

