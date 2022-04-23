/**
 * @file utility.c
 * @author Name:Caesar, Student Number:578751737, Section:N04, CSCI 261, VIU
 * @version 1.0.0
 * @date 6th Feb, 2022
 *
 *
 */


#include "utility.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Parameter 'str' is a NULL terminted string.
//Reverse all the non-NULL characters of the string 'str'
void reverse(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; ++i) {
        char c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
    }
}

//Pointer 'number' is pointing a NULL terminated string, which has enough 
//memory to add one more character.
//Move all the characters of the string 1 position right.
//Insert 'sign' at the first index of the string.
void add_sign(char* number, char sign) {
    int len = strlen(number);
    int i;
    for (i = len; i >= 1; i--) {
        number[i] = number[i-1];
    }
    number[0] = sign;
}

//Allocate enough memory for an extended number.
//Fill the most significant (left most) extra digits of the extended number with zeros and copy
//the least significant (right most) digits from the number.
//Return the pointer of the extended number.
char* extend_integer_binary_to_word_size(char* number, int word_size) {
    int len = strlen(number);
    if (len >= word_size) {
        return strdup(number);
    }

    char *extend = malloc((word_size + 1) * sizeof(char));
    int i;
    int n_extend = word_size - len;
    for (i = 0; i < n_extend; ++i) {
        extend[i] = '0';
    }
    for (i = 0; i < len; ++i) {
        extend[n_extend + i] = number[i];
    }
    extend[word_size] = '\0';
    return extend;
}

//Allocate enough memory for an extended number.
//Copy the most significant (left most) digits of the extended number from the number.
//Fill the least significant (right most) extra digits of the extended number with zeros.
//Return the pointer of the extended number.
char* extend_fraction_binary_to_word_size(char* number, int word_size) {
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

//Return TRUE if all the digits of the number are either zero or one.
int are_binary_digits(char* number) {
    int len = strlen(number);
    int i = 0;
    for (i = 0; i < len; ++i) {
        if (!(number[i] >= '0' && number[i] <= '1')) {
            return FALSE;
        }
    }
    return TRUE;
}

//Return TRUE if all the digits of the number are one of the decimal digits.
int are_decimal_digits(char* number) {
    int len = strlen(number);
    int i = 0;
    if (number[0] == '+' || number[0] == '-') {
        i = 1;
        if (len == 1) {
            return FALSE;
        }
    }
    while (i < len) {
        if (!(number[i] >= '0' && number[i] <= '9')) {
            return FALSE;
        }
        i += 1;
    }
    return TRUE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a binary number and all the digits are binary digits.
int is_binary(char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == BINARY_WORD_SIZE) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number and all the digits are decimal digits.
int is_decimal(char* number) {
    if (are_decimal_digits(number) == TRUE &&
        strlen(number) <= DECIMAL_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a biased_127 decimal number and all the digits are decimal digits.
int is_biased_127_decimal(char* number) {
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
int is_biased_127_binary(char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == BIASED_127_BINARY_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a floating-point significand and all the digits are binary digits.
int is_significand(char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == FLOATING_POINT_SIGNIFICAND_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 
int is_real(char* number) {
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
int is_floating_point(char* number) {
    if (are_binary_digits(number) == TRUE &&
        strlen(number) == FLOATING_POINT_MAX_DIGITS) {
        return TRUE;
    }
    return FALSE;
}

//Return a new string copying the integer part of the real number.
char* get_integer_part(char* number) {
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
char* get_fraction_part(char* number) {
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