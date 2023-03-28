/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 21, 2023
 Programming Assignment: PA5                                                                  
 Description: Defines the structure for the Song class and it's various member functions
*/

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
	public:
		//Constructors
		Song();
		Song(string, string, string, int);
		
		//Miscellaneous member functions
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

		void displaySong();
		string getStringAttributeValue(string);
};

#endif