#include "functions.h"

void printFromFile(char* fileName, char* path){
    FILE* fptr;
    char nameAndPath[100];
    sprintf(nameAndPath, "%s/%s",path,fileName);
    fptr  = fopen(nameAndPath,"r+");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }
    char buffer[100];
    fscanf(fptr, "%s", buffer);
    printf("%s\n", buffer);
    fclose(fptr);
}
