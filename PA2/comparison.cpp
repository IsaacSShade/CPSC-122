/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA2                                                                     
 Description: This program sorts larger and larger datasets of different types using different methods. The efficiency is then put into a data file for each method.
 Notes: I learned how to find the time using https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
*/

#include "header.h"

int main() {
    ofstream selectionResults, bubbleResults, insertionResults;
    vector<int> values = {};
    string tableType = "";

    int dataComparisons = 0, loopComparisons = 0, dataAssignment = 0, loopAssignment = 0, otherOperations = 0, count = 0;
    double time = 0.0;

    //Opening files
    selectionResults.open("selection_sort_results.csv");
    bubbleResults.open("bubble_sort_results.csv");
    insertionResults.open("insertion_sort_results.csv");

    //Setting up table
    selectionResults << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total\n";
    bubbleResults << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total\n";
    insertionResults << "Vector Configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total\n";

    //Decided not to put this as a function because I can't repeat everything for all 3 by using one function because there's different functions for the sorting
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {

            //Picking the different counts
            if (j == 0) {
                count = 500;
            }
            else if (j == 1) {
                count = 1000;
            }
            else if (j == 2) {
                count = 5000;
            }
            else if (j == 3) {
                count = 10000;
            }

            //Picking list of values scenario
            if (i == 0) {
                createSortedVector(values, count);
                tableType = "Sorted";
            }
            else if (i == 1) {
                createDescendingVector(values, count);
                tableType = "Descending";
            }
            else if (i == 2) {
                createRandomVector(values, count);
                tableType = "Random";
            }
            
            selectionResults << tableType << " N=" << count << ",";
            bubbleResults << tableType << " N=" << count << ",";
            insertionResults << tableType << " N=" << count << ",";
            
            //Selection Sort
            time = selectionSort(values, dataComparisons, loopComparisons, dataAssignment, loopAssignment, otherOperations);

            selectionResults << time << ", " << dataComparisons << ", " << loopComparisons << ", " << dataAssignment << ", " << loopAssignment << ", ";
            selectionResults << otherOperations << ", " << dataComparisons + loopComparisons + dataAssignment + loopAssignment + otherOperations << "\n";

            dataComparisons = 0;
            loopComparisons = 0;
            dataAssignment = 0;
            loopAssignment = 0;
            otherOperations = 0;

            //Bubble Sort
            time = bubbleSort(values, dataComparisons, loopComparisons, dataAssignment, loopAssignment, otherOperations);
            
            bubbleResults << time << ", " << dataComparisons << ", " << loopComparisons << ", " << dataAssignment << ", " << loopAssignment << ", ";
            bubbleResults << otherOperations << ", " << dataComparisons + loopComparisons + dataAssignment + loopAssignment + otherOperations << "\n";
            
            dataComparisons = 0;
            loopComparisons = 0;
            dataAssignment = 0;
            loopAssignment = 0;
            otherOperations = 0;

            //Insertion Sort
            time = insertionSort(values, dataComparisons, loopComparisons, dataAssignment, loopAssignment, otherOperations);

            insertionResults << time << ", " << dataComparisons << ", " << loopComparisons << ", " << dataAssignment << ", " << loopAssignment << ", ";
            insertionResults << otherOperations << ", " << dataComparisons + loopComparisons + dataAssignment + loopAssignment + otherOperations << "\n";
            
            dataComparisons = 0;
            loopComparisons = 0;
            dataAssignment = 0;
            loopAssignment = 0;
            otherOperations = 0;
            values.clear();
        }

    }

    //Closing files
    selectionResults.close();
    bubbleResults.close();
    insertionResults.close();
}
