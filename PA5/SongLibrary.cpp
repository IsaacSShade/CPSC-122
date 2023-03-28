/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 21, 2023
 Programming Assignment: PA5                                                                  
 Description: Defines the structure for the SongLibrary class and it's various member functions
*/

#include "SongLibrary.h"

//Input: The song that will be used as a template to copy
//Output: The song changed passed by reference
void copySong(Song& copySong, Song baseSong) {
	copySong.setTitle(baseSong.getTitle());
	copySong.setArtist(baseSong.getArtist());
	copySong.setGenre(baseSong.getGenre());
	copySong.setRating(baseSong.getRating());
}

//SongLibrary Default Value Constructor
//Input: N/A
//Output: Initializes the class with default values
SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

//SongLibrary destructor
//Input: N/A
//Output: Deletes all dynamically allocated memory
SongLibrary::~SongLibrary() {
	if (songs != NULL) {
		delete [] songs;
	}

	numSongs = 0;
}

// ----------- STARTER CODE BLOCK ----------- //

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song * SongLibrary::getSongsArray() {
	return songs;
}

void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

// ------------------------------------------ //

//Input: N/A
//Output: Displays title of every song within this library in order
void SongLibrary::displayLibrary() {
	cout << "Number of songs: " << numSongs << endl;
	cout << "-----------------------------------------\n\n";
	for(int i = 0; i < numSongs; i++) {
		songs[i].displaySong();
	}
}

//Input: The filename
//Output: Initializes an empty SongLibrary object based off of the contents in the file
void SongLibrary::performLoad(string filename) {
	ifstream inFile;
	string temp = "", title = "", artist = "", genre = ""; 
	int rating = 1;

	//In case songs already has data, it wipes it and replaces it with file's contents
	if (songs != NULL) {
		delete [] songs;
		numSongs = 0;
	}

	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "!! File Failed to Open !!" << endl;
		return;
    }

	while (!inFile.eof()) {

		for (int i = 0; i < 4; i++) {
			getline(inFile, temp);
		}

		if (!inFile.eof()) {
			//Extra line between songs
			getline(inFile, temp);
		}
		numSongs++;
	}

	//Going back to beginning of input file
   	inFile.clear();
    inFile.seekg(0, ios::beg);

	//Creating dynamic array of songs
	songs = new Song[numSongs];


	for(int i = 0; i < numSongs; i++) {
		getline(inFile, title);
		getline(inFile, artist);
		getline(inFile, genre);
		inFile >> rating;

		//Extra stuff in input buffer v
		inFile.ignore();

		//Assigning values to the song in the SongLibrary
		songs[i].setTitle(title);
		songs[i].setArtist(artist);
		songs[i].setGenre(genre);
		songs[i].setRating(rating);

		if (!(i + 1 == numSongs)) {
			getline(inFile, temp);
		}
	}

	inFile.close();
	
}

//Input: Name of the file
//Output: Takes the SongLibrary object and outputs it's contents into the selected file in a text-based format.
void SongLibrary::performSave(string filename) {
	ofstream outFile;

	outFile.open(filename);

	if (!outFile.is_open()) {
		cout << "!! File Failed to Open !!" << endl;
		return;
    }

	for(int i = 0; i < numSongs; i++) {
		outFile << songs[i].getTitle() << "\n";
		outFile << songs[i].getArtist() << "\n";
		outFile << songs[i].getGenre() << "\n";
		outFile << songs[i].getRating();
		
		if (!(i + 1 == numSongs)) {
			outFile << "\n\n";
		}
	}

	outFile.close();
}

