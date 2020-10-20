// Lab 9 DS4Talker Skeleton Code
// ./ds4rd - d 054c:05c4 -D DS4_BT -t -b -j -bt | lab9.exe wordslist.txt

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>

#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1 // set to 0 to disable debug output
#define NUMWORDS 14

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char *s)
{
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
int readWords(char *wl[MAXWORDS], char *filename)
{
	int counter = 0;
	FILE *ftpr = fopen(filename, "r");
	char stored[WORDLEN];
	while (!feof(ftpr))
	{
		fgets(stored, WORDLEN, ftpr);
		trimws(stored);
		wl[counter] = (char *)(malloc((strlen(stored) + 1) * sizeof(char)));
		strcpy(wl[counter], stored);
		counter++;
	}
	fclose(ftpr);
	return counter;
}

int main(int argc, char *argv[])
{
	char *wordList[MAXWORDS];
	int wordCounter;
	int i;
	wordCounter = readWords(wordList, argv[1]);

	if (DEBUG)
	{
		printf("Read %d words from %s \n", wordCounter, argv[1]);
		// add code to print the words to the screen here for part 1
		for (i = 0; i < wordCounter; i++)
		{
			printf("%s\n", wordList[i]);
		}
	}

	// most of your code for part 2 goes here. Don't forget to include the ncurses library

	int p = 0;
	int x = 0;
	int y = 0;
	int buffer = 0;
	int b = 0;
	int time, bT, bC, bX, bS, rightDown, leftDown, option, share, l2, r2, l1, r1, l_joy_x, l_joy_y, r_joy_x, r_joy_y;
	int mark;
	int prevX;
	int prevY;
	int n = 0;
	int index[MAXWORDS];
	int cursor[MAXWORDS];
	char finalSentence[80];
	char* backspace = "                                                                ";
	finalSentence[0] = '\0';
	initscr();
	for (int j = 0; j < 15; j++)
	{
		for (int k = 0; k < 75; k += 15)
		{
			if (p < wordCounter)
			{
				mvprintw(j, k, "%15s", wordList[p]);
				refresh();
				p++;
			}
		}
	}
	while (n < 20)
	{
		b = 0;

		prevX = x;
		prevY = y;
		mvaddch(prevY, prevX, ' ');
		mvaddch(y, x, '>');
		refresh();
		while (b == 0)
		{
			prevX = x;
			prevY = y;
			scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
				  &time, &bT, &bC, &bX, &bS, &rightDown, &leftDown, &option,
				  &share, &l2, &r2, &l1, &r1, &l_joy_y, &l_joy_x, &r_joy_x, &r_joy_y);
			buffer = time;
			while (time < buffer + 200)
			{
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
					  &time, &bT, &bC, &bX, &bS, &rightDown, &leftDown, &option,
					  &share, &l2, &r2, &l1, &r1, &l_joy_y, &l_joy_x, &r_joy_x, &r_joy_y);
			}
			if (rightDown != 0)
			{
				mvprintw(16, 0, backspace);
				strcpy(finalSentence, "");
			}
			if (r_joy_x < -50 && prevX > 14)
				x -= 15;
			else if (r_joy_x > 50 && prevX < 60)
				x += 15;
			else if (r_joy_y > 50 && prevY < 14)
				y++;
			else if (r_joy_y < -50 && prevY > 0)
				y--;

			mvaddch(prevY, prevX, ' ');
			mvaddch(y, x, '>');
			refresh();
			mark = ((y * 5) + (x / 15));
			if (bT != 0)
				b = 1;
			else if (bX != 0)
				b = 2;
			else if (bS != 0)
				b = 3;
			else if (bC != 0)
				b = 4;
			else
				continue;
		}
		if (b == 1)
		{ //add word and space
			if (cursor[n] < strlen(finalSentence))
			{
				finalSentence[cursor[n]] = ' ';
				for (int j = 0; j < strlen(wordList[mark]) + 1; j++)
					finalSentence[cursor[n] + 1 + j] = wordList[mark][j];
				n++;
				cursor[n] = strlen(finalSentence);
			}
			else
			{
				char temp[1000] = "";
				strcpy(temp, " ");
				strcat(temp, wordList[mark]);
				index[n] = strlen(temp);
				strcat(finalSentence, temp);
				n++;
				cursor[n] = strlen(finalSentence);
			}
		}
		else if (b == 2)
		{ //remove last word
			n--;
			int w = strlen(finalSentence);
			for (int j = w; j > w - index[n]; j--)
				finalSentence[j] = ' ';
			finalSentence[w] = '\0';
		}
		else if (b == 3)
		{ //add word without space
			if (cursor[n] < strlen(finalSentence))
			{
				for (int j = 0; j < strlen(wordList[mark]) + 1; j++)
					finalSentence[cursor[n] + j] = wordList[mark][j];
				n++;
				cursor[n] = strlen(finalSentence);
			}
			else
			{
				strcat(finalSentence, wordList[mark]);
				index[n] = strlen(wordList[mark]);
				n++;
				cursor[n] = strlen(finalSentence);
			}
		}

		mvprintw(16, 0, "%s", finalSentence);
		refresh();
	}
	return 0;
}
