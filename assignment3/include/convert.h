/**
 * @file convert.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines the some coversion functions to convert integer numbers into twos complement representation.
 */


#ifndef __CONVERT_HEADER__
#define __CONVERT_HEADER__

char* integer_to_binary(int int_num, int binary_size);
//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'bianry_size' binary digits.
//Use decimal-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal number int_num' and save the binary digits into the new string.
//Return the pointer of the new string.


char* get_magnitude_binary(const char* signed_number, int binary_size);
//Ignore the sign bit if there is one and get the integer value of the 'signed_number'.
//Call the function integer_to_binary() and return the result.


int binary_to_int(const char* number);
//Use binary-to-deciaml conversion algorithm to get the equivalent 
//decimal (integer) number from the binary digits.
//Return the integer number.


char one_bit_add(const char op1, const char op2, const char cin, char* cout);
//Parameters 'op1', 'op2' and 'cin' are binary operands, their value can be either
//'0' or '1'.
//Add these binary operands and save the resultant carry of the addition into 'cout'.
//Return the non-carry bit of the result to the caller.


void ones_complement(char* number);
//Flip each binary digit in the number.


void twos_complement(char* number);
//Get the ones complement of the number by calling ones_complement() function.
//Add '1' to the ones complement by calling one_bit_add() function as many times
//as it requires.


char* to_twos_complement(const char* number);
//Check whether the number is a valid decimal number by calling is_decimal() function.
//If yes, perform the followings:
//	Call get_magnitude_binary() function to get the binary representation of the
//	magnitude of the number.
//	Extend the binary representation of the magnitude to BINARY_WORD_SIZE by
//	calling extend_integer_binary_to_word_size() function.
//	If the sing bit of the number is '-' get the twos complement of the
//	the signed magnitude number by calling twos_complement() function.
//	Free all dynamically allocated memories that are no longer required.
//	Return the pointer of the twos complement number to the caller.



char* from_twos_complement(const char* number);
//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//	Use twos-complement-bianry-to-decimal conversion algorithm to get the integer equivalent 
//	of the twos complement number.
//	Convert the integer into a new string and return the string.


#endif
