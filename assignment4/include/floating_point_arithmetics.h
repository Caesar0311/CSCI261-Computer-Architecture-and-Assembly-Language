/**
 * @file floating_point_arithmetics.h
 * @author Humayun Kabir, Instructor, CSCI 261, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines functions to perform floating point arithmetic
 * (add, subtract, multiply, divide) on floating point represented numbers.
 * Rounding is not being used, as a result some precision loss will happen
 *
*/



#ifndef __FLOATING_POINT_ARITHMETICS_HEADER__
#define __FLOATING_POINT_ARITHMETICS_HEADER__



/*
 * 32-bit explicit significand is being used to perform
 * 32-bit twos complement arithmeatic operations, although 
 * it contains only 24 bits value: implicit integer '1' bit 
 * and 23 bits fraction.
 * Implicit '1' bit position in 32-bit explicit significand
 * is (31-23) or 8.
 */
#define EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT_INDEX 8



/*
 * The multiplication of two 32-bit explicit significands 
 * will produce a 64-bit product.
 * In 64-bit product, the least significant 23*2 or 46 bits are fraction
 * and the bit at (63-46) or 17 is implicit integer '1' bit. 
 */ 
#define PRODUCT_SIGNIFICAND_IMPLICIT_ONE_BIT_INDEX 17



int is_zero(const char* number);
//Return TRUE if all the bits in the floating point number is zero.


void check_fp_exponent_overflow(int exponent_value);
//If the exponent_value is greater than FLOATING_POINT_EXPONENT_MAX_VALUE.
//Print an error message on the screen and exit from the program with an error code.

void check_fp_exponent_underflow(int exponent_value);
//If the exponent_value is greater than FLOATING_POINT_EXPONENT_MIN_VALUE.
//Print an error message on the screen and exit from the program with an error code.


char* copy_floating_point(const char* fp_number);
//Copy the floating point number into a new string and return it.

char* zero_floating_point();
//Create a zero floating point in a new string by setting all the bits zero character, 
//NULL terminate the string, and return it.


char* infinity_floating_point();
//Create a infinity floating point in a new string by setting its content to the binary equivalent
//digits of hex 0x7f800000, NULL terminate, and return it.


char* implicit_to_explicit(const char* fp_significand);
//Create an explicit significand of BINARY_WORD_SIZE by copying FLOATING_POINT_SIGNIFICAND_DIGITS 
//number of least significant bits from 'fp_significand' and setting explicit '1' to 
//EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT position and return it.


int get_exponent_difference(const char* fp_number1, const char* fp_number2);
//Compute the exponent difference between two ('fp_number1' and 'fp_number2') floating point
//numbers and return its integer value of the difference. 


void align_significand_to_right(char* significand, int shift_length);
//Align the significand to right by 'shift_length' number of bits.
//You may call logical_shift_right() function 'shift_length' times although it is not an
//optimum solution.


