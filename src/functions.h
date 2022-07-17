#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>

void print_list(char* file_name, char* path);
void print_help();
void add_to_list(char* file_name, char* path);
int inline_arguments_check(int argc, char* argv[], char first_option_letter);


#endif // FUNCTIONS_H_
