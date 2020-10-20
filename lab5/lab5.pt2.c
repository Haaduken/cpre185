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
const int lineSkip = 10;
const double GRAVITY = 9.8;


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int lineCount;
    double t, runOnce, startTime, endTime, preTime;
    double gx, gy, gz, distFallen, timeTotal, v, x;
    t=0;
    v = 0;
    runOnce= 0;
    lineCount = 0;
    printf("Haadi-Mohammad Majeed\nhmajeed\n"); //inital obligatory statement
    do
    {
        scanf("%lf, %lf, %lf, %lf", &t, &gx, &gy, &gz);
    
        if(runOnce == 0)
        {
            printf("Okay, I'm now recieveing data.\nI'm waiting ");
            runOnce++;
        }
        if(lineCount%lineSkip == 0)
        {
            printf(". ");
        }
        lineCount++;
        fflush(stdout);
    } while((close_to(0.2, mag(gx, gy, gz), 0.0) == 0));
	preTime = t * .001;
	startTime = t;
    do
    {
        
        scanf("%lf, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		v = v + 9.8 * (1 - mag(gx, gy, gz)) * (t * .001 - preTime);
		x = x + v * (t * .001 - preTime);
			
		preTime = t * .001;
			
        if(runOnce == 0)
        {
            printf("I'm falling");
            runOnce++;
        }
        if(lineCount%lineSkip == 0)
        {
            printf("!");
        }

        lineCount++;
        fflush(stdout);
    } while(mag(gx, gy, gz) < 2);
    
    endTime = t;
    timeTotal = (endTime - startTime)/1000.0;
    distFallen = .5 * GRAVITY * timeTotal * timeTotal;

	printf("\nOuch! I fell %lf meters in %lf seconds\n", distFallen , timeTotal);
	
	int percentage = 100-((x / distFallen) * 100);
	printf("\nCompensating for air resistance, the fall was %.3lf meters\n", x);
	printf("This is %d%% less than computed before.", percentage);

}
