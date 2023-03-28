/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA2                                                                     
 Description: This program sorts larger and larger datasets of different types using different methods. The efficiency is then put into a data file for each method.
 Notes: I learned how to find the time using https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
*/

#ifndef HEADER_H
    #define HEADER_H

    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <time.h>
    #include <chrono>
    #include <fstream>
    #include <string>

    using namespace std;
    using namespace std::chrono;

    void createSortedVector(vector<int>&, int);
    void createDescendingVector(vector<int>&, int);
    void createRandomVector(vector<int>&, int);
    double selectionSort(vector<int>, int&, int&, int&, int&, int&);
    double bubbleSort(vector<int>, int&, int&, int&, int&, int&);
    double insertionSort(vector<int>, int&, int&, int&, int&, int&);

#endif