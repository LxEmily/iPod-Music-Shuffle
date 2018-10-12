# define MAX_4_ARTISTS 4 
# define MAX_3_SONGS 3
# define TITLE_LENGTH 80

int createPlaylist (char playlist[][TITLE_LENGTH*2], char artists[][TITLE_LENGTH], char sortedArtists[][TITLE_LENGTH], char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], int playlist_num, int artist_count);

void shufflePlaylist(char playlist[][TITLE_LENGTH*2], int playlist_num);

void printPlaylist(char playlist[][TITLE_LENGTH*2], int playlist_num);