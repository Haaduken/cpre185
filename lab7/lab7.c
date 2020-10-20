// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items)
{
	double average;
	double sum = 0.0;
	int i;
	for(i = 0; i < num_items; i++)
	{
		sum += buffer[i];
	}
	average = sum / num_items;
	return average;
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min)
{
	int i;
	for(i = 0; i < num_items; i++)
	{
		if(array[i]<*min)
			*min = array[i];
		if(array[i]>*max)
			*max = array[i];
	}
}

//shift length-1 elements of the buffer to the left and put the
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item)
{
	int i;
	for (i = 0; i < length-1; i++)
	{
		buffer[i] = buffer[i + 1];
	}
	buffer[length-1] = new_item;
}



int main(int argc, char* argv[]) {

	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg);
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	/* PUT YOUR CODE HERE */
	int bS, bX, bC, bT, count, time;
	double minX, maxX, minY, maxY, minZ, maxZ, gx, gy, gz, avgX, avgY, avgZ;
	minX = 0;
	minY = 0;
	minZ = 0;
	maxX = 0;
	maxY = 0;
	maxZ = 0;
	bS = 0;
	count = 0;
	do {
		scanf("%d, %lf ,%lf ,%lf ,%d ,%d ,%d ,%d", &time, &gx, &gy, &gz, &bT, &bC, &bT, &bS);
		count++;
		if(count <= lengthofavg)
		{
			x[count] = gx;
			y[count] = gy;
			z[count] = gz;
		}
		else if(count > lengthofavg)
		{
			updatebuffer(x, lengthofavg, gx);
			updatebuffer(y, lengthofavg, gy);
			updatebuffer(z, lengthofavg, gz);
			//count--;
		}
		if(count >= lengthofavg)
		{
			avgX = avg(x, lengthofavg);
			avgY = avg(y, lengthofavg);
			avgZ = avg(z, lengthofavg);
			maxmin(x, lengthofavg, &maxX, &minX);
			maxmin(y, lengthofavg, &maxY, &minY);
			maxmin(z, lengthofavg, &maxZ, &minZ);
			printf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", 
			time, gx, gy, gz, avgX, avgY, avgZ, maxX, maxY, maxZ, minX, minY, minZ);   
		}
		fflush(stdout);
	} while (bS == 0);
}