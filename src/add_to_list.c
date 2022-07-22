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

    /* PROMPTING USER FOR PRODUCT'S PROPERTIES */

    /* NAME */
    printf("Please input product's name [max. 50 characters]: "); fgets(product.name, sizeof(product.name), stdin); while((getchar() != '\n'));
    if (strlen(product.name) >= 50){
        printf("The product's name is too long and will be truncated.\n");
        product.name[50] = '\n';
    }

    /* PRICE */
    do {
    printf("Please input product's price: "); scanf(" %lf", &product.price);
    } while (product.price <= 0);
    while ((getchar()) != '\n');

    /* DESCRIPTION */
    printf("Please input product's description [max. 200 characters (optional)]:\n"); fgets(product.description, sizeof(product.description), stdin); while(getchar() != '\n');
    if (strlen(product.description) >= 200) {
        printf("The product's description is too long and will be truncated.\n");
        product.description[200] = '\n';
    }

    /* PRIORITY */
    do {
    printf("Please input product's priority [0-5]: "); scanf(" %d", &product.priority);
    } while (product.priority > 5 || product.priority < 0);

    /* PRINTS TO STDOUT (FOR CHECKING) */
    /* printf("\nProduct's characteristicsics:\nName: %sPrice: %lf\nPriority: %d\nDescription: %s",  */
    /*        product.name, product.price, */
    /*        product.priority, product.description); */

    /* SAVES PRODUCT TO A FILE */
    fprintf(fptr, "\n%s%lf\n%s%d", product.name, product.price,
            product.description, product.priority);

    fclose(fptr);
}
