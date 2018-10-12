#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortAndPrint.h"

# define MAX_4_ARTISTS 4 
# define MAX_3_SONGS 3
# define TITLE_LENGTH 80

/* 
 * Sorts strings (artists/songs) alphabetically and returns void. Takes as input:
 * - string: strings (artists/songs) to be sorted
 * - num: the total number of strings (artists/songs)
 * Uses QuickSort 
 *   A loop goes from 0 to num-1 as there are no more strings to compare to after the last
 *     minIndex is set to i, j is set to i+1
 *     strings are compared within a nested loop with above conditions
 *     if the strings are out of place alphabetically, change minIndex and mark minIndexChanged as changed
 *   If minIndexChanged, initialize swap into a null terminated string to prevent runtime errors
 *     then swap the strings out of place
 */
void sortString (char string[][TITLE_LENGTH], int num)
{
	int i=0, j=0;            // Counters
	int minIndex=0;          // Index to mark position of string to be swapped
	int	minIndexChanged=0;   // Marks if minIndex is changed
	char swap[TITLE_LENGTH]; // Array to store string to be swapped
	
	for (i=0; i<num-1; i++) 
	{
		minIndex = i;
		for (j=i+1; j<num; j++)
		{
			if (strcmp(string[j], string[minIndex]) < 0)
			{
				minIndex = j;
				minIndexChanged = 1;
			}
		}
		
		if (minIndexChanged == 1)
		{
			memset(swap, '$', TITLE_LENGTH-2);
			swap[TITLE_LENGTH-1] = '\0';
			strcpy(swap, string[i]);
			strcpy(string[i], string[minIndex]);
			strcpy(string[minIndex], swap);
			minIndexChanged = 0;			
		}
	}
}

/* 
 * Outputs "Sorted list of songs" returns void. Takes as input:
 * - artists: user input artists
 * - sortedArtists: sorted user input artists
 * - songsArtist1-4: user input songs (sorted at this point)
 * Prints each artist and their respective songs 
 *   by looping through each artist in sortedArtists and each song
 *   then compare sortedArtists to artists to ensure the correct set of songs are printed.
 */
void printArtistsSongs(int artist_count, int numSongsPerArtist[], char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], char artists[][TITLE_LENGTH], char sortedArtists[][TITLE_LENGTH])
{
	printf("\nSorted list of songs: \n");
	for (int i=0; i<artist_count; i++)
	{
		printf("%s \n", sortedArtists[i]);
		for (int song_count=0; song_count<MAX_3_SONGS; song_count++)
		{
			for (int j=0; j<artist_count; j++)
			{
				if (strcmp(sortedArtists[i], artists[0]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist1[song_count], "") != 0)
				{
					printf("	- %s \n", songsArtist1[song_count]);
					break;
				}
				
				else if (strcmp(sortedArtists[i], artists[1]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist2[song_count], "") != 0)
				{
					printf("	- %s \n", songsArtist2[song_count]);
					break;				
				}
				else if (strcmp(sortedArtists[i], artists[2]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist3[song_count], "") != 0)
				{
					printf("	- %s \n", songsArtist3[song_count]);
					break;			
				}					
				else if (strcmp(sortedArtists[i], artists[3]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist4[song_count], "") != 0)
				{
					printf("	- %s \n", songsArtist4[song_count]);
					break;
				}
			}
		}
	}
}