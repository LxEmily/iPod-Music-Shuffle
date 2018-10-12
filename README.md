# iPod Music Shuffle

COMP10050 Software Engineering Project I Assignment 1

Individually create a program that sorts and shuffles a list of songs as input in C. 

The program should
1. Prompt the user to insert at most 4 artists and 3 songs per artist.
2. Sort and print the list of artists and songs. Use any sorting algorithm except for Bubble sort.
3. Shuffle the list ensuring that the same song only appears at most twice, after 5 other songs. Modify Fisher Yates Algorithm to meet the requirements.

Additionally, comment and separate the code into independent modules.

The documentation.pdf contains
- How I separated the code into independent modules 
- Some of my design choices
- Additional info
- Sample I/O

These files are uploaded here as the final submitted version, untouched except to remove personal info.

What I could have done better
To meet the shuffling requirements, I could make the program scan through the list and force it to reshuffle until it met the requirements. My actual implementaion involved shufflling the original list once then duplicating it.
