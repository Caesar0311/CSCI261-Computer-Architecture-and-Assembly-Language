/**
 * @file main.c
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Performs floating point arithmetic
 * (add, subtract, multiply, divide) on floating point represented numbers.
 *
*/



#include <stdio.h>
#include <stdlib.h>
#include "floating_point_arithmetics.h"

int main() {
	
	const char* real1 = "1050.61245";
	const char* real2 = "1.5";
	const char* negative_real = "-1050.61245";

	const char* fraction = "0.15625";
	const char* negative_fraction = "-0.15625";

	const char* dividend1 = "0.024414";
	const char* divisor1 = "0.15625";
	const char* negative_dividend1 = "-0.024414";
	const char* negative_divisor1 = "-0.15625";


	const char* dividend2 = "1103786.375000";
	const char* divisor2 = "1050.61245";
	const char* negative_dividend2 = "-1103786.375000";
	const char* negative_divisor2 = "-1050.61245";

	const char* dividend3 = "164.158188";
	const char* negative_dividend3 = "-164.158188";

	char* converted = NULL;

	printf("\n\nFolating point arithmetics:");

	//Addition
	converted = add_real(real1, real1);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real1, real1, converted);
		free(converted);
	}
	
	converted = add_real(real1, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real1, negative_real, converted);
		free(converted);
	}

	
	converted = add_real(real1, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real1, fraction, converted);
		free(converted);
	}

	
	converted = add_real(real1, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real1, negative_fraction, converted);
		free(converted);
	}

	converted = add_real(real2, real2);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real2, real2, converted);
		free(converted);
	}
	
	converted = add_real(real2, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real2, negative_real, converted);
		free(converted);
	}

	
	converted = add_real(real2, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real2, fraction, converted);
		free(converted);
	}

	
	converted = add_real(real2, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", real2, negative_fraction, converted);
		free(converted);
	}
	
	converted = add_real(fraction, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", fraction, negative_real,  converted);
		free(converted);
	}



	converted = add_real(fraction, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", fraction, negative_real,  converted);
		free(converted);
	}


	
	converted = add_real(fraction, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", fraction, fraction, converted);
		free(converted);
	}
	
	converted = add_real(fraction, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", fraction, negative_fraction, converted);
		free(converted);
	}
	printf("\n");


	//Subtraction
	converted = subtract_real(real1, real1);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real1, real1, converted);
		free(converted);
	}
	
	converted = subtract_real(real1, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real1, negative_real, converted);
		free(converted);
	}

	
	converted = subtract_real(real1, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real1, fraction, converted);
		free(converted);
	}

	
	converted = subtract_real(real1, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real1, negative_fraction, converted);
		free(converted);
	}


	converted = subtract_real(real2, real2);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real2, real2, converted);
		free(converted);
	}
	
	converted = subtract_real(real2, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real2, negative_real, converted);
		free(converted);
	}

	
	converted = subtract_real(real2, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real2, fraction, converted);
		free(converted);
	}

	
	converted = subtract_real(real2, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", real2, negative_fraction, converted);
		free(converted);
	}


	converted = subtract_real(fraction, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", fraction, fraction, converted);
		free(converted);
	}
	
	converted = subtract_real(fraction, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", fraction, negative_fraction, converted);
		free(converted);
	}

	
	converted = subtract_real(fraction, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", fraction, negative_real,  converted);
		free(converted);
	}

	converted = subtract_real(negative_real, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", negative_real, fraction, converted);
		free(converted);
	}
	printf("\n");


	//Multiplication
	converted = multiply_real(real1, real1);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real1, real1, converted);
		free(converted);
	}
	
	converted = multiply_real(real1, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real1, negative_real, converted);
		free(converted);
	}

	
	converted = multiply_real(real1, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real1, fraction, converted);
		free(converted);
	}

	
	converted = multiply_real(real1, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real1, negative_fraction, converted);
		free(converted);
	}
	

	converted = multiply_real(real2, real2);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real2, real2, converted);
		free(converted);
	}
	
	converted = multiply_real(real2, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real2, negative_real, converted);
		free(converted);
	}

	
	converted = multiply_real(real2, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real2, fraction, converted);
		free(converted);
	}

	
	converted = multiply_real(real2, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", real2, negative_fraction, converted);
		free(converted);
	}
	

	converted = multiply_real(fraction, fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", fraction, fraction, converted);
		free(converted);
	}
	
	converted = multiply_real(fraction, negative_fraction);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", fraction, negative_fraction, converted);
		free(converted);
	}

	converted = multiply_real(fraction, negative_real);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", fraction, negative_real,  converted);
		free(converted);
	}
	printf("\n");

	//Division	
	converted = divide_real(dividend1, divisor1);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", dividend1, divisor1,  converted);
		free(converted);
	}
	
	converted = divide_real(dividend2, divisor2);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", dividend2, divisor2,  converted);
		free(converted);
	}

	
	converted = divide_real(dividend3, divisor2);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", dividend3, divisor2,  converted);
		free(converted);
	}
	
	converted = divide_real(dividend3, divisor1);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", dividend3, divisor1,  converted);
		free(converted);
	}

	converted = divide_real(negative_dividend3, divisor1);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", negative_dividend3, divisor1,  converted);
		free(converted);
	}

	converted = divide_real(dividend3, negative_divisor1);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", dividend3, negative_divisor1,  converted);
		free(converted);
	}


	converted = divide_real(negative_dividend1, negative_divisor1);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", negative_dividend1, negative_divisor1,  converted);
		free(converted);
	}
	
	converted = divide_real(negative_dividend2, negative_divisor2);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s", negative_dividend2, negative_divisor2,  converted);
		free(converted);
	}

	printf("\n");
	return 0;
}
