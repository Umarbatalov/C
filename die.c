//
// Created by ubatalov on 06.06.2020.
//
#include <stdlib.h>

void die(char *message);

void die(char *message)
{
    printf("%s\n", message);
    exit(0);
}
