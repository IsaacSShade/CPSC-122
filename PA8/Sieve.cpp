/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 25, 2023
 Programming Assignment: PA78                                                          
 Description: Definitions for all the Sieve class's functions
*/

#include "Sieve.h"

// ----------- STARTER CODE BLOCK ----------- //

Sieve::Sieve() {
	n = 0;
	numsQ = new DoublyLinkedQueue();
	primesQ = new DoublyLinkedQueue();
}

Sieve::~Sieve() {
	if (numsQ != NULL) {
		delete numsQ;
	}
	if (primesQ != NULL) {
		delete primesQ;
	}
}

int Sieve::getN() const {
	return n;
}

void Sieve::setN(int nParam) {
	n = nParam;
}

int Sieve::reportResults(double& primePercent) {
	int numPrimes = 0;
	
	cout << "Primes up to " << n << " are as follows: " << endl;
	primesQ->displayQueue();
	
	numPrimes = primesQ->size();
	primePercent = static_cast<double>(numPrimes) / n * 100;
	
	return numPrimes;
}

void Sieve::run() {
	int numPrimes = 0;
	double primePercent = 0.0;
	
	computePrimes();
	numPrimes = reportResults(primePercent);
	cout << numPrimes << " / " << n << " = " << primePercent << "% primes" << endl;
}

// ------------------------------------------ //

void Sieve::createNumsList() {
	numsQ->destroyList();
	for (int i = 2; i <= n; i++) {
		numsQ->enqueue(i);
	}
}

//Input: N/A
//Output: Creates a new primesQ based off numsQ
void Sieve::computePrimes() {
	int checkNum = 0;

	createNumsList();
	primesQ->destroyList();
	
	while (!numsQ->isEmpty()) {
		//Enqueueing the number from front of numsQ list
		checkNum = numsQ->dequeue();
		numsQ->removeDivisibleBy(checkNum);
		primesQ->enqueue(checkNum);
	}
}

