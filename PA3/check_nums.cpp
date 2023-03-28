/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: Febuary 12, 2023
 Programming Assignment: PA3                                                                   
 Description: This program checks every number in a document whether it's a multiple of 7, 11, 13, whether the sum of the numbers is even, or if it's a prime
              number and shows the results in the terminal.
*/

#include "header.h"

int main () {

    ifstream infile;

    int num = 0, sum = 0;
    bool isMultiple = false, isSumEven = true, isPrime = false;
    bool * multiplePtr = &isMultiple, * evenPtr = &isSumEven, * primePtr = &isPrime;

    //Checking if file opened successfully
    infile.open("numbers.txt");
    if (infile.is_open()) {

    }
    else {
        cout << "!! File failed to open !!" << endl;
        return -1;
    }

    while(!infile.eof()) {
        infile >> num;
        answerIntegerQuestions(num, multiplePtr, evenPtr, primePtr);
        sum += num;
        cout << "Number: " << num << " | Sum: " << sum << endl;
        cout << "  Multiple of 7, 11, or 13? || ";
        if (isMultiple) {
            cout << "   | Yes" << endl;
        }
        else {
            cout << "No |" << endl;
        }

        cout << "  Is the current sum even?  || ";
        if (isSumEven) {
            cout << "   | Yes" << endl;
        }
        else {
            cout << "No |" << endl;
        }

        cout << "  Is this a prime number?   || ";
        if (isPrime) {
            cout << "   | Yes" << endl;
        }
        else {
            cout << "No |" << endl;
        }
    }

    return 0;
}
