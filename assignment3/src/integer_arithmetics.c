/**
 * @file integer_arithmetics.c
 * @author Caesar, 578751737,N04 CSCI 261, VIU
 * @version 1.0.0
 * @date Mar 8th, 2022 *
 *
 *
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "integer_arithmetics.h"
#include "utility.h"


// Copy 2's complement, and return
char* copy_twos_complement(const char* number){
    char* temp = calloc(strlen(number) + 1, sizeof(char));
    strcpy(temp, number);
    return temp;
}

// implement addition
char* add_twos_complement(const char* number1, const char* number2){
    char* temp = malloc((strlen(number1) + 1) * sizeof(char));
    memset(temp, 0, (strlen(number1) + 1) * sizeof(char));
    int index = strlen(number1) - 1;
    char op1 = '0';
    char op2 = '0';
    char cin = '0';
    char cout = '0';
    while (index >= 0) {
        op1 = number1[index];
        op2 = number2[index];
        char resulst = one_bit_add(op1, op2, cin, &cout);
        cin = cout;

        temp[index] = resulst;
        index--;
    }
    temp[strlen(number1)] = '\0';
    return temp;
}


// Subtract by addition and 2's complement
char* subtract_twos_complement(const char* number1, const char* number2){
    char* temp_number2 = copy_twos_complement(number2);
    twos_complement(temp_number2);
    char* result = add_twos_complement(number1, temp_number2);
    free(temp_number2);
    return result;
}


// Implementing the Broth Multiplication Algorithm
char* multiply_twos_complement(const char* number1, const char* number2){
    char* aregister = calloc(strlen(number1) + 1, sizeof(char));
    memset(aregister, '0', strlen(number1));
    char* q_1 = calloc(2, sizeof(char));
    q_1[0] = '0';

    char* mregister = copy_twos_complement(number1);
    char* qregister = copy_twos_complement(number2);
    int counter = strlen(number1);
    while (TRUE) {
        if (qregister[strlen(number1) - 1] == '1' && q_1[0] == '0') {
           char*  mregistertemp = subtract_twos_complement(aregister, mregister);
            free(aregister);
            aregister = mregistertemp;
        } else if (qregister[strlen(number1) - 1] == '0' && q_1[0] == '1') {
           char* mregistertemp = add_twos_complement(aregister, mregister);
            free(aregister);
            aregister = mregistertemp;
        }
        group_arithmetic_shift_right(aregister, qregister, q_1, 1);
        counter = counter - 1;
        if (counter == 0)
            break;
    }
    char* resulst = calloc(strlen(number1) * 2 + 1, sizeof(char));
    memcpy(resulst, aregister, strlen(number1));
    memcpy(resulst + strlen(number1), qregister, strlen(number1));
    free(aregister);
    free(qregister);
    free(mregister);
    free(q_1);
    return resulst;
}


// Binary division algorithm using registers and 2's complement
char* divide_twos_complement(const char* number1, const char* number2, char* reminder){
    char* aregister = calloc(strlen(number1) + 1, sizeof(char));
    memset(aregister, '0', strlen(number1));

    char* qregister = copy_twos_complement(number1);
    char* mregister = copy_twos_complement(number2);

    if (qregister[0] == '1')
        twos_complement(qregister);

    if (mregister[0] == '1')
        twos_complement(mregister);

    int counter = strlen(number1);
    while (TRUE) {
        group_logical_shift_left(aregister, qregister, 1);

        char* mregistertemp = subtract_twos_complement(aregister, mregister);
        free(aregister);
        aregister = mregistertemp;

        if (aregister[0] == '1') {
            qregister[strlen(qregister) - 1] = '0';
            char* mregistertemp = add_twos_complement(aregister, mregister);
            free(aregister);
            aregister = mregistertemp;
        } else {
            qregister[strlen(qregister) - 1] = '1';
        }
        counter = counter - 1;
        if (counter == 0)
            break;
    }
    free(mregister);
    memcpy(reminder, aregister, strlen(number1));
    free(aregister);

    if (number1[0] == '1' && number2[0] == '0') {
        twos_complement(qregister);
        twos_complement(reminder);
    } else if (number1[0] == '1' && number2[0] == '1') {
        twos_complement(reminder);
    } else if (number1[0] == '0' && number2[0] == '1') {
        twos_complement(qregister);
    }

    return qregister;
}



char* add_integer(const char* number1, const char* number2){
    char* number1_complement = to_twos_complement(number1);
    char* number2_complement = to_twos_complement(number2);

    char* complemt_result = add_twos_complement(number1_complement, number2_complement);
    char* result = from_twos_complement(complemt_result);
    free(complemt_result);
    free(number1_complement);
    free(number2_complement);
    return result;
}


char* subtract_integer(const char* number1, const char* number2){
    char* number1_complement = to_twos_complement(number1);
    char* number2_complement = to_twos_complement(number2);

    char* complemt_result = subtract_twos_complement(number1_complement, number2_complement);
    char* result = from_twos_complement(complemt_result);

    free(complemt_result);
    free(number1_complement);
    free(number2_complement);
    return result;
}



char* multiply_integer(const char* number1, const char* number2){
    char* number1_complement = to_twos_complement(number1);
    char* number2_complement = to_twos_complement(number2);

    char* complemt_result = multiply_twos_complement(number1_complement, number2_complement);
    char* result = from_twos_complement(complemt_result);

    free(complemt_result);
    free(number1_complement);
    free(number2_complement);

    return result;
}


char* divide_integer(const char* number1, const char* number2, char* reminder){
    char* number1_complement = to_twos_complement(number1);
    char* number2_complement = to_twos_complement(number2);

    char* complemt_result =
        divide_twos_complement(number1_complement, number2_complement, reminder);
    char* result = from_twos_complement(complemt_result);

    char* result_reminder = from_twos_complement(reminder);
    strcpy(reminder, result_reminder);
    free(result_reminder);
    free(complemt_result);
    free(number1_complement);
    free(number2_complement);
    return result;
}
