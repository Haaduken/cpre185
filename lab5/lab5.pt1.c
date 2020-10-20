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
const double acceleration = 9.8;


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
    int t, runOnce, lineCount, startTime, endTime;
    double gx, gy, gz, distFallen, timeTotal;
    t=0;
    runOnce= 0;
    lineCount = 0;
    printf("Haadi-Mohammad Majeed\nhmajeed\n"); //inital obligatory statement
    do
    {
        scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
    
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

    startTime = t;
    runOnce = 0;

    do
    {
        scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
    
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
    distFallen = .5 * acceleration * timeTotal*timeTotal;
    printf("\nI have fallen %lf metres in %lf seconds", distFallen, timeTotal);

}

/*
if(runOnce == 0)
        {
            printf("Okay, I'm now recieveing data.\nI'm waiting ");
            runOnce++;
        }
        if((close_to(0.03, mag(gx, gy, gz), 0.0) == 0))
        {
            if(lineCount%lineSkip == 0)
            {
                printf(". ");
            }
        }
        else
        {
            break;
        }
        lineCount++;
        fflush(stdout);
    }
    timeStartFalling = t;
    printf("%d", timeStartFalling);
    /*
    printf("\n\tHelp me! I'm falling!");
    while(1)
    {
        if(lineCount%lineSkip == 0)
        {
            printf("!");
        }
        lineCount++;
    }
    */
   