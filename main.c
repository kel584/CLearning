#include <stdio.h>
#include "io/io.h"
#include "encryption/encryption.h"


int main() {
getInput();
char *printString = stringToBinary(ReadInputFile(filename));
CreateOutputFile(printString);
    
return 0;

}
