#include <stdio.h>
#include "io/io.h"
#include "encryption/encryption.h"
#include "ui/ui.h"


int main() {
PrintWelcome();
int len;
getInput();
char *binarystring = stringToBinary(ReadInputFile(filename));
char *compareString;
char *invertedBits;
char *finalBits;
char *finalHex;
printf("binary string: %s\n", binarystring);
len = strlen(binarystring);
compareString = randomGenerator(binarystring, len);
printf("compare string: %s\n", compareString);
invertedBits = invertBits(binarystring);
printf("inverted bits: %s\n", invertedBits);
finalBits = xorbits(invertedBits, compareString);
printf("xor bits final result: %s\n", finalBits);
finalHex = binaryToHex(finalBits);
CreateOutputFile(finalHex);
free(compareString);
free(invertedBits);
free(finalBits);
free(finalHex);
return 0;

}
