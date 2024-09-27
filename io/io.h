#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static char command[200];
static char filename[50];
static char method[50];
static char outputfile[50];
static char outputStringBuffer[100];
static char txtstr[50] = ".txt";
static char Buffer[100];
static char *inputStringBuffer = NULL;
static size_t contentSize = 0;
FILE *fptr;

int getSelection();
void CreateOutputFile();
void getInput();
char* ReadInputFile(const char *filename);
bool checkValidInput(const char *filename);

#endif