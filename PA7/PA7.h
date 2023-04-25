/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 18, 2023
 Programming Assignment: PA7                                                           
 Description: Header file for the main program
*/

#ifndef PA7_H
#define PA7_H

#include <iostream>
#include <fstream>
#include "Calculator.h"

using namespace std;

void runProgram(string fileName);
void setUpTable(ifstream &inFile, string symbolTable[]);
void printResults(string infix, string postfix, string result);


#endif