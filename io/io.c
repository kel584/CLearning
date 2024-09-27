#include "io.h"

int getSelection(){
    int selection;
    scanf("%d", &selection);
}

void getInput(){
    while(1){
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';


        if (sscanf(command, "-f %99s -m %99s -o %99s", filename, method, outputfile) == 3){

            break;
        } else{
            printf("Invalid command. Please use the format: -f filename -m method -o outputfile\n");
        }
    }
}

bool checkValidInput(const char *filename) {
    int length = strlen(filename);
    if (length >= 4 && strcmp(&filename[length - 4], ".txt") == 0) {
        return true;
    }
    return false;
}

char* ReadInputFile(const char *filename) {
    if (!checkValidInput(filename)) {
        printf("Invalid file input. The file must end with .txt\n");
        return NULL;
    }

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("File not found, please specify the full path.\n");
        return NULL;
    }


    while (fgets(Buffer, sizeof(Buffer), fptr) != NULL) {
        size_t bufferLength = strlen(Buffer);

        // Reallocate memory to hold the new content
        char *newContent = realloc(inputStringBuffer, contentSize + bufferLength + 1);
        if (newContent == NULL) {
            printf("Memory allocation failed!\n");
            free(inputStringBuffer);
            fclose(fptr);
            return NULL;
        }
        inputStringBuffer = newContent;

        // Copy the buffer to the end of the inputStringBuffer
        strcpy(inputStringBuffer + contentSize, Buffer);
        contentSize += bufferLength;
    }

    fclose(fptr);
    return inputStringBuffer;
}

void CreateOutputFile(char* encryptedtext){
        if(ReadInputFile(filename) != NULL){
        sprintf(outputStringBuffer, "%s\n", encryptedtext);
        strcat(outputfile, txtstr);
        fptr = fopen(outputfile, "w");
        fprintf(fptr, outputStringBuffer);
        fclose(fptr);
        }
        else{
            printf("Error Reading Output File");
        }

}