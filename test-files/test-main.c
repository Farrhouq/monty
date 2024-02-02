// #include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *comm = "";
    char *tok= NULL, *arg = NULL;

    char line[100];
    strcpy(line, comm);
    tok = strtok(line, " ");
    arg = strtok(NULL, " ");

    char first[] = "push\n";
    char sec[] = "push";

    first[4]  = '\0';
    
    printf("%d\n", strcmp("push\n", "push"));
    printf("%s, %s\n", tok, arg);
    return (0);
}