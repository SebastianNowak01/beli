#include "functions.h"

void printHelp(){
    printf( "Beli - command line shopping list\n\n"
            "Usage: ./beli [options] [list]*\n\n"
            "Options:\n"
            "   a, add             adds an item to a list\n"
            "   c, create          creates a new list named [list]\n"
            "   r, remove          removes a list named [list]\n"
            "   b, blank           erases whole list named [list]\n"
            "   p, print           prints [list]'s content\n"
            "   h, help            prints this help\n\n"
            "*If no [list] argument is provided the action will be executed on the original list.\n"
            );
}
