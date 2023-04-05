/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 4, 2023
 Programming Assignment: PA6                                                                  
 Description: The header for PA6 defining functions and rerouting the headers and defintions for the classes to one file.
*/

#ifndef PA6_H
#define PA6_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 9;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif