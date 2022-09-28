#include "functions.h"
#include <stdio.h>
#include <string.h>

int inline_arguments_check(int argc, char *argv[], char first_option_letter,
                           char *home_dir) {
  /* IMPROPER OPTIONS CHECK */

  /* 12 is the amount of all possible options */
  char *possible_options[12] = {"a", "add",   "c", "create", "r", "remove",
                                "b", "blank", "p", "print",  "h", "help"};
  int is_valid;
  is_valid = 0;
  for (int i = 0; i < 12; i++) {
    if (strcmp(argv[1], possible_options[i]) == 0) {
      is_valid = 1;
    }
  }

  if (is_valid == 0) {
    return 1;
  }

  /* CREATE OPTION WITHOUT SPECIFIED LIST */
  if (argc == 2 && first_option_letter - 'c' == 0) {
    return 2;
  }

  if (argc == 3) {
    /* CHECK LIST NAME LENGTH*/
    if (strlen(argv[2]) <= 0 || strlen(argv[2]) > 15) {
      return 3;
    } else {
      /* CHECK LIST NAME CORRECTNESS */
      regex_t regex_pointer;
      int is_compilation_succesful;
      int regex_match;

      is_compilation_succesful = regcomp(&regex_pointer, "^[0-9a-zA-Z_]*$", 0);

      if (is_compilation_succesful != 0) {
        return 4;
      }

      regex_match = regexec(&regex_pointer, argv[2], 0, NULL, 0);

      if (regex_match == REG_NOMATCH) {
        return 5;
      }
      /* CHECKING IF 'CREATE' OPTION WAS USED ON AN ALREADY EXISTING LIST
       * OR IF 'BLANK' OPTION WAS USED ON A NON-EXISTING LIST*/
      if (first_option_letter == 'c' || first_option_letter == 'b' ||
          first_option_letter == 'a') {
        FILE *fptr;
        const char *list_of_all_lists = "/.config/beli/all_lists.beli";
        char path_to_list_of_all_lists[66]; // 66 because 38 from home_dir and
                                            // 28 from list_of_all_lists
        char current_list[20];
        int lists_count;
        int can_create = 1;
        int can_blank = 0;
        int can_add = 0;
        sprintf(path_to_list_of_all_lists, "%s%s", home_dir, list_of_all_lists);

        fptr = fopen(path_to_list_of_all_lists, "r");
        if (fptr == NULL) {
          printf("Could not open the file.\n");
          exit(1);
        }

        fscanf(fptr, "%d", &lists_count);

        for (int i = 0; i < lists_count; i++) {
          fscanf(fptr, "%s", current_list);

          if (strcmp(current_list, argv[2]) == 0) {
            can_add = 1;
            can_create = 0;
            can_blank = 1;
          }
        }

        fclose(fptr);

        if (can_create == 0 && first_option_letter == 'c') {
          return 6;
        }

        if (can_blank == 0 && first_option_letter == 'b') {
          return 7;
        }

        if (can_add == 0 && first_option_letter == 'a') {
          return 8;
        }
      }
    }
  }
  return 0;
}
