/**
 * @file utility.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines the some utility functions that are useful to perform integer arithmetic
 * (add, subtract, multiply, divide) on twos complement represented integer numbers.
 */


#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__


#define BINARY_WORD_SIZE 32

#define DECIMAL_MAX_DIGITS 10

#define TRUE 1
#define FALSE 0


void reverse(char* str);
//Parameter 'str' is a NULL terminted string.
//Reverse all non-NULL characters of the string 'str'


void add_sign(char* number, const char sign);
//Pointer 'number' is pointing a NULL terminated string, which has enough 
//memory to add one more character.
//Move all the characters of the string 1 position right.
//Insert 'sign' at the first index of the string.
 

char* extend_integer_binary_to_word_size(const char* number, int word_size); 
//Allocate enough memory for an extended number.
//Fill the most significant (left most) extra digits of the extended number with zeros and copy
//the least significant (right most) digits from the number.
//Return the pointer of the extended number.

int count_leading_ones(const char* number);
//Count and return the number of consecutive ones at the beginning of the binary number.
 

void group_arithmetic_shift_right(char* aregister, char* qregister, char* q_1, int word_size);
//Both 'aregister' and 'qregister' have 'word_size' number of binary digits and 'q_1' has only
//one binary digits. 
//Assume they have been placed together from left to right.
//Perform arithmetic right shift of the bits of the group assuming the sign bit at 'aregister[0]'.


void group_logical_shift_left(char* aregister, char* qregister, int word_size);
//Both 'aregister' and 'qregister' have 'word_size' number of binary digits. 
//Assume they have been placed together from left to right.
//Perform logical left shift of the bits of the group.


int are_binary_digits(const char* number);
//Return TRUE if all the digits of the number are either zero or one.


int are_decimal_digits(const char* number);
//Return TRUE if all the digits of the number are one of the decimal digits.


int is_binary(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a double word binary number and all the digits are binary digits.


int is_decimal(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number and all the digits are decimal digits.



#endif
