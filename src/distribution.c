#include "gaussian.h"


void Initiate(Distribution *struc_ptr, int count, int seed){

srand48(seed);

float sum = 0, var_sum = 0;
// I still want to implement my own PRNG
for (int i = 0; i < count; ++i){
	struc_ptr->x[i] = (float)drand48();  // REDO THIS. NOT GOOD ENOUGH!!!! current range is 0 to 3
	sum += struc_ptr->x[i];
}

// Calculating mean and variance
struc_ptr->mean = (float) sum / count;

for(int i = 0; i < count; ++i){
	
	var_sum += pow(struc_ptr->x[i] - struc_ptr->mean, 2);
}
struc_ptr->var = (float) var_sum / count;
}


void Gaussian(Distribution *struc_ptr, int n){

for(int i = 0; i < n; ++i)
	struc_ptr->output[i] = (1.0 / sqrt(2.0*M_PI* struc_ptr->var)) * exp(-pow(struc_ptr->x[i] - struc_ptr->mean, 2.0) / 2.0 * struc_ptr->var);
}


void PrintResults(Distribution *Dist_ptr, int count){
	printf("x values \t output Distribution values\n-------------------------------------------\n");
	for (int i =0; i < count; ++i)
		fprintf(stdout, "%f \t\t %f\n", Dist_ptr->x[i], Dist_ptr->output[i]);
}


void WriteToFile(Distribution *Dist_ptr, int count){

FILE *fptr;
char filename[25];
snprintf(filename, 25, "%s.dat", Dist_ptr->name);

fptr = fopen(filename, "w");
if(!fptr)
	fprintf(stderr, "Error: could not open %s", filename);

for(int i = 0; i < count; ++i){
	fprintf(fptr, "%1.5f  %1.5f\n",Dist_ptr->x[i], Dist_ptr->output[i]);
}

fclose(fptr);
}