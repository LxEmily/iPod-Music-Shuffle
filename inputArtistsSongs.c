#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inputArtistsSongs.h"

# define MAX_4_ARTISTS 4 
# define MAX_3_SONGS 3
# define TITLE_LENGTH 80

/* 
 * Removes newline characters from strings (artists/songs). Takes as input:
 * - newlined_string: string with newline, mainly for artists and songsArtist1-4
 * - counter: to ensure the correct position of 2-D array is used
 * Extra newline characters are due to fgets reading them
 * This function removes them by decrementing strlen then replacing them with the null terminator
 */
void removeNewline(char newlined_string[][TITLE_LENGTH], int counter)
{
	int title_length = strlen(newlined_string[counter])-1 ;
	if 	(newlined_string[counter][title_length] == '\n')	
		newlined_string[counter][title_length] = '\0' ;
}

/* 
 * Prompts user to insert at most 4 artists and returns number of inserted artists. Takes as input:
 * - artists: to store user input artists
 * - numSongsPerArtist: counter for number of songs for each artist
 * - songsArtist1-4: to store user input songs, required as this function calls the function insertSongs
 * - sortedArtists: to copy of user input artists to be sorted later
 * The user may use newline to quit inserting artists, 
 *   else the inserted artists' newline character due to fgets is removed 
 *   and function insertSongs for said artist is called
 * If the user inputs the same artist more than once prompt the user to input another artist
 * A copy of artists is stored in sortedArtists for later sorting
 * The function finally returns the number of inserted artists
 */
int insertArtists(char artists[][TITLE_LENGTH], int numSongsPerArtist[MAX_4_ARTISTS], char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], char sortedArtists[][TITLE_LENGTH])
{	
	int artist_count; 
	for (artist_count=0; artist_count<MAX_4_ARTISTS; artist_count++)
	{
		printf("\nInsert artist/group name %d: \n", artist_count+1);
		fgets(artists[artist_count], TITLE_LENGTH, stdin);
		
		if (artist_count == 0 && artists[0][0] == '\n')
		{
			printf("Please input at least one artist. \n");
			artist_count = -1;
		}		
		else if (artists[artist_count][0] == '\n')
			break;
		else
		{
			removeNewline(artists, artist_count);
			if (artist_count > 0 && strcmp(artists[artist_count], "")!=0 && strcmp(artists[artist_count-1], artists[artist_count]) == 0 || strcmp(artists[artist_count-2], artists[artist_count]) == 0)
			{
				printf("Please do not input the same artist more than once. \n");
				artist_count -= 1;
			}
			else
				insertSongs(songsArtist1, songsArtist2, songsArtist3, songsArtist4, artists, artist_count, numSongsPerArtist);
		}
	}
	
	for (int i=0; i<artist_count; i++)
		strcpy(sortedArtists[i], artists[i]);

	if (artist_count>0)
		return artist_count;
	else
		return 0;
}

/* 
 * Prompts user to insert at most 3 songs per artist and returns void. Takes as input:
 * - artists: to prompt user to insert songs for said artist
 * - numSongsPerArtist: counter for number of songs for each artist
 * - songsArtist1-4: to store user input songs, required as this function calls the function insertSongs
 * - artist_count: to ensure the songs are stored into the correct arrays
 * If the user inserted an artist but no songs, repeatedly prompt the user to input a song.
 * If the user inserts the same song, repeatedly prompt the user to input another song.
 * The user may use newline to quit inserting songs, 
 *   else the inserted songs' newline character due to fgets is removed 
 *   and the respective numSongsPerArtist is incremented
 * If artist_count somehow exceeds 4, an error message is printed and the loop terminates
 */
