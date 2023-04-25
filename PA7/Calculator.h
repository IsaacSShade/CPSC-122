#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Header for all the Calculator class's functions
*/

#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);

// -------------- Functions I've added --------------
int precedenceAssigner(string value, bool notOnStack);
string calculateValue(string operation, string rightValue, string leftValue);
// --------------------------------------------------

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);
};

#endif