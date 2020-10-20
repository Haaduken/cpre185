/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Haadi Majeed
- 	Section: 10
-	NetID: 957539608
-	Date: Today
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


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{

    /* Put your code after this line */
	int a = 6427 + 1725;
	int b = (6971 * 3925) - 95;
	double c = 79 + 12 / 5;
	double d = 3640.0/107.9;
	int e = (22/3) *3;
	int f = 22 / (3*3);
	double g = 22 / (3*3);
	double h = 22 / 3*3;
	double i = (22/3) *3;
	int j = 22.0/ (3 * 3.0);
	double k = 22.0/3.0*3.0;
	
	printf("a = %d\nb = %d\nc = %.2lf\nd = %.2lf\ne = %d\nf = %d\ng = %.2lf\nh = %.2lf\ni = %.2lf\nj = %d\nk = %.2lf\n", a,b,c,d,e,f,g,h,i,j,k);
	
	double area;
	double circumfrence; 
	int feet = 14;
	double metres;
	int farhrenheit = 76;
	double centigrade;

	//M_PI for pi const
	circumfrence = 2 * M_PI * 3.7508045 ;
	area = M_PI * pow(3.7508045, 2);
	printf("\nCircumference = %.3lf \nArea = %.3lf", circumfrence, area);
	
	metres = feet * 0.3048;
	printf("\n%d feet is %lf metres", feet, metres);
	
	centigrade = (farhrenheit - 32) / 1.8;
	printf("\n%d f is %lf C", farhrenheit, centigrade);
	
    return 0;

}

