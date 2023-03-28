/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 21, 2023
 Programming Assignment: PA5                                                                  
 Description: Definitions for all the song class's functions
*/

#include "Song.h"

//Input: A string to convert to lowercase
//Output: Ignores special characters, returns a string that's all lowercase.
string convertToLowercase(string s) {
	string temp = s;
	for(int i = 0; i < s.length(); i++) {
		if ((s[i] >= 65)&& (s[i] <= 90)) {
			temp[i] = static_cast<char>(s[i] + 32);
		}
	}
	return temp;
}

//Default Value Constructor
//Input: N/A
//Output: Sets the value of the Song when it's created to starter values.
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
}

//Explicit Value Constructor
//Input: Strings for the title, artist, genre, and an int for the rating
//Output: Assigns each attribute of the Song object with the inputted values
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
	artist = artistParam;
	genre = genreParam;
	setRating(ratingParam);
}

// ----------- STARTER CODE BLOCK ----------- //

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

// ------------------------------------------ //

//Input: N/A
//Output: Displays all attributes of the song
void Song::displaySong() {
	cout << title << " by " << artist << endl;
	cout << "Genre: " << genre << endl;
	cout << "Rating: " << rating << endl << endl;
}

//Input: Attribute to display as a string
//Output: If attribute inputted is valid, it returns a string with that attribute's value
string Song::getStringAttributeValue(string attribute) {
	string lowerCaseAttribute = convertToLowercase(attribute);
	string result = "";

	if(lowerCaseAttribute == "title") {
		result = title;
	}
	else if(lowerCaseAttribute == "artist") {
		result = artist;
	}
	else if (lowerCaseAttribute == "genre") {
		result = genre;
	}
	else if (lowerCaseAttribute == "rating") {
		result = to_string(rating);
	}
	else {
		cout << "!! Invalid input into function: getStringAttributeValue -> " << attribute << " !!" << endl;
		return "";
	}

	return result;
}