//Input: Name of the attribute to be sorted by
//Output: Uses bubble sort to sort the songs attribute in SongsLibrary
void SongLibrary::performSort(string attribute) {
	bool sorted = false;
	string tempTitle = "", tempArtist = "", tempGenre = "";
	int tempRating = 1;

	if (songs == NULL) {
		cout << "\n!! Can't sort songs when there are no songs in the library !!\n";
		return;
	}
	if (songs[0].getStringAttributeValue(attribute) == "") {
		return;
	}

	while(!sorted) {
		sorted = true;
		
		for (int i = 1; i < numSongs; i++) {
			if (songs[i - 1].getStringAttributeValue(attribute) > songs[i].getStringAttributeValue(attribute)) {
				sorted = false;

				tempTitle = songs[i].getTitle();
				tempArtist = songs[i].getArtist();
				tempGenre = songs[i].getGenre();
				tempRating = songs[i].getRating();

				copySong(songs[i], songs[i - 1]);

				songs[i - 1].setTitle(tempTitle);
				songs[i - 1].setArtist(tempArtist);
				songs[i - 1].setGenre(tempGenre);
				songs[i - 1].setRating(tempRating);
			}
		}
	}
}

//Input: The attribute to search in, and the value of that attribute
//Output: Whether the search was successful is the bool passed out, and the pointers of the Song object found and it's index in the SongLibrary are changed.
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	if (songs == NULL) {
		cout << "\n!! Can't search for songs when there are no songs in the library !!\n";
		return false;
	}
	if (songs[0].getStringAttributeValue(searchAttribute) == "") {
		return false;
	}

	for(int i = 0; i < numSongs; i++) {
		if (songs[i].getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*foundSong = songs[i];
			*index = i;

			return true;
		}
	}

	return false;
}

//Input: The song object to add to the song library
//Output: The songs array is updated to include the new song appended at the end
void SongLibrary::performAddSong(Song newSong) {
	Song tempArray[numSongs + 1];

	if (songs != NULL) {
		for(int i = 0; i < numSongs; i++) {
			copySong(tempArray[i], songs[i]);
		}
	}

	delete [] songs;
	copySong(tempArray[numSongs], newSong);

	numSongs++;
	songs = new Song[numSongs];

	for (int i = 0; i < numSongs; i++) {
		copySong(songs[i], tempArray[i]);
	}

}

//Input: The index to remove
//Output: The songs attribute is updated to what it was before minus the Song object
void SongLibrary::performRemoveSong(int indexToRemove) {
	Song tempArray[numSongs - 1];

	if (songs == NULL) {
		cout << "\n!! Can't remove a song when there are no songs in the library !!\n";
		return;
	}
	if (indexToRemove >= numSongs) {
		cout << "\n!! Can't remove a song with an index that doesn't exist !!\n";
		return;
	}
	
	//Copies the array but doesn't copy the index that is removed
	for(int i = 0; i < numSongs; i++) {
		if (indexToRemove > i) {
			copySong(tempArray[i], songs[i]);
		}
		else if (indexToRemove < i ) {
			copySong(tempArray[i - 1], songs[i]);
		}
	}

	delete [] songs;

	numSongs--;
	songs = new Song[numSongs];

	for (int i = 0; i < numSongs; i++) {
		copySong(songs[i], tempArray[i]);
	}
}

//Input: The index to edit, the attribute to change and that attribute's value
//Output: Changes the selected attribute's value
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	string lowercaseAttribute = convertToLowercase(attribute);

	if (songs == NULL) {
		cout << "\n!! Can't edit a song when there are no songs in the library !!\n";
		return;
	}
	if (indexToEdit >= numSongs) {
		cout << "\n!! Can't edit a song with an index that doesn't exist !!\n";
		return;
	}

	if(lowercaseAttribute == "title") {
		songs[indexToEdit].setTitle(newAttributeValue);
	}
	else if(lowercaseAttribute == "artist") {
		songs[indexToEdit].setTitle(newAttributeValue);
	}
	else if (lowercaseAttribute == "genre") {
		songs[indexToEdit].setTitle(newAttributeValue);
	}
	else if (lowercaseAttribute == "rating") {
		songs[indexToEdit].setRating(stoi(newAttributeValue));
	}
	else {
		cout << "!! Invalid input into function: performEditSong -> " << attribute << " !!" << endl;
	}
}

