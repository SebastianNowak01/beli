#include "functions.h"

void create_or_blank_list(char* list_name, char* path){
    FILE* fptr;
    char name_and_path[100];
    sprintf(name_and_path, "%s/%s", path, list_name);
    fptr  = fopen(name_and_path,"w");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }
    int buffer;
    fprintf(fptr, "0");
    fscanf(fptr,"%d", &buffer);
    printf("%d", buffer);
    fclose(fptr);
}