void insertSongs(char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], char artists[][TITLE_LENGTH], int artist_count, int numSongsPerArtist[MAX_4_ARTISTS])
{
	int song_count; 
	for (song_count=0; song_count<MAX_3_SONGS; song_count++)
	{
		printf("Insert song %d for %s \n", song_count+1, artists[artist_count]);
		if (artist_count == 0)
		{
			fgets(songsArtist1[song_count], TITLE_LENGTH, stdin);	
			if (song_count == 0 && strcmp(artists[artist_count], "")!=0 && songsArtist1[song_count][0] == '\n')
			{
				printf("Please input at least one song for %s. \n", artists[artist_count]);
				song_count -= 1;
			}
			else if (songsArtist1[song_count][0] == '\n')
			{
				strcpy(songsArtist1[song_count], "");
				break;
			}
			else
			{
				removeNewline(songsArtist1, song_count);
				if (song_count > 0 && strcmp(artists[artist_count], "")!=0 && strcmp(songsArtist1[song_count-1], songsArtist1[song_count]) == 0 || strcmp(songsArtist1[song_count-2], songsArtist1[song_count]) == 0)
				{
					printf("Please do not input the same song for %s. \n", artists[artist_count]);
					song_count -= 1;
				}
				else
					numSongsPerArtist[artist_count]++;
			}
		}
		
		else if (artist_count == 1)
		{
			fgets(songsArtist2[song_count], TITLE_LENGTH, stdin);
			if (song_count == 0 && strcmp(artists[artist_count], "")!=0 && songsArtist2[song_count][0] == '\n')
			{
				printf("Please input at least one song for %s. \n", artists[artist_count]);
				song_count -= 1;
			}
			else if (songsArtist2[song_count][0] == '\n')
			{
				strcpy(songsArtist2[song_count], "");
				break;
			}
			else
			{
				removeNewline(songsArtist2, song_count);
				if (song_count > 0 && strcmp(artists[artist_count], "")!=0 && strcmp(songsArtist2[song_count-1], songsArtist2[song_count]) == 0 || strcmp(songsArtist2[song_count-2], songsArtist2[song_count]) == 0)
				{
					printf("Please do not input the same song for %s. \n", artists[artist_count]);
					song_count -= 1;
				}
				else
					numSongsPerArtist[artist_count]++;
			}
		}			
		
		else if (artist_count == 2)
		{
			fgets(songsArtist3[song_count], TITLE_LENGTH, stdin);
			if (song_count == 0 && strcmp(artists[artist_count], "")!=0 && songsArtist3[song_count][0] == '\n')
			{
				printf("Please input at least one song for %s. \n", artists[artist_count]);
				song_count -= 1;
			}
			else if (songsArtist3[song_count][0] == '\n')
			{
				strcpy(songsArtist3[song_count], "");
				break;
			}
			else
			{						
				removeNewline(songsArtist3, song_count);
				if (song_count > 0 && strcmp(artists[artist_count], "")!=0 && strcmp(songsArtist3[song_count-1], songsArtist3[song_count]) == 0 || strcmp(songsArtist3[song_count-2], songsArtist3[song_count]) == 0)
				{
					printf("Please do not input the same song for %s. \n", artists[artist_count]);
					song_count -= 1;
				}
				else
					numSongsPerArtist[artist_count]++;
			}
		}			
		
		else if (artist_count == 3)
		{
			fgets(songsArtist4[song_count], TITLE_LENGTH, stdin);	
			if (song_count == 0 && strcmp(artists[artist_count], "")!=0 && songsArtist4[song_count][0] == '\n')
			{
				printf("Please input at least one song for %s. \n", artists[artist_count]);
				song_count -= 1;
			}
			else if (songsArtist4[song_count][0] == '\n')
			{
				strcpy(songsArtist4[song_count], "");
				break;
			}
			else
			{
				removeNewline(songsArtist4, song_count);
				if (song_count > 0 && strcmp(artists[artist_count], "")!=0 && strcmp(songsArtist4[song_count-1], songsArtist4[song_count]) == 0 || strcmp(songsArtist4[song_count-2], songsArtist4[song_count]) == 0)
				{
					printf("Please do not input the same song for %s. \n", artists[artist_count]);
					song_count -= 1;
				}
				else
					numSongsPerArtist[artist_count]++;
			}
		}
		
		else if (artist_count >= MAX_4_ARTISTS)
		{
			printf("Error: You have exceeded the number of artists/groups supported. \n");
			break;
		}
	}
}