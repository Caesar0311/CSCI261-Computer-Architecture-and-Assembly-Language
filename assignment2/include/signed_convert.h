/**
 * @file signed_convert.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines functions to convert signed numbers from one number system to another
 * number system as below:
 *	Signed Integer to Sign Magnitude Binary
 *	Sign Magnitude Binary to Signed Integer
 *	Signed Integer to Twos Complement Binary
 *	Twos Complement Binary to Signed Integer
 *	Signed Integer to Biased-127 Binary
 *	Biased-127 Binary to Signed Integer
 *	Signed Real to Floating Point Binary
 *	Floating Point Binary to Signed Real 
 *
 */


#ifndef __SIGNED_CONVERT_HEADER__
#define __SIGNED_CONVERT_HEADER__


char* integer_to_binary(int int_num, int binary_size);
//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'bianry_size' binary digits.
//Use decimal-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal number int_num' and save the binary digits into the new string.
//Return the pointer of the new string.


char* fraction_to_binary(char* number, int binary_size);
//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'bianry_size' binary digits.
//Use decimal-fraction-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal fraction number and save the binary digits into the new string.
//Return the pointer of the new string.



int binary_to_int(char* number, int is_sign_magnitude);
//Use binary-to-deciaml conversion algorithm to get the equivalent 
//decimal (integer) number from the binary digits.
//If 'is_sign_magnitude' is TRUE, ignore the most significant sign bin in the 
//conversion process.
//Return the integer number.


char one_bit_add(char op1, char op2, char cin, char* cout);
//Parameters 'op1', 'op2' and 'cin' are binary operands, their value can be either
//'0' or '1'.
//Add these binary operands and save the resultant carry of the addition into 'cout'.
//Return the result of the addition to the caller.


char* get_magnitude_binary(char* signed_number, int binary_size);
//Ignore the sign bit if there is one and get the integer value of the 'signed_number'.
//Call the function integer_to_binary() and return the result.


char* to_sign_magnitude(char* number);
//Check whether the number is a valid decimal number by calling is_decimal() function.
//If yes, perform the followings:
//	Call get_magnitude_binary() function to get the binary representation of the
//	magnitude of the number.
//	Extend the binary representation of the magnitude to BINARY_WORD_SIZE by
//	calling extend_integer_binary_to_word_size() function.
//	Free all dynamically allocated memories that are no longer required.
//	Set the appropriate sign bit for the signed magnitude number and return it
//	to the caller.


char* from_sign_magnitude(char* number);
//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//	Call binary_to_int() function indicating it's a sign magnitude binary number
//	and get the integer equivalent of the sign magnitude number.
//	Convert the integer into a new string and add the appropriate sign to the string.
//	Return the string.


void ones_complement(char* number);
//Flip each binary digit in the number.


void twos_complement(char* number);
//Get the ones complement of the number by calling ones_complement() function.
//Add '1' to the ones complement by calling one_bit_add() function as many times
//as it requires.


char* to_twos_complement(char* number);
//Check whether the number is a valid decimal number by calling is_decimal() function.
//If yes, perform the followings:
//	Call get_magnitude_binary() function to get the binary representation of the
//	magnitude of the number.
//	Extend the binary representation of the magnitude to BINARY_WORD_SIZE by
//	calling extend_integer_binary_to_word_size() function.
//	If the sing bit of the number is '-' get the twos complement of the
//	the signed magnitude number by calling twos_complement() function.
//	Free all dynamically allocated memories that are no longer required.
//	Return the twos complement number to the caller.



char* from_twos_complement(char* number);
//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//	Use twos-complement-bianry-to-decimal conversion algorithm to get the integer equivalent 
//	of the twos complement number.
//	Convert the integer into a new string and return the string.



char* int_to_biased_127(int number);
//Check whether the integer number is within the range of BIASED_127_MIN_VALUE and 
//BIASED_127_MAX_VALUE.
//If yes, perform the followings:
//	Add BIASED_VALUE to the number
//	Call integer_to_binary() function to get the binary representation of the biased 
//	number.
//	Call extend_integer_binary_to_word_size() to extend the biased binary to
//	BIASED_127_BINARY_MAX_DIGITS.
//	Free all dynamically allocated memories that are no longer required. 
//	Return the extended binary to the caller.


char* to_biased_127(char* number);
//Check whether the number is a valid biased_127 number by calling is_biased_127() fucntion.
//If yes, get the integer equivalent of the biased_127 number and call int_to_biased_127()
//function to get the binary represenation of bised_127 number and return it to the caller.


int int_from_biased_127(char* number);
//Call int_from_biased_127() function to get the integer equivalent of the biased_127 number
//and subtract the BIASED_VALUE from the number and return it.


char* from_biased_127(char* number);
//Check whether the number is a valid binary representation of a biased_127 number by calling
//is_baised_127_binary() function.
//If yes, 
//	Call int_from_biased_127() function to get the integer equivalent of the baised_127
//	number.
//	Allocate enough memory to a string to hold BIASED_127_MAX_DIGITS plus the sign.
//	Convert the integer number to the new string and return it.
//


void normalize(char* integer, char* fraction, int* exponent);
//Parameters 'integer', 'fraction' are intermediate binary represenation of the integer
//and fraction parts of a real number and 'exponent' is binary exponent value of the
//real number.
//Following floating-point-normalization algorithm move the digits of the integer and 
//the fraction parts as necessary and adjust the exponent value accordingly.  


char* to_floating_point(char* number);
//Check whether the number is a valid real number by calling is_real() function.
//If yes, perform the followings:
//	Call get_integer_part() function to get the integer part of the real number.
//	Call get_fraction_part() fucntion to get the fraction part of the real number.
//	Call get_magnitude_binary() function to get the binary representation of the
//	integer part of the real number.
//	Call fraction_to_binary() function to get the binary representation of the 
//	fraction part of the real number.
//	Call normalize() function to normalize the integer and fraction binaries and 
//	to adjust the exponent of the real number.
//	Call int_to_biased_127() function to get biased_127 binary representation
//	of the adjusted exponent of the floating point number.
//	Call extend_integer_binary_to_word_size() function to extend biased_127 exponent
//	bianry to FLOATING_POINT_EXPONENT_DIGITS.
//	Call extend_fraction_binary_to_word_size() function to extend fraction
//	bianry (floating point significand) to FLOATING_POINT_SIGNIFICAND_DIGITS.
//	Allocate enough memory to a new string to hold the parts of the  floating point
//	number.
//	Set the sign bit of the floating point number according to the sign bit of the
//	the real number.
//	Copy the biased_127 exponent into the floating point string.
//	Copy the floating point significand into the floating point string.
//	Free all dynamically allocated memories that are no longer required.
//	Return the floating point string to the caller.


double get_significand_value(char* sig);
//Check whether 'sig' is a valid significand by calling is_significand() function.
//If yes, use significand binary to double conversion algorithm to find the value
//of the significand and return it.


char* from_floating_point(char* number);
//Check whether the number is a valid floating point number or not 
//by calling is_floating_point() function.
//If yes, perform the followings:
//	Extract the exponent part from the floating point number.
//	Call int_from_biased_127() function to get the exponent value for the real number.
//	Extract the significand part from the floating point number.
//	Call get_significand_value() function to get the value of the significand part.
//	Compute the real number using the sign bit of the floation point number and the above
//	computed exponent and significand values.
//	Allocate enough memory to a new string to hold the sign and the digits of a real number.
//	Convert the above computed real number into the new string.
//	Free all dynamically allocated memories that are no longer required.
//	Return the real number string to the caller.


#endif
