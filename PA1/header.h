/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA1                                                                      
 Description: This program translates english to morse code and morse code to english.
*/


#ifndef HEADER_H
    #define HEADER_H

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>
    #include <vector>
    #include <cctype>

    using namespace std;

    const char englishConversion[43] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '\0', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const string morseConversion[43] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/", "", "", "", "", "", "", ".-",
        "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
        "-..-", "-.--", "--.."};
    bool userInput(string&, string&);
    void openFiles(ifstream&, string, ofstream&, string);
    void closeFiles(ifstream&, ofstream&);
    void englishToMorse(ifstream&, ofstream&, int&);
    void morseToEnglish(ifstream&, ofstream&, int&);


#endif