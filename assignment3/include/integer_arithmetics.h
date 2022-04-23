/**
 * @file integer_arithmetics.h
 * @author Humayun Kabir, Instructor, CSCI 360, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines the functions to perform integer arithmetic (add, subract, multiply, and divide)
 * on twos complement represented integer numbers.
 */


#ifndef __INTEGER_ARITHMETICS_HEADER__
#define __INTEGER_ARITHMETICS_HEADER__


char* copy_twos_complement(const char* number);
//Allocate enough memory to a string to hold a twos complement number.
//Copy the twos complement number into the new string and return it to
//the caller.


char* add_twos_complement(const char* number1, const char* number2);
//Allocate enough memory to a string to hold a resultant twos complement number.
//Add all the bits (from right to left) of two twos complement numbers by calling one_bit_add() 
//function with appropriate carry-in value in each call.
//Save the carry of one_bit_add() function to pass it to the next call. 
//Assign the return value of one_bit_add() function to the corresponding bit of the new string.
//After adding all the bits return the result string to the caller.



char* subtract_twos_complement(const char* number1, const char* number2);
//Copy the second number into another number by calling copy_twos_complement() function.
//Get the negated or twos complement of the copy by calling twos_complement() function.
//Add the first number with the twos complement of the copied number to get the subtraction result.
//Free memory from the copy.
//Return the result to the caller.


char* multiply_twos_complement(const char* number1, const char* number2);
//Allocate enough memory to a 'aregister' to hold the bits of a twos complement number.
//Initialize 'aregister' bits to zeros.
//Allocate enough memory to hold a bit in 'q_1' and initialize it to zero.
//Copy multiplicand (number1) into a 'mregister' by calling copy_twos_complement() function.
//Copy multiplier (number2) into a 'qregister' by calling copy_twos_complement() function.
//Perform the steps of Booth's Multiplication Algorithm using 'aregister', 'mregister, 'qregister' and 'q_1'.
//Call group_arithmetic_shift_rigth() function when you need to perform a group arithmetic right 
//shift on 'aregister', 'qregister', and 'q_1' in the algorithm step.
//Most significant word of the multiplication result will be available in 'aregister'.
//Least significand word of the multiplication result will be available in 'qregister'.
//Concatenate these two result words into a single result of double word size.
//Free all dynamically allocated memories that are no longer required.
//Return the double word result to the caller.
  

char* divide_twos_complement(const char* number1, const char* number2, char* reminder);
//Allocate enough memory to a 'aregister' to hold the bits of a twos complement number.
//Initialize 'aregister' bits to zeros.
//Copy dividend (number1) into a 'qregister' by calling copy_twos_complement() function.
//If the dividend sign is negative negate its copy by calling twos_complement() function.
//Copy divisor (number2) into a 'mregister' by calling copy_twos_complement() function.
//If the divisor sign is negative negate its copy by calling twos_complement() function.
//Perform the steps of unsigned division algorithm using 'aregister', 'mregister', and 'qregister'.
//Call group_logical_shift_left() function when you need to perform a group logical left shift
//of 'aregister' and 'qregister' as the part of the algorithm step.
//Quotient of division operation will be available in 'qregister' perform a twos complement on it 
//by calling twos_complement() function if necessary.
//Reminder of division operation will be available in 'aregister' perform a twos complement on it
//by calling twos_complement() function if necessary.
//Copy 'aregister' into 'reminder'.
//Free all dynamically allocated memories that are no longer required.
//Return the quotient to the caller.
 

char* add_integer(const char* number1, const char* number2);
//Get the twos complemt of the integer numbers by calling to_twos_complement() function.
//Add the twos complement numbers by calling add_twos_complemt() function.
//Convert the twos complement result into an integer number by calling from_twos_complement()
//function.
//Free all dynamically allocated memories that are no longer required.
//Return the integer result to the caller.


char* subtract_integer(const char* number1, const char* number2);
//Get the twos complemt of the integer numbers by calling to_twos_complement() function.
//Subtract the twos complement numbers by calling subtract_twos_complemt() function.
//Convert the twos complement result into an integer number by calling from_twos_complement()
//function.
//Free all dynamically allocated memories that are no longer required.
//Return the integer result to the caller.


char* multiply_integer(const char* number1, const char* number2);
//Get the twos complemt of the integer numbers by calling to_twos_complement() function.
//Multiply the twos complement numbers by calling multiply_twos_complemt() function.
//Convert the twos complement result into an integer number by calling from_twos_complement()
//function.
//Free all dynamically allocated memories that are no longer required.
//Return the integer result to the caller.


char* divide_integer(const char* number1, const char* number2, char* reminder);
//Get the twos complemt of the integer numbers by calling to_twos_complement() function.
//Allocate enough memory to a new string to hold a twos complement reminder.
//Divide the twos complement numbers by calling divide_twos_complemt() function.
//Convert the twos complement quotient into an integer number by calling from_twos_complement()
//function.
//Convert the twos complement reminder into an integer number by calling from_twos_complement()
//function.
//Copy the integer reminder into 'reminder'.
//Free all dynamically allocated memories that are no longer required.
//Return the integer quotient to the caller.


#endif
