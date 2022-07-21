#include "functions.h"

void add_to_list(char* list_name, char* path){
    FILE* fptr;
    char name_and_path[100];
    Product product;

    sprintf(name_and_path, "%s/%s", path, list_name);

    fptr  = fopen(name_and_path, "a");
    if (fptr == NULL) {
        printf("Could not open the file.\n");
        exit(1);
    }
    /* GETTING PRODUCTS' COUNT */

    /* PROMPTING USER FOR PRODUCT'S PROPERTIES */
    printf("Please input product's name (max. 50 characters): "); fgets(product.name, sizeof(product.name), stdin);

    printf("Please input product's price: "); scanf("%lf", &product.price); while ((getchar()) != '\n');

    printf("Please input product's description: "); fgets(product.description, sizeof(product.description), stdin);
    printf("Please input product's priority: "); scanf("%d", &product.priority);

    printf("\nProduct's characteristics:\nName: %sPrice: %lf\nPriority: %d\nDescription: %s",
           product.name, product.price,
           product.priority, product.description);

    fprintf(fptr, "\n%s%lf\n%s%d", product.name, product.price,
            product.description, product.priority);
}
