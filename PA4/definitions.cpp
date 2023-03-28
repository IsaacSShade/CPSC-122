/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 1st, 2023
 Programming Assignment: PA4                                                                   
 Description: These are the definitions for the functions for both tasks
*/

#include "header.h"

/**************************************TASK 1*************************************************/

//Input: The string to be processed, and an array with all the LetterOccurrence structs that correspond to each char that will be measured.
//Output: Inserts the structs with data on the number of times it's char is in the input string, and the frequency of that char to the total chars.
void processString(const string s, LetterOccurrence letterOccs[]) {
    //Total Chars is needed to ignore whitespace
    double totalChars = 0.0;

    //Initializing the LetterOccurrences
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        letterOccs[i].count = 0;
        letterOccs[i].frequency = 0.0;
    }

    for (int i = 0; i < s.length(); i++) {
        
        //Getting the ASCII-based LetterOccurrence and updating count and frequency
        //if the character's ASCII value is greater than A and less than z, and isn't the characters between Z and a
        if (( ((static_cast<int>(s[i]) - 65) > -1) && ((static_cast<int>(s[i]) - 65) < 58)) && !( ((static_cast<int>(s[i]) - 65) >= 26) && ((static_cast<int>(s[i]) - 65) <= 31) )) {
            totalChars++;
            //To account for the skip between the characters in between Z and a
            if (static_cast<int>(s[i]) - 65 > 31) {      
                letterOccs[static_cast<int>(s[i]) - 65 - 6].count++;
                letterOccs[static_cast<int>(s[i]) - 65 - 6].frequency = letterOccs[static_cast<int>(s[i]) - 65].count / totalChars;
            }
            else {
                letterOccs[static_cast<int>(s[i]) - 65].count++;
                letterOccs[static_cast<int>(s[i]) - 65].frequency = letterOccs[static_cast<int>(s[i]) - 65].count / totalChars;
            }
        }
    }
}

//Input: The array with every LetterOccurrence struct that corresponds to the measured chars, and pointers for the output variables.
//Output: The character that is most frequent, the amount of times that character shows up, and the frequency of that character to the total characters
void computeMaximumOccurences(const LetterOccurrence letterOccs[], char * c, int * count, double * freq) {
    int max = -1, maxIndex = -1;

    //Finding the max
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        if (letterOccs[i].count > max) {
            max = letterOccs[i].count;
            maxIndex = i;
        }
    }

    if (maxIndex + 65 > 90) {
        *c = static_cast<char>(maxIndex + 65 + 6);
    }
    else {
        *c = static_cast<char>(maxIndex + 65);
    }
    
    *count = max;
    *freq = letterOccs[maxIndex].frequency;
}

//Input: The array with every LetterOccurrence struct that corresponds to the measured chars, the character that is most frequent, it's amount, and it's frequency
//Output: Prints the histogram and data to the console
void printHistogram(const LetterOccurrence letterOccs[], const char frequentChar, const int maxCount, const double maxFrequency) {
    cout << "\n----------------------------------------------------\n";

    for(int i = maxCount; i > 0; i--) {
        for (int j = 0; j < ARRAY_LENGTH; j++) {

            if (letterOccs[j].count >= i) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }

    cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n";
    cout << "----------------------------------------------------\n";
    cout << "Most Frequent Character: " << frequentChar << endl;
    cout << "Most Frequent Character's Count: " << maxCount << endl;
    cout << "Most Frequent Character's Frequency: " << maxFrequency << endl;
}

/**************************************TASK 2*************************************************/

//Input: The input file
//Output: The name of the driver, the number of packages, and an array with all of the Package structs.
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
    string placeholder = "";
    getline(inFile, *driverName);
    Package * packageArray;

    //Start counting number of packages delivered
    while(!inFile.eof()) {
        for (int i = 0; i < 7; i++) {
            getline(inFile, placeholder);
        }

        (*numPackages)++;
    }

    //Declaring dynamic memory array because we have the number of packages
    packageArray = new Package[*numPackages];

    //Going back to beginning of input file
    inFile.clear();
    inFile.seekg(0, ios::beg);

    //Get rid of first line
    getline(inFile, placeholder);

    //Start putting data into array
    for(int i = 0; i < *numPackages; i++) {
        getline(inFile, placeholder);
        inFile >> packageArray[i].ID;
        inFile >> packageArray[i].weight;
        inFile >> packageArray[i].width;
        inFile >> packageArray[i].length;
        inFile >> packageArray[i].height;
        //Switching from >> to getline so need to use ignore
        inFile.ignore();
    }

    return packageArray;
}

//Input: An array with all the Pacakge structs, and the number of packages
//Output: The heaviest package's ID, weight, and the average weight of all packages
void computePackageStats(const Package * packages, const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
    for (int i = 0; i < numPackages; i++) {

        if (packages[i].weight > *heaviestWeight) {
            *heaviestWeight = packages[i].weight;
            *heaviestId = packages[i].ID;
        }

        *avgWeight += packages[i].weight;
    }

    *avgWeight = (*avgWeight) / numPackages;
}

//Input: An array with all the Package structs, the name of the driver, number of packages, the heaviest package's ID, weight, and the average weight of all packages.
//Output: A printed list of every Package struct, it's attributes, the name of the driver, and the statistics of the packages.
void printPackageStats(const Package * packages, const string driverName, const int numPackages, const int heaviestID, const double heaviestWeight, 
 const double avgWeight) {
    cout << "\nNumber of Packages on " << driverName << "'s truck: " << numPackages << endl;
    cout << "-----------------------\n";
    cout << "| Package Information |\n";
    cout << "-----------------------";
    
    for (int i = 0; i < numPackages; i++) {
        cout << "\n\nPackage ID: " << packages[i].ID;
        cout << "\nPackage Weight: " << packages[i].weight;
        cout << "\nPackage Width: " << packages[i].width;
        cout << "\nPackage Length: " << packages[i].length;
        cout << "\nPackage Height: " << packages[i].height;
    }

    cout << "\n\n-----------------\n";
    cout << "| Package Stats |\n";
    cout << "-----------------\n";
    cout << "\nID of Heaviest Package: " << heaviestID;
    cout << "\nWeight of Heaviest Package: " << heaviestWeight;
    cout << "\nAverage Weight of Packages: " << avgWeight;
    cout << endl << endl;

}