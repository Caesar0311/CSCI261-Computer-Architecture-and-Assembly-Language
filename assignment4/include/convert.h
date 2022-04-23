/**
 * @file convert.h
 * @author Humayun Kabir, Instructor, CSCI 261, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines the some coversion functions to convert real numbers into floating point representation.
 */


#ifndef __CONVERT_HEADER__
#define __CONVERT_HEADER__



char* integer_to_binary(int int_num, int binary_size);
//Allocate enough memory for a new string to hold an integer binary number.
//Use decimal-to-binary conversion algorithm to get the equivalent binary digits from 
//the decimal number int_num' and save the binary digits into the new string.
//Return the pointer of the new string.


char* fraction_to_binary(const char* number, int binary_size);
//Allocate enough memory for a new string to hold a fraction binary number.
//Use decimal-fraction-to-binary conversion algorithm to get the equivalent binary digits from 
//the decimal fraction and save the binary digits into the new string.
//Return the pointer of the new string.


int binary_to_int(const char* number);
//Use binary-to-deciaml conversion algorithm to get the equivalent 
//decimal (integer) number from the binary digits.
//Return the integer number.


char one_bit_add(const char op1, const char op2, const char cin, char* cout);
//Parameters 'op1', 'op2' and 'cin' are binary operands, their value can be either
//'0' or '1' and cannot be modified inside this function.
//Add these binary operands and save the resultant carry of the addition into 'cout'.
//Return the result of the addition to the caller.


char* get_magnitude_binary(const char* signed_number, int binary_size);
//Ignore the sign of the 'signed_number', if there is one.
//Get the integer value from 'signed_number'.
//Get the equivalent binary digits of the integer value by calling integer_to_binary() 
//and return the result.


void ones_complement(char* number);
//Filip each binary digit in the number.


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
//	the extened binary number by calling twos_complement() function.
//	Free all dynamically allocated memories that are no longer required.
//	Return the twos complement number to the caller.



char* from_twos_complement(const char* number);
//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//	Use twos-complement-bianry-to-decimal conversion algorithm to get the integer equivalent 
//	of the twos complement number. 
//	If the sign bit (most significant or left most bit) is nagative, make sure, you subtract 
//	the signifacance value of the sign bit instead of it.
//	If the sign bit is negative, in order to omptimize the performance of your code you can 
//	use the least significant sign bit (which is the right most sign bit in a negative 
//	twos complement number) during the conversion. You can call count_leading_ones() function for this purpose.
//	If the sign bit is positive and there are many leading zeros, in order to optimize the performance
//	of your code you can ignore all the leading zeros. You can call count_leading_zeros() for this purpose. 
//	Convert the integer into a new string and return the pointer of the string.


char* int_to_biased_127(int number);
//Check whether the integer number is within the range of FLOATING_POINT_EXPONENT_MIN_VALUE and 
//FLOATING_POINT_EXPONENT_MAX_VALUE.
//If yes, perform the followings:
//	Add BIASED_VALUE to the number
//	Call integer_to_binary() function to get the binary representation of the biased 
//	number.
//	Call extend_integer_binary_to_word_size() to extend the biased binary to
//	BIASED_127_BINARY_MAX_DIGITS.
//	Free all dynamically allocated memories that are no longer required. 
//	Return the extended binary to the caller.


char* to_biased_127(const char* number);
//Check whether the number is a valid biased_127 number by calling is_biased_127() fucntion.
//If yes, get the integer equivalent of the biased_127 number and call int_to_biased_127()
//function to get the binary represenation of bised_127 number and return it to the caller.


int int_from_biased_127(const char* number);
//Call binary_to_int() function to get the integer equivalent of the biased_127 number
//and subtract the BIASED_VALUE from the number and return it.


char* from_biased_127(const char* number);
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
//and fraction parts of a real number and 'exponent' is exponent value of the
//real number in decimal (int).
//Following floating-point-normalization algorithm move the digits of the integer and 
//the fraction parts as necessary and adjust the exponent value accordingly.  


char* to_floating_point(const char* number);
//Check whether the number is a valid real number by calling is_real() function.
//If yes, perform the followings:
//	Call get_integer_part() function to get the integer part of the real number.
//	Call get_fraction_part() fucntion to get the fraction part of the real number.
//	Call get_magnitude_binary() function to get the binary representation of the
//	integer part of the real number.
//	Call fraction_to_binary() function to get the binary representation of the 
//	fraction part of the real number.
//	Initialize the exponent to zero.
//	Call normalize() function to normalize the integer and fraction binaries and 
//	to adjust the exponent of the number.
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
//	Copy the floating point significand into the floating point string. Remember
//	to exclude implicit '1' from the significand while copying.
//	Free all dynamically allocated memories that are no longer required.
//	Return the pointer of the floating point string to the caller.


double get_significand_value(const char* sig);
//Check whether 'sig' is a valid significand by calling is_significand() function.
//If yes, use significand binary-to-double conversion algorithm to find the fraction
//value from the significand, add implicit '1' with the fraction value and return
//the result.


char* extract_exponent(const char* number);
//Copy the exponent part of the floating point number into a new string and return
//the pointer of the new string to the caller.


char* extract_significand(const char* number);
//Copy the significand part of the floating point number into a new string and return
//the pointer of the string to the caller.


char* from_floating_point(const char* number);
//Check whether the number is a valid floating point number or not 
//by calling is_floating_point() function.
//If yes, perform the followings:
//	Extract the exponent part from the floating point number by calling 'extract_exponent()' function.
//	Call int_from_biased_127() function to get the exponent value for the floating point number.
//	Extract the significand part from the floating point number by calling 'extract_significand()' function.
//	Call get_significand_value() function to get the value of the significand part.
//	Compute the real number using the sign bit of the floation point number and the above
//	exponent and significand values.
//	Allocate enough memory to a new string to hold the sign and the digits of a real number.
//	Convert the above computed real number into the new string.
//	Free all dynamically allocated memories that are no longer required.
//	Return the pointer of real-number string to the caller.



#endif
