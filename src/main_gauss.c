#include "gaussian.h"


// still needs to initiate x values
int main(int argc, char * argv[]){

if(argc > 1){
	printf("No arguments are allowed. shutting down %s\n", argv[0]);
	exit(-1);
}

int n, choice;

Distribution prob_struc, *Dist_ptr;
Dist_ptr = &prob_struc;


printf("Number of samples (x) to generate (integer value): ");
scanf("%d",&n);
printf("Probability Distrubtion to measure (select the number): \n 1. Gaussian\n");
scanf("%d", &choice);

switch(choice){
	case 1:
	strcpy(prob_struc.name, "Gaussian");
	break;
	default:
	printf("No valid distribution function was chosen. shutting down %s\n", argv[0]);
	exit(1);
}

Dist_ptr->x = (double*) malloc( n * sizeof(double));
Dist_ptr->output = (double*) malloc( n * sizeof(double));

// where the action happens
initiate(Dist_ptr, n, 42);
Gaussian(Dist_ptr, n);
printresults(Dist_ptr, n);

free(Dist_ptr->x);
free(Dist_ptr->output);

	return 0;
}

