/**
 * @file utility.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines utility functions that are useful to convert numbers from one number system
 * to another number system.
 */



#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__


#define BINARY_WORD_SIZE 32		//Number of digits of a binary word
#define DECIMAL_MAX_DIGITS 10		//Maximum number of digits allowed in a decimal number 
#define HEX_MAX_DIGITS 8		//Maximum number of digits allowed in a hex number
#define REAL_PART_MAX_DIGITS 5 		//Maximum number of digits allowed in a part of a real number 
#define REAL_PART_MAX_VALUE 65536	//Maximum value allowed for a part of a real number
#define FIXED_POINT_PART_MAX_DIGITS 16 	//Maximum number of digits allowed in a part of a fixed point number
#define REAL_MAX_DIGITS 11		//Maximum number of digits allowed in a real number
#define FIXED_POINT_MAX_DIGITS 32	//Maximum number of digits allowed in a fixed point number.

#define TRUE 1				//Logical TRUE representation
#define FALSE 0			//Logical FALSE representation



void reverse(char* str);
//Parameter 'str' is a NULL terminted string.
//Reverse all the characters, except NULL, in the string 'str'


void add_prefix(char* number, char p0, char p1);
//Pointer 'number' is pointing a NULL terminated string, which has enough memory to add 
//two more characters.
//Move all the characters of the string 2 positions right.
//Insert 'p0' at the first index of the string.
//Insert 'p1' at the second index of the string.
 

char* extend_to_word_size(char* number, int word_size); 
//If the length of the 'number' is greater than 'word_size' report error.
//If the length of the 'number' is less than 'word_size' do the followings:
//	Allocate enough memory for a new word.
//	Fill the most significant extra digits of the word with zeros and copy
//	the least significant digits from the number.
//	Free the memory from the pointer 'number'.
//	Point the new word by the pointer 'number'.
 

int are_binary_digits(char* number);
//Return TRUE if all the digits of the number are either zero or one.


int are_hex_digits(char* number);
//Return TRUE if all the digits of the number are one of the hex digits.


int are_decimal_digits(char* number);
//Return TRUE if all the digits of the number are one of the decimal digits.


int is_binary(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a binary number, starts with the prefix '0b', and all the digits are binary digits.


int is_hex(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a hex number, starts with the prefix '0x', and all the digits are hex digits.


int is_decimal(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number, starts with no prefix, and all the digits are decimal digits.


int is_real_part(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of a real number, all the digits are decimal digits, and its value 
//is within the limit.


int is_fixed_point_part(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of a fixed point number, and all the digits are binary digits.


int is_real(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 


int is_fixed_point(char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of fixed popint number, and all the digits are binary digits.


char* get_integer_part(char* number);
//Return a new string copying the integer part of the real number.


char* get_fraction_part(char* number);
//Return a new string copying the fraction part of the real number.


#endif
