/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA2                                                                     
 Description: This program sorts larger and larger datasets of different types using different methods. The efficiency is then put into a data file for each method.
 Notes: I learned how to find the time using https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
*/

#include "header.h"

//Input: An empty vector, and the size it needs to be
//Output: A vector from 0 to size
void createSortedVector(vector<int>& values, int size) {
    for (int i = 0; i < size; i++) {
        values.push_back(i);
    }
}

//Input: An empty vector, and the size it needs to be
//Output: A vector from size to 0
void createDescendingVector(vector<int>& values, int size) {
    for (int i = 0; i < size; i++) {
        values.push_back(size - i);
    }
}

//Input: An empty vector, and the size it needs to be
//Output: A vector filled with random numbers
void createRandomVector(vector<int>& values, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        values.push_back(rand() % (size * 2));
    }
}

//Input: A full vector
//Output: The time it took to sort everything using selection sort and the various values to count the number of operations done passed by reference
double selectionSort(vector<int> values, int& dataComparison, int& loopComparison, int& dataAssignment, int& loopAssignment, int& otherOperations) {
    auto start = high_resolution_clock::now();
    /*******************************The Sort***************************************/
    int minIndex = 0, min = values.at(0);
    dataAssignment++;                          //minIndex = 0
    dataAssignment++;                          //min = values.at(0)

    dataAssignment++;                          //int i = 0
    for (int i = 0; i < values.size(); i++) {
        loopAssignment++;                      //i++
        loopComparison++;                      //i < values.size()

        dataAssignment++;                      //int j = i
        for (int j = i; j < values.size(); j++) {
            loopAssignment++;                  //j++
            loopComparison++;                  //j < values.size()
            
            dataComparison++;                  //if (values.at(j) < min)
            if (values.at(j) < min) {
                min = values.at(j);
                minIndex = j;

                dataAssignment++;              //min = values.at(j)
                dataAssignment++;              //minIndex = j
            }
        }
        loopComparison++;                       // for loop last iteration

        values.at(minIndex) = values.at(i);
        values.at(i) = min;
        dataAssignment++;                      //values.at(minIndex) = values.at(i)
        dataAssignment++;                      //values.at(i) = min
    }
    loopComparison++;                           //for loop last iteration
    /**********************************************************************/

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count() / 1000000.0);
}

//Input: A full vector
//Output: The time it took to sort everything using bubble sort and the various values to count the number of operations done passed by reference
double bubbleSort(vector<int> values, int& dataComparison, int& loopComparison, int& dataAssignment, int& loopAssignment, int& otherOperations) {
    auto start = high_resolution_clock::now();

    /*******************************The Sort***************************************/
    bool unsorted = true;
    int placeholder = 0;

    dataAssignment++;                               //unsorted = true
    dataAssignment++;                               //placeholder = 0

    while(unsorted) {
        loopComparison++;                           //while(unsorted)

        unsorted = false;
        dataAssignment++;                           //unsorted = false

        dataAssignment++;                           //int i = 0
        for(int i = 0; i < (values.size() - 1); i++) {
            loopComparison++;                       //i < (values.size() - 1)
            loopAssignment++;                       //i++
            
            dataComparison++;                       //if (values.at(i) > values.at(i + 1))
            if (values.at(i) > values.at(i + 1)) {
                placeholder = values.at(i);
                values.at(i) = values.at(i + 1);
                values.at(i + 1) = placeholder;

                unsorted = true;

                dataAssignment++;                   //placeholder = values.at(i)
                dataAssignment++;                   //values.at(i) = values.at(i + 1)
                dataAssignment++;                   //values.at(i + 1) = placeholder
                dataAssignment++;                   //unsorted = true
            }
        }
        loopComparison++;                           //last for loop iteration
    }
    loopComparison++;                               //last while loop iteration

    /**********************************************************************/

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count() / 1000000.0);
}

//Input: A full vector
//Output: The time it took to process everything using insertion sort and the various values to count the number of operations done passed by reference
double insertionSort(vector<int> values, int& dataComparison, int& loopComparison, int& dataAssignment, int& loopAssignment, int& otherOperations) {
    auto start = high_resolution_clock::now();

    /*******************************The Sort***************************************/
    int placeholder = 0;
    dataAssignment++;                           //placeholder = 0

    dataAssignment++;                           //int i = 1
    for (int i = 1; i < values.size(); i++) {
        loopComparison++;                       //i < values.size()
        loopAssignment++;                       //i++

        int j = i;
        dataAssignment++;                       //int j = i

        loopComparison++;                       //((j - 1) > 0)
        while( ((j - 1) > 0) && (values.at(j) < values.at(j - 1)) ) {
            loopComparison++;                   //(values.at(j) < values.at(j - 1))

            placeholder = values.at(j);
            values.at(j - 1) = values.at (j);
            values.at(j) = placeholder;

            dataAssignment++;                   //placeholder = values.at(j)
            dataAssignment++;                   //values.at(j - 1) = values.at (j)
            dataAssignment++;                   //values.at(j) = placeholder

            j--;
            dataAssignment++;                   //j--
        }


    }
    loopComparison++;                           //last iteration of for loop

    /**********************************************************************/

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count() / 1000000.0);
}