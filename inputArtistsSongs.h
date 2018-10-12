# define MAX_4_ARTISTS 4 
# define MAX_3_SONGS 3
# define TITLE_LENGTH 80

void removeNewline(char newlined_string[][TITLE_LENGTH], int counter);

int insertArtists(char artists[][TITLE_LENGTH], int numSongsPerArtist[MAX_4_ARTISTS], char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], char sortedArtists[][TITLE_LENGTH]);

void insertSongs(char songsArtist1[][TITLE_LENGTH], char songsArtist2[][TITLE_LENGTH], char songsArtist3[][TITLE_LENGTH], char songsArtist4[][TITLE_LENGTH], char artists[][TITLE_LENGTH], int artist_count, int numSongsPerArtist[MAX_4_ARTISTS]);