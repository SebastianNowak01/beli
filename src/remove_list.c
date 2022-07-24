#include "functions.h"

void remove_list(char* list_name, char* path){
    char command[100];
    sprintf(command, "rm -f %s/%s", path, list_name);
    printf("%s", command);
    system(command);
}
