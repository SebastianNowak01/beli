#include "functions.h"

int inline_arguments_check(int argc, char* argv[], char first_option_letter){
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
        return 1;
    }

    /* CREATE OPTION WITHOUT SPECIFIED LIST */
    if (argc == 2 && first_option_letter - 'c' == 0){
        return 2;
    }

    /* CHECKING LENGTH OF 3RD ARGUMENT AND CHECK NAME CORRECTNESS */
    if (argc == 3){
        if (strlen(argv[2]) <= 0 || strlen(argv[2]) > 15){
        return 3;
        }
        else {
            regex_t regex_pointer;
            int is_compilation_succesful;
            int regex_match;

            is_compilation_succesful = regcomp(&regex_pointer, "^[0-9a-zA-Z_]*$", 0);

            if (is_compilation_succesful != 0){
                return 4;
            }

            regex_match = regexec(&regex_pointer, argv[2], 0, NULL, 0);

            if (regex_match == REG_NOMATCH){
                return 5;
            }

        }
    }
    return 0;
}
