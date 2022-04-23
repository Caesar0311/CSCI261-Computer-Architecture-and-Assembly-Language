/**
 * @file utility.c
 * @author Caesar, 578751737， CSCI 261, VIU
 * @version 1.0.0
 * @date  22, Mar, 2022
 *
 * Implement the functions specified in 'utility.h' header file. 
 *
*/
 
/*
 * Include library header files.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

void reverse(char* str)
// Parameter 'str' is a NULL terminted string.
// Reverse all non-NULL characters of the string 'str'
{
    if (str == NULL)
        return;
    int len = strlen(str);
    char* temp = str + len - 1;
    int tempchar = 0;
    while (str < temp) {
        tempchar = *temp;
        *temp = *str;
        *str = tempchar;
        temp--;
        str++;
    }
}

void add_sign(char* number, const char sign)
// Pointer 'number' is pointing a NULL terminated string, which has enough
// memory to add one more character.
// Move all the characters of the string 1 position right.
// Insert 'sign' at the first index of the string.
{
    if (number == NULL)
        return;
    memcpy(number + 1, number, strlen(number) + 1);
    number[0] = sign;
}

int count_leading_zeros(const char* number)
// Count and return the number of consecutive ones at the beginning of the binary number.
{
    int counter = 0;
    for (size_t i = 0; i < strlen(number); i++) {
        if (number[i] == '0')
            counter++;
        else
            break;
    }
    return counter;
}
int count_leading_ones(const char* number)
// Count and return the number of consecutive ones at the beginning of the binary number.
{
    int counter = 0;
    for (size_t i = 0; i < strlen(number); i++) {
        if (number[i] == '1')
            counter++;
        else
            break;
    }
    return counter;
}

char* extend_integer_binary_to_word_size(const char* number, int word_size)
// Allocate enough memory for an extended number.
// Fill the most significant (left most) extra digits of the extended number with zeros and copy
// the least significant (right most) digits from the number.
// Return the pointer of the extended number.
{
    char* temp = malloc((word_size + 1) * sizeof(char));
    int len = strlen(number);
    memset(temp, '0', word_size + 1);
    memcpy(temp + word_size - len, number, len);
    temp[word_size] = '\0';
    return temp;
}

//Allocate enough memory for an extended number.
//Copy the most significant (left most) digits of the extended number from the number.
//Fill the least significant (right most) extra digits of the extended number with zeros.
//Return the pointer of the extended number.
char* extend_fraction_binary_to_word_size(const char* number, int word_size) {
    int len = strlen(number);
    if (len >= word_size) {
        return strdup(number);
    }
    char *extend = malloc((word_size + 1) * sizeof(char));
    int i;
    for (i = 0; i < word_size; ++i) {
        extend[i] = '0';
    }
    for (i = 0; i < strlen(number); ++i) {
        extend[i] = number[i];
    }
    extend[word_size] = '\0';
    /* printf("\n%s %lu", number, strlen(number)); */
    /* printf("\n%s %d", extend, word_size); */
    return extend;
}



void group_arithmetic_shift_right(char* aregister, char* qregister, char* q_1, int word_size)
// Both 'aregister' and 'qregister' have 'word_size' number of binary digits and 'q_1' has only
// one binary digits.
// Assume they have been placed together from left to right.
// Perform arithmetic right shift of the bits of the group assuming the sign bit at 'aregister[0]'.
{
    int temp = aregister[0];
    *q_1 = qregister[strlen(qregister) - 1];

    memcpy(qregister + word_size, qregister, strlen(qregister) - word_size);
    memcpy(qregister, aregister + strlen(aregister) - word_size, word_size);
    memcpy(aregister + word_size, aregister, strlen(aregister) - word_size);
    memset(aregister + word_size, temp, word_size);
}

void group_logical_shift_left(char* aregister, char* qregister, int word_size)
// Both 'aregister' and 'qregister' have 'word_size' number of binary digits.
// Assume they have been placed together from left to right.
// Perform logical left shift of the bits of the group.
{
    memcpy(aregister, aregister + word_size, strlen(aregister) - word_size);
    memcpy(aregister + strlen(aregister) - word_size, qregister, word_size);
    memcpy(qregister, qregister + word_size, strlen(aregister) - word_size);
    memset(qregister + strlen(aregister) - word_size, '0', word_size);
}
					 
