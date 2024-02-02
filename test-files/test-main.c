// #include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    // char *tok = NULL;
    char *comm = "";
    char *tok= NULL, *arg = NULL;

    char line[100];
    strcpy(line, comm);
    tok = strtok(line, " ");
    arg = strtok(NULL, " ");
    printf("%s, %s\n", tok, arg);
    return (0);
}