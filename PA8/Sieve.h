/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 25, 2023
 Programming Assignment: PA78                                                          
 Description: The header file for the SIeve class's functions
*/

#ifndef SIEVE_H
#define SIEVE_H

#include <iostream>
#include <cmath>
#include "DoublyLinkedQueue.h"

using namespace std;

class Sieve {
	private:
		int n;
		DoublyLinkedQueue * numsQ; 
		DoublyLinkedQueue * primesQ;
	public:
		Sieve(); // DVC
		Sieve(string); // EVC
		~Sieve(); // destructor
		int getN() const;
		void setN(int);
		void createNumsList(); //New function made by me
		void computePrimes();
		int reportResults(double&);
		void run();
};

#endif