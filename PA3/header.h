/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: Febuary 12, 2023
 Programming Assignment: PA3
 Description: A combined header file for all 3 tasks.
*/

//I've made a combined header file for all tasks
#ifndef HEADER_H
    #define HEADER_H

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cmath>
    #include <vector>
    #include <time.h>

    using namespace std;

    const int PRIME_NUMBERS[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    const int NUM_PLAYER_NUMBERS = 10;

    void answerIntegerQuestions(const int num, bool * isMultiple, bool * isSumEven, bool * isPrime);
    void isNumMultiple(const int num, const int checkNum, bool * isMultiple);
    void isNumPrime(const int num, bool * isPrime);

    bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers);

    string * createWordsArray(ifstream& inFile, const int size);
    void generateSentence(string * sentence, const string * articlesArr, const int articlesSize, const string * nounsArr, const int nounsSize,
     const string * verbsArr, const int verbsSize, const string * prepsArr, const int prepsSize);
    void sortArray(string * list, const int listSize);
    void printArray(const string name, const string * list, const int listArray);

#endif