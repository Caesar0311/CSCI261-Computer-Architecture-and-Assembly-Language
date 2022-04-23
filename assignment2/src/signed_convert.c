/**
 * @file signed_convert.c
 * @author Name:Caesar, Student Number:578751737, Section:N04, CSCI 261, VIU
 * @version 1.0.0
 * @date 8th Feb, 2022
   *
 */

/*
 * Include necessary standard library header files.
 */
#include "signed_convert.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Include necessary custom header files.
 */

/*
 * Include necessary custom header files.
 */

//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'bianry_size' binary digits.
//Use decimal-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal number int_num' and save the binary digits into the new string.
//Return the pointer of the new string.
char* integer_to_binary(int int_num, int binary_size) {
    char *binary = calloc((binary_size + 1), sizeof(char));
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

//Ignore the sign bit if there is one and get the integer value of the 'signed_number'.
//Call the function integer_to_binary() and return the result.
char* get_magnitude_binary(char* signed_number, int binary_size) {
    int len = strlen(signed_number);
    int i = 0;
    if (signed_number[0] == '+' || signed_number[0] == '-') {
        i = 1;
    }
    int num = 0;
    while (i < len) {
        num = num * 10 + signed_number[i] - '0';
        i++;
    }
    return integer_to_binary(num, binary_size);
}

static int fraction_multi_two(char* number) {
    int len = strlen(number);
    int i;
    int carry = 0;
    for (i = len-1; i >= 0; --i) {
        int v = number[i] - '0';
        v = v * 2 + carry;
        number[i] = v % 10 + '0';
        carry = v / 10;
    }
    // trim tail zero.
    for (i = len - 1; i >= 0; --i) {
        if (number[i] == '0') {
            number[i] = '\0';
        } else {
            break;
        }
    }
    return carry;
}

//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'bianry_size' binary digits.
//Use decimal-fraction-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal fraction number and save the binary digits into the new string.
//Return the pointer of the new string.
char* fraction_to_binary(char* number, int binary_size) {
    char *binary = calloc((binary_size + 1), sizeof(char));
    char *copy = strdup(number);
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



//Check whether the number is a valid decimal number by calling is_decimal() function.
//If yes, perform the followings:
//    Call get_magnitude_binary() function to get the binary representation of the
//    magnitude of the number.
//    Extend the binary representation of the magnitude to BINARY_WORD_SIZE by
//    calling extend_integer_binary_to_word_size() function.
//    Free all dynamically allocated memories that are no longer required.
//    Set the appropriate sign bit for the signed magnitude number and return it
//    to the caller.
char* to_sign_magnitude(char* number) {
    if (is_decimal(number) == TRUE) {
        char *magnitude = get_magnitude_binary(number, BINARY_WORD_SIZE-1);
        char *sign_mag = extend_integer_binary_to_word_size(magnitude, BINARY_WORD_SIZE);
        if (number[0] == '-') {
            sign_mag[0] = '1';
        }
        free(magnitude);
        return sign_mag;
    }
    return NULL;
}


//Use binary-to-deciaml conversion algorithm to get the equivalent 
//decimal (integer) number from the binary digits.
//If 'is_sign_magnitude' is TRUE, ignore the most significant sign bin in the 
//conversion process.
//Return the integer number.
int binary_to_int(char* number, int is_sign_magnitude) {
    int int_num = 0;
    int len = strlen(number);
    int i = (is_sign_magnitude == TRUE ? 1 : 0);
    while (i < len) {
        int_num = int_num * 2 + number[i] - '0';
        i++;
    }
    return int_num;
}

//Parameters 'op1', 'op2' and 'cin' are binary operands, their value can be either
//'0' or '1'.
//Add these binary operands and save the resultant carry of the addition into 'cout'.
//Return the result of the addition to the caller.
char one_bit_add(char op1, char op2, char cin, char* cout) {
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

static char* int_to_str(int int_num) {
    char *mag = calloc((DECIMAL_MAX_DIGITS + 2), sizeof(char));
    int i = 0;
    do {
        mag[i++] = int_num % 10 + '0';
        int_num /= 10;
    } while(int_num > 0);
    mag[i] = '\0';
    reverse(mag);
    return mag;
}

//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//    Call binary_to_int() function indicating it's a sign magnitude binary number
//    and get the integer equivalent of the sign magnitude number.
//    Convert the integer into a new string and add the appropriate sign to the string.
//    Return the string.
char* from_sign_magnitude(char* number) {
    if (is_binary(number) == TRUE) {
        int int_num = binary_to_int(number, TRUE);
        char *mag = int_to_str(int_num);
        if (number[0] == '0') {
            add_sign(mag, '+');
        } else {
            add_sign(mag, '-');
        }
        return mag;
    }
    return NULL;
}

//Flip each binary digit in the number.
void ones_complement(char* number) {
    int len = strlen(number);
    int i;
    for (i = 0; i < len; ++i) {
        if (number[i] == '0') {
            number[i] = '1';
        } else {
            number[i] = '0';
        }
    }
}


//Get the ones complement of the number by calling ones_complement() function.
//Add '1' to the ones complement by calling one_bit_add() function as many times
//as it requires.
void twos_complement(char* number) {
    ones_complement(number);
    int i = 0;
    int len = strlen(number);
    char op2 = '1', cin = '0';
    for (i = len-1; i >= 0; --i) {
        number[i] = one_bit_add(number[i], op2, cin, &cin);
        op2 = '0';
    }
}


//Check whether the number is a valid decimal number by calling is_decimal() function.
//If yes, perform the followings:
//    Call get_magnitude_binary() function to get the binary representation of the
//    magnitude of the number.
//    Extend the binary representation of the magnitude to BINARY_WORD_SIZE by
//    calling extend_integer_binary_to_word_size() function.
//    If the sing bit of the number is '-' get the twos complement of the
//    the signed magnitude number by calling twos_complement() function.
//    Free all dynamically allocated memories that are no longer required.
//    Return the twos complement number to the caller.
char* to_twos_complement(char* number) {
    if (is_decimal(number) == TRUE) {
        char *magnitude = get_magnitude_binary(number, BINARY_WORD_SIZE-1);
        char *sign_mag = extend_integer_binary_to_word_size(
                magnitude, BINARY_WORD_SIZE);
        if (number[0] == '-') {
            twos_complement(sign_mag);
        }
        free(magnitude);
        return sign_mag;
    }
    return NULL;
}


//Check whether the number is a valid binary number by calling is_binary() function.
//If yes, perform the followings:
//    Use twos-complement-bianry-to-decimal conversion algorithm to get the integer equivalent 
//    of the twos complement number.
//    Convert the integer into a new string and return the string.
char* from_twos_complement(char* number) {
    if (is_binary(number) == TRUE) {
        int int_num = binary_to_int(number, TRUE);
        if (number[0] == '1') {
            int_num -= (1 << (strlen(number) - 1));
            int_num = -int_num;
        }
        char *mag = int_to_str(int_num);
        if (number[0] == '1') {
            add_sign(mag, '-');
        }
        return mag;
    }
    return NULL;
}


//Check whether the integer number is within the range of?BIASED_127_DECIMAL_MIN_VALUE?and
//BIASED_127_DECIMAL_MAX_VALUE.
//If yes, perform the followings:
// Add BIASED_VALUE to the number
// Call integer_to_binary() function to get the binary representation of the biased
// number.
// Call extend_integer_binary_to_word_size() to extend the biased binary to
// BIASED_127_BINARY_MAX_DIGITS.
// Free all dynamically allocated memories that are no longer required.
// Return the extended binary to the caller.
char* int_to_biased_127(int number) {
    if (number >= BIASED_127_DECIMAL_MIN_VALUE && number <= BIASED_127_DECIMAL_MAX_VALUE) {
        number += BIASED_VALUE;
        char *biased = integer_to_binary(number, BIASED_127_BINARY_MAX_DIGITS);
        char *ret = extend_integer_binary_to_word_size(biased, BIASED_127_BINARY_MAX_DIGITS);
        free(biased);
        return ret;
    }
    return NULL;
}


//Check whether the number is a valid biased_127 number by calling is_biased_127() fucntion.
//If yes, get the integer equivalent of the biased_127 number and call int_to_biased_127()
//function to get the binary represenation of bised_127 number and return it to the caller.
char* to_biased_127(char* number) {
    if (is_biased_127_decimal(number) == TRUE) {
        return int_to_biased_127(atoi(number));
    }
    return NULL;
}

//Call int_from_biased_127() function to get the integer equivalent of the biased_127 number
//and subtract the BIASED_VALUE from the number and return it.
int int_from_biased_127(char* number) {
    return binary_to_int(number, FALSE) - BIASED_VALUE;
}


//Check whether the number is a valid binary representation of a biased_127 number by calling
//is_baised_127_binary() function.
//If yes, 
//    Call int_from_biased_127() function to get the integer equivalent of the baised_127
//    number.
//    Allocate enough memory to a string to hold BIASED_127_MAX_DIGITS plus the sign.
//    Convert the integer number to the new string and return it.
//
char* from_biased_127(char* number) {
    if (is_biased_127_binary(number) == TRUE) {
        int int_num = int_from_biased_127(number);
        char *ret = NULL;
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


//Parameters 'integer', 'fraction' are intermediate binary represenation of the integer
//and fraction parts of a real number and 'exponent' is binary exponent value of the
//real number.
//Following floating-point-normalization algorithm move the digits of the integer and 
//the fraction parts as necessary and adjust the exponent value accordingly.  
void normalize(char* integer, char* fraction, int* exponent) {
    int int_len = strlen(integer);
    int frac_len = strlen(fraction);
    int i;
    if (integer[0] == '1') {
        *exponent = int_len - 1;
        for (i = frac_len; i >= 0; --i) {
            if (i + *exponent < BINARY_WORD_SIZE) {
                fraction[i+*exponent] = fraction[i];
            }
        }
        for (i = 1; i < int_len; i++) {
            fraction[i-1] = integer[i];
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

//Check whether the number is a valid real number by calling is_real() function.
//If yes, perform the followings:
//    Call get_integer_part() function to get the integer part of the real number.
//    Call get_fraction_part() fucntion to get the fraction part of the real number.
//    Call get_magnitude_binary() function to get the binary representation of the
//    integer part of the real number.
//    Call fraction_to_binary() function to get the binary representation of the 
//    fraction part of the real number.
//    Call normalize() function to normalize the integer and fraction binaries and 
//    to adjust the exponent of the real number.
//    Call int_to_biased_127() function to get biased_127 binary representation
//    of the adjusted exponent of the floating point number.
//    Call extend_integer_binary_to_word_size() function to extend biased_127 exponent
//    bianry to FLOATING_POINT_EXPONENT_DIGITS.
//    Call extend_fraction_binary_to_word_size() function to extend fraction
//    bianry (floating point significand) to FLOATING_POINT_SIGNIFICAND_DIGITS.
//    Allocate enough memory to a new string to hold the parts of the  floating point
//    number.
//    Set the sign bit of the floating point number according to the sign bit of the
//    the real number.
//    Copy the biased_127 exponent into the floating point string.
//    Copy the floating point significand into the floating point string.
//    Free all dynamically allocated memories that are no longer required.
//    Return the floating point string to the caller.
char* to_floating_point(char* number) {
    /* printf("\nnumber = %s", number); */
    if (is_real(number) == TRUE) {
        char *int_part = get_integer_part(number);
        char *fraction_part= get_fraction_part(number);
        char *int_part_binary = get_magnitude_binary(int_part, BINARY_WORD_SIZE);
        char *fraction_part_binary = fraction_to_binary(fraction_part, BINARY_WORD_SIZE);

        int exponent = 0;
        /* printf("\nint = %s %lu", int_part_binary, strlen(int_part_binary)); */
        /* printf("\nfrac = %s %lu", fraction_part_binary, strlen(fraction_part_binary)); */
        normalize(int_part_binary, fraction_part_binary, &exponent);

        /* printf("\nexponent = %d", exponent); */
        char *exp = int_to_biased_127(exponent);
        /* printf("\nexp = %s %lu", exp, strlen(exp)); */
        /* printf("\nfrac = %s %lu", fraction_part_binary, strlen(fraction_part_binary)); */

        char *ex_exp = extend_integer_binary_to_word_size(exp, FLOATING_POINT_EXPONENT_DIGITS);
        char *ex_frac = extend_fraction_binary_to_word_size(fraction_part_binary, FLOATING_POINT_SIGNIFICAND_DIGITS);
        /* printf("\nexp = %s %lu", ex_exp, strlen(ex_exp)); */
        /* printf("\nfrac = %s %lu", ex_frac, strlen(ex_frac)); */

        char *ret = calloc((FLOATING_POINT_MAX_DIGITS + 1), sizeof(char));
        if (number[0] == '-') {
            ret[0] = '1';
        } else {
            ret[0] = '0';
        }
        int i = 0;
        for (i = 0; i < FLOATING_POINT_EXPONENT_DIGITS && ex_exp[i]; ++i) {
            ret[i+1] = ex_exp[i];
        }
        for (i = 0; i < FLOATING_POINT_SIGNIFICAND_DIGITS && ex_frac[i]; ++i) {
            ret[i+9] = ex_frac[i];
        }
        ret[i+9] = '\0';
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

//Check whether 'sig' is a valid significand by calling is_significand() function.
//If yes, use significand binary to double conversion algorithm to find the value
//of the significand and return it.
double get_significand_value(char* sig) {
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

//Check whether the number is a valid floating point number or not 
//by calling is_floating_point() function.
//If yes, perform the followings:
//    Extract the exponent part from the floating point number.
//    Call int_from_biased_127() function to get the exponent value for the real number.
//    Extract the significand part from the floating point number.
//    Call get_significand_value() function to get the value of the significand part.
//    Compute the real number using the sign bit of the floation point number and the above
//    computed exponent and significand values.
//    Allocate enough memory to a new string to hold the sign and the digits of a real number.
//    Convert the above computed real number into the new string.
//    Free all dynamically allocated memories that are no longer required.
//    Return the real number string to the caller.
char* from_floating_point(char* number) {
    if (is_floating_point(number) == TRUE) {
        char *exp = calloc((FLOATING_POINT_EXPONENT_DIGITS+1), sizeof(char));
        strncpy(exp, number + 1, FLOATING_POINT_EXPONENT_DIGITS);
        int exp_v = int_from_biased_127(exp);
        double sig = get_significand_value(
                number + SIGNIFICAND_START_BIT_IN_FLOATING_POINT);
        if (sig < 0) {
            free(exp);
            return NULL;
        }
        double t = 2.0;
        if (exp_v < 0) {
            t = 1/2.0;
            exp_v = -exp_v;
        }
        /* sig += 1; */
        /* printf("\nsig = %lf %d", sig, exp_v); */

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

        char *ret = calloc((REAL_MAX_DIGITS + 3), sizeof(char));
        sprintf(ret, "%lf", sig);
        free(exp);
        return ret;
    }
    return NULL;
}
