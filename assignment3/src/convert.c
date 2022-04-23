/**
 * @file convert.c
 * @author Caesar, 578751737,N04 CSCI 261, VIU
 * @version 1.0.0
 * @date Mar 8th, 2022 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "utility.h"

//integer convert binary number
char* integer_to_binary(int int_num, int binary_size)
{
    char* binary = calloc((binary_size + 1), sizeof(char));
    int i = 0;
    do {
        if (int_num % 2 == 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        int_num /= 2;
        i++;
    } while (int_num > 0 && i < binary_size);
    binary[i] = '\0';
    reverse(binary);
    return binary;

}



char* get_magnitude_binary(const char* signed_number, int binary_size){
    size_t i = 0;
    if (signed_number[0] == '+' || signed_number[0] == '-')
        signed_number++;
    int num = 0;
    for (; i < strlen(signed_number); i++)
        num = num * 10 + signed_number[i] - '0';
    return integer_to_binary(num, binary_size);
}


// binary number conversion integer
int binary_to_int(const char* number){
    int int_num = 0;
    int len = strlen(number);
    int i = 0;
    while (i < len) {
        int_num = int_num * 2 + number[i] - '0';
        i++;
    }
    return int_num;
}


// single digit addition
char one_bit_add(const char op1, const char op2, const char cin, char* cout){
    int op1_v = op1 - '0';
    int op2_v = op2 - '0';
    int cin_v = cin - '0';
    int s = op1_v + op2_v + cin_v;
    char ret = '0';
    *cout = '0';
    if (s == 1) {
        ret = '1';
    } else if (s == 2) {
        *cout = '1';
    } else if (s == 3) {
        ret = '1';
        *cout = '1';
    }
    return ret;
}


void ones_complement(char* number){
    for (size_t i = 0; i < strlen(number); i++) {
        char temp = number[i];
        if (temp == '0')
            number[i] = '1';
        else
            number[i] = '0';
    }
}



void twos_complement(char* number){
    ones_complement(number);
    int i = 0;
    int len = strlen(number);
    char op2 = '1', cin = '0';
    for (i = len - 1; i >= 0; --i) {
        number[i] = one_bit_add(number[i], op2, cin, &cin);
        op2 = '0';
    }
}



char* to_twos_complement(const char* number){
    if (is_decimal(number) == TRUE) {
        char* magnitude = get_magnitude_binary(number, BINARY_WORD_SIZE - 1);
        char* sign_mag = extend_integer_binary_to_word_size(magnitude, BINARY_WORD_SIZE);
        if (number[0] == '-') {
            twos_complement(sign_mag);
        }
        free(magnitude);
        return sign_mag;
    }
    return NULL;
}



char* from_twos_complement(const char* number){
    if (is_binary(number)) {
        char* sign_mag = calloc(strlen(number) + 1, sizeof(char));
        strcpy(sign_mag, number);

        if (sign_mag[0] == '1') {
            twos_complement(sign_mag);
        }
        int int_num = binary_to_int(sign_mag);
        free(sign_mag);
        char* mag = calloc((DECIMAL_MAX_DIGITS + 2), sizeof(char));
        int i = 0;
        do {
            mag[i++] = int_num % 10 + '0';
            int_num /= 10;
        } while (int_num > 0);
        mag[i] = '\0';
        reverse(mag);

        if (number[0] == '1') {
            add_sign(mag, '-');
        }
        return mag;
    }
    return NULL;
}
