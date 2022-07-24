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
            /* EXTRACT FIRST LETTER FROM 'OPTION' FOR CHECKING ERRORS AND OPTIONS*/
            ;
            char first_option_letter;
            char home_dir[38]; //38 because of the fact that username can be 32 characters long + 6 characters for the /home/
            first_option_letter = argv[1][0];
            strcpy(home_dir, getenv("HOME"));
            int error_type;

            error_type = inline_arguments_check(argc, argv, first_option_letter, home_dir);
            switch(error_type){
                case 1:
                    printf("There is no such option! Run beli with 'help' flag for more information.\n");
                    return 1;
                    break;

                case 2:
                    printf("Cannot create a new list with no name.\n");
                    return 1;
                    break;

                case 3:
                    printf("Invalid list name length! List names can be up to 15 characters long.\n");
                    return 1;
                    break;

                case 4:
                    printf("Regex compilation error.\n");
                    return 1;
                    break;

                case 5:
                    printf("Invalid list name! List names can only be letters, numbers and underscores.\n");
                    return 1;
                    break;

                case 6:
                    printf("Cannot create already existing list.\n");
                    return 1;
                    break;

                default:
                    //No errors while checking inline arguments
                    break;
            }

            /* -------------------- PROPER MAIN FUNCTION -------------------- */
            /* DECLARED VARIABLES TO GET 'HOME' VARIABLE AND SUBSEQUENTLY FULL PATH TO CONFIG FILE */
            char list_name[20]; //20 because 15 chars maximum for name and + 5 for .beli extension
            char path[57]; //57 because of home_dir size and /.config/beli/lists
            const char* config_path = "/.config/beli/lists";

            /* GETTING FULL PATH TO CONFIG FILES TO OPERATE ON FILES WITHIN */
            strcpy(path, home_dir);
            strcat(path, config_path);

            /* OBTAINING LIST NAME (OR USING PRIMARY LIST IF NO 3RD ARGUMENT SPECIFIED) */
            /* printf("%s\n", path); */
            if (argc == 2){
                strcpy(list_name,"list.beli");
            }
            else if (argc == 3) {
                strcpy(list_name, argv[2]);
                strcat(list_name, ".beli");
            }
            /* printf("%s", list_name); */

            /* HANDLING ALL THE DIFFERENT OPTIONS */

            switch(first_option_letter){
                case 'a':
                    add_to_list(list_name, path);
                    break;
                case 'c':
                    create_or_blank_list(list_name, path);
                    break;
                case 'r':
                    remove_list(list_name, path);
                    break;
                case 'b':
                    create_or_blank_list(list_name, path);
                    break;
                case 'p':
                    print_list(list_name, path);
                    break;
                case 'h':
                    print_help();
                    break;
               default:
                   //this should never happen
                   return 1;
            }
	    
            break;
        default:
            printf("Too many arguments! Run beli with 'help' flag for more information.\n");
            return 1;
            break;
    }
}
