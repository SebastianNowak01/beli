 #include "functions.h"

int main(int argc, char* argv[]){
    switch (argc) {
        /* WITHOUT ARGUMENTS THE PROGRAM WILL PRINT OUT HELP OPTION */
        case 1:
            print_help();
            break;
        /* 3RD ARGUMENT IS (MOSTLY) OPTIONAL SO THERE IS NO (BIG) DIFFERENCE BETWEEN 2 AND 3 ARGUMENTS*/
        case 2:
        case 3:
            /* -------------------- ERROR CHECKING -------------------- */

            /* IMPROPER OPTIONS CHECK */
            /* 12 is the amount of all possible options */
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

            /* EXTRACT FIRST LETTER FROM 'OPTION' FOR CHECKING ERRORS AND OPTIONS*/
            char first_option_letter;
            first_option_letter = argv[1][0];

            /* CREATE OPTION WITHOUT SPECIFIED LIST */
            if (argc == 2 && first_option_letter - 'c' == 0){
                printf("Cannot create a new list with no name.\n");
                return 1;
            }

            /* CHECKING LENGTH OF 3RD ARGUMENT IF 'CREATE' WAS USED AND CHECK FOR ANY '/' */
            if (argc == 3){
                if (strlen(argv[2]) <= 0 || strlen(argv[2]) > 15){
                printf("Invalid list name length! List names can be up to 15 characters long.\n");
                return 1;
                }
                else {
                    regex_t regex_pointer;
                    int is_compilation_succesful;
                    int regex_match;

                    is_compilation_succesful = regcomp(&regex_pointer, "^[0-9a-zA-Z_]*$", 0);

                    if (is_compilation_succesful != 0){
                        printf("Regex compilation error.\n");
                        return 1;
                    }

                    regex_match = regexec(&regex_pointer, argv[2], 0, NULL, 0);

                    if (regex_match == REG_NOMATCH){
                        printf("Invalid file name! File names can only be letters, numbers and underscores.\n");
                        return 1;
                    }

                }
            }

            /* -------------------- PROPER MAIN FUNCTION -------------------- */


            /* DECLARED VARIABLES TO GET 'HOME' VARIABLE AND SUBSEQUENTLY FULL PATH TO CONFIG FILE */
            char home_dir[38]; //38 because of the fact that username can be 32 characters long + 6 characters for the /home/
            char list_name[20]; //20 because 15 chars maximum for name and + 5 for .beli extension
            char path[57]; //57 because of home_dir size and /.config/beli/lists
            const char* config_path = "/.config/beli/lists";

            /* GETTING FULL PATH TO CONFIG FILES TO OPERATE ON FILES WITHIN */
            strcpy(home_dir, getenv("HOME"));
            strcpy(path, home_dir);
            strcat(path, config_path);

            /* OBTAINING LIST NAME (OR USING PRIMARY LIST IF NO 3RD ARGUMENT SPECIFIED) */
            printf("%s\n", path);
            if (argc == 2){
                strcpy(list_name,"list.beli");
            }
            else if (argc == 3) {
                strcpy(list_name, argv[2]);
                strcat(list_name, ".beli");
            }
            printf("%s", list_name);

            /* HANDLING ALL THE DIFFERENT OPTIONS */
            /* HELP OPTION */
            if (first_option_letter - 'h' == 0){
               print_help();
            }
            /* ADD OPTION */
            /* else if (first_option_letter - 'a' == 0){ */
            /*    add_to_list(list_name,); */
            /* } */
            break;
        default:
            printf("Too many arguments! Run beli with 'help' flag for more information.\n");
            return 1;
            break;
                }
}
