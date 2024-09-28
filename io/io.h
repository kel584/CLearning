#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern char command[200]; 
extern char filename[50];
extern char method[50];
extern char outputfile[50];
extern char outputStringBuffer[100];
extern char txtstr[50];
extern char Buffer[100];
extern char *inputStringBuffer;
extern size_t contentSize;
extern FILE *fptr;


int getSelection();
void CreateOutputFile(char* encryptedtext);
void getInput();
char* ReadInputFile(const char *filename);
bool checkValidInput(const char *filename);

#endif