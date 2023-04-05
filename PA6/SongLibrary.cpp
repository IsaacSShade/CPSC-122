#include "SongLibrary.h"
#include <string>

//Input: N/A
//Outpit: DVC - Initializes Song Libraries with these default values
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

//Input: The old song that will be copied
//Output: A new Song Library initialized with the values of the old one
SongLibrary::SongLibrary(const SongLibrary& other) {
	head = new Song(*(other.head));
	Song * cur = head;
	Song * copy = other.getHead()->getNext();

	while(copy != NULL) {
		cur->setNext(new Song (*copy));
		cur = cur->getNext();
		copy = copy->getNext();
	}
}

//Input: N/A
//Output: Destroys the entire Song Library object when program ends
SongLibrary::~SongLibrary() {
	Song * cur = head;
	Song * prev = NULL;
	while (cur != NULL) {
		prev = cur;
		cur = cur->getNext();
		delete prev;
	}

	head = NULL;
}

//Input: N/A
//Output: Returns the head
Song * SongLibrary::getHead() const {
	return head;
}

//Input: A pointer to the Song object that will be the start of the linked list
//Output: Sets the head of the song library to the new head
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		Song * cur = head;
		Song * prev = NULL;
		while (cur != NULL) {
			prev = cur;
			cur = cur->getNext();
			delete prev;
		}
	}

	head = newHead;
}

//Input: N/A
//Output: String with the name of the sort attribute
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

//Input: New attribute to set to
//Output: Sets the new sort attribute of the library
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

//Input: File to load in
//Output: Creates a Song Library with the data
void SongLibrary::performLoad(string filename) {
	ifstream inFile;
	string temp = "", title = "", artist = "", genre = ""; 
	int rating = 1;
	Song * prev = NULL;

	//In case songs already has data, it wipes it and replaces it with file's contents
	setHead(NULL);

	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "!! File Failed to Open !!" << endl;
		return;
    }

	while (!inFile.eof()) {
		Song * songPtr = new Song;

		getline(inFile, title);
		getline(inFile, artist);
		getline(inFile, genre);
		inFile >> rating;

		//Extra stuff in input buffer v
		inFile.ignore();
		

		//Assigning values to the song in the SongLibrary
		songPtr->setTitle(title);
		songPtr->setArtist(artist);
		songPtr->setGenre(genre);
		songPtr->setRating(rating);

		this->performInsertSongInOrder(songPtr);

		//Extra space between songs
		if (!inFile.eof()) {
			getline(inFile, temp);
		}
	}

	inFile.close();
}

//Input: Name of the file
//Output: Takes the SongLibrary object and outputs it's contents into the selected file in a text-based format.
void SongLibrary::performSave(string filename) {
	ofstream outFile;
	Song * cur = head;

	outFile.open(filename);

	if (!outFile.is_open()) {
		cout << "!! File Failed to Open !!" << endl;
		return;
    }

	while (cur != NULL) {
		outFile << cur->getTitle() << "\n";
		outFile << cur->getArtist() << "\n";
		outFile << cur->getGenre() << "\n";
		outFile << cur->getRating();
		
		if (!(cur->getNext() == NULL)) {
			outFile << "\n\n";
		}

		cur = cur->getNext();
	}

	outFile.close();
}

//Input: N/A
//Output: Sorts the library based on the sorting attribute of the library
void SongLibrary::performSort() {

	if (head == NULL) {
		cout << "\n!! Can't sort songs when there are no songs in the library !!\n";
		return;
	}
	if (head->getNext() == NULL) {
		return;
	}

	SongLibrary copy = *this;
	Song * copyCur = copy.head;

	setHead(NULL);

	
	while (copyCur != NULL) {
		Song * newSong = new Song(*copyCur);
		this->performInsertSongInOrder(newSong);
		copyCur = copyCur->getNext();
	}

	//Freeing memory manually
	copy.SongLibrary::~SongLibrary();
}

//Input: The attribute to search for and the value to find
//Output: Song found, passed by pointers: a boolean on whether or not the value was found, and the index it was found (starts at 1)
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	Song * cur = head;
	*index = 0;

	while (cur != NULL) {
		index++;
		if(cur->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*found = true;
			return cur;
		}
		cur = cur->getNext();
	}

	*found = false;
	return NULL; //if nothing is found
}

//Input: Song to insert
//Output: Automatically sorts and inserts that song in the library
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	Song * cur = head;
	Song * prev = NULL;

	if(head == NULL) {  //If there is no head
		setHead(songToInsert);
	}
	else if (songToInsert->getStringAttributeValue(sortAttribute) < head->getStringAttributeValue(sortAttribute) ) {
		//If songToInsert's sortAttribute is less than head's sortAttribute value
		head = songToInsert;
		head->setNext(cur);
		
	}
	else { //Normal
		while (cur != NULL) {
			prev = cur;
			cur = cur->getNext();

			if (prev->getStringAttributeValue(sortAttribute) <= songToInsert->getStringAttributeValue(sortAttribute)) {
				if (cur == NULL || (songToInsert->getStringAttributeValue(sortAttribute) < cur->getStringAttributeValue(sortAttribute))) {
					prev->setNext(songToInsert);
					songToInsert->setNext(cur);
					break;
				}
			}
		}
	}
	
}


//Input: Pointer of the song to remove
//Output: Removes song
void SongLibrary::performRemoveSong(Song * songToRemove) {
	Song * newNext = songToRemove->getNext();
	Song * cur = head;
	Song * prev = NULL;

	while (cur != songToRemove) {
		prev = cur;
		cur = cur->getNext();
	}

	prev->setNext(newNext);
	delete cur;
}

//Input: Pointer to the song to edit, the attribute to edit, and the new value of that attribute
//Output: Song's chosen attribute is edited.
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	string lowercaseAttribute = convertToLowercase(attribute);

	if(lowercaseAttribute == "title") {
		songToEdit->setTitle(newAttributeValue);
	}
	else if(lowercaseAttribute == "artist") {
		songToEdit->setTitle(newAttributeValue);
	}
	else if (lowercaseAttribute == "genre") {
		songToEdit->setTitle(newAttributeValue);
	}
	else if (lowercaseAttribute == "rating") {
		songToEdit->setRating(stoi(newAttributeValue));
	}
	else {
		cout << "!! Invalid input into function: performEditSong -> " << attribute << " !!" << endl;
	}
}