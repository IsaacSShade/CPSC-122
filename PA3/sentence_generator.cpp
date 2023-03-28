/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: Febuary 12, 2023
 Programming Assignment: PA3
 Description: Takes an input file full of words and says how many sentences to generate, and generates random sentences based off of those words! It also sorts
              the word bank in alphabetical order and prints them.
*/

#include "header.h"

int main() {

    //Seeding new random numbers
    srand(time(NULL));

    ifstream inFile;
    string * articles = nullptr, * nouns = nullptr, * verbs = nullptr, * prepositions = nullptr, * sentencePtr;
    string ignore = "", sentence = "";
    int numSentences = 0, articleSize = 0, nounSize = 0, verbSize = 0, prepSize = 0;

    sentencePtr = &sentence;

    //Checking if file opened successfully
    inFile.open("input_words.txt");
    if (inFile.is_open()) {

    }
    else {
        cout << "!! File failed to open !!" << endl;
        return -1;
    }

    inFile >> numSentences;

    inFile >> ignore;
    inFile >> articleSize;
    articles = createWordsArray(inFile, articleSize);

    inFile >> ignore;
    inFile >> nounSize;
    nouns = createWordsArray(inFile, nounSize);

    inFile >> ignore;
    inFile >> verbSize;
    verbs = createWordsArray(inFile, verbSize);

    inFile >> ignore;
    inFile >> prepSize;
    prepositions = createWordsArray(inFile, prepSize);

    //Sorting the arrays
    sortArray(articles, articleSize);
    sortArray(nouns, nounSize);
    sortArray(verbs, verbSize);
    sortArray(prepositions, prepSize);

    //Starting to print Results
    cout << endl << "WORD BANK:\n";
    printArray("Articles", articles, articleSize);
    printArray("Nouns", nouns, nounSize);
    printArray("Verbs", verbs, verbSize);
    printArray("Prepositions", prepositions, prepSize);
    cout << endl;
    

    cout << "SENTENCES:\n";
    for(int i = 0; i < numSentences; i++) {
        generateSentence(sentencePtr, articles, articleSize, nouns, nounSize, verbs, verbSize, prepositions, prepSize);
        cout << " " << (i + 1) << ". " << sentence << endl;
    }

    cout << endl;
    delete(articles);
    delete(nouns);
    delete(verbs);
    delete(prepositions);
    articles = nullptr;
    nouns = nullptr;
    verbs = nullptr;
    prepositions = nullptr;

    inFile.close();

    return 0;
}

