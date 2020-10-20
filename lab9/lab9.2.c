// Lab 9 DS4Talker Skeleton Code
// ./ds4rd - d 054c:05c4 -D DS4_BT -t -b -j -bt | lab9.exe wordslist.txt

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//#include <ncurses/ncurses.h>

#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output


//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' || s[i] == '\n')
		{
			s[i] = '\0';
		}
	}
}

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename)
{
	int counter = 0;
	FILE* ftpr = fopen(filename, "r");
	char stored[WORDLEN];
	while (!feof(ftpr))
	{
		fgets(stored, WORDLEN, ftpr);
		trimws(stored);
		wl[counter] = (char*)(malloc((strlen(stored) + 1) * sizeof(char)));
		strcpy(wl[counter], stored);
		counter++;
	}
	fclose(ftpr);
	return counter;
}


int main(int argc, char* argv[])
{
	char* wordList[MAXWORDS];
	int wordCounter;
	int i;
	wordCounter = readWords(wordList, argv[1]);

	if (DEBUG)
	{
		printf("Read %d words from %s \n", wordCounter, argv[1]);
		// add code to print the words to the screen here for part 1
		for (i = 0; i < MAXWORDS; i++)
		{
			printf("%s\n", wordList[i]);
		}
	}


// most of your code for part 2 goes here. Don't forget to include the ncurses library

  return 0;
}
