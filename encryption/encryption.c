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