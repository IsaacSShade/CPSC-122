/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: April 4, 2023
 Programming Assignment: PA6                                                                  
 Description: The meat of the code used in Main.cpp for running the menus and getting user input and running commands on the classes
*/

#include "PA6.h"
#include <string>

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
	cout << "9) Exit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	Song * cur = NULL, * songPtr = NULL;
	string firstInput = "", secondInput = "", thirdInput = "";
	int index = 0, songRating = 1;
	bool found = false;
	int * indexPtr = &index;
	bool * foundPtr = &found;

	switch (choice) {
		case 1:
			cout << "\nPlease enter the name of the file to load from\n";
			cout << "  >>";
			getline(cin, firstInput);

			lib.performLoad(firstInput);
			break;
		case 2:
			cout << "\nPlease enter the name of the file to save in\n";
			cout << "  >>";
			getline(cin, firstInput);

			lib.performSave(firstInput);
			break;
		case 3: 
			cur = lib.getHead();
			cout << endl;

			while (cur != NULL) {
				cur->displaySong();
				cout << endl;
				cur = cur->getNext();
			}

			break;
		case 4:
			cout << "\nPlease enter the name of the attribute to sort with\n";
			cout << "  >>";
			getline(cin, firstInput);
			firstInput = convertToLowercase(firstInput);

			if (!((firstInput == "title") || (firstInput == "artist") || (firstInput == "genre") || (firstInput == "rating"))) {
				cout << "!! Invalid attribute !!" << endl;
				break;
			}

			lib.setSortAttribute(firstInput);
			lib.performSort();
			break;
		case 5:
			cout << "\nPlease enter the attribute you will be searching for\n";
			cout << "  >>";
			getline(cin, firstInput);

			if (!((firstInput == "title") || (firstInput == "artist") || (firstInput == "genre") || (firstInput == "rating"))) {
				cout << "!! Invalid attribute !!" << endl;
				break;
			}

			cout << "\nPlease enter the value of " << firstInput << " you will be searching for\n";
			cout << "  >>";
			getline(cin, secondInput);

			songPtr = lib.performSearch(firstInput, secondInput, foundPtr, indexPtr);

			cout << "Match found: " << found << endl;
			if(found) {
				cout << "Displaying attributes of song #" << *indexPtr << ":\n\n";
				songPtr->displaySong();
			}
			break;
		case 6:
			cout << "\nPlease enter the name of the song you will be adding\n";
			cout << "  >>";
			getline(cin, firstInput);

			cout << "\nPlease enter the artist of the song you will be adding\n";
			cout << "  >>";
			getline(cin, secondInput);

			cout << "\nPlease enter the genre of the song you will be adding\n";
			cout << "  >>";
			getline(cin, thirdInput);

			cout << "\nPlease enter the rating of the song you will be adding\n";
			cout << "  >>";
			cin >> songRating;
			cin.ignore();

			songPtr = new Song;
			songPtr->setTitle(firstInput);
			songPtr->setArtist(secondInput);
			songPtr->setGenre(thirdInput);
			songPtr->setRating(songRating);

			lib.performInsertSongInOrder(songPtr);
			break;
		case 7:
			found = false;

			cout << "\nPlease enter the title of the song you are removing\n";
			cout << "  >>";
			getline(cin, firstInput);

			songPtr = lib.performSearch("title", firstInput, foundPtr, indexPtr);

			cout << "Match found: " << found << endl;
			if(found) {
				cout << "Deleting...\n\n";
				lib.performRemoveSong(songPtr);
			}
			break;
		case 8:
			found = false;
			cout << "\nPlease enter the title of the song you are editing\n";
			cout << "  >>";
			getline(cin, firstInput);

			songPtr = lib.performSearch("title", firstInput, foundPtr, indexPtr);

			cout << "Match found: " << found << endl;
			if(found) {
				cout << "\nPlease enter the name of the attribute you will be editing\n";
				cout << "  >>";
				getline(cin, firstInput);

				cout << "\nPlease enter the value of " << firstInput << " you will be editing\n";
				cout << "  >>";
				getline(cin, secondInput);

				lib.performEditSong(songPtr, firstInput, secondInput);
			}

			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}