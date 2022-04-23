/**
 * @file convert.c
 * @author Caesar, 578751737， CSCI 261, VIU
 * @version 1.0.0
 * @date  22, Mar, 2022
 *
 * Implement the functions specified in 'convert.h' header file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "utility.h"


static int fraction_multi_two(char* number) {
    int len = strlen(number);
    int i;
    int carry = 0;
    for (i = len - 1; i >= 0; --i) {
        int v = number[i] - '0';
        v = v * 2 + carry;
        number[i] = v % 10 + '0';
        carry = v / 10;
    }
    // trim tail zero.
    for (i = len - 1; i >= 0; --i) {
        if (number[i] == '0') {
            number[i] = '\0';
        }
        else {
            break;
        }
    }
    return carry;
}



char* integer_to_binary(int int_num, int binary_size) {
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

char* fraction_to_binary(const char* number, int binary_size) {
    char* binary = calloc((binary_size + 1), sizeof(char));
    char* copy = strdup(number);
    int i = 0;
    while (copy[0] != '\0' && i < binary_size) {
        if (fraction_multi_two(copy)) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        i++;
    }
    binary[i] = '\0';
    free(copy);
    return binary;
}

int binary_to_int(const char* number) {
    int int_num = 0;
    int len = strlen(number);
    int i = 0;
    while (i < len) {
        int_num = int_num * 2 + number[i] - '0';
        i++;
    }
    return int_num;
}

char one_bit_add(const char op1, const char op2, const char cin, char* cout) {
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

char* get_magnitude_binary(const char* signed_number, int binary_size) {
    size_t i = 0;
    if (signed_number[0] == '+' || signed_number[0] == '-')
        signed_number++;
    int num = 0;
    for (; i < strlen(signed_number); i++)
        num = num * 10 + signed_number[i] - '0';
    return integer_to_binary(num, binary_size);
}

void ones_complement(char* number) {
    for (size_t i = 0; i < strlen(number); i++) {
        char temp = number[i];
        if (temp == '0')
            number[i] = '1';
        else
            number[i] = '0';
    }
}

void twos_complement(char* number) {
    ones_complement(number);
    int i = 0;
    int len = strlen(number);
    char op2 = '1', cin = '0';
    for (i = len - 1; i >= 0; --i) {
        number[i] = one_bit_add(number[i], op2, cin, &cin);
        op2 = '0';
    }
}

char* to_twos_complement(const char* number) {
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

char* from_twos_complement(const char* number) {
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

char* int_to_biased_127(int number) {
    if (number >= FLOATING_POINT_EXPONENT_MIN_VALUE && number <= FLOATING_POINT_EXPONENT_MAX_VALUE) {
        number += BIASED_VALUE;
        char* biased = integer_to_binary(number, BIASED_127_BINARY_MAX_DIGITS);
        char* ret = extend_integer_binary_to_word_size(biased, BIASED_127_BINARY_MAX_DIGITS);
        free(biased);
        return ret;
    }
    return NULL;
}

char* to_biased_127(const char* number) {
    if (is_biased_127_decimal(number) == TRUE) {
        return int_to_biased_127(atoi(number));
    }
    return NULL;
}

static char* int_to_str(int int_num) {
    char* mag = calloc((DECIMAL_MAX_DIGITS + 2), sizeof(char));
    int i = 0;
    do {
        mag[i++] = int_num % 10 + '0';
        int_num /= 10;
    } while (int_num > 0);
    mag[i] = '\0';
    reverse(mag);
    return mag;
}


int int_from_biased_127(const char* number) {
    return binary_to_int(number) - BIASED_VALUE;
}

char* from_biased_127(const char* number) {
    if (is_biased_127_binary(number) == TRUE) {
        int int_num = int_from_biased_127(number);
        char* ret = NULL;
        if (int_num < 0) {
            int_num = -int_num;
            ret = int_to_str(int_num);
            add_sign(ret, '-');
        } else {
            ret = int_to_str(int_num);
        }
        return ret;
    }
    return NULL;
}

void normalize(char* integer, char* fraction, int* exponent) {
    int int_len = strlen(integer);
    int frac_len = strlen(fraction);
    int i;
    if (integer[0] == '1') {
        *exponent = int_len - 1;
        for (i = frac_len; i >= 0; --i) {
            if (i + *exponent < BINARY_WORD_SIZE) {
                fraction[i + *exponent] = fraction[i];
            }
        }
        for (i = 1; i < int_len; i++) {
            fraction[i - 1] = integer[i];
        }
    } else {
        *exponent = 0;
        for (i = 0; i < frac_len; ++i) {
            if (fraction[i] == '1') {
                break;
            }
        }
        if (i != frac_len) {
            i++;
            *exponent = -i;
            while (i < frac_len) {
                fraction[i + *exponent] = fraction[i];
                i++;
            }
            fraction[i + *exponent] = '\0';
        }
    }
}

char* to_floating_point(const char* number) {
 
    if (is_real(number) == TRUE) {
        char* int_part = get_integer_part(number);
        char* fraction_part = get_fraction_part(number);
        char* int_part_binary = get_magnitude_binary(int_part, BINARY_WORD_SIZE);
        char* fraction_part_binary = fraction_to_binary(fraction_part, BINARY_WORD_SIZE);

        int exponent = 0;
        /* printf("\nint = %s %lu", int_part_binary, strlen(int_part_binary)); */
        /* printf("\nfrac = %s %lu", fraction_part_binary, strlen(fraction_part_binary)); */
        normalize(int_part_binary, fraction_part_binary, &exponent);

        /* printf("\nexponent = %d", exponent); */
        char* exp = int_to_biased_127(exponent);
        /* printf("\nexp = %s %lu", exp, strlen(exp)); */
        /* printf("\nfrac = %s %lu", fraction_part_binary, strlen(fraction_part_binary)); */

        char* ex_exp = extend_integer_binary_to_word_size(exp, FLOATING_POINT_EXPONENT_DIGITS);
        char* ex_frac = extend_fraction_binary_to_word_size(fraction_part_binary,
                                                            FLOATING_POINT_SIGNIFICAND_DIGITS);
        /* printf("\nexp = %s %lu", ex_exp, strlen(ex_exp)); */
        /* printf("\nfrac = %s %lu", ex_frac, strlen(ex_frac)); */

        char* ret = calloc((FLOATING_POINT_MAX_DIGITS + 1), sizeof(char));
        if (number[0] == '-') {
            ret[0] = '1';
        } else {
            ret[0] = '0';
        }
        int i = 0;
        for (i = 0; i < FLOATING_POINT_EXPONENT_DIGITS && ex_exp[i]; ++i) {
            ret[i + 1] = ex_exp[i];
        }
        for (i = 0; i < FLOATING_POINT_SIGNIFICAND_DIGITS && ex_frac[i]; ++i) {
            ret[i + 9] = ex_frac[i];
        }
        ret[i + 9] = '\0';
        free(int_part);
        free(int_part_binary);
        free(fraction_part);
        free(fraction_part_binary);
        free(exp);
        free(ex_exp);
        free(ex_frac);
        return ret;
    }
    return NULL;
}

