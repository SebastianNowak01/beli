 #include "functions.h"

int main(int argc, char* argv[]){
    switch (argc) {
        case 1:
            print_help();
            break;
        case 2:
        case 3:
            /* ERROR CHECKING SECTION: IMPROPER OPTIONS */
            char* possible_options[12] = {"a", "add", "c", "create", "r", "remove", "b", "blank", "p", "print", "h", "help"};
            int is_valid;
            is_valid = 0;
            for (int i=0; i < 12;i++){
                if (strcmp(argv[1], possible_options[i]) == 0){
                    is_valid = 1;
                }
            }

            if (is_valid == 0){
                printf("There is no such option! Run beli with 'help' flag for more information.\n");
                return 1;
            }

            char first_option_letter;
            first_option_letter = argv[1][0];
            if (argc == 2 && first_option_letter - 'c' == 0){
                printf("Cannot create a new list with no name.\n");
                return 1;
            }


            /* PROPER MAIN FUNCTION */
            char home_dir[38]; //38 because of the fact that username can be 32 characters long + 6 characters for the /home/
            char list_name[20]; //20 because 15 chars maximum for name and + 5 for .beli extension
            strcpy(home_dir, getenv("HOME"));

            if (argc == 2){
                strcpy(list_name,"list.beli");
            }
            else if (argc == 3) {
                strcpy(list_name, argv[2]);
                strcat(list_name, ".beli");
            }
            printf("%s", list_name);

            if (first_option_letter - 'h' == 0){
               print_help();
            }
            break;
        default:
            printf("Too many arguments! Run beli with 'help' flag for more information.\n");
            return 1;
            break;
                }
}
