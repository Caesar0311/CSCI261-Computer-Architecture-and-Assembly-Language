/**
 * @file utility.h
 * @author Humayun Kabir, Instructor, CSCI 261, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *   
 * Defines some utility functions that are useful to perform integer arithmetic
 * (add, subtract, multiply, divide) on twos complement represented numbers.
 * Defines some utility functions that are useful to perform floating point arithmetic
 * (add, subtract, multiply, divide) on floating point represented numbers.
 *  
 */


#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__



#define BINARY_WORD_SIZE 32		//Number of digits of a binary word

#define DECIMAL_MAX_DIGITS 10		//Maximum number of digits allowed in a decimal number 

#define BIASED_VALUE 127		//Bias value for biased_127 number
#define BIASED_127_DECIMAL_MAX_DIGITS 3		//Maximum number of digits allowed in a biased_127 decimal number 
#define BIASED_127_BINARY_MAX_DIGITS 8 	//Maximum number of digits allowed in a biased_127 binary number 

#define REAL_PART_MAX_DIGITS 10 	//Maximum number of digits allowed in a part of a real number 
#define REAL_PART_BINARY_MAX_DIGITS 64
#define REAL_MAX_DIGITS 25		//Maximum number of digits allowed in a real number


#define FLOATING_POINT_EXPONENT_DIGITS 8 //Maximum number of binary digits allowed in an exponent 
					 //of a floating point number 
					
#define FLOATING_POINT_EXPONENT_MAX_VALUE 127	  //Maximum value allowed for floating point exponent 
					 
#define FLOATING_POINT_EXPONENT_MIN_VALUE -126	  //Minimum value allowed for floating point exponent 
					 
#define SIGNIFICAND_START_BIT_IN_FLOATING_POINT 9 //Bit index in a floating point number where the significand
						  //part of the floating point number starts
#define FLOATING_POINT_SIGNIFICAND_DIGITS 23	  //Maximum number of binary digits allowed in a significand 								  	    // of a floating point number 

#define FLOATING_POINT_MAX_DIGITS 32 	//Maximum number of binary digits allowed in a floating point number 						  						 
#define TRUE 1				//Logical TRUE representation

#define FALSE 0			//Logical FALSE representation

void reverse(char* str);
//Parameter 'str' is a NULL terminted string.
//Reverse all the characters, except NULL, of the string 'str'
				
void add_sign(char* number, const char sign);
//Pointer 'number' is pointing a NULL terminated string, which has enough 
//memory to add one more character.
//Move all the characters of the string 1 position right.
//Insert 'sign' at the first index of the string.
				
int count_leading_zeros(const char* number);
//Count and return the number of consecutive zeros at the beginning of the binary number.
				
int count_leading_ones(const char* number);
//Count and return the number of consecutive ones at the beginning of the binary number.
			
char* extend_integer_binary_to_word_size(const char* number, const int word_size); 
//Allocate enough memory for a new string to hold the extended binary.
//Fill the most significant extra digits of the word with zeros and copy
//the least significant digits from the binary number represented by parameter 'number'.
//Return the pointer of the extended binary.	

char* extend_fraction_binary_to_word_size(const char* number, const int word_size);
//Allocate enough memory for a new sring to hold the extended binary.
//Fill the least significant extra digits of the word with zeros and copy
//the most significant digits from the binary number represented by parameter 'number'.
//Return the pointer of the extended binary. 

void group_arithmetic_shift_right(char* aregister, char* qregister, char* q_1, const int word_size);
//Both 'aregister' and 'qregister' have 'word_size' number of binary digits and 'q_1' has only
//one binary digits. 
//Assume they have been placed together from left to right.
//Perform 1-bit arithmetic right shift of the bits of the group assuming the sign bit is at 'aregister[0]'.
					 
void group_logical_shift_left(char* aregister, char* qregister, const int word_size);
//Both 'aregister' and 'qregister' have 'word_size' number of binary digits. 
//Assume they have been placed together from left to right.
//Perform 1-bit logical left shift of the bits of the group.
					 
void logical_shift_right(char* aregister);
//Perform 1-bit logical right shift on 'aregister' bits.
					 
void logical_shift_left(char* aregister);
//Perform 1-bit logical left shift on 'aregister' bits.
					 
int are_binary_digits(const char* number);
//Return TRUE if the digits of the number are either zero or one.
					
int are_decimal_digits(const char* number);
//Return TRUE if the digits of the number are one of the decimal digits (0 to 9).
					 
int is_binary(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a binary number and all the digits are binary digits.
					 
int is_decimal(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number and all the digits are decimal digits.
					
int is_biased_127_decimal(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased_127 number and all the digits are decimal digits.
					 
int is_biased_127_binary(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased binary number and all the digits are binary digits.
					 
int is_significand(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating-point significand  and all the digits are binary digits.
					 
int is_real(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 
					 
int is_floating_point(const char* number);
//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of floating point number, and all the digits are binary digits.
					 
char* get_integer_part(const char* number);
//Assume parameter 'number' represents a real number.
//Return a new string copying the integer part of the real number.
					 
char* get_fraction_part(const char* number);
//Assume parameter 'number' represents a real number.
//Return a new string copying the fraction part of the real number.
				
#endif
