/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/

int close_to(double tolerance, double point, double value);
double mag(double x, double y, double z);
int sideCheck(int currentSide, int previousSide);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


	int side;
	b1 = 0;
	
	//double tolerance = .01;			mag tolerance for detecting movement
	//double point = 1.0;				mag is the point
	//double value = 0;					mag value for not moving

	//printf("testing close_to: %d", close_to(tolerance, point, value));


    while (b1 != 1) //while triangle isnt pushed
	 { 
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4);

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */

        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

			if ((close_to(0.03, mag(ax, ay, az), 0.0) == 1)) {
				if (close_to(0.25, gy, 1) == 1) {					
					if (sideCheck(side, 1)) {
						printf("Remote is facing: TOP\n");
					}
					side = 1;
				}
				if (close_to(0.3, gy, -1) == 1) {
					if (sideCheck(side, 2)) {
						printf("Remote is facing: BOTTOM\n");
					}
					side = 2;
				}
				if (close_to(0.3, gx, 1) == 1) {
					if (sideCheck(side, 3)) {
						printf("Remote is facing: RIGHT\n");
					}
					side = 3;
				}
				if (close_to(0.3, gx, -1) == 1) {
					if (sideCheck(side, 4)) {
						printf("Remote is facing: LEFT\n");
					}
					side = 4;
				}
				if (close_to(0.3, gz, 1) == 1) {
					if (sideCheck(side, 5)) {
						printf("Remote is facing: BACK\n");
					}
					side = 5;
				}
				if (close_to(0.3, gz, -1) == 1) {
					if (sideCheck(side, 6)){
						printf("Remote is facing: FRONT\n");
				}
					side = 6;
				}
			}
			fflush(stdout);

    }

    return 0;
}

/* Put your functions here */
int close_to(double tolerance, double point, double value) {	
	if (value > (point + tolerance) || value < (point - tolerance)) {
		return 0; 
	}
	else {
		return 1; 
	}		
}

double mag(double x, double y, double z) {
	return sqrt((pow(x, 2.0)) + (pow(y, 2.0)) + (pow(z, 2.0)));
}

int sideCheck(int currentSide, int previousSide)
{
	if(currentSide != previousSide)
		return 1;
	if(currentSide == previousSide)
		return 0;
}