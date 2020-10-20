#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXWORDS 50000
#define DEBUG  0 


//find where the string target is in the list, return the index
// returns -1 if not found
int find(char* target, char* list[], int numWords) {
	int i;
	for(i=0; i<numWords; i++) {
		if (strcasecmp(target, list[i]) == 0) {
			return i;
			}			
		}
	return -1; //not found
	}
// *found is true if word exists in list, false if not.
int binarySearch(char* target, char* list[], int begin, int end, int* found) {
	if (begin >end) { *found = 0; return begin;}

	int middle = (end+begin)/2;
	int cmp = strcasecmp(target, list[middle]);
	*found =0;
	if (cmp == 0) {
		*found = 1; 
		return middle;
		}
	
	if (cmp <0) { 
		return binarySearch( target, list, begin, middle -1, found);
	} else {
		return binarySearch(target, list, middle+1, end, found);
	}
	}
	



// filename is argv[1]
int main(int argc, char* argv[]) {
	char* words[MAXWORDS];
	int count[MAXWORDS];
	int numread =0;	
	char aword[1000];
	int where;
	FILE* f ;  // refer to the file that we open
	f = fopen(argv[1], "r"); 
	while (fscanf(f, " %s", aword) == 1  ) {
		if (DEBUG) { printf(" Read %s it's %d chars long\n", aword, strlen(aword));}	
		where = find(aword, words, numread);		
		if (where == -1) { // add word to list
			words[numread] = malloc(sizeof(char) *(strlen(aword) + 1));
			strcpy(words[numread], aword); // like assignment for strings 
			count[numread] =1;
			numread++;
		} else {
			count[where] ++;	
		}	
		}
	fclose(f);
	int i;
	for (i=0; i<numread; i++) {
		printf("%6d: %s\n", count[i], words[i]);
		}

	}
