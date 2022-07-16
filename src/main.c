 #include "functions.h"

int main(int argc, char* argv[]){
    switch (argc) {
        case 1:
            printHelp();
            break;
        case 2:
        case 3:
            /*ERROR CHECKING SECTION: IMPROPER OPTIONS*/
            char* possibleOptions[12] = {"a", "add", "c", "create", "r", "remove", "b", "blank", "p", "print", "h", "help"};
            int isValid;
            isValid = 0;
            for (int i=0; i < 12;i++){
                if (strcmp(argv[1], possibleOptions[i]) == 0){
                    isValid = 1;
                }
            }
            if (isValid == 0){
                printf("There is no such option! Run beli with 'help' flag for more information.\n");
                return 1;
            }

            char firstLetter;
            firstLetter = argv[1][0];
            if (argc == 2 && firstLetter - 'c' == 0){
                printf("Cannot create a new list with no name.\n");
                return 1;
            }
            char homeDir[38]; //38 because of the fact that username can be 32 characters long + 6 characters for the /home/
            char listName[20]; //20 because 15 chars maximum for name and + 5 for .beli extension
            strcpy(homeDir, getenv("HOME"));

            if (argc == 2){
                strcpy(listName,"list.beli");
            }
            else if (argc == 3) {
                strcpy(listName, argv[2]);
                strcat(listName, ".beli");
            }
            printf("%s", listName);
            break;
        default:
            printf("Too many arguments! Run beli with 'help' flag for more information.\n");
            return 1;
            break;
                }
}
