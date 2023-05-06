#include "PA9.h"

// TODO: finish this function
int countDigits(string s) {
	return -1; // TODO: fix this
}

// TODO: finish this function by testing countDigits()
void runTask1() {

}

// TODO: finish this function
int sumDigits(int num) {
	return -1; // TODO: fix this
}

// TODO: finish this function by testing sumDigits()
void runTask2() {

}

// TODO: finish this function
bool isPalindrome(string s) {
	return false; // TODO: fix this
}
	
// TODO: finish this function by testing isPalindrome()
void runTask3() {

}

// TODO: finish this function by testing getMaxValue() and getMaxValueHelper()
void runTask4() {

}

// TODO: finish this function
void generateSubstrings(string s, vector<string>& substrings) {

}

// TODO: finish this function by testing generateSubstrings()
void runTask5() {

}

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