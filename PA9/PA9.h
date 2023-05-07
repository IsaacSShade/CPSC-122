/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: May 6, 2023
 Programming Assignment: PA9                                                          
 Description: Header file for for all of PA9
*/

#ifndef PA9_H
#define PA9_H

#include <iostream>
#include <vector>

// for task 4
#include "LinkedList.h"

using namespace std;

// TODO: add your additional PA9.cpp function prototypes in the appropriate spot below

// task 1 prototypes
int countDigits(string);
void runTask1();

// task 2 prototypes
int sumDigits(int);
void runTask2();

// task 3 prototypes
bool isPalindrome(string);
void runTask3();

// task 4 prototypes
void runTask4();

// task 5 prototypes
void generateSubstrings(string, vector<string>&);
void sequentialSubstrings(string, vector<string>&);
void printSubstrings(vector<string>&);
void runTask5();

// BONUS ONLY struct definition and prototypes
struct Coordinates {
	int row;
	int col;
};
bool traverseMaze(char[8][8], Coordinates[], int *, int, int);
void displayMaze(char[8][8]);
void runBONUSTask();

#endif