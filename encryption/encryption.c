#include "encryption.h"

void charToBinary(char c, char *binary){ //takes a char and an array base to save conversion

    for(int i = 7; i >= 0; i--){ //iterates 8 times
        binary[7-i] = (c & (1 << i)) ? '1' : '0'; //bitmasks the character and performs and operation
    }

    binary[8] = '\0'; //adds null terminator
}

char* stringToBinary(const char *str){
    if (str == NULL) return NULL; //checks if passed string exists

    size_t len = strlen(str); //saves strings length to len

    char *binary = malloc(len * 8 + 1); //allocates one byte per character plus one for null terminator

    if (binary == NULL) { //if binary stays null, outputs error
        printf("Memory allocation failed for string encryption!");
        return NULL;
    }

    binary[0] = '\0'; //initializes an empty string

    for (size_t i = 0; i < len; i++){ //executes length - 1 which is to exclude null terminator
        char bin[9]; //creates a 8 character long string
        charToBinary(str[i], bin); //saves each character converted to binary in bin
        strcat(binary, bin); //appends bin into binary
    }

    return binary; //returns the whole bitset

}

unsigned int convertToUnsignedInt(char *str) {
    unsigned int result = 0;
    for (int i = 0; i < 5 && str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    printf("#convertint Returning result: %d\n", result);
    return result;
}

char* randomGenerator(char *seed, int len) {
    printf("starting random generator\n");
    srand(convertToUnsignedInt(seed));
    printf("srand successful\n");

    // Allocate memory for outputbits with len + 1 for null terminator
    char *outputbits = malloc(len + 1);

    printf("starting for loop len is: %d\n", len);
    for (int i = 0; i <= len; i++) {
        outputbits[i] = (rand() % 2) + '0';  // Store '0' or '1' as characters
        printf("random generator loop iteration number: %d, bit: %c\n", i, outputbits[i]);  // Print the bit
    }
    outputbits[len] = '\0';  // Null-terminate the string

    printf("Length of outputbits: %zu\n", strlen(outputbits));  // Check the length
    return outputbits;
}


char* invertBits(char *bits){
        int len = strlen(bits); //gets length of bits and saves it

        char *outputbits = malloc(len + 1); //allocates memory for outputbits +1 is for null terminator

        for (int i = 0; i < len; i++){ //iterates len times
            if(bits[i] == '1'){ //if 1 turns it into 0
                outputbits[i] = '0';
            }
            else if(bits[i] == '0'){ // if 0 turns it into 1
                outputbits[i] = '1';
            }
            else{
                printf("Invalid character in bitset");
            }
        }
        outputbits[len] = '\0';
            printf("Returning inverted bits: %s", outputbits); //debug
        return outputbits;
}

char* xorbits(char* bitStr1, char* bitStr2){ //takes two strings at the same length, we don't check for length since we generate the strings
    int len1 = strlen(bitStr1); 
    int len2 = strlen(bitStr2);
    char* result = malloc(strlen(bitStr1) + 1); //allocates memory for result

    for (int i = 0; i < len1; i++){ //runs len times
        if(bitStr1[i] == bitStr2[i]){ //if two bits are same zeroes them
            result[i] = '0';
        }else{ //if they are different puts 1
            result[i] = '1';
        }
    }
    result[len1] = '\0';
    printf("Returning xor result: %s", result); //debug
    return result;
}

char* binaryToHex(const char *binary) {
    int len = strlen(binary);
    int hexIndex = 0;
    unsigned int value = 0;
    char* hex = malloc(len + 1);
    // Loop through the binary string
    for (int i = 0; i < len; i++) {
        value = (value << 1) | (binary[i] - '0'); // Shift left and add current bit

        // Every 4 bits, convert to hex
        if ((i + 1) % 4 == 0 || i == len - 1) {
            hexIndex += sprintf(&hex[hexIndex], "%X", value); // Convert to hex and store in hex string
            value = 0; // Reset value for next group
        }
    }
    hex[hexIndex] = '\0'; // Null-terminate the hex string
    return hex;
}


