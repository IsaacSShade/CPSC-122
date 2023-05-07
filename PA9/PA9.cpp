/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: May 6, 2023
 Programming Assignment: PA9                                                          
 Description: Definitions for all of PA9's functions
*/

#include "PA9.h"

//Input: A string
//Output: The number of digits in that string
int countDigits(string s) {
	int count = 0;

	if (s.length() == 0) {
		return 0;
	}

	count += countDigits(s.substr(1));

	//Use function isdigit() to see if character is an int
	if (isdigit(s[0]) == true ) {
		count += 1;
	}

	return count;
}

//Input: N/A
//Output: Runs a function to count the number of digits in a user-inputted string.
void runTask1() {
	string input = "";
	int numDigits = 0;

	cout << "Please input a string to count the digits within (EX: 10N4)\n";
	cout << " >> ";
	getline(cin, input);
	numDigits = countDigits(input);
	cout << "\nDigits found: " << numDigits << endl;
	cout << "-----------------------------------\n";
	
}

//Input: A number
//Output: Finds the sum of the digits of the number.
int sumDigits(int num) {
	string input = "", newInput = "", startNumStr = "";
	int newNum = 0, sum = 0, startNum = 0;

	input = to_string(num);
	
	if (input.length() != 1) {
		newInput = input.substr(1);
		newNum = stoi(newInput);
		sum = sumDigits(newNum);

		startNumStr = input[0];
		startNum = stoi(startNumStr);

		return (startNum + sum);
	}
	else {
		//End case
		return num;
	}
}

//Input: N/A
//Output: Runs a function to calculate the sum from digits in a user-inputted int.
void runTask2() {
	int input = 0;

	cout << "Please input an int to add the sum of the digits within (EX: 164)\n";
	cout << " >> ";

	cin >> input;
	if (!cin) {
		cout << "\n\n!! Invalid Input !!\n\n";
		return;
	}
	cin.ignore();

	cout << "\nSum of Digits: " << sumDigits(input) << endl;
	cout << "-----------------------------------\n";
}

//Input: A string
//Output: True if a palindrome or empty string, false if not a palindrome
bool isPalindrome(string s) {
	string newString = s;
	
	//If there's 0 or 1 character left (END CASE)
	if (s.length() < 2) {
		return true;
	}
	//Replacing whitespace characters while still using the recursiveness for cool points
	if (s[0] == ' ') {
		return isPalindrome(s.substr(1));
	}
	if (s[s.length() - 1] == ' ') {
		return isPalindrome(s.substr(0, (s.length() - 1)));
	}

	//Checking if both sides equal each other
	if (s[0] == s[s.length() - 1]) {
		return isPalindrome(s.substr(1, (s.length() - 2)));
	}
	else {
		return false;
	}
}
	
//Input: N/A
//Output: Runs a function to determine whether a user-inputted string is a palindrome.
//Notes: Used this to display true/false https://stackoverflow.com/questions/15960015/c-printing-boolean-what-is-displayed
void runTask3() {
	string input = "";

	cout << "Please input a string to detect if it's a palindrome - capitalization matters (EX: anna)\n";
	cout << " >> ";

	getline(cin, input);

	cout << "\nPalindrome?: " << boolalpha << isPalindrome(input) << endl;
	cout << "-----------------------------------\n";
}

//Input: N/A
//Output: Creates a linked list from user input, then finds the maximum.
void runTask4() {
	int input1 = 0, input2 = 0, input3 = 0;
	LinkedList testList;

	cout << "Please input 3 numbers separated by a space to put inside a linked list to find the maximum (EX: 1 12003 4)\n";
	cout << " >> ";
	//Assuming they input correctly
	cin >> input1;
	cin >> input2;
	cin >> input3;
	cin.ignore();

	testList.appendNode(input1);
	testList.appendNode(input2);
	testList.appendNode(input3);

	cout << "\nMaximum Found: " << testList.getMaxValue() << endl;
	cout << "-----------------------------------\n";
	
}

//Input: A string 
//Output: All possible substrings of the initial string (passed by reference)
void generateSubstrings(string s, vector<string>& substrings) {
	
	if (s.length() <= 1) {
		substrings.push_back(s);
		substrings.push_back("");
	}
	else {
		sequentialSubstrings(s, substrings);
		generateSubstrings(s.substr(1), substrings);
	}
}

//Input: A string and a vector that will contain all of the substrings
//Output: Adds all substrings of the string getting shrunk by one to the vector
void sequentialSubstrings(string s, vector<string>& substrings) {
	substrings.push_back(s);

	if (s.length() != 1) {
		sequentialSubstrings(s.substr(0, (s.length() - 1)), substrings);
	}
}

//Input: List of substrings
//Output: Prints out a list of the substrings in the vector to the terminal
void printSubstrings(vector<string>& substrings) {
	if (substrings.size() == 0) {
		return;
	}

	cout << substrings[substrings.size() - 1] << ", ";
	substrings.pop_back();
	printSubstrings(substrings);
}

//Input: N/A
//Output: Outputs every substring of the user-inputted string
void runTask5() {
	vector<string> substrings;
	string input = "";

	cout << "Please input a string to find all substrings of it (EX: tweedle)\n";
	cout << " >> ";

	getline(cin, input);

	cout << "\nSubstrings Found: ";
	generateSubstrings(input, substrings);
	printSubstrings(substrings);
	cout << "\n-----------------------------------\n";
}

// ------------ BONUS | I did not do this ------------ //

// BONUS ONLY: utility function for BONUS task
// no need for any changes here
void displayMaze(char maze[8][8]) {
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for(i = 0; i < 8; i++) {
		cout << i;
		for(j = 0; j < 8; j++) {
			cout << " " << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// TODO: BONUS ONLY finish this function
bool traverseMaze(char maze[8][8], Coordinates solution[], int * steps, int currRow, int currCol) {
	return false; // TODO: fix this
}

// TODO: BONUS ONLY finish this function by testing traverseMaze()
void runBONUSTask() {
	
}