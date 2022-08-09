#include "functions.h"

void print_list(char* list_name, char* path){
    FILE* fptr;
    char name_and_path[100];
    Product product;
    int product_count;

    sprintf(name_and_path, "%s/%s",path,list_name);
    
    fptr  = fopen(name_and_path,"r");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }

    fscanf(fptr, "%d", &product_count);
    for (int i=0; i < product_count; i++){
    fscanf(fptr, "%s\n%lf\n%s\n%d\n", product.name, &product.price, product.description, &product.priority);
    printf("%s\n%lf\n%s\n%d\n", product.name, product.price, product.description, product.priority);
    }
    fclose(fptr);
}
