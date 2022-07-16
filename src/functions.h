#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>


void print_from_file(char* file_name, char* path);
void print_help();
void write_to_file(char* file_name);

#endif // FUNCTIONS_H_