char* add_floating_point(const char* fp_number1, const char* fp_number2);
//Check whether 'fp_number1' is zero or not by calling is_zero() function.
//If yes, return a copy of 'fp_number2'.
//Check whether 'fp_number2' is zero or not by calling is_zero() function.
//If yes, return a copy of 'fp_number1'.
//Extract the significands from both floating point numbers by calling extract_significand() function.
//Create explicit significands of BINARY_WORD_SIZE and get explicit '1' inserted from both significands 
//by calling implicit_to_explicit() function.
//Get the exponent difference between two floating point numbers by calling get_exponent_difference()
//function.
//If exponent difference is positive, align the second explicit significand by calling
//align_significand_to_right() function and set the result exponent to the first floating point
//number exponent. Return a copy of the first floating point number if the second explicit 
//significand becomes zero after the alignment.
//If exponent difference is negative, align the first explicit significand by calling
//align_significand_to_right() function and set the result exponent to the second floating point
//number exponent. Return a copy of the second floating point number if the first explicit 
//significand becomes zero after the alignment.
//If exponent diference is zero, set the result exponent to any of the floating point numbers
//exponent.
//Get the integer value of the result exponent by calling int_from_biased_127() function.
//Get the twos complement of the first explicit significand if the sign bit of the first floating
//point number is negative.
//Get the twos complement of the second explicit significand if the sign bit of the second floating
//point number is negative.
//Add two explicit significands by calling add_twos_complement() function.
//Get the twos complement of the result significand if necessary.
//Return a zero floating point if the result is zero.
//Normalize the result as followings, if necessary.
	//Each explicit significand has eaxactly one explicit integer (1) bit and 
	//FLOATING_POINT_SIGNIFICAND_DIGITS number of fraction bits.
	//If addition result has exaclty (FLOATING_POINT_SIGNIFICAND_DIGITS + 1) digits,
	//it is already normalized. 
	//If addition result has more than (FLOATING_POINT_SIGNIFICAND_DIGITS + 1) digits, 
	//shift the result right by calling logical_shift_right() function and increment the result 
	//exponent until the addition result becomes exactly (FLOATING_POINT_SIGNIFICAND_DIGITS +1 ) digits. 
	//Check whether there is an exponent overflow or not after each increment by 
	//calling check_fp_exponent_overflow() function. 
	//If addition result has less than (FLOATING_POINT_SIGNIFICAND_DIGITS + 1) digits,
	//shift the result left by calling logical_shift_left() function and decrement 
	//the result exponent value, and check exponent underflow by calling 
	//check_fp_exponent_underflow() function after each decrement. 

//Get biased_127 representation of the result exponent value by calling int_to_biased_127()
//furnction.
//Allocate enough memory for a result floating point number.
//Set appropriate sign value to the floating point number.
//Copy the biased_127 result exponent into floating point number exponent.
//Copy the most siginificant FLOATING_POINT_SIGNIFICAND_DIGITS number of bits from the fraction component
//of the normalized addition result into floating point significand.
//Free all dynamically allocated memories that are no longer required.
//Return the pointer of the floating point number to the caller.

//Create a result floating point number by setting appropriate sign value and by copying the 
//biased_127 result exponent and the significand from the above normalized result (don't copy 
//explicit '1' of the significand).
//Free all dynamically allocated memories that are no longer required.
//Return the result floating point number to the caller.


char* subtract_floating_point(const char* fp_number1, const char* fp_number2);
//Get a copy of the second floating point number by calling copy_floating_point() function.
//Flip the sign bit of the copy floating point number.
//Call add_floating_point() function with the first and the copy of the second floating point
//numbers.
//Free memory from the copy floating point number.
//Return the result of add_floating_point() fucntion.


char* multiply_floating_point(const char* fp_number1, const char* fp_number2);
//Return a zero floating point if any of the floating point number is zero. Call is_zero() and
//zero_floating_point() function for this purpose.
//Extract the exponents from both floating point nubers by calling extract_exponent() function.
//Get the integer values from both exponents by calling int_from_biased_127() function and add
//them to get the result exponent value.
//Check result exponent underflow by calling check_fp_exponent_underflow() function.
//Check result exponent overlow by calling check_fp_exponent_overflow() function.
//Extract the significands from both floating point numbers by calling extract_significand() function.
//Create explicit significands of BINARY_WORD_SIZE from both significands and get explicit '1' inserted 
//by calling implicit_to_explicit() function.
//Multiply two explicit significands by calling multiply_twos_complement() function.
//Normalize the multiplication result as followings, if necessary.
	//Each explicit significand has eaxactly one explicit integer (1) bit and 
	//FLOATING_POINT_SIGNIFICAND_DIGITS number of fraction bits.
	//After multiplication, if we get 2*FLOATING_POINT_SIGNIFICAND_DIGITS number of fraction
	//bits and one explicit integer (1) bit the result is already normalized. 
	//If multiplication result has more than (2*FLOATING_POINT_SIGNIFICAND_DIGITS + 1) digits, 
	//shift the result right by calling logical_shift_right() function and increment the result 
	//exponent until the result becomes exactly (2*FLOATING_POINT_SIGNIFICAND_DIGITS + 1) digits. 
	//Check whether there is an exponent overflow or not after each increment by 
	//calling check_fp_exponent_overflow() function. 
	
