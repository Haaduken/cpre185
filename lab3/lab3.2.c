/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

int buttonNum(int a, int b, int x, int y);
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
		int tri, circ, x, squa;


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%d,%d,%d", &tri, & circ, &x, & squa); 
		
		printf("Number of buttons pressed: %d\n", buttonNum(tri, circ, x, squa));
		fflush(stdout);
    }

return 0;
}

int buttonNum(int a, int b, int x, int y)
{
	
	return (a+b+x+y);
	
}