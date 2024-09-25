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
            printf("Filename: %s\n", filename);
            printf("Method: %s\n", method);
            printf("Outputfile: %s\n", outputfile);
            break;
        } else{
            printf("Invalid command. Please use the format: -f filename -m method -o outputfile\n");
        }
    }
}