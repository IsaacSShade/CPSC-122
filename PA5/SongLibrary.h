/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: March 21, 2023
 Programming Assignment: PA5                                                                  
 Description: Definitions for all the SongLibrary class's functions
*/

#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

//New Functions added by me
void copySong(Song& copySong, Song baseSong);

class SongLibrary {
	private:
		int numSongs;
		Song * songs;
	public:
		//Constructor
		SongLibrary();
		//Destructor
		~SongLibrary();

		//Various Miscellaneous member functions
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsArray();
		void setSongsArray(Song *);

		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);

};

#endif