#include "io.h"
char command[200];
char filename[50];
char method[50];
char outputfile[50];
char outputStringBuffer[100];
char txtstr[50] = ".txt";
char Buffer[100];
char *inputStringBuffer = NULL;
size_t contentSize = 0;
FILE *fptr;

int getSelection(){
    int selection;
    scanf("%d", &selection);
}

void getInput(){
    while(1){
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin); //saves input to command variable
        command[strcspn(command, "\n")] = '\0'; //replaces "\n" with \0


        if (sscanf(command, "-f %99s -m %99s -o %99s", filename, method, outputfile) == 3){ //checks if every item matched.
            printf("%s, %s, %s", filename, method, outputfile); //prints matched items for debugging
            break;
        } else{
            printf("\nInvalid command. Please use the format: -f filename -m method -o outputfile\n");
        }
    }
}

bool checkValidInput(const char *filename) {
    int length = strlen(filename); //gets the length of filename and saves it
    printf("Checking filename: %s\n", filename); //debugging
    if (length >= 4 && strcmp(&filename[length - 4], ".txt") == 0) { //if length is bigger or equal to four and last 4 digits are .txt it returns true
        return true;
    }
    return false;
}

char* ReadInputFile(const char *filename) {
    if (!checkValidInput(filename)) {
        printf("Invalid file input. The file must end with .txt\n");
        return NULL;
    }

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("File not found, please specify the full path.\n");
        return NULL;
    }


    while (fgets(Buffer, sizeof(Buffer), fptr) != NULL) { //moves to the next line each successful iteration, saves the lines content into the buffer
        size_t bufferLength = strlen(Buffer); //gets buffers length and saves it


        char *newContent = realloc(inputStringBuffer, contentSize + bufferLength + 1); //sets inputStringBuffers size + content size which is 0 for first iteration + bufferlength + 1 for null terminator to newContent, newContent is the current data read.
        if (newContent == NULL) { //if realloc managed to allocate memory it'll skip this
            printf("Memory allocation failed!\n");
            free(inputStringBuffer);
            fclose(fptr);
            return NULL;
        }
        inputStringBuffer = newContent; //makes room for the current size of the data read.

 
        strcpy(inputStringBuffer + contentSize, Buffer); //copies the data from buffer to inputStringBuffer + contentsize, contentsize is crucial for text to be not overwritten.
        contentSize += bufferLength; //adds bufferLength to contentsize, this updates contentsize which prevents overwriting.
    }

    fclose(fptr); //closes the pointer to the files address
    return inputStringBuffer; //returns the data read.
}

void CreateOutputFile(char* encryptedtext){
        if(encryptedtext != NULL){ //checks if input text is null if yes skips to else
        sprintf(outputStringBuffer, "%s\n", encryptedtext); //adds outputStringBuffer the input text
        strcat(outputfile, txtstr); //adds ending of the file name to .txt so it can open it
        fptr = fopen(outputfile, "w"); //gets a handle to created file
        fprintf(fptr, outputStringBuffer); //pastes the outputStringBuffer to created file
        fclose(fptr); //closes the handle
        }
        else{
            printf("Error Reading Output File");
        }

}