//Get biased_127 representation of the result exponent value by calling int_to_biased_127()
//furnction.
//Allocate enough memory for a result floating point number.
//Set appropriate sign value to the floating point number.
//Copy the biased_127 result exponent into floating point number exponent.
//Copy the most siginificant FLOATING_POINT_SIGNIFICAND_DIGITS number of bits from the fraction component
//of the normalized multiplication result into floating point significand.
//Free all dynamically allocated memories that are no longer required.
//Return the pointer of the floating point number to the caller.


char* divide_floating_point(const char* fp_number1, const char* fp_number2);
//Return a zero floating point number if the first floating point number is zero. Call is_zero() and
//zero_floating_point() function for this purpose.
//Return an infinity floating point number if the second floating point number is zero. Call is_zero() and
//infinity_floating_point() function for this purpose.
//Extract the exponents from both floating point nubers by calling extract_exponent() function.
//Get the integer values from both exponents by calling int_from_biased_127() function and subtract
//them to get the result exponent value.
//Check result exponent underflow by calling check_fp_exponent_underflow() function.
//Check result exponent overlow by calling check_fp_exponent_overflow() function.
//Extract the significands from both floating point numbers by calling extract_significand() function.
//Create explicit significands of BINARY_WORD_SIZE from both significands and get explicit '1' bit inserted 
//by calling implicit_to_explicit() function.
//Divide the first explicit significand by the secong explicit significand in order to get a quotient 
//that contains both integer and fraction component by calling divide_twos_complement_significand() function.
//In BINARY_WORD_SIZE quotient, the first bit is integer '1' and the rest (BINARY_WORD_SIZE -1) bits
//are fraction.
//Get biased_127 representation of the result exponent value by calling int_to_biased_127()
//furnction.
//Allocate enough memory for a result floating point number.
//Set appropriate sign value to the floating point number.
//Copy the biased_127 result exponent into floating point number exponent.
//Copy the most siginificant FLOATING_POINT_SIGNIFICAND_DIGITS number of bits from the fraction component
//of the quotient into floating point significand.
//Free all dynamically allocated memories that are no longer required.
//Return the pointer of the floating point number to the caller.



char* add_real(const char* number1, const char* number2);
//Get floating point representation of both real numbers by calling to_floating_point() function.
//Add two floating point numbers by calling add_floating_point() function.
//Get the real result from the floating point result by calling from_floating_point() function.
//Free all dynamically allocated memories that are no longer required.
//Return the result real number to the caller.



char* subtract_real(const char* number1, const char* number2);
//Get floating point representation of both real numbers by calling to_floating_point() function.
//Subtract two floating point numbers by calling subtract_floating_point() function.
//Get the real result from the floating point result by calling from_floating_point() function.
//Free all dynamically allocated memories that are no longer required.
//Return the result real number to the caller.



char* multiply_real(const char* number1, const char* number2);
//Get floating point representation of both real numbers by calling to_floating_point() function.
//Multiply two floating point numbers by calling multiply_floating_point() function.
//Get the real result from the floating point result by calling from_floating_point() function.
//Free all dynamically allocated memories that are no longer required.
//Return the result real number to the caller.



char* divide_real(const char* number1, const char* number2);
//Get floating point representation of both real numbers by calling to_floating_point() function.
//Divide two floating point numbers by calling divide_floating_point() function.
//Get the real result from the floating point result by calling from_floating_point() function.
//Free all dynamically allocated memories that are no longer required.
//Return the result real number to the caller.



#endif
