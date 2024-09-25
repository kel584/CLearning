#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <string.h>
static char command[200];
static char filename[50];
static char method[50];
static char outputfile[50];

int getSelection();

void getInput();

#endif