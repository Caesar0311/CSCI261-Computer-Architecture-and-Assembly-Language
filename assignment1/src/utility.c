/**
 * @file utility.c
 * @author Name:Caesar, Student Number:578751737, Section:N04, CSCI 261, VIU
 * @version 1.0.0
 * @date 24th Jan, 2022
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

//Parameter 'str' is a NULL terminted string.
//Reverse all the characters, except NULL, in the string 'str'
void reverse(char* str) {
    int length = strlen(str);
    for(int i = 0; i < length/2+1; i++) {
        char tmp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = tmp;
    }
}

//Pointer 'number' is pointing a NULL terminated string, which has enough memory to add 
//two more characters.
//Move all the characters of the string 2 positions right.
//Insert 'p0' at the first index of the string.
//Insert 'p1' at the second index of the string.
void add_prefix(char* number, char p0, char p1) {
    int length = strlen(number);
    for(int i = length+2; i >= 2; i++) {
        number[i] = number[i-2];
    }
    number[0] = p0;
    number[1] = p1;
}

 
//If the length of the 'number' is greater than 'word_size' report error.
//If the length of the 'number' is less than 'word_size' do the followings:
//	Allocate enough memory for a new word.
//	Fill the most significant extra digits of the word with zeros and copy
//	the least significant digits from the number.
//	Free the memory from the pointer 'number'.
//	Point the new word by the pointer 'number'.
char* extend_to_word_size(char* number, int word_size) {
    int length = strlen(number);
    if(length > word_size+3) {
        return NULL;
    } else if(length < word_size){
        char *new_word = (char *) malloc(sizeof(char)*(word_size+3));
        new_word[word_size+3] = '\0';
        int i=length-1,j=word_size+1;
        for(; i>=0&&j>=0;i--,j--) {
            new_word[j] = number[i];
        }
        while(j >= 0) {
            new_word[j--] = '0';
        }
        free(number);
        number = new_word;
        return number;
    } else {
        return number;
    } 
}
 
//Return TRUE if all the digits of the number are either zero or one.
int are_binary_digits(char* number) {
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        if(number[i] != '0' && number[i] != '1') {
            return FALSE;
        }
    }
    return TRUE;
}


//Return TRUE if all the digits of the number are one of the hex digits.
int are_hex_digits(char* number) {
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        if((number[i] >= '0' && number[i] <= '9') || (number[i] >= 'A' && number[i] <= 'F')) {
            continue;
        } else {
            return FALSE;
        }
    }
    return TRUE; 
}

//Return TRUE if all the digits of the number are one of the decimal digits.
int are_decimal_digits(char* number) {
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if(number[i] >= '0' && number[i] <= '9') {
            continue;
        } else {
            return FALSE;
        }
    }
    return TRUE; 
}


//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a binary number, starts with the prefix '0b', and all the digits are binary digits.
int is_binary(char* number) {
    int length = strlen(number);
    if (length <= 2) return FALSE;
    if (!(number[0] == '0' && number[1] == 'b')) return FALSE;
    return are_binary_digits(number+2);
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a hex number, starts with the prefix '0x', and all the digits are hex digits.
int is_hex(char* number) {
    int length = strlen(number);
    if (length <= 2) return FALSE;
    if (!(number[0] == '0' && number[1] == 'x')) return FALSE;
    return are_hex_digits((number+2));
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a decimal number, starts with no prefix, and all the digits are decimal digits.
int is_decimal(char* number) {
    return are_decimal_digits(number);
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of a real number, all the digits are decimal digits, and its value 
//is within the limit.
int is_real_part(char* number) {
    return are_decimal_digits(number);
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of a fixed point number, and all the digits are binary digits.
int is_fixed_point_part(char* number) {
    return are_binary_digits(number);
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a real number, and the digits are either a decimal digit or a decimal point ('.') 
int is_real(char* number) {
    int decimal_point_count = 0;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if(number[i] == '.') { decimal_point_count++;}
        else if(!(number[i] >= '0' && number[i] <= '9')) return FALSE;
        if(decimal_point_count >= 2) return FALSE;
    }
    return TRUE;
}

//Return TRUE if the number of digits in parameter 'number' is within the limit
//of a part of fixed point number, and all the digits are binary digits.
int is_fixed_point(char* number) {
    int length = strlen(number);
    if(length != 32) return FALSE;
    return are_binary_digits(number);
}

//Return a new string copying the integer part of the real number.
char* get_integer_part(char* number) {
    char *point_idx;
    int length = strlen(number);
    int real_size = 0;
    point_idx = strchr(number,'.');
    if(point_idx == NULL) real_size = length;
    else {
        real_size = (int)(point_idx - number);
    }
    if(real_size == 0) return NULL;

    char *real_part = (char *) malloc(sizeof(char)*(real_size+1));
    for(int i = 0; i < length; i++) {
        real_part[i] = number[i];
    }
    real_part[real_size] = '\0';
    return real_part;
}

//Return a new string copying the fraction part of the real number.
char* get_fraction_part(char* number) {
    char *point_idx;
    int length = strlen(number);
    int frac_size = 0;
    point_idx = strchr(number,'.');
    if(point_idx == NULL) return NULL;

    frac_size = length - (int)(point_idx - number) - 1;
    char *frac_part = (char *) malloc(sizeof(char)*(frac_size+1));
    for(int i = (int)(point_idx - number)+1,j=0; i < length; i++,j++) {
        frac_part[j] = number[i];
    }
    frac_part[frac_size] = '\0';
    return frac_part;
}
