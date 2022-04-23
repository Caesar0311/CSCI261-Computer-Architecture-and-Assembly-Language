/**
 * @file integer_arithmetics.h
 * @author Humayun Kabir, Instructor, CSCI 261, VIU
 * @version 1.0.0
 * @date August 04, 2021
 *
 * Defines the functions to perform integer arithmetic (add, subract, multiply, and divide)
 * on twos complement represented integer numbers.
 */


#ifndef __INTEGER_ARITHMETICS_HEADER__
#define __INTEGER_ARITHMETICS_HEADER__


char* copy_twos_complement(const char* number, int word_size);
//Allocate enough memory to a string to hold a twos complement number.
//Copy the twos complement number into the new string and return it to
//the caller.


char* add_twos_complement(const char* number1, const char* number2, int word_size);
//Allocate enough memory to a string to hold a resultant twos complement number.
//Add all the bits (from right to left) of two twos complement numbers by calling one_bit_add() 
//function with appropriate carry-in value in each call.
//Pass the carry-out value resulted from a previous call of one_bit_add() function as the
//carry-in parameter into the next call of one_bit_add() function. 
//Assign the result returned by one_bit_add() function to the corresponding bit of the new string.
//After adding all the bits return the result string to the caller.



char* subtract_twos_complement(const char* number1, const char* number2, int word_size);
//Copy the second number into a new number by calling copy_twos_complement() function.
//Get the negated or twos complement of the copy by calling twos_complement() function.
//Add the first number with the twos-complement of the copy to get the subtraction result.
//Free memory from the copy.
//Return the result to the caller.


char* multiply_twos_complement(const char* number1, const char* number2, int word_size);
//Allocate enough memory to a 'aregister' to hold the bits of a twos complement number.
//Initialize 'aregister' bits to zero character and NULL terminate.
//Allocate enough memory to hold a bit in 'q_1' and initialize it to zero.
//Copy multiplicand (number1) into a 'mregister' by calling copy_twos_complement() function.
//Copy multiplier (number2) into a 'qregister' by calling copy_twos_complement() function.
//Initialize 'count' to 'word_size'.
//Perform the steps of Booth's Multiplication Algorithm using 'aregister', 'mregister, 'qregister' and 'q_1'
//Call group_arithmetic_shift_rigth() function when you need to perform a group arithmetic right 
//shift on 'aregister', 'qregister', and 'q_1' in the algorithm step.
//Most significant word of the multiplication result will be available in 'aregister'.
//Least significand word of the multiplication result will be available in 'qregister'.
//Concatenate these two result words ('aregister' and 'qregister') into a single word.
//Remember the size of the concatenated word will be the double of that of these registers.
//Free all dynamically allocated memories that are no longer required.
//Return the pointer of the concatenated word to the caller.
  

char* divide_twos_complement_significand(const char* number1, const char* number2, int word_size);
//Allocate enough memory to a 'aregister' to hold the bits of a twos complement number.
//Initialize 'aregister' bits to zero character and NULL terminate.
//Copy dividend (number1) into a 'qregister' by calling copy_twos_complement() function.
//If the dividend sign is negative, negate 'qregister' content by calling twos_complement() function.
//Copy divisor (number2) into a 'mregister' by calling copy_twos_complement() function.
//If the divisor sign is negative, negate 'mregister' content by calling twos_complement() function.
//Inititialize 'count' to (2*'word_size' -1) in order to get the fraction in the quotient instead of a 
//reminder (unlike an integer division). Here, the 'dividend' is assumed as the product of two 
//twos-complement numbers of 'word_size' number of binary digits, i.e., the projectd number of binary 
//digits in the product (dividend) are (2*word_size -1).
//Perform the steps of unsigned division algorithm using 'aregister', 'mregister', and 'qregister' and
//Call group_logical_shift_left() function when you need to perform a group logical left shift
//of 'aregister' and 'qregister' as the part of the algorithm step.
//Quotient with the fraction of division operation will be available in 'qregister'.
//Perform a twos complement on it by calling twos_complement() function if necessary.
//Reminder of division operation will be available in 'aregister', you can ignore this reminder.
//Free all dynamically allocated memories that are no longer required.
//Return the pointer of the quotient to the caller.
 
#endif
