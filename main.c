#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(char* message){
    printf("%s\n", message);
    exit(0);
}

int
main()
{
    char a[2];

    a[0] = 'a';

    if(!strcmp(a, "a")) {
        puts("a is \"a\"");
    }

    return 0;
}
