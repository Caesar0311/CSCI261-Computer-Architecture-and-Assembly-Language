/**
 * @file utility.c
 * @author Caesar, 578751737,N04 CSCI 261, VIU
 * @version 1.0.0
 * @date Mar 8th, 2022 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

//Reverse all the non-NULL characters 
void reverse(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; ++i) {
        char c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
    }
}

//add the sign
void add_sign(char* number, char sign) {
    int len = strlen(number);
    int i;
    for (i = len; i >= 1; i--) {
        number[i] = number[i-1];
    }
    number[0] = sign;
}


char* extend_integer_binary_to_word_size(const char* number, int word_size){
    char* temp = malloc((word_size + 1) * sizeof(char));
    int len = strlen(number);
    memset(temp, '0', word_size + 1);
    memcpy(temp + word_size - len, number, len);
    temp[word_size] = '\0';
    return temp;
}

// Count and return the number of consecutive ones at the beginning of the binary number.
int count_leading_ones(const char* number){
    int counter = 0;
    for (size_t i = 0; i < strlen(number); i++) {
        if (number[i] == '1')
            counter++;
        else
            break;
    }
    return counter;
}



void group_arithmetic_shift_right(char* aregister, char* qregister, char* q_1, int word_size){
    int temp = aregister[0];
    *q_1 = qregister[strlen(qregister) - 1];

    memcpy(qregister + word_size, qregister, strlen(qregister) - word_size);
    memcpy(qregister, aregister + strlen(aregister) - word_size, word_size);
    memcpy(aregister + word_size, aregister, strlen(aregister) - word_size);
    memset(aregister + word_size, temp, word_size);
}


void group_logical_shift_left(char* aregister, char* qregister, int word_size){
    memcpy(aregister, aregister + word_size, strlen(aregister) - word_size);
    memcpy(aregister + strlen(aregister) - word_size, qregister, word_size);
    memcpy(qregister, qregister + word_size, strlen(aregister) - word_size);
    memset(qregister + strlen(aregister) - word_size, '0', word_size);
}


// Return TRUE if all the digits of the number are either zero or one.
int are_binary_digits(const char* number){
    for (size_t i = 0; i < strlen(number); i++) {
        if (number[i] > '1' || number[i] < '0')
            return FALSE;
    }
    return TRUE;
}

// Return TRUE if all the digits of the number are one of the decimal digits.
int are_decimal_digits(const char* number){
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

// Return TRUE if the number of digits in parameter 'number' is within the limit of a double word binary number and all the digits are binary digits.
int is_binary(const char* number){
    if (number == NULL || strlen(number) == 0 || strlen(number) > BINARY_WORD_SIZE * 2)
        return FALSE;

    return are_binary_digits(number);
}

// Return TRUE if the number of digits in parameter 'number' is within the limit of a decimal number and all the digits are decimal digits.
int is_decimal(const char* number){
    if (number == NULL || strlen(number) == 0 || strlen(number) > DECIMAL_MAX_DIGITS)
        return FALSE;
    return are_decimal_digits(number);
}
