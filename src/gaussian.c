#include "gaussian.h"


void initiate(Distribution *struc_ptr, int count, int seed){

srand(seed);

for (int i = 0; i < count; ++i)
	struc_ptr->x[i] = (double) rand()/ RAND_MAX ;
}


void Gaussian(Distribution *struc_ptr, int n){

float var = 1.0, mu = 0.0;

for(int i = 0; i < n; ++i)
	struc_ptr->output[i] = (1.0 / sqrt(2.0*M_PI*var)) * exp(-pow(struc_ptr->x[i] - mu, 2.0) / 2.0 * var);

}

void printresults(Distribution *Dist_ptr, int count){
	printf("x values \t output Distribution values\n-------------------------------------------\n");
	for (int i =0; i < count; ++i)
		fprintf(stdout, "%f \t\t %f\n", Dist_ptr->x[i], Dist_ptr->output[i]);
}