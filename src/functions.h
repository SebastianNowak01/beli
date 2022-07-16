#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>


void printFromFile(char* fileName, char* path);
void printHelp();
void writeToFile(char* fileName);

#endif // FUNCTIONS_H_