void logical_shift_right(char* aregister) 
//Perform 1-bit logical right shift on 'aregister' bits.
{
    memcpy(aregister+1, aregister, strlen(aregister) - 1);
    memset(aregister, '0', 1);
}
					 
void logical_shift_left(char* aregister)
//Perform 1-bit logical left shift on 'aregister' bits.
{
    memcpy(aregister, aregister+1, strlen(aregister) - 1);
    memset(aregister+strlen(aregister) - 1, '0', 1);
}

int are_binary_digits(const char* number)
// Return TRUE if all the digits of the number are either zero or one.
{
    for (size_t i = 0; i < strlen(number); i++) {
        if (number[i] > '1' || number[i] < '0')
            return FALSE;
    }
    return TRUE;
}

int are_decimal_digits(const char* number)
// Return TRUE if all the digits of the number are one of the decimal digits.
{
    if (number == NULL || strlen(number) == 0)
        return FALSE;
    size_t i = 0;
    if (number[0] == '+' || number[0] == '-') {
        i++;
        if (strlen(number) == 1)
            return FALSE;
    }
    for (; i < strlen(number); i++) {
        if (number[i] > '9' || number[i] < '0')
            return FALSE;
    }
    return TRUE;
}

int is_binary(const char* number)
// Return TRUE if the number of digits in parameter 'number' is within the limit
// of a double word binary number and all the digits are binary digits.
{
    if (number == NULL || strlen(number) == 0 || strlen(number) > BINARY_WORD_SIZE * 2)
        return FALSE;

    return are_binary_digits(number);
}

int is_decimal(const char* number)
// Return TRUE if the number of digits in parameter 'number' is within the limit
// of a decimal number and all the digits are decimal digits.
{
    if (number == NULL || strlen(number) == 0 || strlen(number) > DECIMAL_MAX_DIGITS)
        return FALSE;
    return are_decimal_digits(number);
}


//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased_127 decimal number and all the digits are decimal digits.
int is_biased_127_decimal(const char* number) {
    int len = strlen(number);
    if (number[0] == '+' || number[0] == '-') {
        len -= 1;
    }
    if (are_decimal_digits(number) == TRUE &&
        len <= BIASED_127_DECIMAL_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased binary number and all the digits are binary digits.
int is_biased_127_binary(const char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == BIASED_127_BINARY_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating-point significand and all the digits are binary digits.
int is_significand(const char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == FLOATING_POINT_SIGNIFICAND_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 
int is_real(const char* number) {
    int len = strlen(number);
    int i = 0;
    if (number[0] == '+' || number[0] == '-') {
        len -= 1;
        i = 1;
    }
    int count_dot = 0;
    int index_dot = -1;
    for (; i < len; ++i) {
        if (number[i] == '.') {
            index_dot = i;
            count_dot += 1;
        } else if (!(number[i] >= '0' && number[i] <= '9')) {
            return FALSE;
        }
    }
    if (count_dot != 1) {
        return FALSE;
    }
    if (index_dot > REAL_PART_MAX_DIGITS || (len - 1) > REAL_MAX_DIGITS) {
        return FALSE;
    }
    return TRUE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating point number, and all the digits are binary digits.
int is_floating_point(const char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == FLOATING_POINT_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return a new string copying the integer part of the real number.
char* get_integer_part(const char* number) {
    int len = strlen(number);
    int i;
    for (i = 0; i < len; ++i) {
        if (number[i] == '.') {
            break;
        }
    }
    char *int_part = malloc((i + 1) * sizeof(char));
    strncpy(int_part, number, i);
    int_part[i] = '\0';
    return int_part;
}

//Return a new string copying the fraction part of the real number.
char* get_fraction_part(const char* number) {
    int len = strlen(number);
    int i;
    for (i = 0; i < len; ++i) {
        if (number[i] == '.') {
            break;
        }
    }
    char *fraction_part = malloc((len - i) * sizeof(char));
    strncpy(fraction_part, number + i + 1, len - i - 1);
    fraction_part[len - i - 1] = '\0';
    return fraction_part;
}