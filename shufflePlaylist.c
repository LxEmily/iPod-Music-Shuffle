#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "shufflePlaylist.h"

# define MAX_4_ARTISTS 4 
# define MAX_3_SONGS 3
# define TITLE_LENGTH 80

/* 
 * Creates a playlist of artists and songs then returns playlist_num. Takes as input:
 * - playlist: to store artists and their songs concatenated 
 * - artists: user input artists
 * - sortedArtists: sorted user input artists
 * - songsArtist1-4: user input songs
 * - playlist_num: counter for number of songs for each artist
 * - artist_count: number of artists
 * Concatenates each artist and their songs together, stores them into playlist and increment playlist_num
 *  by looping through each artist and songs
 *  and comparing sortedArtists to artists, and checking if artist and their respective songs exist
 *  to ensure the correct set of artist and song are concatenated
 */
int createPlaylist (char playlist[][TITLE_LENGTH*2], char artists[][TITLE_LENGTH], char sortedArtists[][TITLE_LENGTH], char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], int playlist_num, int artist_count)
{
	for (int i=0; i<artist_count; i++)
	{
		for (int k=0; k<MAX_3_SONGS; k++) 
		{
			for (int j=0; j<artist_count; j++)
			{
				if (strcmp(sortedArtists[i], artists[0]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist1[k], "") != 0)
				{
					strcpy(playlist[playlist_num], sortedArtists[i]);
					strcat(playlist[playlist_num], " - ");
					strcat(playlist[playlist_num], songsArtist1[k]);
					playlist_num++;
					break;
				}
				else if (strcmp(sortedArtists[i], artists[1]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist2[k], "") != 0)
				{
					strcpy(playlist[playlist_num], sortedArtists[i]);
					strcat(playlist[playlist_num], " - ");
					strcat(playlist[playlist_num], songsArtist2[k]);						
					playlist_num++;
					break;
				}
				else if (strcmp(sortedArtists[i], artists[2]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist3[k], "") != 0)
				{
					strcpy(playlist[playlist_num], sortedArtists[i]);
					strcat(playlist[playlist_num], " - ");
					strcat(playlist[playlist_num], songsArtist3[k]);
					playlist_num++;
					break;
				}
				else if (strcmp(sortedArtists[i], artists[3]) == 0 && strcmp(sortedArtists[i], "") != 0 && strcmp(songsArtist4[k], "") != 0)		
				{				
					strcpy(playlist[playlist_num], sortedArtists[i]);
					strcat(playlist[playlist_num], " - ");
					strcat(playlist[playlist_num], songsArtist4[k]);
					playlist_num++;
					break;
				}
				else
					break;
			}
		}
	}
	
	if (playlist_num>0)
		return playlist_num;	
	else
		return 0;
}

/* 
 * Shuffles playlist and prevents repeating songs within 5 plays. Returns void. Takes as input:
 * - playlist: strings of concatenated artists and songs
 * - playlist_num: total number of strings (songs) in playlist
 * Uses Fisher Yates Algorithm
 *   A loop i goes from 0 to playlist_num
 *     in each iteration j is randomized
 *     and if i and j are different
 *     the strings (songs) stored in their respective positions are swapped.
 */
void shufflePlaylist(char playlist[][TITLE_LENGTH*2], int playlist_num)
{
	char swap[TITLE_LENGTH*2] = {0};
	
	srand(time(NULL)); // Seeds RNG

	for (int i=0; i<playlist_num; i++)
	{
		int j = rand()%(i+1);
		if (j!=i)
		{
			strcpy(swap, playlist[j]);
			strcpy(playlist[j], playlist[i]);
			strcpy(playlist[i], swap);
		}
	}
}

/* 
 * Prints duplicated shuffled playlist and returns void. Takes as input:
 * - playlist: strings of concatenated artists and songs
 * - playlist_num: total number of strings (songs) in playlist
 * If user input more than 5 songs, duplicate playlist and playlist_num
 *   and loops through playlist_num to print every song in playlist
 */
void printPlaylist(char playlist[][TITLE_LENGTH*2], int playlist_num)
{	
	if (playlist_num > 5)
	{
		for (int i=0; i<playlist_num; i++)
			strcpy(playlist[playlist_num+i], playlist[i]);
		
		playlist_num *= 2;
	}
	printf("\nShuffled Playlist: \n");
	for (int i=0; i<playlist_num; i++)
		printf("%s \n", playlist[i]);
}