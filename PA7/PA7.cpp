/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: All of the functions that main uses
*/

#include "PA7.h"

//Input: Input file name
//Output: Outputs the infix, postfix, and final output for each infix equation included
void runProgram(string fileName) {
    Calculator calc;
    ifstream inFile;
    string symbolTable['Z' + 1];
    string infix = "", postfix = "", result = "";
    

    inFile.open(fileName);

	if (!inFile.is_open()) {
		cout << "!! File Failed to Open !!" << endl;
		return;
    }

    setUpTable(inFile, symbolTable);
    calc.setSymbolTable(symbolTable);
    
    //Prints results in a neat table to the terminal
    cout << "\n";
    while(!inFile.eof()) {
        inFile >> infix;
        if (infix == "#") {
            break;
        }

        postfix = calc.convertInfixToPostfix(infix);
        result = calc.evaluatePostfix(postfix);

        printResults(infix, postfix, result);
    }
    cout << "-------------------------------------------------\n\n";

}

//Input: Input file and the table for correlating characters with values
//Output: The table is updated with values for each character included
void setUpTable(ifstream &inFile, string symbolTable[]) {
    string number = "";
    char operand = '\0';

    while(true) {
        inFile >> operand;
        if (operand == '#') {
            break;
        }

        inFile >> number;
        symbolTable[operand] = number;
    }
}

void printResults(string infix, string postfix, string result) {
    cout << "-------------------------------------------------\n";
    cout << "Infix Equation: " << infix << endl;
    cout << "Postfix Equation: " << postfix << endl;
    cout << "Calculation: " << result << endl;
}