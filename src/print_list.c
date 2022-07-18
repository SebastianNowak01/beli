#include "functions.h"

void print_list(char* file_name, char* path){
    FILE* fptr;
    char name_and_path[100];

    sprintf(name_and_path, "%s/%s",path,file_name);
    
    fptr  = fopen(name_and_path,"r+");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }
    char buffer[100];
    fscanf(fptr, "%s", buffer);
    printf("%s\n", buffer);
    fclose(fptr);
}
