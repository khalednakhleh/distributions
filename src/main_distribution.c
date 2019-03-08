#include "gaussian.h"

int main(int argc, char * argv[]){

if(argc > 1){
	fprintf(stderr, "No arguments are allowed. shutting down %s\n", argv[0]);
	exit(-1);
}

int n, choice;

Distribution prob_struc, *Dist_ptr;
Dist_ptr = &prob_struc;

printf("Number of samples (x) to generate (integer value): ");
scanf("%d",&n);
printf("Probability Distrubtion to measure (select the number): \n 1. gaussian\n");
scanf("%d", &choice);

switch(choice){
	case 1:
	strcpy(prob_struc.name, "gaussian");
	break;
	default:
	printf("No valid distribution function was chosen. shutting down %s\n", argv[0]);
	exit(1);
}

Dist_ptr->x = (float*) malloc( n * sizeof(double));
Dist_ptr->output = (float*) malloc( n * sizeof(double));

if(!(Dist_ptr->x) || !(Dist_ptr->output)){
	fprintf(stderr,"Error: could not allocate memory for values. Shutting down.\n");
	exit(1);
}

// where the action happens
Initiate(Dist_ptr, n, 42);
Gaussian(Dist_ptr, n);
WriteToFile(Dist_ptr, n);

free(Dist_ptr->x);
free(Dist_ptr->output);

printf("%s: Done.\n", argv[0]);

	return 0;
}

