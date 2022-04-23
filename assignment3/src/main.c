/**
 * @file main.c
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Performs integer arithmetic (add, subtract, multiply, and divide) on twos complement 
 * represented integer numbers.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "integer_arithmetics.h"

int main() {

	const char* integer1 = "1050";
	const char* negative_integer1 = "-1050";

	const char* seven = "7";
	const char* three = "3";

	const char* minus_seven = "-7";
	const char* minus_three = "-3";

	const char* dividend1 = "1103886";
	const char* divisor1 = "1050";	

	const char* negative_dividend1 = "-1103886";
	const char* negative_divisor1 = "-1050";	


	char* converted = NULL;

	printf("\nInteger arithmetics:");
	
	converted = add_integer(seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", seven, three, converted);
		free(converted);
	}
	
	converted = add_integer(minus_seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", minus_seven, three, converted);
		free(converted);
	}


	
	converted = add_integer(seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", seven, minus_three, converted);
		free(converted);
	}

	
	converted = add_integer(minus_seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", minus_seven, minus_three, converted);
		free(converted);
	}

	
	converted = add_integer(integer1, integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", integer1, integer1, converted);
		free(converted);
	}


	converted = add_integer(integer1, negative_integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) + (%s) \t=> \t%s", integer1, negative_integer1, converted);
		free(converted);
	}
	
	converted = subtract_integer(seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", seven, three, converted);
		free(converted);
	}
	
	converted = subtract_integer(minus_seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", minus_seven, three, converted);
		free(converted);
	}


	
	converted = subtract_integer(seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", seven, minus_three, converted);
		free(converted);
	}

	
	converted = subtract_integer(minus_seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", minus_seven, minus_three, converted);
		free(converted);
	}



	converted = subtract_integer(integer1, integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", integer1, integer1, converted);
		free(converted);
	}


	converted = subtract_integer(integer1, negative_integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) - (%s) \t=> \t%s", integer1, negative_integer1, converted);
		free(converted);
	}



	converted = multiply_integer(seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", seven, three, converted);
		free(converted);
	}


	converted = multiply_integer(minus_seven, three);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", minus_seven, three, converted);
		free(converted);
	}


	converted = multiply_integer(seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", seven, minus_three, converted);
		free(converted);
	}


	converted = multiply_integer(minus_seven, minus_three);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", minus_seven, minus_three, converted);
		free(converted);
	}
	
	converted = multiply_integer(integer1, integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", integer1, integer1, converted);
		free(converted);
	}
	
	converted = multiply_integer(negative_integer1, integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", negative_integer1, integer1, converted);
		free(converted);
	}

	converted = multiply_integer(integer1, negative_integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", integer1, negative_integer1, converted);
		free(converted);
	}

	converted = multiply_integer(negative_integer1, negative_integer1);
	if(converted != NULL) {
		printf("\n\t \t(%s) * (%s) \t=> \t%s", negative_integer1, negative_integer1, converted);
		free(converted);
	}

	char reminder[33] = {0};
	converted = divide_integer(seven, three, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", seven, three, converted, reminder);
		free(converted);
	}
	
	converted = divide_integer(minus_seven, three, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", minus_seven, three, converted, reminder);
		free(converted);
	}

	converted = divide_integer(seven, minus_three, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", seven, minus_three, converted, reminder);
		free(converted);
	}

	converted = divide_integer(minus_seven, minus_three, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", minus_seven, minus_three, converted, reminder);
		free(converted);
	}

	converted = divide_integer(dividend1, divisor1, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", dividend1, divisor1, converted, reminder);
		free(converted);
	}

	converted = divide_integer(negative_dividend1, divisor1, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", negative_dividend1, divisor1, converted, reminder);
		free(converted);
	}

	converted = divide_integer(dividend1, negative_divisor1, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", dividend1, negative_divisor1, converted, reminder);
		free(converted);
	}

	converted = divide_integer(negative_dividend1, negative_divisor1, reminder);
	if(converted != NULL) {
		printf("\n\t \t(%s) / (%s) \t=> \t%s, reminder: %s", negative_dividend1, negative_divisor1, converted, reminder);
		free(converted);
	}




	printf("\n");
	return 0;
}
