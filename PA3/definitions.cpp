/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: Febuary 12, 2023
 Programming Assignment: PA3
 Description: A combined definitions file for the functions on all 3 tasks.
*/

# include "header.h"

/*************************Task 1 Functions******************************/

//Input: The number to check
//Output: Pointers to the different boolean checks: is it a multiple of 7, 11, 13, is the sum of all numbers even, and is the number prime
void answerIntegerQuestions(const int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
    bool alreadyEven = *isSumEven;

    //Resetting values
    *isMultiple = false;
    *isSumEven = false;
    *isPrime = false;

    isNumMultiple(num, 7, isMultiple);
    isNumMultiple(num, 11, isMultiple);
    isNumMultiple(num, 13, isMultiple);

    //Able to reuse previous function for isSumEven
    isNumMultiple(num, 2, isSumEven);
    //if new number is even and previous is even then = even (value already given from function)
    //if new number is odd and previous is even then = odd (value already given from function)
    if (((alreadyEven == false) && (*isSumEven == true)) || ((alreadyEven == true) && (*isSumEven == false))) {
        //if new number is even and previous is odd then = odd and vice versa
        *isSumEven = false;
    }
    if ((alreadyEven == false) && (*isSumEven == false)) {
        //if new number is odd and previous is odd, then = even
        *isSumEven = true;
    }
    
    isNumPrime(num, isPrime);

}

//Input: The number to check, and the number to check whether the previous number is a multiple of
//Output: A boolean pointer that returns true if it's a multiple of it
void isNumMultiple(const int num, const int checkNum, bool * isMultiple) {
    if (*isMultiple == false) {
        if (abs(num) >= checkNum) {
            if ((num % checkNum) == 0) {
                *isMultiple = true;
            }
        }
    }
}

//Input: The number to check
//Output: The pointer to a boolean that returns true if the number is prime
void isNumPrime(const int num, bool * isPrime) {
    *isPrime = true;
    for (int i = 0; i < 25; i++) {
        if (num == 1) {
            *isPrime = false;
            break;
        }
        if (num <= PRIME_NUMBERS[i]) {
            break;
        }
        if ((num % PRIME_NUMBERS[i]) == 0) {
            *isPrime = false;
            break;
        }
    }
}

/*************************Task 2 Functions******************************/

//Input: The winning ticket number, the pointer to the array of all the player's numbers, and the number of numbers in that array
//Output: Returns true if the player has won the lottery
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers) {
    for(int i = 0; i < numPlayerNumbers; i++) {
        if (winningTicketNum == *(playerNumbers + i)) {
            return true;
        }
    }

    return false;
}

/*************************Task 3 Functions******************************/

//Input: The file to read from, and the size of the array
//Output: Creates an array in dynamic memory and returns the string pointer of that array of words
string * createWordsArray(ifstream& inFile, const int size) {
    string * arrayPtr;
    arrayPtr = new string[size];

    for(int i = 0; i < size; i++) {
        inFile >> arrayPtr[i];
    }

    return arrayPtr;
}

//Input: The pointer to the different dynamic memory arrays for the different types of words, and the number of words in those arrays
//Output: The pointer to the sentecnce it generates
void generateSentence(string * sentence, const string * articlesArr, const int articlesSize, const string * nounsArr, const int nounsSize,
 const string * verbsArr, const int verbsSize, const string * prepsArr, const int prepsSize) {
    //Initializing variables
    string article1 = articlesArr[(rand() % articlesSize)], noun1 = nounsArr[(rand() % nounsSize)], verb = verbsArr[(rand() % verbsSize)];
    string prep = prepsArr[(rand() % prepsSize)],article2 = articlesArr[(rand() % articlesSize)], noun2 = nounsArr[(rand() % nounsSize)];
    
    //Structure is article noun verb preposition article noun -- Capitatilize first letter and add exclamation point at end
    article1[0] = toupper(article1[0]);
    *sentence = article1 + " " + noun1 + " " + verb + " " + prep + " " + article2 + " " + noun2 + "!";
}

//Input: The pointer to the dynamic memory array and the size of that array
//Output: Sorts the array
void sortArray(string * list, const int listSize) {
    bool sorted = false;
    string placeholder = "";

    //bubble sort
    while(!sorted) {
        sorted = true;
        for(int i = 0; i < (listSize - 1); i++) {

            if(list[i].compare(list[i + 1]) > 0) {
                sorted = false;
                placeholder = list[i];
                list[i] = list[i + 1];
                list[i + 1] = placeholder;
            }
        }
    }
}

//Input: A name for the array, the pointer to that dynamic memory string array, and the number of variables in that array
//Output: Outputs a list of everything in that list after the name of that array
void printArray(const string name, const string * list, const int listArray) {
    cout << name << ":";
    for (int i = 0; i < listArray; i++) {
        cout << " " << list[i];
    }
    cout << endl;
}