double get_significand_value(const char* sig) {
    if (is_significand(sig) == TRUE) {
        double sum = 1.0;
        double v = 0.5;
        int i = 0;
        for (i = 0; i < FLOATING_POINT_SIGNIFICAND_DIGITS; ++i) {
            if (sig[i] == '1') {
                sum += v;
            }
            v /= 2.0;
        }
        return sum;
    }
    return -1;
}

char* extract_exponent(const char* number)
// Copy the exponent part of the floating point number into a new string and return
// the pointer of the new string to the caller.
{
    char* temp = calloc(  FLOATING_POINT_EXPONENT_DIGITS + 1, sizeof(char));
    memcpy(temp, number + 1, FLOATING_POINT_EXPONENT_DIGITS);
    return temp;
}

char* extract_significand(const char* number)
// Copy the significand part of the floating point number into a new string and return
// the pointer of the string to the caller.
{
    char* temp = calloc( FLOATING_POINT_SIGNIFICAND_DIGITS + 1,sizeof(char));
    memcpy(temp, number + SIGNIFICAND_START_BIT_IN_FLOATING_POINT, FLOATING_POINT_SIGNIFICAND_DIGITS);
    return temp;
}

char* from_floating_point(const char* number) {
    if (is_floating_point(number) == TRUE) {
        char* exp = calloc((FLOATING_POINT_EXPONENT_DIGITS + 1), sizeof(char));
        strncpy(exp, number + 1, FLOATING_POINT_EXPONENT_DIGITS);
        int exp_v = int_from_biased_127(exp);
        double sig = get_significand_value(number + SIGNIFICAND_START_BIT_IN_FLOATING_POINT);
        if (sig < 0) {
            free(exp);
            return NULL;
        }
        double t = 2.0;
        if (exp_v < 0) {
            t = 1 / 2.0;
            exp_v = -exp_v;
        }


        if (exp_v > 0) {
            while (exp_v > 0) {
                if (exp_v % 2 == 1) {
                    /* printf("\n%lf", t); */
                    sig *= t;
                }
                exp_v >>= 1;
                t = t * t;
            }
        }

        if (number[0] == '1') {
            sig = -sig;
        }

        char* ret = calloc((REAL_MAX_DIGITS + 3), sizeof(char));
        sprintf(ret, "%lf", sig);
        free(exp);
        return ret;
    }
    return NULL;
}
