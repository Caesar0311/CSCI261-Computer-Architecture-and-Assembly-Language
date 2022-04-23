/**
 * @file convert.c
 * @author Name:Caesar, Student Number:578751737, Section:N04, CSCI 261, VIU
 * @version 1.0.0
 * @date 24th Jan, 2022
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "utility.h"


//Pointer 'number' is pointing a string representation of a decimal number.
//Get the integer value from the string representation. 
//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'word_size' binary digits plus 2 prefixes.
//Use decimal-to-binary conversion algorithm to get the equivalent binary digits of 
//the decimal number and save the binary digits into the new string.
//Return the pointer of the new string.
char* decimal_to_binary(char* number, int word_size) {
    int int_val = atoi(number);
    // int length = strlen(number);
    char *binary = (char *) malloc(sizeof(char)*(word_size+3));
    binary[word_size+2] = '\0'; // end flag
    int b_idx = word_size+1;

    while (int_val != 0) {
        int cur = int_val % 2;
        binary[b_idx] = '0' + cur;
        int_val = int_val / 2;
        b_idx--;
    }

    while (b_idx >= 0)
    {
        binary[b_idx] = '0';
        b_idx--;
    }

    return binary;
}

//Pointer 'number' is pointing a string representation of a binary number.
//Use binary-to-decimal conversion algorithm to get the equivalent decimal (integer) 
//value from the binary digits.
//Dynamically allocate enough memory for a new string so that it can hold a decimal
//number with 'word_size' decimal digits.
//Convert the decimal (integer) value into the new string.
//Return the pointer of the new string.
char* binary_to_decimal(char* number, int word_size) {
    // convert bin to int val
    int length = strlen(number);
    int d_val = 0;
    for(int i = 0; i < length; i++) {
        d_val = d_val*2 + (number[i]-'0');
    }
    char *decimal = (char *) malloc(sizeof(char)*(word_size+1));
    sprintf(decimal,"%d",d_val);
    return decimal;
}

 


//Pointer 'number' is pointing a string representation of a decimal number.
//Get the integer value from the string representation. 
//Dynamically allocate enough memory for a new string so that it can hold a hex
//number with 'HEX_MAX_DIGITS' hex digits plus 2 prefixes.
//Use decimal-to-hex conversion algorithm to get the equivalent hex digits of 
//the decimal number and save the hex digits into the new string.
//Add '0x' prefix to the string.
//Return the pointer of the new string.
char* decimal_to_hex(char* number) {
    char hex_mark[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int int_val = atoi(number);
    // int length = strlen(number);
    char *hex = (char *) malloc(sizeof(char)*(HEX_MAX_DIGITS+3));
    hex[HEX_MAX_DIGITS+2] = '\0'; // end flag
    int h_idx = HEX_MAX_DIGITS+1;
    hex[0] = '0';
    hex[1] = 'x';

    while (int_val != 0) {
        int cur = int_val % 16;
        hex[h_idx] = hex_mark[cur];
        int_val = int_val / 16;
        h_idx--;
    }

    while (h_idx >= 2)
    {
        hex[h_idx] = '0';
        h_idx--;
    }

    return hex;
}


//Pointer 'number' is pointing a string representation of a hex number.
//The hex number is always prefixed with '0x'.
//Use hex-to-decimal conversion algorithm to get the equivalent decimal (integer) 
//value from the hex digits.
//Dynamically allocate enough memory for a new string so that it can hold a decimal
//number with 'DECIMAL_MAX_DIGITS' decimal digits.
//Convert the decimal (integer) value into the new string.
//Return the pointer of the new string.
char* hex_to_decimal(char* number) {
    // convert hex to int val
    int length = strlen(number);
    int d_val = 0;
    for(int i = 2; i < length; i++) {
        d_val = d_val*16 + ((number[i] >= '0' && number[i] <= '9')?(number[i]-'0'):(number[i]-'A'+10));
    }
    char *decimal = (char *) malloc(sizeof(char)*(DECIMAL_MAX_DIGITS+1));
    sprintf(decimal,"%d",d_val);
    return decimal;
} 

//Parameter 'nibble' is a group of four binary digits.
//Return the equivalent hex digit of the nibble.
char nibble_to_hex_digit(char* nibble) {
    char hex_mark[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int d_val = 0;
    for(int i = 0; i < strlen(nibble); i++) {
        d_val = d_val*2 + (nibble[i]-'0');
    }
    return hex_mark[d_val];
}
 
//Create an array of nibbles from the binary number.
//Dynamically allocate enough memory for a new string so that it can hold a hex
//number with 'HEX_MAX_DIGITS' hex digits plus 2 prefixes.
//Add the prefix '0x' to the new string.
//Get the hex digits from the nibbles in the array and save them into the string.
//Return the pointer of the new string.
char* binary_to_hex(char* number) {
    int length = strlen(number)-2;
    int nibble_size = (length+3)/4;
    char **nibbles=(char**)malloc(sizeof(char*)*nibble_size);
    for(int i=0; i<nibble_size; i++)  
        nibbles[i]=(char*)malloc(sizeof(char)*4);
    int b_idx = length+2-1;
    for(int i=nibble_size-1; i >= 0; i--) {
        if(b_idx >= 5) {
            for(int j=0; j < 4 ; j++,b_idx--) {
                nibbles[i][j] = number[length+2-(nibble_size-i)*4+j];
            }    
        } else {
            for(int j=b_idx-2; j >= 0 && b_idx >= 2; j--,b_idx--) {
                nibbles[i][j] = number[b_idx];
            }          
        }
    }
    char *hex = (char *) malloc(sizeof(char)*(HEX_MAX_DIGITS+3));
    hex[HEX_MAX_DIGITS+2] = '\0'; // end flag
    hex[0] = '0';
    hex[1] = 'x';
    int h_idx = HEX_MAX_DIGITS+1;
    int n_idx = nibble_size-1;
    while(n_idx >= 0)  {
        hex[h_idx] = nibble_to_hex_digit(nibbles[n_idx]);
        n_idx--;
        h_idx--;
    }

    while (h_idx >= 2)
    {
        hex[h_idx] = '0';
        h_idx--;
    }

    return hex;
}
  

//Pointer 'number' is pointing a string representation of a hex number.
//Dynamically allocate enough memory for a new string so that it can hold a binary
//number with 'BINARY_WORD_SIZE' binary digits plus 2 prefixes.
//Add the prefix '0b' to the string.
//Use hex-to-binary conversion algorithm to get the equivalent binary digits of 
//the hex number and save the binary digits into the new string.
//Return the pointer of the new string.
char* hex_to_binary(char* number) {
    int length = strlen(number);
    char *binary = (char *) malloc(sizeof(char)*(BINARY_WORD_SIZE+3));
    binary[BINARY_WORD_SIZE+2] = '\0';
    binary[0] = '0';
    binary[1] = 'b';

    int b_idx = BINARY_WORD_SIZE+1, h_idx = length-1;
    while (h_idx >= 2) {
        int d_val = (number[h_idx] >= '0' && number[h_idx] <= '9')?number[h_idx]-'0':number[h_idx]-'A'+10;
        for(int j = 0; j < 4; j++) {
            binary[b_idx] = '0' + (d_val % 2);
            d_val /= 2;
            b_idx--;
        }
        h_idx--;        
    }

    while (b_idx >= 2) {
        binary[b_idx--] = '0';
    }
    return binary;
}

 
//Return the result calling binary_to_decimal() function if the number is 
//represented in binary format. Pass the pointer to the first binary digit
//of the binary number into binary_to_decimal() function.
//Return the result calling hex_to_decimal() function if the number is 
//represented in hex format.
//Return a copy of the number removing the leading zeros if the number is 
//represented in decimal.
char* to_decimal(char* number) {
    if(is_binary(number)) {
        return binary_to_decimal(number+2,BINARY_WORD_SIZE);
    } else if (is_hex(number)) {
        return hex_to_decimal(number);
    } else if (is_decimal(number)){
        int length = strlen(number);
        int d_idx = 0;
        while (d_idx < length) {
            if(number[d_idx] == '0') {
                d_idx++;
            } else {
                break;
            }
        }
        int cpy_length = length - d_idx;
        char *cpy_decimal = (char *) malloc(sizeof(char)*cpy_length);
        int c_idx = 0;
        while(d_idx < length) {
            cpy_decimal[c_idx++] = number[d_idx++];
        }
        return cpy_decimal;
    } else {
        printf("\nError! Invalid digit in the number: %s\n", number);
        return NULL;
    }
}


//Call decimal_to_binary() function if the number is represented in decimal format.
//Add prefix '0b' with the binary number and return.
//Return the result calling hex_to_binary() function if the number is 
//represented in hex format.
//Return a copy of the number if the number is represented in binary.
char* to_binary(char* number) {
    if(is_decimal(number)) {
        char *bin = decimal_to_binary(number,BINARY_WORD_SIZE);
        bin[0] = '0';
        bin[1] = 'b';
        return bin;
    } else if (is_hex(number)) {
        return hex_to_binary(number);
    } else if(is_binary(number)) {
        int length = strlen(number);
        char *cpy_bin = (char *) malloc(sizeof(char)*length);
        strcpy(cpy_bin,number);
        return cpy_bin;
    } else {
        printf("\nError! Invalid digit in the number: %s\n", number);
       return NULL;
    }
}


//Return the result calling decimal_to_hex() function if the number is 
//represented in decimal format.
//Return the result calling binary_to_hex() function if the number is 
//represented in binary format.
//Return a copy of the number if the number is represented in hex.
char* to_hex(char* number) {
    if(is_decimal(number)) {
        return decimal_to_hex(number);
    } else if (is_binary(number)) {
        return binary_to_hex(number);
    } else if (is_hex(number)) {
        int length = strlen(number);
        char *cpy_hex = (char *) malloc(sizeof(char)*length);
        strcpy(cpy_hex,number);
        return cpy_hex;
    } else {
        printf("\nError! Invalid digit in the number: %s\n", number);
        return NULL;
    } 
}


//Call is_real_part() function to check whether it is a valid fraction part of a real number.
//If yes, perform the followings:
//      Allocate enough memory dynamically to a new string to hold
//      FIXED_POINT_PART_MAX_DIGITS binary digits.
//      Use decimal-fraction-to-binary conversion algorithm to get the binary digits and
//      save the binary digits into the new string.
//      Extend the binary representation to FIXED_POINT_PART_MAX_SIZE by calling
//      extend_to_word_size() function and return the extended binary.
char* integer_part_to_binary(char* number) {
    if(is_real_part(number)) {
        char *bin_digits = decimal_to_binary(number,FIXED_POINT_PART_MAX_DIGITS);
        bin_digits = extend_to_word_size(bin_digits,FIXED_POINT_PART_MAX_DIGITS);
        return bin_digits;
    } else {
        return NULL;
    }
}

//Call is_fixed_point_part() function to check whether it is a valid integer part of a 
//fixed point number.
//If yes, call binary_to_decimal() function to return the decimal representation of the part.
char* binary_to_integer_part(char* number) {
    if(is_fixed_point_part(number)) {
        return binary_to_decimal(number,BINARY_WORD_SIZE);
    } else {
        return NULL;
    }
}


//Call is_real_part() function to check whether it is a valid fraction part of a real number.
//If yes, perform the followings:
//	Allocate enough memory dynamically to a new string to hold
//	FIXED_POINT_PART_MAX_DIGITS binary digits.
//	Use decimal-fraction-to-binary conversion algorithm to get the binary digits and
//	save the binary digits into the new string.
//	Extend the binary representation to FIXED_POINT_PART_MAX_SIZE by calling 
//	extend_to_word_size() function and return the extended binary.
char* fraction_part_to_binary(char* number) {
    if(is_real_part(number)) {
        char *binary = (char *) malloc(sizeof(char)*(FIXED_POINT_PART_MAX_DIGITS+1));
        binary[FIXED_POINT_PART_MAX_DIGITS] = '\0'; // end flag
        int b_idx = 0;
        float f_val = atoi(number)*1.0;
        for(int i = 0; i < strlen(number);i++) {f_val /= 10.0;}

        f_val -= (int) f_val;
        while(f_val&&b_idx<FIXED_POINT_PART_MAX_DIGITS) {
            f_val *= 2;
            binary[b_idx++] = f_val >= 1 ? '1' : '0';
            f_val -= (int) f_val;
        }
        binary = extend_to_word_size(binary,FIXED_POINT_PART_MAX_DIGITS);
        return binary;
    } else {
        return NULL;
    }
}


//Call is_fixed_point_part() function to check whether it is a valid fraction part of a 
//fixed point number.
//If yes, perform the followings:
//	Use binary-to-fraction conversion algorithm to get the fraction value of a real 
//	number.
//	Allocate enough memory dynamically to a new string to hold REAL_PART_MAX_DIGITS 
//	decimal digits plus a the decimal point.
//	Convert the fraction value into the new string and return the pointer
//	of the string.
char* binary_to_fraction_part(char* number) {
    if(is_fixed_point_part(number)) {
        char *frac_part = (char * )malloc(sizeof(char)*(REAL_PART_MAX_DIGITS+2));
        double f_val = 0;
        double digits = 0.5;

        for(int i=0; i < strlen(number); i++) {
            f_val += digits*(number[i]-'0');
            digits *= 0.5;
        }

        sprintf(frac_part,"%f",f_val);

        for(int i=0; i<strlen(frac_part);i++) {
            frac_part[i] = frac_part[i+1];
        }
        return frac_part;
    } else {
        return NULL;
    }
}



//Call is_real() function to check whether it is a valid  real number.
//If yes, perform the followings:
//	Get the integer part of the real number into a new string by calling
//	get_integer_part() function and pass it to integer_part_to_binary() 
//	function to get the binary representation of the integer part of the real number.
//	Get the fraction part of the real number into a new string by calling
//	get_fraction_part() function and pass it to fraction_part_to_binary() function 
//	to get the binary representation of the fraction part of the real number.
//	Concatenate both the integer and fraction part binaries into a new 
//	fixed point repsrented string.
//	Free all the dynamically allocated memories that are no longer required.
//	Return the pointer of the pointer of the fixed point string.
char* to_fixed_point(char* number) {
    if(is_real(number)) {
        char *int_part = get_integer_part(number);
        char *int_binary = integer_part_to_binary(int_part);
        char *frac_part = get_fraction_part(number);
        char *frac_binary = fraction_part_to_binary(frac_part);
        char *fixed_point_str = (char *)malloc(sizeof(char)*(strlen(int_binary)+strlen(frac_binary)+1));
        sprintf(fixed_point_str, "%s%s", int_binary+2, frac_binary+2);
        return fixed_point_str;
    } else {
        return NULL;
    }
}

//Call is_fixed_point() function to check whether it is a valid fixed point number.
//If yes, perform the followings:
//	Get the copy of the integer part of the fixed point number into a new string
//	and pass it to binary_to_integer_part() function to get the decimal 
//	representation of the integer part of the fixed point number.
//	Get the copy of the fraction part of the fixed point number into a new string
//	and pass it to binary_to_fraction_part() function to get the decimal fraction 
//	representation of the fraction part of the fixed point number.
//	Concatenate both integer and fraction parts into a new 
//	real number repsrented string.
//	Free all the dynamically allocated memories that are no longer required.
//	Return the pointer of the real number string.
char* from_fixed_point(char* number) {
    if(is_fixed_point(number)) {
        char *int_part = (char *) malloc(sizeof(char)*(16+1));
        int_part[-1] = '\0';
        for(int i=0;i<16;i++) int_part[i] = number[i]; 
        char *int_dec = binary_to_integer_part(int_part);

        char *frac_part = (char *) malloc(sizeof(char)*(16+1));
        frac_part[-1] = '\0';
        for(int i=0;i<16;i++) frac_part[i] = number[i+16]; 
        char *frac_dec = binary_to_fraction_part(frac_part);

        char *real_num_str = (char *)malloc(sizeof(char)*(strlen(int_dec)+strlen(frac_part)+1));
        sprintf(real_num_str, "%s%s", int_dec, frac_dec);
        return real_num_str;
    } else {
        return NULL;
    }
}
