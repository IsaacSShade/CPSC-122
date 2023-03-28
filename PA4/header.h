/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 1st, 2023
 Programming Assignment: PA4                                                                    
 Description: This is the header file for both tasks, has two structs called LetterOccurrence and Package.
*/

#ifndef HEADER_H
    #define HEADER_H
    #include <iostream>
    #include <string>
    #include <fstream>

    using namespace std;

    struct LetterOccurrence
    {
        int count;
        double frequency;
    };

    struct Package {
        int ID;
        double weight;
        int width;
        int length;
        int height;
    };

    const int ARRAY_LENGTH = 52;

    void processString(const string s, LetterOccurrence letterOccs[]);
    void computeMaximumOccurences(const LetterOccurrence letterOccs[], char * c, int * count, double * freq);
    void printHistogram(const LetterOccurrence letterOccs[], const char frequentChar, const int maxCount, const double maxFrequency);

    Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages);
    void computePackageStats(const Package * packages, const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight);
    void printPackageStats(const Package * packages, const string driverName, const int numPackages, const int heaviestID, const double heaviestWeight, 
     const double avgWeight);


    
#endif