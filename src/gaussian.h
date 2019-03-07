#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct Distributions{
double *x;
float mean;
float var;
double *output;
char name[25];
}Distribution;


void initiate(Distribution *struc_ptr, int count, int seed); // Gives initial values for x, mean "u", variance "var" array based on a PRNG



void Gaussian(Distribution *struc_ptr, int n); // Calculates the Gaussian distribution function for given x input array


void printresults(Distribution *Dist_ptr, int count);