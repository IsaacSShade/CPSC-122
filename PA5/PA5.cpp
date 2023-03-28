/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 21, 2023
 Programming Assignment: PA5                                                                  
 Description: The meat of the code used in Main.cpp for running the menus and getting user input and running commands on the classes
*/

#include "PA5.h"

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << " 1) Display library" << endl;
	cout << " 2) Load library" << endl;
	cout << " 3) Store library" << endl;
	cout << " 4) Sort library" << endl;
	cout << " 5) Search library" << endl;
	cout << " 6) Add song to library" << endl;
	cout << " 7) Remove song from library" << endl;
	cout << " 8) Edit song in library" << endl;
	cout << " 9) Quit" << endl;
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
	string firstInput = "", secondInput = "", thirdInput = "";
	Song newSong;
	Song * songPtr = &newSong;
	int songIndex = 0, songRating = 1;
	int * indexPtr = &songIndex;
	bool found = false;

	switch (choice) {
		case 1:
			lib.displayLibrary();
			break;
		case 2:
			cout << "\nPlease enter the name of the file to load from\n";
			cout << "  >>";
			getline(cin, firstInput);

			lib.performLoad(firstInput);
			break;
		case 3: 
			cout << "\nPlease enter the name of the file to save in\n";
			cout << "  >>";
			getline(cin, firstInput);

			lib.performSave(firstInput);
			break;
		case 4:
			cout << "\nPlease enter the attribute for the song library to be sorted by\n";
			cout << "  >>";
			getline(cin, firstInput);

			lib.performSort(firstInput);
			break;
		case 5:
			cout << "\nPlease enter the attribute you will be searching for\n";
			cout << "  >>";
			getline(cin, firstInput);

			cout << "\nPlease enter the value of " << firstInput << " you will be searching for\n";
			cout << "  >>";
			getline(cin, secondInput);

			found = lib.performSearch(firstInput, secondInput, songPtr, indexPtr);

			cout << "Match found: " << found << endl;
			if(found) {
				cout << "Displaying attributes of song with index " << *indexPtr << ":\n\n";
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

			newSong.setTitle(firstInput);
			newSong.setArtist(secondInput);
			newSong.setGenre(thirdInput);
			newSong.setRating(songRating);

		 	lib.performAddSong(newSong);
		 	break;
		case 7:
			cout << "\nPlease enter the index of the song you will be removing\n";
			cout << "  >>";
			cin >> songIndex;
			cin.ignore();

			lib.performRemoveSong(songIndex);
			break;
		case 8:
			cout << "\nPlease enter the index of the song you will be editing\n";
			cout << "  >>";
			cin >> songIndex;
			cin.ignore();

			cout << "\nPlease enter the name of the attribute you will be editing\n";
			cout << "  >>";
			getline(cin, firstInput);

			cout << "\nPlease enter the value of " << firstInput << " you will be editing\n";
			cout << "  >>";
			getline(cin, secondInput);

			lib.performEditSong(songIndex, firstInput, secondInput);
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