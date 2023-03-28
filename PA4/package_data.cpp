/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 1st, 2023
 Programming Assignment: PA4                                                                  
 Description: This program takes an input file with a list of packages and their data, and prints out a list of all it's statistics in a neat way.
*/

#include "header.h"

int main(int argc, char * argv[]) {
    ifstream inFile;
    Package * packageArray;

    string truckerName = "";
    string * truckerNamePtr = &truckerName;
    int numPackages = 0, heaviestID = 0;
    int * numPackagesPtr = &numPackages, * heaviestIDPtr = &heaviestID;
    double heaviestWeight = -1.0, averageWeight = 0.0;
    double * heaviestWeightPtr = &heaviestWeight, * averageWeightPtr = &averageWeight;

    //Opening file
    inFile.open(argv[1]);

    if (inFile.is_open()) {

    }
    else {
        cout << "!! File Failed to Open !!" << endl;
        cout << "Name of file: " << argv[1] << endl;
        return -1;
    }

    packageArray = loadPackages(inFile, truckerNamePtr, numPackagesPtr);
    computePackageStats(packageArray, numPackages, heaviestIDPtr, heaviestWeightPtr, averageWeightPtr);
    printPackageStats(packageArray, truckerName, numPackages, heaviestID, heaviestWeight, averageWeight);

    //Closing file and deleting dynamically allocated memory
    delete(packageArray);
    packageArray = nullptr;
    inFile.close();
}

