/**
 * @file main.c
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Convert signed numbers from one number system to another number system.
 */


#include <stdio.h>
#include <stdlib.h>
#include "signed_convert.h"

int main() {

	char integer[] = "1050";
	char positive_integer[] = "+1050";
	char negative_integer[] = "-1050";
	char sign_mag_positive[] = "00000000000000000000010000011010";
	char sign_mag_negative[] = "10000000000000000000010000011010";

	char twos_comp_positive[] = "00000000000000000000010000011010";
	char twos_comp_negative[] = "11111111111111111111101111100110";

	char biased_127_smallest[] = "-126";
	char biased_127_zero[] = "0";
	char biased_127_largest[] = "+127";

	char biased_127_binary_smallest[] = "00000001";
	char biased_127_binary_zero[] = "01111111";
	char biased_127_binary_largest[] = "11111110";
	
	
	
	char real[] = "1050.61245";
	char negative_real[] = "-1050.61245";
	char real2[] = "16777216.0";
	char real3[] = "256.15625";
	char floating_point[] = "01000100100000110101001110011001";
	char negative_floating_point[] = "11000100100000110101001110011001";
	char floating_point2[] = "01001011100000000000000000000000";
	char floating_point3[] = "01000011100000000001010000000000";

	char fraction[] = "0.15625";
	char fraction_floating_point[] = "00111110001000000000000000000000";
	char fraction2[] = "0.00000119";
	char fraction_floating_point2[] = "00110101100111111011100000000000";
	char negative_fraction[] = "-0.15625";
	char negative_fraction_floating_point[] = "10111110001000000000000000000000";



	char* converted = NULL;

	printf("\nSigned-magnitude representations:");
	converted = to_sign_magnitude(integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", integer, converted);
		free(converted);
	}

	converted = to_sign_magnitude(positive_integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", positive_integer, converted);
		free(converted);
	}


	converted = to_sign_magnitude(negative_integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_integer, converted);
		free(converted);
	}

	converted = from_sign_magnitude(sign_mag_positive);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", sign_mag_positive, converted);
		free(converted);
	}

	converted = from_sign_magnitude(sign_mag_negative);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", sign_mag_negative, converted);
		free(converted);
	}

	printf("\n\nTwo's complement representations:");
	converted = to_twos_complement(integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", integer, converted);
		free(converted);
	}

	converted = to_twos_complement(positive_integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", positive_integer, converted);
		free(converted);
	}


	converted = to_twos_complement(negative_integer);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_integer, converted);
		free(converted);
	}


	converted = from_twos_complement(twos_comp_positive);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", twos_comp_positive, converted);
		free(converted);
	}

	converted = from_twos_complement(twos_comp_negative);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", twos_comp_negative, converted);
		free(converted);
	}

	printf("\n\nBiased_127 representations:");

	converted = to_biased_127(biased_127_smallest);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_smallest, converted);
		free(converted);
	}

	converted = to_biased_127(biased_127_zero);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_zero, converted);
		free(converted);
	}



	converted = to_biased_127(biased_127_largest);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_largest, converted);
		free(converted);
	}

	converted = from_biased_127(biased_127_binary_smallest);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_binary_smallest, converted);
		free(converted);
	}

	converted = from_biased_127(biased_127_binary_zero);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_binary_zero, converted);
		free(converted);
	}



	converted = from_biased_127(biased_127_binary_largest);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", biased_127_binary_largest, converted);
		free(converted);
	}

	printf("\n\nFloating point representations:");
	converted = to_floating_point(real);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", real, converted);
		free(converted);
	}

	converted = to_floating_point(negative_real);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_real, converted);
		free(converted);
	}

	converted = to_floating_point(real2);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", real2, converted);
		free(converted);
	}


	converted = to_floating_point(real3);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", real3, converted);
		free(converted);
	}


	converted = to_floating_point(fraction);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", fraction, converted);
		free(converted);
	}

	converted = to_floating_point(fraction2);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", fraction2, converted);
		free(converted);
	}



	converted = to_floating_point(negative_fraction);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_fraction, converted);
		free(converted);
	}

	converted = from_floating_point(floating_point);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", floating_point, converted);
		free(converted);
	}

	converted = from_floating_point(negative_floating_point);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_floating_point, converted);
		free(converted);
	}

	converted = from_floating_point(floating_point2);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", floating_point2, converted);
		free(converted);
	}


	converted = from_floating_point(floating_point3);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", floating_point3, converted);
		free(converted);
	}


	converted = from_floating_point(fraction_floating_point);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", fraction_floating_point, converted);
		free(converted);
	}


	converted = from_floating_point(fraction_floating_point2);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", fraction_floating_point2, converted);
		free(converted);
	}



	converted = from_floating_point(negative_fraction_floating_point);
	if(converted != NULL) {
		printf("\n\tConverted \t%s \t=> \t%s", negative_fraction_floating_point, converted);
		free(converted);
	}


	printf("\n");
	return 0;
}
