/**
 * @file floating_point_arithmetics.c
 * @author Caesar, 578751737， CSCI 261, VIU
 * @version 1.0.0
 * @date  22, Mar, 2022
 *
 *
 * Implement the functions specified in 'floating_point_arithmetics.h' header file.
 *
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "floating_point_arithmetics.h"
#include "integer_arithmetics.h"
#include "utility.h"

int is_zero(const char* number) {
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] == '0' || number[i] == '.' || number[i] == '+' || number[i] == '-')
            continue;
        else
            return FALSE;
    }
    return TRUE;
}

void check_fp_exponent_overflow(int exponent_value) {
    if (exponent_value > FLOATING_POINT_EXPONENT_MAX_VALUE) {
        printf("exponent_overflow\n");
        exit(-1);
    }
}

void check_fp_exponent_underflow(int exponent_value) {
    if (exponent_value < FLOATING_POINT_EXPONENT_MIN_VALUE) {
        printf("exponent_underflow\n");
        exit(-1);
    }
}

char* copy_floating_point(const char* fp_number) {
    char* temp = calloc(strlen(fp_number) + 1, sizeof(char));
    strcpy(temp, fp_number);
    return temp;
}

char* zero_floating_point() {
    char* temp = calloc(BINARY_WORD_SIZE + 1, sizeof(char));
    memset(temp, '0', BINARY_WORD_SIZE);
    return temp;
}

char* infinity_floating_point() {
    char* temp = calloc(BINARY_WORD_SIZE + 1, sizeof(char));
    strcpy(temp, "01111111100000000000000000000000");
    return temp;
}

// Create an explicit significand of BINARY_WORD_SIZE by copying FLOATING_POINT_SIGNIFICAND_DIGITS
// number of least significant bits from 'fp_significand' and setting explicit '1' to
// EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT position and return it.
char* implicit_to_explicit(const char* fp_significand) {
    char* temp = calloc(BINARY_WORD_SIZE + 1, sizeof(char));
    memcpy(temp + EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT_INDEX + 1, fp_significand,
           FLOATING_POINT_SIGNIFICAND_DIGITS);
    memset(temp, '0', EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT_INDEX + 1);
    temp[EXPLICIT_SIGNIFICAND_IMPLICIT_ONE_BIT_INDEX] = '1';
    return temp;
}

int get_exponent_difference(const char* fp_number1, const char* fp_number2) {
    char* exponent_binary_number1 = extract_exponent(fp_number1);
    int exponent_int_number1 = binary_to_int(exponent_binary_number1);

    char* exponent_binary_number2 = extract_exponent(fp_number2);
    int exponent_int_number2 = binary_to_int(exponent_binary_number2);

    int diff = exponent_int_number1 - exponent_int_number2;
    free(exponent_binary_number1);
    free(exponent_binary_number2);
    return diff;
}

void align_significand_to_right(char* significand, int shift_length) {
    for (int i = 0; i < shift_length; i++)
        logical_shift_right(significand);
}

char* add_floating_point(const char* fp_number1, const char* fp_number2) {
    // Phase 1 (Zero check):
    // Check whether 'fp_number1' is zero
    if (is_zero(fp_number1))
        return copy_floating_point(fp_number2);
    // Check whether 'fp_number2' is zero
    if (is_zero(fp_number2))
        return copy_floating_point(fp_number1);

    // Phase 2 (Significand alignment) :
    // Extract the significands
    char* extract_significand_number1 = extract_significand(fp_number1);
    char* extract_significand_number2 = extract_significand(fp_number2);

    // Create explicit significands
    char* explicit_number1 = implicit_to_explicit(extract_significand_number1);
    char* explicit_number2 = implicit_to_explicit(extract_significand_number2);

    // Get the exponent difference
    int exponent_diff = get_exponent_difference(fp_number1, fp_number2);
    char* extract_exponent_temp = NULL;
    if (exponent_diff > 0) {
        align_significand_to_right(explicit_number2, exponent_diff);
        if (is_zero(explicit_number2)) {
            free(extract_significand_number1);
            free(extract_significand_number2);
            free(explicit_number1);
            free(explicit_number2); 

            return copy_floating_point(fp_number1);
        }
        extract_exponent_temp = extract_exponent(fp_number1);
    } else if (exponent_diff < 0) {
        align_significand_to_right(explicit_number1, -exponent_diff);
        if (is_zero(explicit_number1)) {
            free(extract_significand_number1);
            free(extract_significand_number2);
            free(explicit_number1);
            free(explicit_number2); 

            return copy_floating_point(fp_number2);
        }

        extract_exponent_temp = extract_exponent(fp_number2);
    } else {
        extract_exponent_temp = extract_exponent(fp_number1);
    }

    int int_result_exponent = int_from_biased_127(extract_exponent_temp);

    // Phase 3 (Addition):
    char* temp_number1 = copy_twos_complement(explicit_number1, BINARY_WORD_SIZE);
    if (fp_number1[0] == '1')
        twos_complement(temp_number1);

    char* temp_number2 = copy_twos_complement(explicit_number2, BINARY_WORD_SIZE);
    if (fp_number2[0] == '1') {
        // free(temp_number2);
        twos_complement(temp_number2);
    }

    char* add_result = add_twos_complement(temp_number1, temp_number2, BINARY_WORD_SIZE);

    // printf("\n%s:", add_result);
    // Return a zero floating point if the result is zero.
    if (is_zero(add_result)) {
        free(extract_significand_number1);
        free(extract_significand_number2);
        free(explicit_number1);
        free(explicit_number2);
        free(extract_exponent_temp);
        free(temp_number1);
        free(temp_number2);
        free(add_result);
        return zero_floating_point();
    }
    char sign_value = add_result[0];
    if (sign_value == '1')
        twos_complement(add_result);

    // Phase 4 (Normalization):
    while (1) {
        int zero_counter = count_leading_zeros(add_result);
        int significand_start_index = zero_counter + 1;
        int significand_length = BINARY_WORD_SIZE - significand_start_index;
        int significand_length_diff = significand_length - (FLOATING_POINT_SIGNIFICAND_DIGITS);

        if (significand_length_diff == 0)
            break;
        if (significand_length_diff > 0) {
            int_result_exponent = int_result_exponent + 1;
            check_fp_exponent_underflow(int_result_exponent);
            check_fp_exponent_overflow(int_result_exponent);
            logical_shift_right(add_result);

        } else if (significand_length_diff < 0) {
            int_result_exponent = int_result_exponent - 1;
            check_fp_exponent_underflow(int_result_exponent);
            check_fp_exponent_overflow(int_result_exponent);
            logical_shift_left(add_result);
        }
    }

    // initial
    char* final_result = calloc(BINARY_WORD_SIZE + 1, 1);
    memset(final_result, '0', BINARY_WORD_SIZE);

    // sign
    // if ((fp_number1[0] == '0' && fp_number2[0] == '1') || (fp_number1[0] == '1' && fp_number2[0]
    // == '0'))
    memset(final_result, sign_value, 1);

    // exponent
    char* result_exponent = int_to_biased_127(int_result_exponent);
    memcpy(final_result + 1, result_exponent, FLOATING_POINT_EXPONENT_DIGITS);

    // significand
    memcpy(final_result + SIGNIFICAND_START_BIT_IN_FLOATING_POINT,
           add_result + SIGNIFICAND_START_BIT_IN_FLOATING_POINT, FLOATING_POINT_SIGNIFICAND_DIGITS);

    free(extract_significand_number1);
    free(extract_significand_number2);
    free(explicit_number1);
    free(explicit_number2);
    free(extract_exponent_temp);
    free(temp_number1);
    free(temp_number2);
    free(add_result);
    free(result_exponent);
    return final_result;
}

char* subtract_floating_point(const char* fp_number1, const char* fp_number2) {
    char* temp_number2 = copy_floating_point(fp_number2);
    temp_number2[0] = temp_number2[0] == '1' ? '0' : '1';
    char* result = add_floating_point(fp_number1, temp_number2);
    free(temp_number2);
    return result;
}

char* multiply_floating_point(const char* fp_number1, const char* fp_number2) {
    if (is_zero(fp_number1) || is_zero(fp_number2))
        return copy_floating_point(fp_number2);

    char* exponent_1 = extract_exponent(fp_number1);
    char* exponent_2 = extract_exponent(fp_number2);
    int int_exponent_1 = int_from_biased_127(exponent_1);
    int int_exponent_2 = int_from_biased_127(exponent_2);
    int add_exponent = int_exponent_1 + int_exponent_2;
    check_fp_exponent_underflow(add_exponent);
    check_fp_exponent_overflow(add_exponent);

    char* extract_significand_number1 = extract_significand(fp_number1);
    char* extract_significand_number2 = extract_significand(fp_number2);

    char* explicit_number1 = implicit_to_explicit(extract_significand_number1);
    char* explicit_number2 = implicit_to_explicit(extract_significand_number2);

    char* multiply_result =
        multiply_twos_complement(explicit_number1, explicit_number2, BINARY_WORD_SIZE);

    int zero_counter = count_leading_zeros(multiply_result);
    int significand_start_index = zero_counter + 1;
    int significand_length = BINARY_WORD_SIZE * 2 - significand_start_index;
    int significand_length_diff = significand_length - 2 * FLOATING_POINT_SIGNIFICAND_DIGITS;
    if (significand_length_diff > 0) {
        add_exponent = add_exponent + significand_length_diff;
        // logical_shift_right()
        check_fp_exponent_underflow(add_exponent);
        check_fp_exponent_overflow(add_exponent);
    }
    // initial
    char* final_result = calloc(BINARY_WORD_SIZE + 1, 1);
    memset(final_result, '0', BINARY_WORD_SIZE);

    // sign
    if ((fp_number1[0] == '0' && fp_number2[0] == '1') ||
        (fp_number1[0] == '1' && fp_number2[0] == '0'))
        memset(final_result, '1', 1);

    // exponent
    char* result_exponent = int_to_biased_127(add_exponent);
    memcpy(final_result + 1, result_exponent, FLOATING_POINT_EXPONENT_DIGITS);

    // significand
    memcpy(final_result + SIGNIFICAND_START_BIT_IN_FLOATING_POINT,
           multiply_result + significand_start_index, FLOATING_POINT_SIGNIFICAND_DIGITS);

    free(exponent_1);
    free(exponent_2);
    free(extract_significand_number1);
    free(extract_significand_number2);
    free(explicit_number1);
    free(explicit_number2);
    free(multiply_result);
    free(result_exponent);

    return final_result;
}

char* divide_floating_point(const char* fp_number1, const char* fp_number2) {
    if (is_zero(fp_number1))
        return zero_floating_point();

    if (is_zero(fp_number2))
        return infinity_floating_point();

    char* exponent_1 = extract_exponent(fp_number1);
    char* exponent_2 = extract_exponent(fp_number2);
    int int_exponent_1 = int_from_biased_127(exponent_1);
    int int_exponent_2 = int_from_biased_127(exponent_2);
    int add_exponent = int_exponent_1 - int_exponent_2;
    check_fp_exponent_underflow(add_exponent);
    check_fp_exponent_overflow(add_exponent);

    char* extract_significand_number1 = extract_significand(fp_number1);
    char* extract_significand_number2 = extract_significand(fp_number2);

    char* explicit_number1 = implicit_to_explicit(extract_significand_number1);
    char* explicit_number2 = implicit_to_explicit(extract_significand_number2);

    char* quotient_result =
        divide_twos_complement_significand(explicit_number1, explicit_number2, BINARY_WORD_SIZE);

    // initial
    char* final_result = calloc(BINARY_WORD_SIZE + 1, 1);
    memset(final_result, '0', BINARY_WORD_SIZE);

    // sign
    if ((fp_number1[0] == '0' && fp_number2[0] == '1') ||
        (fp_number1[0] == '1' && fp_number2[0] == '0'))
        memset(final_result, '1', 1);

    // exponent
    char* result_exponent = int_to_biased_127(add_exponent);
    memcpy(final_result + 1, result_exponent, FLOATING_POINT_EXPONENT_DIGITS);

    // significand
    memcpy(final_result + SIGNIFICAND_START_BIT_IN_FLOATING_POINT, quotient_result + 1,
           FLOATING_POINT_SIGNIFICAND_DIGITS);

    free(exponent_1);
    free(exponent_2);
    free(extract_significand_number1);
    free(extract_significand_number2);
    free(explicit_number1);
    free(explicit_number2);
    free(quotient_result);
    free(result_exponent);

    return final_result;
}

char* add_real(const char* number1, const char* number2) {
    char* fp_number1 = to_floating_point(number1);
    char* fp_number2 = to_floating_point(number2);

    char* result = add_floating_point(fp_number1, fp_number2);
    char* result_real = from_floating_point(result);
    free(fp_number1);
    free(fp_number2);
    free(result);
    return result_real;
}

char* subtract_real(const char* number1, const char* number2) {
    char* fp_number1 = to_floating_point(number1);
    char* fp_number2 = to_floating_point(number2);

    char* result = subtract_floating_point(fp_number1, fp_number2);
    char* result_real = from_floating_point(result);
    free(fp_number1);
    free(fp_number2);
    free(result);
    return result_real;
}

char* multiply_real(const char* number1, const char* number2) {
    char* fp_number1 = to_floating_point(number1);
    char* fp_number2 = to_floating_point(number2);

    char* result = multiply_floating_point(fp_number1, fp_number2);
    char* result_real = from_floating_point(result);
    free(fp_number1);
    free(fp_number2);
    free(result);
    return result_real;
}

char* divide_real(const char* number1, const char* number2) {
    char* fp_number1 = to_floating_point(number1);
    char* fp_number2 = to_floating_point(number2);

    char* result = divide_floating_point(fp_number1, fp_number2);
    char* result_real = from_floating_point(result);
    free(fp_number1);
    free(fp_number2);
    free(result);
    return result_real;
}
