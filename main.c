/*
	@LxEmily

	COMP10050 Assignment 1: iPod Music Shuffle
	Original file structure by Lecturer Dr. Liliana Pasquel

	Update 02/02/18: Implemented artists and songs input 
		- function removeNewline
		- and printing the inputs for testing
	Update 08/02/18: Edits
		- if newline is entered the for loop for inputing artists/songs exits
	Update 09/02/18: Factor above code into functions
	Update 15/02/18: Implemented sorting
		- more refactoring
	Update 16/02/18: Implemented Artist + Song Concatenate and Fisher Yates Shuffle
	Update 22/02/18: Brute forced the shuffle, some refactoring
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "inputArtistsSongs.h" // Deals with Part 1: Insert artists and songs
#include "sortAndPrint.h"      // Deals with Part 2: Sorted list of songs
#include "shufflePlaylist.h"   // Deals with Part 3: Shuffled Playlist

# define MAX_4_ARTISTS 4       // At most 4 artists
# define MAX_3_SONGS 3         // At most 3 songs each artist
# define TITLE_LENGTH 80       // At most 80 characters each song name

int main (void)
{
	// Variable declarations initialized to 0
		char artists[MAX_4_ARTISTS][TITLE_LENGTH] = {0};       // Array of artists names 
		char sortedArtists[MAX_4_ARTISTS][TITLE_LENGTH] = {0}; // Array of sorted artists names
		char songsArtist1[MAX_3_SONGS][TITLE_LENGTH] = {0};    // Array of songs for artist 1
		char songsArtist2[MAX_3_SONGS][TITLE_LENGTH] = {0};    // Array of songs for artist 2
		char songsArtist3[MAX_3_SONGS][TITLE_LENGTH] = {0};    // Array of songs for artist 3
		char songsArtist4[MAX_3_SONGS][TITLE_LENGTH] = {0};    // Array of songs for artist 4
		int  numSongsPerArtist[MAX_4_ARTISTS] = {0};           // Counter for number of songs for each artist
		int  artist_count = 0;                                 // Counter for number of artists
		int  playlist_num = 0;                                 // Counter for number of elements in playlist
		
		// Array of artists and their songs concatenated (holds at most 24 strings, each of 160 characters)
		char playlist[2*MAX_4_ARTISTS*MAX_3_SONGS][TITLE_LENGTH*2] = {0};

	// Part 1: Insert artist and songs
		artist_count = insertArtists(artists, numSongsPerArtist, songsArtist1, songsArtist2, songsArtist3, songsArtist4, sortedArtists);

	// Part 2: Sorted list of songs		
		// Sort all artists and songs
		sortString(sortedArtists, artist_count);
		sortString(songsArtist1, numSongsPerArtist[0]);
		sortString(songsArtist2, numSongsPerArtist[1]);
		sortString(songsArtist3, numSongsPerArtist[2]);
		sortString(songsArtist4, numSongsPerArtist[3]);	 
		
		// Print "Sorted list of songs"
		printArtistsSongs(artist_count, numSongsPerArtist, songsArtist1, songsArtist2, songsArtist3, songsArtist4, artists, sortedArtists);
	
	// Part 3: Creates a playlist by concatenating artists and their songs into respective strings then shuffle	
		// Concatenate artist and song to create playlist
		playlist_num = createPlaylist(playlist, artists, sortedArtists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, playlist_num, artist_count);
		
		// Shuffles playlist
		shufflePlaylist(playlist, playlist_num);
		
		// Prints playlist
		printPlaylist(playlist, playlist_num);

	return 0;
}