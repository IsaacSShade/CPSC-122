/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA1                                                                      
 Description: This program translates english to morse code and morse code to english.
*/

#include "header.h"

int main() {

    ifstream inFile;
    ofstream outFile;
    vector<char> lineCharacters['\0'];

    string inFileName = "", outFileName = "";
    int totalChars = 0;
    bool engToMorse = false;

    engToMorse = userInput(inFileName, outFileName);

    openFiles(inFile, inFileName, outFile, outFileName);

    if(engToMorse) {
        englishToMorse(inFile, outFile, totalChars);
    }
    else {
        morseToEnglish(inFile, outFile, totalChars);
    }
    
    cout << "Total characters (including whitespace and newlines): " << totalChars << endl << endl;
    closeFiles(inFile, outFile);
}
