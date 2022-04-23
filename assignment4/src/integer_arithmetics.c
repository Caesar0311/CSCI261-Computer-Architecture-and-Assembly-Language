/**
 * @file integer_arithmetics.c
 * @author Caesar, 578751737， CSCI 261, VIU
 * @version 1.0.0
 * @date  22, Mar, 2022
 *
 * Implement the functions specified in 'integer_arithmetics.h' header file.
 *
 */
 
/*
 * Include the standard library header files.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Include custom header files.
 */
#include "convert.h"
#include "integer_arithmetics.h"
#include "utility.h"

char* copy_twos_complement(const char* number, int word_size) {
    char* temp = calloc(strlen(number) + 1, sizeof(char));
    strcpy(temp, number);
    return temp;
}

char* add_twos_complement(const char* number1, const char* number2, int word_size) {
    //  printf("%s\n",number1);
    // printf("%s\n",number2);
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

char* subtract_twos_complement(const char* number1, const char* number2, int word_size) {
    char* temp_number2 = copy_twos_complement(number2, word_size);
    twos_complement(temp_number2);
    char* result = add_twos_complement(number1, temp_number2, word_size);
    free(temp_number2);
    return result;
}

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
char* multiply_twos_complement(const char* number1, const char* number2, int word_size) {
    char* aregister = calloc(strlen(number1) + 1, sizeof(char));
    memset(aregister, '0', strlen(number1));
    char* q_1 = calloc(2, sizeof(char));
    q_1[0] = '0';

    char* mregister = copy_twos_complement(number1, word_size);
    char* qregister = copy_twos_complement(number2, word_size);
    int counter = word_size;
    while (TRUE) {
        if (qregister[strlen(number1) - 1] == '1' && q_1[0] == '0') {
            char* mregistertemp = subtract_twos_complement(aregister, mregister, word_size);
            free(aregister);
            aregister = mregistertemp;
        } else if (qregister[strlen(number1) - 1] == '0' && q_1[0] == '1') {
            char* mregistertemp = add_twos_complement(aregister, mregister, word_size);
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

char* divide_twos_complement_significand(const char* number1, const char* number2, int word_size) {
    char* aregister = calloc(strlen(number1) + 1, sizeof(char));
    memset(aregister, '0', strlen(number1));

    char* qregister = copy_twos_complement(number1, word_size);
    char* mregister = copy_twos_complement(number2, word_size);

    if (qregister[0] == '1')
        twos_complement(qregister);

    if (mregister[0] == '1')
        twos_complement(mregister);

    int counter = 2 * word_size - 1;
    while (TRUE) {
        group_logical_shift_left(aregister, qregister, 1);

        char* mregistertemp = subtract_twos_complement(aregister, mregister, word_size);
        free(aregister);
        aregister = mregistertemp;

        if (aregister[0] == '1') {
            qregister[strlen(qregister) - 1] = '0';
            char* mregistertemp = add_twos_complement(aregister, mregister, word_size);
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
   // memcpy(reminder, aregister, strlen(number1));
    free(aregister);

    if (number1[0] == '1' && number2[0] == '0') {
        twos_complement(qregister);
        //twos_complement(reminder);
    } else if (number1[0] == '1' && number2[0] == '1') {
       // twos_complement(reminder);
    } else if (number1[0] == '0' && number2[0] == '1') {
        twos_complement(qregister);
    }

    return qregister;
}
