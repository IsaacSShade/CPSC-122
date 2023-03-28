/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: January 28, 2023
 Programming Assignment: PA1                                                                      
 Description: This program translates english to morse code and morse code to english.
*/

#include "header.h"

//Input: Input file name, output file name
//Output: (true) Task is to convert from english to morse (false) Task is to convert from morse to english
//Description: Prompts a command from the user for the file names and what they want to convert.
bool userInput(string& inputFileName, string& outputFileName) {
    string command = "";

    cout << endl << "Please type in -m for english to morse, or -t for morse to english." << endl;
    cout << "After that, input the name of the input file and then the name of the output file." << endl;
    cout << ">>";

    cin >> command;
    cin >> inputFileName;
    cin >> outputFileName;
    cout << endl;

    if (command == "-m") {
        return true;
    }
    else {
        return false;
    }
}

//Input: input file, the name of the input file, the output file, the name of the output file
//Output: N/A
//Description: Opens both the input and output folders and checks if it opened correctly.
void openFiles(ifstream& infile, string inName, ofstream& outfile, string outName) {
    infile.open(inName);
    outfile.open(outName);

    if (infile.is_open()) {

    }
    else {
        cout << "!! File failed to open !!" << endl;
        exit(-1);
    }
}

//Input: input file, the output file
//Output: N/A
//Description: Closes both the input file and the output file
void closeFiles(ifstream& infile, ofstream& outfile) {
    infile.close();
    outfile.close();
}

//Input: input file, the output file
//Output: Total number of characters (passed by reference)
//Description: Gets each line of the input file, translates every character inside each line to morse code, and outputs the translation to the output file.
void englishToMorse(ifstream& infile, ofstream& outfile, int& totalChars) {
    string line;
    bool found = false, firstLoop = true;
    int count = -1;

    while(!infile.eof()) {
        getline(infile, line);
        firstLoop = true;

        for(int i = 0; i < line.size(); i++) {
            found = false;
            count = -1;         //Resetting count
            char c = toupper(line[i]);
            //Finding character
            while(found == false) {
                count++;
                if (englishConversion[count] == c) {
                    found = true;
                }
            }

            //Outputting Translation
            if (firstLoop) {
                outfile << morseConversion[count];
                firstLoop = false;
            }
            else {
                outfile << ' ' << morseConversion[count];
            }

            totalChars++;
        }

        if(!infile.eof()) {
            outfile << '\n';
            totalChars++;  //Adds a character for the newline
        }

    }
}

//Input: input file, the output file
//Output: Total number of characters (passed by reference)
//Description: Gets each line of the input file, translates every morse character inside each line to an english character, 
//             and outputs the translation to the output file.
void morseToEnglish(ifstream& infile, ofstream& outfile, int& totalChars) {
    istringstream iss;
    string line, word;
    bool found = false;
    int count = -1;

    while(!infile.eof()) {
        word = "";
        getline (infile, line);

        iss.clear();
        iss.str(line);

        while (iss.good()) {
            found = false;
            count = -1;
            iss >> word;
            
            //Finding Character
            while (found == false) {
                count++;
                if (morseConversion[count] == word) {
                    found = true;
                }
            }

            //Outputting Translation
            outfile << englishConversion[count];
            totalChars++;
        }

        if(!infile.eof()) {
            outfile << '\n';
            totalChars++;  //Adds a character for the newline
        }
    }
}