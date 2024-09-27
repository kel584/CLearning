#include "encryption.h"
void charToBinary(char c, char *binary){

    for(int i = 7; i >= 0; i--){
        binary[7-i] = (c & (1 << i)) ? '1' : '0';
    }

    binary[8] = '\0';
}

char* stringToBinary(const char *str){
    if (str == NULL) return NULL;

    size_t len = strlen(str);

    char *binary = malloc(len * 8 + 1);

    if (binary == NULL) {
        printf("Memory allocation failed for string encryption!");
        return NULL;
    }

    binary[0] = '\0';

    for (size_t i = 0; i < len; i++){
        char bin[9];
        charToBinary(str[i], bin);
        strcat(binary, bin);
    }

    return binary;

}