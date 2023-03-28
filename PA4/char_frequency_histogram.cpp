/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 1st, 2023
 Programming Assignment: PA4                                                                    
 Description: This program takes a sentence and creates a histogram based on the frequency of each letter, capitalized is separate from lowercase.
*/

#include "header.h"

int main() {
    string inputSentence = "";
    LetterOccurrence letterOccs[ARRAY_LENGTH];

    char frequentChar;
    char * frequentCharPtr = &frequentChar;
    int count;
    int * countPtr = &count;
    double maxFrequency;
    double * maxFrequencyPtr = &maxFrequency;

    while (true) {
        cout << "\nPlease input text:    (type quit to exit program)\n";
        cout << "  >>";
        getline(cin, inputSentence);

        if (inputSentence == "quit") {
            break;
        }

        processString(inputSentence, letterOccs);
        computeMaximumOccurences(letterOccs, frequentCharPtr, countPtr, maxFrequencyPtr);

        printHistogram(letterOccs, frequentChar, count, maxFrequency);
    }
    
    cout << endl;

}