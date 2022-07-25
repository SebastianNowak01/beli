#include "functions.h"

void create_or_blank_list(char* list_name, char* path, char* home_dir){
    FILE* fptr;
    char list_name_with_no_extension[16];
    char name_and_path[100];
    sprintf(name_and_path, "%s/%s", path, list_name);
    const char* list_of_all_lists = "/.config/beli/all_lists.beli";
    char path_to_list_of_all_lists[66]; //66 because 38 from home_dir and 28 from list_of_all_lists
    int buffer;

    sprintf(path_to_list_of_all_lists, "%s%s", home_dir, list_of_all_lists);
    for (int i=0; i < strlen(list_name)-5; i++){
        list_name_with_no_extension[i] = list_name[i];
    }

    fptr  = fopen(name_and_path,"w");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }

    fprintf(fptr, "0");
    fclose(fptr);

    fptr = fopen(path_to_list_of_all_lists, "a");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }

    fprintf(fptr, "\n%s", list_name_with_no_extension);
    fclose(fptr);

}
