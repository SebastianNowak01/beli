 #include "functions.h"

int main(int argc, char* argv[]){
    switch (argc) {
        case 1:
            char* fileName = "list.beli";
            char* path = "/home/USER/.config/beli";
            printList(fileName,path);
            break;
        case 2:
        case 3:

            break;
        default:
                }

    /* const char* homedir; */
    /* if ((homedir = getenv("HOME")) == NULL) { */
    /*     homedir = getpwuid(getuid())->pw_dir; */
    /* } */

    /* if (strcmp(argv[1],"-a") == 0 || strcmp(argv[1],"-add") == 0){ */
    /*     printf("Herpu me!"); */
    /* } */

    /* if (argc != 2){ */
    /*     printf("Wrong parameters!\n"); */
    /* } */
}
