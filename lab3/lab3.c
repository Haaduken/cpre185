/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
double mag(double x, double y, double z);
int minutes(int ms);
int seconds(int ms);
int millis(int ms);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;   
    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 

/* CODE SECTION 0 */
		//printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", t/1000.0, ax, ay, az);
		
/* CODE SECTION 1 */
        //printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));  
            
/* CODE SECTION 2 */
        printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 
    }

return 0;
}

/* Put your functions here */

double mag(double x, double y, double z)
{
	return (sqrt( pow(x,2) + pow(y,2) + pow(z,2)));
}

int minutes(int ms)
{
	return (ms/60000);
}

int seconds(int ms)
{
	int seconds = ms/1000;
	if (seconds >= 60)
		seconds-=60;
	return (seconds);
}
int millis(int ms)
{
	return (ms%1000);
}