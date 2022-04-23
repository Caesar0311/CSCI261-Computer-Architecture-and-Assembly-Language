/**
 * @file main.c
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Converts the numbers from one number system to another number system.
 */



#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "utility.h"

/**
 * Main function of assingment1.
 * It converts the numbers from one number system to another number system.
 */
int main() {
	printf("\nDecimal, Binary, and Hex number systems:");
	printf("\n\t- Decimal numbers (base 10), no prefix, decimal digits: 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.");
	printf("\n\t- Binary numbers (base 2), 0b prefix, binary digits: 0 and 1.");
	printf("\n\t- Hex numbers (base 16), 0x prefix, hex digits 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, and F.");
	
	printf("\n\nConverting from one  number system to another number system. \n"); 

	char inv_decimal[] = "2345abc56";

	char zero_leading_decimal[] = "000254";

	char decimal[] = "1050";
	char large_decimal[] = "2147483647";
	
	char inv_binary[] = "0b01340111";

	char binary[] = "0b10000011010";
	char large_binary[] = "0b01111111111111111111111111111111";
	
	char inv_hex[] = "0x234afgh2";

	char hex[] = "0x41A";
	char large_hex[] = "0x7FFFFFFF";

	char real[] = "1050.61245";
	char fixed_point[] = "00000100000110101001110011001001";	
	
	
	char* converted = NULL;

	printf("\n\nChecking invalid numbers:");
	converted = to_decimal(inv_decimal);
	if ( converted != NULL) {
		printf("\n\tConverted %s  => %s", inv_decimal, converted);
       		free(converted);
	}
	
	converted = to_decimal(inv_binary);
	if ( converted != NULL) {
		printf("\n\tConverted %s => %s", binary, converted);
       		free(converted);
	}

	
	converted = to_decimal(inv_hex);
	if( converted !=NULL) {
		printf("\n\tConverted %s => %s", hex, converted);
       		free(converted);
	}	
	

	printf("\n\nConverting to decimal:");
	converted = to_decimal(zero_leading_decimal);
	if ( converted != NULL) {
		printf("\n\tConverted %s  => %s", zero_leading_decimal, converted);
       		free(converted);
	}


	converted = to_decimal(decimal);
	if ( converted != NULL) {
		printf("\n\tConverted %s  => %s", decimal, converted);
       		free(converted);
	}


	converted = to_decimal(binary);
	if ( converted != NULL) {
		printf("\n\tConverted %s => %s", binary, converted);
       		free(converted);
	}

	converted = to_decimal(large_binary);
	if ( converted != NULL) {
		printf("\n\tConverted %s => %s", large_binary, converted);
       		free(converted);
	}

	converted = to_decimal(hex);
	if( converted !=NULL) {
		printf("\n\tConverted %s => %s", hex, converted);
       		free(converted);
	}	

	converted = to_decimal(large_hex);
	if( converted !=NULL) {
		printf("\n\tConverted %s => %s", large_hex, converted);
       		free(converted);
	}	

	printf("\n\nConverting to binary:");
	converted = to_binary(decimal);
	if( converted != NULL) {
		printf("\n\tConverted %s => %s", decimal, converted);
       		free(converted);
	}	
	
	converted = to_binary(large_decimal);
	if( converted != NULL) {
		printf("\n\tConverted %s => %s", large_decimal, converted);
       		free(converted);
	}	
	
	converted = to_binary(binary);
	if( converted != NULL) {
		printf("\n\tConverted %s => %s", binary, converted);
       		free(converted);
	}	


	converted = to_binary(hex);
	if (converted != NULL) {
		printf("\n\tConverted %s => %s", hex, converted);
       		free(converted);
	}	
	
	converted = to_binary(large_hex);
	if (converted != NULL) {
		printf("\n\tConverted %s => %s", large_hex, converted);
       		free(converted);
	}	

	printf("\n\nConverting to hex:");
	converted = to_hex(decimal);
	if( converted !=NULL) {
		printf("\n\tConverted %s => %s", decimal, converted);
       		free(converted);
	}	
	
	converted = to_hex(large_decimal);
	if( converted !=NULL) {
		printf("\n\tConverted %s => %s", large_decimal, converted);
       		free(converted);
	}	


	converted = to_hex(binary);
	if( converted != NULL ) {
		printf("\n\tConverted %s => %s", binary, converted);
       		free(converted);
	}	

	converted = to_hex(large_binary);
	if( converted != NULL ) {
		printf("\n\tConverted %s => %s", large_binary, converted);
       		free(converted);
	}	



	printf("\n\nConverting to and from fixed point:");
	converted = to_fixed_point(real);
	if( converted != NULL ) {
		printf("\n\tConverted %s => %s", real, converted);
       		free(converted);
	}	


	converted = from_fixed_point(fixed_point);
	if( converted != NULL ) {
		printf("\n\tConverted %s => %s", fixed_point, converted);
       		free(converted);
	}	

	printf("\n");
	
	return 0;
}
