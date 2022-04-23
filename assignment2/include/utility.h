/**
 * @file utility.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines some utility functions that are useful to convert signed numbers from one number system
 * to another number system.
 */


#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__


#define BINARY_WORD_SIZE 32		//Number of digits of a binary word

#define DECIMAL_MAX_DIGITS 10		//Maximum number of digits allowed in a decimal number 

#define BIASED_VALUE 127		//Bias value for biased_127 number

#define BIASED_127_DECIMAL_MAX_DIGITS 3		//Maximum number of digits allowed in a biased_127 decimal number 

#define BIASED_127_BINARY_MAX_DIGITS 8 	//Maximum number of digits allowed in a biased_127 binary number 

//Minium decimal value allowed to a valid biased_127 exponent in a IEE 754 32-bit floating point number is -126
#define BIASED_127_DECIMAL_MIN_VALUE -126	

//Maxinum decimal value allowed to a valid biased_127 exponent in a IEE 754 32-bit floating point number is 127
#define BIASED_127_DECIMAL_MAX_VALUE 127	

#define REAL_PART_MAX_DIGITS 10 	//Maximum number of digits allowed in a part of a real number 

#define REAL_MAX_DIGITS 22		//Maximum number of digits allowed in a real number

#define FLOATING_POINT_EXPONENT_DIGITS 8 //Maximum number of binary digits allowed in an exponent 
					 //of a floating point number 

#define SIGNIFICAND_START_BIT_IN_FLOATING_POINT 9 //Bit index in a floating point number where the significand
						  //part of the floating point number starts

#define FLOATING_POINT_SIGNIFICAND_DIGITS 23	  //Maximum number of binary digits allowed in a significand 
						  // of a floating point number 

#define FLOATING_POINT_MAX_DIGITS 32 	//Maximum number of binary digits allowed in a floating point number 


#define TRUE 1				//Logical TRUE representation
#define FALSE -1			//Logical FALSE representation



void reverse(char* str);
//Parameter 'str' is a NULL terminted string.
//Reverse all the non-NULL characters of the string 'str'


void add_sign(char* number, char sign);
//Pointer 'number' is pointing a NULL terminated string, which has enough 
//memory to add one more character.
//Move all the characters of the string 1 position right.
//Insert 'sign' at the first index of the string.
 

char* extend_integer_binary_to_word_size(char* number, int word_size); 
//Allocate enough memory for an extended number.
//Fill the most significant (left most) extra digits of the extended number with zeros and copy
//the least significant (right most) digits from the number.
//Return the pointer of the extended number.


char* extend_fraction_binary_to_word_size(char* number, int word_size);
//Allocate enough memory for an extended number.
//Copy the most significant (left most) digits of the extended number from the number.
//Fill the least significant (right most) extra digits of the extended number with zeros.
//Return the pointer of the extended number.


int are_binary_digits(char* number);
//Return TRUE if all the digits of the number are either zero or one.


int are_decimal_digits(char* number);
//Return TRUE if all the digits of the number are one of the decimal digits.


int is_binary(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a binary number and all the digits are binary digits.


int is_decimal(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number and all the digits are decimal digits.


int is_biased_127_decimal(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased_127 decimal number and all the digits are decimal digits.


int is_biased_127_binary(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased binary number and all the digits are binary digits.


int is_significand(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating-point significand and all the digits are binary digits.


int is_real(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 

int is_floating_point(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating point number, and all the digits are binary digits.


char* get_integer_part(char* number);
//Return a new string copying the integer part of the real number.


char* get_fraction_part(char* number);
//Return a new string copying the fraction part of the real number.


#endif
